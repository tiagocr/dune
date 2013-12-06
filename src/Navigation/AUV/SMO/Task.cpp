//***************************************************************************
// Copyright 2007-2013 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Universidade do Porto. For licensing   *
// terms, conditions, and further information contact lsts@fe.up.pt.        *
//                                                                          *
// European Union Public Licence - EUPL v.1.1 Usage                         *
// Alternatively, this file may be used under the terms of the EUPL,        *
// Version 1.1 only (the "Licence"), appearing in the file LICENCE.md       *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://www.lsts.pt/dune/licence.                                        *
//***************************************************************************
// Author: Tiago Rodrigues                                                  *
//***************************************************************************

// DUNE headers.
#include <DUNE/DUNE.hpp>

namespace
{
  namespace Navigation
  {
    namespace AUV
    {
      namespace SMO
      {
        using DUNE_NAMESPACES;

        //AUV Parameters
        static const int xg=0;
        static const int yg=0;
        static const float zG = 0.01;
        static const float zg=0.01;
        static const float Ixx = 0.04;
        static const float Iyy = 2.1;
        static const float Izz = 2.1;
        static const int Ixy = 0;
        static const int Iyx = 0;
        static const int Ixz = 0;
        static const int Iyz = 0;
        static const int Izy = 0;
        static const int Izx = 0;

        static const int m=18;

        static const int Xdudt = -1;
        static const int Ydvdt = -16;
        static const int Zdwdt = -16;
        static const int Kdpdt = 0;
        static const float Mdqdt = 0;//-0.7637;
        static const float Ndrdt = 0;//-0.7637;

        static const int W=176;
        static const int B=177;

        double timestep=0;

        // Sliding Mode Observer Matrices
        Math::Matrix nu_dot(6,1,0.0);
        Math::Matrix nu_dot_ant(6,1,0.0);
        Math::Matrix nu_dot_est(6,1,0.0);
        Math::Matrix nu_dot_est_ant(6,1,0.0);
        Math::Matrix dn_est(6,1,0.0);
        Math::Matrix nu(6,1,0.0);
        Math::Matrix nu_ant(6,1,0.0);
        Math::Matrix nu_est(6,1,0.0);
        Math::Matrix nu_error(6,1,0.0);
        Math::Matrix tau(6,1,0.0);
        Math::Matrix v_est(6, 1, 0.0);
        Math::Matrix dv_dt_est(6,1,0.0);
        Math::Matrix J_ant(6,6,0.0);
        Math::Matrix J(6,6,0.0);
        Math::Matrix v(6,1,0.0);
        Math::Matrix dJ(6,6,0.0);


        struct Arguments
        {
          //Consumer parameters
          double x=0;
          double y=0;
          double z=0;
          double range=0;
          double bearing=0;
          int flag_initial_point=0;
          int flag_initial_orientation=0;
          double gps_fix[4];
          double gps_initial_point[4];
          double gps_accuracy[2];
          double gps_treshold;
          double euler_angles[3];
          double euler_angles_est[3];
          double euler_angles_delta[4];
          double accelerations[4];
          double velocities[7];
          double velocities_ant[7]={0,0,0,0,0,0,0};
          double watervelocity[6];
          double profundity[2];
          double servo_pos[4];
          double thruster;
          double tstep;
          double er[2];
          double timestamps[6];
          double lin_timestamp;
          double lin_timestamp_ant;
          int lin_timestamp_init=0;
          double angvel_timestamp;
          double angvel_timestamp_ant;
          double euler_timestamp;
          double euler_timestamp_ant;
          int euler_timestamp_init=0;
          int angvel_timestamp_init=0;
          double timestamps_ant[6];
          double calmode;
          double timestamp_init=0;
          int flag_valid_pos=0;

          // Resolve Entity string
          std::vector<std::string> servo_entities;
          std::string imu_entities;
          std::string ahrs_entities;

          // Entity ID
          int imu_entity;
          int ahrs_entity;
          int temp_entities;

          // Get entity from reading
          int angvel_entity=0;
          int ea_entity=0;

          int flag_imu_active=0;
          int flag_ahrs_active=0;

        };

        struct Task: public DUNE::Tasks::Task
        {

          //! Constructor.
          //! @param[in] name task name.
          //! @param[in] ctx context.

          //! Use NavigationUnvertainty messages to send tau to test
          IMC::EstimatedState m_est;
          IMC::NavigationUncertainty m_tau;

          //! Time window between values.
          DUNE::Time::Delta m_delta;
          /* DUNE::Time::Delta u_delta;
             DUNE::Time::Delta v_delta;
             DUNE::Time::Delta w_delta;
             DUNE::Time::Delta p_delta;
             DUNE::Time::Delta q_delta;
             DUNE::Time::Delta r_delta;*/

          Arguments m_args;
          Derivative<double> deriv;

          Task(const std::string& name, Tasks::Context& ctx):
            DUNE::Tasks::Task(name, ctx)
          {

            param("Entity Label - Servos", m_args.servo_entities)
            .defaultValue("Servo 0, Servo 1, Servo 2, Servo 3")
            .description("Label of the servo position message to compute produced torque");

            param("Entity Label - IMU", m_args.imu_entities)
            .defaultValue("IMU")
            .description("Label of the IMU message");

            param("Entity Label - AHRS", m_args.ahrs_entities)
            .defaultValue("AHRS")
            .description("Label of the AHRS message");


            //Register Consumers

            //Linear Accelerations
            bind<IMC::Acceleration>(this);

            //Euler Angles
            bind<IMC::EulerAngles>(this);

            //Linear and Angular Velocities
            bind<IMC::AngularVelocity>(this);
            bind<IMC::GroundVelocity>(this);

            //Water Velocity
            bind<IMC::WaterVelocity>(this);

            //Depth
            bind<IMC::Depth>(this);

            //Servo Position
            bind<IMC::ServoPosition>(this);

            //Thrust Actuation
            bind<IMC::SetThrusterActuation>(this);

            //It misses position measure, how to obtain from wgs84 gps?

            //GPS Fix - Initial point to calculate displacement?
            bind<IMC::GpsFix>(this); //WGS-84 lat, lon and height above ellipsoide

            bind<IMC::EntityActivationState>(this);

            bind<IMC::EntityState>(this);


          }

          void
          onEntityResolution(void)
          {

            /*try
              {
              for(size_t i = 0; i < m_args.servo_entities.size(); ++i)
              {
              unsigned id = resolveEntity(m_args.servo_entities[i]);
              }
              }
              catch (...)
              {
              //cout << "default exception";
              }*/

            try
            {
              m_args.imu_entity = resolveEntity(m_args.imu_entities);
            }
            catch (...)
            {
              m_args.imu_entity = -1;
            }

            try
            {
              m_args.ahrs_entity = resolveEntity(m_args.ahrs_entities);
            }
            catch (...)
            {
              m_args.ahrs_entity = -1;
            }

          }

          //GPSFix
          void
          consume(const IMC::GpsFix* gpsfix)
          {

            m_args.gps_accuracy[0]=gpsfix->hacc;

            if(m_args.flag_initial_point==0){m_args.gps_treshold=m_args.gps_accuracy[0]+1;}
            if(m_args.flag_initial_point!=0){m_args.gps_treshold=7;}

            if (gpsfix->validity & IMC::GpsFix::GFV_VALID_POS /*& m_args.gps_accuracy[0]<m_args.gps_treshold*/)
            {
              if(m_args.gps_accuracy[0]<m_args.gps_treshold)
              {
                m_args.gps_fix[1] = gpsfix->lat;
                m_args.gps_fix[2] = gpsfix->lon;
                m_args.gps_fix[3] = gpsfix->height;
                m_args.flag_valid_pos = 1;
              }

              if(m_args.flag_initial_point==0)
              {
                m_args.gps_initial_point[0]=m_args.gps_fix[1];
                m_args.gps_initial_point[1]=m_args.gps_fix[2];
                m_args.gps_initial_point[2]=m_args.gps_fix[3];
                m_args.flag_initial_point=1;
              }

              if(m_args.gps_accuracy[0]>=m_args.gps_treshold)
              {
                m_args.flag_valid_pos = 0;
              }

            }

            if (!(gpsfix->validity & IMC::GpsFix::GFV_VALID_POS)/* || (m_args.gps_accuracy[0]>=m_args.gps_treshold)*/)
            {
              m_args.flag_valid_pos = 0;
            }

          }

          //Euler Angles - AHRS
          void
          consume(const IMC::EulerAngles* euler)
          {
            m_args.euler_angles[0] = euler->phi;
            m_args.euler_angles[1] = euler->theta;
            m_args.euler_angles[2] = euler->psi;

            if(m_args.flag_initial_orientation==0)
            {
              m_args.flag_initial_orientation=1;
              nu(3,0)=m_args.euler_angles[0];
              nu(4,0)=m_args.euler_angles[1];
              nu(5,0)=m_args.euler_angles[2];//+16*3.14/180;//+20*3.14/180;
              nu_est(3,0)=m_args.euler_angles[0];
              nu_est(4,0)=m_args.euler_angles[1];
              nu_est(5,0)=m_args.euler_angles[2];//+16*3.14/180;//+20*3.14/180;
            }

            m_args.ea_entity = euler->getSourceEntity();


            m_args.euler_timestamp = euler->getTimeStamp();//p_delta.getDelta();

            if(m_args.euler_timestamp_init == 0)
            {
              m_args.euler_timestamp_ant = m_args.euler_timestamp;
              m_args.euler_timestamp_init = 1;
            }

          }


          //Linear Acceleration - IMU
          void
          consume(const IMC::Acceleration* acc)
          {
            m_args.accelerations[0] = acc->x;
            m_args.accelerations[1] = acc->y;
            m_args.accelerations[2] = acc->z;
            m_args.accelerations[3] = acc->time;
          }

          //Linear Velocity - DVL
          void
          consume(const IMC::GroundVelocity* vel)
          {

            if (vel->validity & IMC::GroundVelocity::VAL_VEL_X)
            {
              m_args.velocities[0] = vel->x;
              //m_args.timestamps[0] = vel->getTimeStamp();//u_delta.getDelta();//vel->getTimestamp();
              m_args.velocities_ant[0]=m_args.velocities[0];
              m_args.lin_timestamp = vel->getTimeStamp();
            }
            if (!(vel->validity & IMC::GroundVelocity::VAL_VEL_X))
            {
              m_args.velocities[0] = m_args.velocities_ant[0];
              //m_args.timestamps[0] = vel->getTimeStamp();
              m_args.lin_timestamp = vel->getTimeStamp();
            }

            if(m_args.lin_timestamp_init == 0)
            {
              m_args.lin_timestamp_ant = m_args.lin_timestamp;
              m_args.lin_timestamp_init = 1;
            }


            if (vel->validity & IMC::GroundVelocity::VAL_VEL_Y)
            {
              m_args.velocities[1] = vel->y;
              m_args.timestamps[1] = vel->getTimeStamp();//v_delta.getDelta(); //vel->getTimestamp();
              m_args.velocities_ant[1]=m_args.velocities[1];
            }
            if (!(vel->validity & IMC::GroundVelocity::VAL_VEL_Y))
            {
              m_args.velocities[1] = m_args.velocities_ant[1];
            }


            if (vel->validity & IMC::GroundVelocity::VAL_VEL_Z)
            {
              m_args.velocities[2] = vel->z;
              m_args.timestamps[2] = vel->getTimeStamp();//w_delta.getDelta();//vel->getTimestamp();
              m_args.velocities_ant[2]=m_args.velocities[2];
            }
            if (!(vel->validity & IMC::GroundVelocity::VAL_VEL_Z))
            {
              m_args.velocities[2] = m_args.velocities_ant[2];
            }


          }

          //Angular Velocity - IMU or AHRS
          void
          consume(const IMC::AngularVelocity* angvel)
          {
            if(m_args.flag_imu_active == 1 & angvel->getSourceEntity() == m_args.imu_entity)
            {
              m_args.velocities[3] = angvel->x;
              m_args.velocities[4] = angvel->y;
              m_args.velocities[5] = angvel->z;

              m_args.angvel_timestamp = angvel->getTimeStamp();//p_delta.getDelta();

              if(m_args.angvel_timestamp_init == 0)
              {
                m_args.angvel_timestamp_ant = m_args.angvel_timestamp;
                m_args.angvel_timestamp_init = 1;
              }

            }

            m_args.angvel_entity = angvel->getSourceEntity();
          }

          //Water Velocity
          void
          consume(const IMC::WaterVelocity* wvel)
          {
            m_args.watervelocity[0] = wvel->x;
            m_args.watervelocity[1] = wvel->y;
            m_args.watervelocity[2] = wvel->z;
            m_args.watervelocity[3] = 0;
            m_args.watervelocity[4] = 0;
            m_args.watervelocity[5] = 0;
          }

          //Depth - Pressure Sensor
          void
          consume(const IMC::Depth* dep)
          {
            m_args.profundity[0] = dep->value;
          }

          //Servo Positions
          void
          consume(const IMC::ServoPosition* msg)
          {
            //if (msg->getSourceEntity() == m_spos_ent)
            // {
            m_args.servo_pos[msg->id] = msg->value;
            // assumes messages come in the ordered by id even though they may not
            // will not make much difference
            /*  if (msg->id == 3)
                computeProducedTorque();*/
            //}

            //m_args.entities = msg->getSourceEntity();
          }

          //Thrust Actuation
          void
          consume(const IMC::SetThrusterActuation* msg)
          {
            m_args.thruster = msg->value;
          }


          void
          consume(const IMC::EntityActivationState* msg)
          {

            /* if (msg->getSourceEntity() == m_args.imu_entity)
               {
               if (msg->state == IMC::EntityActivationState::EAS_ACTIVE)
               {
               m_args.flag_imu_active = 1 ;
               }
               if (msg->state == IMC::EntityActivationState::EAS_INACTIVE)
               {
               m_args.flag_imu_active = 0 ;
               }
               }

               if (msg->getSourceEntity() == m_args.ahrs_entity)
               {
               if (msg->state == IMC::EntityActivationState::EAS_ACTIVE)
               {
               m_args.flag_ahrs_active = 1 ;
               }
               if (msg->state == IMC::EntityActivationState::EAS_INACTIVE)
               {
               m_args.flag_ahrs_active = 0 ;
               }
               }*/

          }

          void
          consume(const IMC::EntityState* msg)
          {
            if (msg->getSourceEntity() == m_args.imu_entity)
            {
              if (msg->state == IMC::EntityState::ESTA_NORMAL)
              {
                m_args.flag_imu_active = 1 ;
              }
              if (msg->state != IMC::EntityState::ESTA_NORMAL)
              {
                m_args.flag_imu_active = 0 ;
              }
            }

            if (msg->getSourceEntity() == m_args.ahrs_entity)
            {
              if (msg->state == IMC::EntityState::ESTA_NORMAL)
              {
                m_args.flag_ahrs_active = 1 ;
              }
              if (msg->state != IMC::EntityState::ESTA_NORMAL)
              {
                m_args.flag_ahrs_active = 0 ;
              }
            }
          }


          //! Update internal state with new parameter values.
          void
          onUpdateParameters(void)
          {
          }

          //! Release resources.
          void
          onResourceRelease(void)
          {
          }



          /*********************Compute Rotation Matrix, is Derivative and Velocity measure Matrix*********************/

          Matrix
          ComputeJ(void)
          {
            // Pass euler angles to row matrix
            Math::Matrix ea(3,1);
            ea(0) = Math::Angles::normalizeRadian(m_args.euler_angles_est[0]);
            ea(1) = Math::Angles::normalizeRadian(m_args.euler_angles_est[1]);
            ea(2) = Math::Angles::normalizeRadian(m_args.euler_angles_est[2]);

            // Create 6x6 Rotation Matrix
            Math::Matrix J(6,6);
            J = ea.toDCMSMO();

            return J;
          }

          Matrix
          Computev(void)
          {
            // Create Row matrix from measures
            Math::Matrix v_tmp(6,1);
            v_tmp(0) = m_args.velocities[0];
            v_tmp(1) = m_args.velocities[1];
            v_tmp(2) = m_args.velocities[2];
            v_tmp(3) = m_args.velocities[3];//-m_args.bias_r;
            v_tmp(4) = m_args.velocities[4]-m_args.er[0];//-m_args.bias_p;
            v_tmp(5) = m_args.velocities[5]-m_args.er[1];//-m_args.bias_y;

            if(v_tmp(0)>1.9)
            {
              v_tmp(0)=1.9;
            }
            if(v_tmp(0)<0)
            {
              v_tmp(0)=0;
            }

            return v_tmp;
          }

          Matrix
          ComputeJ_est(double pos_estimado[])
          {
            // Pass euler angles to row matrix
            Math::Matrix ea(3,1);
            ea(0) = Math::Angles::normalizeRadian(pos_estimado[3]);
            ea(1) = Math::Angles::normalizeRadian(pos_estimado[4]);
            ea(2) = Math::Angles::normalizeRadian(pos_estimado[5]);

            // Create 6x6 Rotation Matrix
            Math::Matrix J_est(6,6);
            J_est = ea.toDCMSMO();

            return J_est;
          }

          /*********************END Compute Rotation Matrix, is Derivative and Velocity measure Matrix*********************/



          /*********************Compute AUV Model Matrices*********************/


          Matrix
          ComputeM_RB(void)//Function checked, inertia matrix is good
          {
            //Inertia Matrix
            double MRB_vector[36]={m,0,0,0,m*zG,0,0,m,0,-m*zG,0,0,0,0,m,0,0,0, 0,-m*zG,0,Ixx,0,0,m*zG,0,0,0,Iyy,0,0,0,0,0,0,Izz};
            return ( Matrix(MRB_vector, 6, 6) );
          }

          Matrix
          ComputeM_A(void)//Function checked, inertia matrix is good
          {
            //Inertia Matrix
            double MA_vector[6]={-Xdudt,-Ydvdt,-Zdwdt,-Kdpdt,-Mdqdt,-Ndrdt};
            return ( Matrix(MA_vector, 6) ); // Creates diagonal Matrix
          }

          Matrix
          ComputeC_RB(double v_estimado[])//Function checked, coriolis matrix is good
          {
            // Coriolis Matrix

            //double u = vel[0];//m_args.velocities[0];
            double u = v_estimado[0];
            double v = v_estimado[1];
            double w = v_estimado[2];
            double p = v_estimado[3];
            double q = v_estimado[4];
            double r = v_estimado[5];

            double CRB_vector[36]={0,0,0,m*(yg*q+zg*r),-m*(xg*q-w),-m*(xg*r+v),0,0,0,-m*(yg*p+w),m*(zg*r+xg*p),-m*(yg*r-u),0,0,0,-m*(zg*p-v),-m*(zg*q+u),m*(xg*p+yg*q),-m*(yg*q+zg*r),m*(yg*p+w),m*(zg*p-v),0,Iyz*q-Ixz*p+Izz*r,Iyz*r+Ixy*p-Iyy*q,m*(xg*q-w),-m*(zg*r+xg*p),m*(zg*q+u),Iyz*q+Ixz*p-Izz*r,0,-Ixz*r-Ixy*q+Ixx*p,m*(xg*r+v),m*(yg*r-u),-m*(xg*p+yg*q),-Iyz*r-Ixy*p+Iyy*q,Ixz*r+Ixy*q-Ixx*p,0};

            return (Matrix(CRB_vector, 6, 6) );
          }

          Matrix
          ComputeC_A(double v_estimado[])//Function checked, coriolis matrix is good
          {
            // Coriolis Matrix

            double ur = v_estimado[0];
            double vr = v_estimado[1];
            double wr = v_estimado[2];
            double pr = v_estimado[3];
            double qr = v_estimado[4];
            double rr = v_estimado[5];

            double CA_vector[36]={0,0,0,0,-Zdwdt*wr,Ydvdt*vr,0,0,0,Zdwdt*wr,0,-Xdudt*ur,0,0,0,-Ydvdt*vr,Xdudt*ur,0,0,-Zdwdt*wr,Ydvdt*vr,0,-Ndrdt*rr, Mdqdt*qr,Zdwdt*wr,0,-Xdudt*ur,Ndrdt*rr,0,-Kdpdt*pr,-Ydvdt*vr,Xdudt*ur,0,-Mdqdt*qr,Kdpdt*pr,0};

            return (Matrix(CA_vector, 6, 6) );
          }

          Matrix
          ComputeD(double v_estimado[]) //Function checked, damping matrix is good
          {
            // Damping Matrix

            double ur = v_estimado[0];
            double vr = v_estimado[1];
            double wr = v_estimado[2];
            double pr = v_estimado[3];
            double qr = v_estimado[4];
            double rr = v_estimado[5];

            double D1_vector[36]={2.4,0,0,0,0,0,0,23,0,0,0,-11.5,0,0,23,0,11.5,0,0,0,0,0.3,0,0,0,0,-3.1,0,9.7,0,0,3.1,0,0,0,9.7};

            double D2_vector[36]={2.4*std::abs(ur),0,0,0,0,0,0,80.0*std::abs(vr),0,0,0,-0.3*std::abs(rr),0,0,80.0*std::abs(wr),0,0.3*std::abs(qr),0,0,0,0,6e-4*std::abs(pr),0,0,0,0,-1.5*std::abs(wr),0,9.1*std::abs(qr),0,0,1.5*std::abs(vr),0,0,0,9.1*std::abs(rr)};


            return (Matrix(D1_vector, 6, 6) + Matrix(D2_vector, 6, 6) );
          }

          Matrix
          ComputeL(double v_estimado[])//Function checked, lift matrix is good
          {
            // Lift Matrix

            double ur = v_estimado[0];

            double L_vector[36]={0,0,0,0,0,0,0,30*ur,0,0,0,-7.7*ur,0,0,30*ur,0,7.7*ur,0,0,0,0,0,0,0,0,0,9.9*ur,0,3.1*ur,0,0,-9.9*ur,0,0,0,3.1*ur};

            /*inf("value L");
              std::cout << Matrix(L_vector, 6, 6) << std::endl;*/

            return (Matrix(L_vector, 6, 6) );

          }

          Matrix
          ComputeG(double pos_estimado[]) //Function checked, restoring forces matrix is good
          {
            // Restoring forces Matrix

            /*double phi = Math::Angles::normalizeRadian(m_args.euler_angles_est[0]);
              double theta = Math::Angles::normalizeRadian(m_args.euler_angles_est[1]);
              double psi = Math::Angles::normalizeRadian(m_args.euler_angles_est[2]);*/
            double phi = Math::Angles::normalizeRadian(pos_estimado[3]);
            double theta = Math::Angles::normalizeRadian(pos_estimado[4]);
            double psi = Math::Angles::normalizeRadian(pos_estimado[5]);

            // Pass euler angles to row matrix
            Math::Matrix G(6,1);
            G(0) = (W-B)*sin(theta);
            G(1) = -(W-B)*cos(theta)*sin(phi);
            G(2) = -(W-B)*cos(theta)*cos(phi);
            G(3) = zg*W*cos(theta)*sin(phi);
            G(4) = zg*W*sin(theta);
            G(5) = 0;

            return G;

          }


          Matrix
          ComputeTau(void)
          {
            Matrix tau_tmp(6, 1, 0.0);
            Matrix deflections(3, 1, 0.0);
            Matrix m_fin_lift(5,1);
            double m_motor_friction = -0.06;
            double fincoef[5] = {9.6, -9.6, 1.82, -3.84, -3.84};
            m_fin_lift= Matrix(fincoef, 5, 1);


            deflections(0) = m_args.servo_pos[3] - m_args.servo_pos[0] + m_args.servo_pos[1] - m_args.servo_pos[2];
            deflections(1) = m_args.servo_pos[1] + m_args.servo_pos[2];
            deflections(2) = m_args.servo_pos[0] + m_args.servo_pos[3];

            tau_tmp(0) = m_args.thruster * 10; // Times 10 to compute thruster force between -10 and 10
            tau_tmp(1) = m_fin_lift(0) * m_args.velocities[0] * m_args.velocities[0] * deflections(2);
            tau_tmp(2) = m_fin_lift(1) * m_args.velocities[0] * m_args.velocities[0] * deflections(1);
            tau_tmp(3) = m_fin_lift(2) * m_args.velocities[0] * m_args.velocities[0] * deflections(0) + m_motor_friction * tau_tmp(0);
            tau_tmp(4) = m_fin_lift(3) * m_args.velocities[0] * m_args.velocities[0] * deflections(1);
            tau_tmp(5) = m_fin_lift(4) * m_args.velocities[0] * m_args.velocities[0] * deflections(2);


            return tau_tmp;
          }

          /*********************END Compute AUV Model Matrices*********************/




          /*********************Sliding Mode Observer Gain Matrices*********************/

          Matrix
          ComputeK1(void)
          {
            Matrix K1 = Matrix(6, 6, 0.0);
            K1(0, 0) = 0.7;
            K1(1, 1) = 0.6;
            K1(2, 2) = 0.6;
            K1(3, 3) = 4;
            K1(4, 4) = 0.2;
            K1(5, 5) = 0.9;

            return K1;
          }

          Matrix
          ComputeK2(void)
          {
            Matrix K2 = Matrix(6, 6, 0.0);
            K2(0, 0) = 0.7;
            K2(1, 1) = 0.5;
            K2(2, 2) = 0.5;
            K2(3, 3) = 4;
            K2(4, 4) = 0.4;
            K2(5, 5) = 0.7;

            return K2;
          }

          Matrix
          Computealfa1(void)
          {
            Matrix alfa1 = Matrix(6, 6, 0.0);
            alfa1(0, 0) = 0.7;
            alfa1(1, 1) = 0.4;
            alfa1(2, 2) = 0.4;
            alfa1(3, 3) = 3;
            alfa1(4, 4) = 0.2;
            alfa1(5, 5) = 0.7;

            return alfa1;
          }

          Matrix
          Computealfa2(void)
          {
            Matrix alfa2 = Matrix(6, 6, 0.0);
            alfa2(0, 0) = 0.6;
            alfa2(1, 1) = 0.5;
            alfa2(2, 2) = 0.5;
            alfa2(3, 3) = 3;
            alfa2(4, 4) = 0.1;
            alfa2(5, 5) = 0.7;

            return alfa2;
          }

          Matrix
          Computesignum(double error[])
          {
            Matrix signum = Matrix(6, 1, 0.0);
            int i=0;

            for ( i = 0; i <= 5; i++ )
            {
              if(error[i]<0)
              {
                signum(i, 0) = - 1;
              }
              if(error[i]>=0)
              {
                signum(i, 0) = 1;
              }
            }

            return signum;
          }

          Matrix
          Computetanh(double error[])
          {
            Matrix tgh=Matrix(6,1,0.0);
            int i=0;
            double boundarylayer=0.05;

            for ( i = 0; i <= 5; i++)
            {
              tgh(i, 0) = tanh(error[i]/boundarylayer);
            }

            return tgh;
          }

          /*********************END Sliding Mode Observer Gain Matrices*********************/



          //! Main loop.
          void
          onMain(void)
          {
            while (!stopping())
            {
              waitForMessages(1.0);




              /*******************Get time step for integration*******************/

              m_args.tstep = m_delta.getDelta();
              timestep=m_args.tstep;
              /*inf("value timestep");
                std::cout << m_args.tstep << std::endl;*/

              /*******************END Getting time step for integration*******************/



              /*******************GPS Signal Acquisition*******************/


              /* double phi = Math::Angles::normalizeRadian(m_args.euler_angles[0]);
                 double theta = Math::Angles::normalizeRadian(m_args.euler_angles[1]);
                 double psi = Math::Angles::normalizeRadian(m_args.euler_angles[2]);    */

              Coordinates::WGS84::getNEBearingAndRange(m_args.gps_initial_point[0], m_args.gps_initial_point[1], m_args.gps_fix[1], m_args.gps_fix[2], &m_args.bearing, &m_args.range);

              m_args.x = m_args.range * std::cos(m_args.bearing);
              m_args.y = m_args.range * std::sin(m_args.bearing);
              m_args.z = m_args.profundity[0];

              std::cout << m_args.x << std::endl;
              std::cout << m_args.y << std::endl;
              std::cout << m_args.flag_valid_pos << std::endl;
              std::cout << m_args.gps_accuracy[0] << std::endl;

              //inf("GPS Fix Coordinates");
              //std::cout <<m_args.x/*m_args.gps_initial_point[0]*/// << std::endl;
              //std::cout <<m_args.y/*m_args.gps_initial_point[1]*/ << std::endl;
              //std::cout <<m_args.z/*m_args.gps_initial_point[2]*/ << std::endl;
              /*inf("Euler Angles");
                std::cout <<phi<< std::endl;
                std::cout <<theta<< std::endl;
                std::cout <<psi<< std::endl;*/

              /*******************END GPS Signal Acquisition*******************/



              /*********************Position Measure from Velocity*********************/


              m_args.euler_angles_est[0] = nu(3,0);
              m_args.euler_angles_est[1] = nu(4,0);
              m_args.euler_angles_est[2] = nu(5,0);


              //Take out earth rotation from angular velocities

              m_args.er[0]=((sin(nu(3,0))*sin(nu(4,0))*cos(nu(5,0))-cos(nu(3,0))*sin(nu(5,0)))*cos(m_args.gps_fix[1]) - sin(nu(3,0))*cos(nu(4,0))*sin(m_args.gps_fix[1]))*7.292115e-5;

              m_args.er[1]=((sin(nu(3,0))*sin(nu(5,0))+cos(nu(3,0))*sin(nu(4,0))*cos(nu(5,0)))*cos(m_args.gps_fix[1]) - cos(nu(3,0))*cos(nu(4,0))*sin(m_args.gps_fix[1]))*7.292115e-5;


              // Calculate Rotation Matrix
              J=ComputeJ();
              v=Computev();


              // Calculate nu_dot
              nu_dot=J*v;

              // Integrate velocity in Earth-fixed Frame to obtain position
              //double delta_lin=m_args.timestamps[0]-m_args.timestamps_ant[0];
              //double delta_ang=m_args.timestamps[3]-m_args.timestamps_ant[3];
              double delta_lin = m_args.lin_timestamp - m_args.lin_timestamp_ant;
              double delta_ang = m_args.angvel_timestamp - m_args.angvel_timestamp_ant;
              double delta_euler = m_args.euler_timestamp - m_args.euler_timestamp_ant;
              //if(m_args.timestamp_init<1 & delta_lin>100){delta_lin=0;m_args.timestamp_init+=1;}
              //if(m_args.timestamp_init<1 & delta_ang>100){delta_ang=0;m_args.timestamp_init+=0.5;}

              nu(0,0)=nu(0,0) + (nu_dot_ant(0,0) + nu_dot(0,0))/2*delta_lin;
              nu(1,0)=nu(1,0) + (nu_dot_ant(1,0) + nu_dot(1,0))/2*delta_lin;
              nu(2,0)=nu(2,0) + (nu_dot_ant(2,0) + nu_dot(2,0))/2*delta_lin;

              nu(3,0)=nu(3,0) + (nu_dot_ant(3,0) + nu_dot(3,0))/2*delta_ang;
              nu(4,0)=nu(4,0) + (nu_dot_ant(4,0) + nu_dot(4,0))/2*delta_ang;
              nu(5,0)=nu(5,0) + (nu_dot_ant(5,0) + nu_dot(5,0))/2*delta_ang;

              /*double delta_dj=delta_ang;
              // Compute derivative of Rotation Matrix
              if(std::abs(delta_dj)<0.000001){J_ant=J;delta_dj=1;}
              dJ=(J-J_ant)/delta_dj;
              /*inf("value timestamp ");
              std::cout << dJ << std::endl;*/
              //J_ant=J;

              nu_dot_ant=nu_dot;

              //m_args.timestamps_ant[0]=m_args.timestamps[0];
              m_args.lin_timestamp_ant = m_args.lin_timestamp;
              m_args.angvel_timestamp_ant = m_args.angvel_timestamp;
              m_args.euler_timestamp_ant = m_args.euler_timestamp;
              //m_args.timestamps_ant[3]=m_args.timestamps[3];/*


              /*inf("value timestamp ");
                std::cout << std::setprecision(20) << std::showpoint;
                std::cout << delta_lin << std::endl;
                std::cout << delta_ang << std::endl;
                inf("value nu ");
                std::cout << nu << std::endl;*/
              /*inf("value teste nu_dot ");
                std::cout << nu_dot << std::endl;
                inf("value v");
                std::cout << v << std::endl;
                std::cout << J << std::endl;*/
              // Send message with position


              double teste[12] = {nu(0, 0), nu(1, 0), nu(2, 0), nu(3, 0), nu(4, 0), nu(5, 0), v(0,0), v(1,0), v(2,0), v(3,0), v(4,0), v(5,0)};
              m_tau.x = teste[0];
              m_tau.y = teste[1];
              m_tau.z = teste[2];
              m_tau.phi = m_args.euler_angles[0];//teste[3];
              m_tau.theta = m_args.euler_angles[1];//teste[4];
              m_tau.psi = m_args.euler_angles[2];//teste[5];
              m_tau.u = teste[6];
              m_tau.v = teste[7];
              m_tau.w = teste[8];
              m_tau.p = nu_est(3,0);teste[9];
              m_tau.q = teste[10];
              m_tau.r = teste[11];
              dispatch(m_tau);


              /*******************END Position Measure from Velocity*******************/


              /*********************Choose what measure to use in estimation and correct velocity estimation based*********************/

              if(m_args.flag_valid_pos == 1)
              {
                nu(0,0)=m_args.x;
                nu(1,0)=m_args.y;
                nu(2,0)=m_args.z;
              }

              if(m_args.flag_valid_pos == 0)
              {//std::cout << m_args.gps_accurracy[0] << std::endl;
                nu(0,0)=nu(0,0);
                nu(1,0)=nu(1,0);
                nu(2,0)=m_args.profundity[0]; // Depth Sensor to reference vector
              }
              double delta_smo=0;
              if(m_args.flag_imu_active == 1/*m_args.imu_entity == m_args.angvel_entity*/)
              {
                std::cout << "teste1" << std::endl;
                nu(3,0)=nu(3,0);
                nu(4,0)=nu(4,0);
                nu(5,0)=nu(5,0);
                delta_smo=delta_ang;
              }

              if((m_args.flag_imu_active == 0 || m_args.flag_imu_active == -1) & m_args.flag_ahrs_active==1/*m_args.ahrs_entity == m_args.ea_entity*/)
              {
                std::cout << "teste2" << std::endl;
                nu(3,0)=m_args.euler_angles[0];
                nu(4,0)=m_args.euler_angles[1];
                nu(5,0)=m_args.euler_angles[2];
                delta_smo=delta_euler;
              }


              nu(3,0)=Math::Angles::normalizeRadian(nu(3,0));
              nu(4,0)=Math::Angles::normalizeRadian(nu(4,0));
              nu(5,0)=Math::Angles::normalizeRadian(nu(5,0));

              /*********************End Choosing measure to use in estimation and correct velocity estimation based*********************/





              /**************************Sliding Mode Observer*************************/


              // Calculate error for Sliding Mode Observer
              nu_error=nu_est-nu;


              /*************************AUV Model Calculation*************************/


              // Estimate AUV Dynamic dv_dt_est = inv(M) * ( tau - C * v - D * v - L * v - G ); - nu_dot = J * v_est

              // Compute tau - tau = M * dv_dt + C * v + D * v + L * v +  G
              tau = ComputeTau();
              /*if(flag_teste==0){
                tau(0,0)=10;tau(1,0)=0;tau(2,0)=0;tau(3,0)=-0.06*10;tau(4,0)=0;tau(5,0)=0;}
                if(v_est(0,0)>1 & flag_teste==0)
                {
                flag_teste=1;
                tau(0,0)=10;tau(1,0)=0;tau(2,0)=0;tau(3,0)=-0.06*10;tau(4,0)=0;tau(5,0)=0;
                }*/

              double v_estimado[6] = {v_est(0, 0), v_est(1, 0), v_est(2, 0), v_est(3, 0), v_est(4, 0), v_est(5, 0)};
              double pos_estimado[6] = {nu(0, 0), nu(1, 0), nu(2, 0), nu(3, 0), nu(4, 0), nu(5, 0)};
              Math::Matrix J_est(6,6); J_est=ComputeJ_est(pos_estimado);

              //Compute k1, k2, alfa1, alfa 2 and signum function for Sliding Mode Observer

              Math::Matrix K1(6,6); K1=ComputeK1();
              Math::Matrix K2(6,6); K2=ComputeK2();
              Math::Matrix alfa1(6,6); alfa1=Computealfa1();
              Math::Matrix alfa2(6,6); alfa2=Computealfa2();
              double error[6] = {nu_error(0, 0), nu_error(1, 0), nu_error(2, 0), nu_error(3, 0), nu_error(4, 0), nu_error(5, 0)};
              Math::Matrix signum(6,1); signum=Computesignum(error);
              Math::Matrix tanghyper(6,1); tanghyper=Computetanh(error);


              double delta_dj=delta_ang;
              // Compute derivative of Rotation Matrix
              if(std::abs(delta_dj)<0.000001){J_ant=J;delta_dj=1;}
              dJ=(J-J_ant)/delta_dj;
              /*inf("value timestamp ");
                std::cout << dJ << std::endl;*/
              J_ant=J;


              // Dynamic of AUV in Eart-fixed Frame

              Math:: Matrix Mn(6,6); Mn = inverse (transpose( J ) ) * ( ComputeM_RB() + ComputeM_A() )  * inverse( J );
              Math:: Matrix Cn(6,6); Cn = inverse (transpose( J ) ) * ( ( ComputeC_RB(v_estimado) + ComputeC_A(v_estimado) ) - ( ComputeM_RB() +  ComputeM_A() )  * inverse ( J ) * dJ ) * inverse (J);
              Math:: Matrix Dn(6,6); Dn = inverse (transpose( J ) ) * ComputeD(v_estimado) * inverse ( J );
              Math:: Matrix Gn(6,6); Gn = inverse (transpose( J ) ) * ComputeG(pos_estimado);
              Math:: Matrix Ln(6,6); Ln = inverse (transpose( J ) ) * ComputeL(v_estimado) * inverse (J);
              Math:: Matrix Fn(6,6); Fn = inverse (transpose( J ) ) * tau;

              /***********************END AUV Model Calculation***********************/

              //dv_dt_est = /*-alfa2 * nu_error + */inverse( ComputeM_RB() + ComputeM_A() ) * (tau - ( ComputeC_RB(v_estimado) + ComputeC_A(v_estimado) ) * v_est - ComputeD(v_estimado) * v_est - ComputeL(v_estimado) * v_est - ComputeG()/* - K2 * signum */);

              // Sliding Mode Observer
              dn_est = J * v_est;
              dv_dt_est = inverse( J ) * ( -alfa2 * nu_error + inverse( Mn ) * ( Fn - Cn * dn_est - Dn * dn_est - Ln * dn_est - Gn ) - dJ * v_est - K2 * signum );
              //dv_dt_est = inverse( ComputeM_RB() + ComputeM_A() ) * (tau -  ComputeC_RB(v_estimado) * v_est - ComputeC_A(v_estimado) * v_est - ComputeD(v_estimado) * v_est - ComputeL(v_estimado) * v_est - ComputeG(pos_estimado));

              v_est = v_est + dv_dt_est * delta_smo;//delta_ang;//timestep ;

              if(v_est(0)>1.9)
              {
                v_est(0)=1.9;
              }
              if(v_est(0)<0)
              {
                v_est(0)=0;
              }

              nu_dot_est =  -alfa1 * nu_error + J * v_est - K1 * signum;

              nu_est = nu_est + (nu_dot_est_ant + nu_dot_est)/2 * delta_smo;//delta_ang;//* timestep;

              nu_dot_est_ant = nu_dot_est;

              // Normalize estimated and measure euler angles

              nu_est(3,0)=Math::Angles::normalizeRadian(nu_est(3,0));
              nu_est(4,0)=Math::Angles::normalizeRadian(nu_est(4,0));
              nu_est(5,0)=Math::Angles::normalizeRadian(nu_est(5,0));


              double teste1[12] = {nu_est(0, 0), nu_est(1, 0), nu_est(2, 0), nu_est(3, 0), nu_est(4, 0), nu_est(5, 0), v_est(0,0), v_est(1,0), v_est(2,0), v_est(3,0), v_est(4,0), v_est(5,0)};
              m_est.x = teste1[0];
              m_est.y = teste1[1];
              m_est.z = teste1[2];
              m_est.phi = teste1[3];
              m_est.theta = teste1[4];
              m_est.psi = teste1[5];
              m_est.u = teste1[6];
              m_est.v = teste1[7];
              m_est.w = teste1[8];
              m_est.p = teste1[9];
              m_est.q = teste1[10];
              m_est.r = teste1[11];
              m_est.lat = m_args.gps_initial_point[0];
              m_est.lon = m_args.gps_initial_point[1];
              m_est.height = m_args.gps_initial_point[2];
              //inf("teste1");
              /*std::cout <<  dv_dt_est << std::endl;
                std::cout << v_est << std::endl;
                std::cout << nu_est << std::endl;*/
              /*std::cout << m_args.flag_ahrs_active << std::endl;
                std::cout << m_args.flag_imu_active << std::endl;
                std::cout << m_args.ahrs_entity << std::endl;
                std::cout << m_args.ea_entity << std::endl;
                std::cout << delta_ang << std::endl;
                std::cout << delta_euler << std::endl;*/
              /*std::cout << m_args.imu_entity << std::endl;
                std::cout << m_args.angvel_entity << std::endl;
                std::cout << m_args.ahrs_entity << std::endl;
                std::cout << m_args.ea_entity << std::endl;*/
              //std::cout << tau << std::endl;
              /*std::cout << m_args.servo_pos[0] << std::endl;
                std::cout << m_args.servo_pos[1] << std::endl;
                std::cout << m_args.servo_pos[2] << std::endl;
                std::cout << m_args.servo_pos[3] << std::endl;*/
              //std::cout << m_args.entities << std::endl;
              dispatch(m_est);


              /*******************END Sliding Mode Observer*******************/



              //sleep(1);
              //sleep(timestep);
            }
          }
        };
      }
    }
  }
}

DUNE_TASK
