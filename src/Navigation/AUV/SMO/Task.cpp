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
#include "model.hpp"
#include "gain_matrices.hpp"

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

        //Centriptal and Inertial Matrix terms
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

        static const int m = 18;

        static const int Xdudt = -1;
        static const int Ydvdt = -16;
        static const int Zdwdt = -16;
        static const int Kdpdt = 0;
        static const float Mdqdt = 0;//-0.7637;
        static const float Ndrdt = 0;//-0.7637;


        // Damping Matrix Terms
        static const float X_u = -2.4;
        static const float Y_v = -23;
        static const float Y_r = 11.5;
        static const float Z_w = -23;
        static const float Z_q = -11.5;
        static const float K_p = -0.3;
        static const float M_q = -9.7;
        static const float M_w = 3.1;
        static const float N_r = -9.7;
        static const float N_v = -3.1;

        static const float X_uabsu = -2.4;
        static const float Y_vabsv = -80;
        static const float Y_rabsr = 0.3;
        static const float Z_wabsw = -80;
        static const float Z_qabsq = -0.3;
        static const float K_pabsp = -6e-4;
        static const float M_qabsq = -9.1;
        static const float M_wabsw = 1.5;
        static const float N_rabsr = -9.1;
        static const float N_vabsv = -1.5;

        // Restoring Forces terms
        static const int W = 176;
        static const int B = 177;

        struct Arguments
        {
          //Sliding Matrix Gains
          float k1[6];
          float k2[6];
          float alfa1[6];
          float alfa2[6];

          //Roll estimation parameter on/off
          int roll_estimation_on_off;

          //Attenuator for lateral estimation with rpm measures only
          float rpm_lateral_attenuator;

          //Boundary layer ize
          double boundary_layer;

          //RPM Multiplicative Factor
          double rpm_multiplicative_factor;

          // Resolve Entity string
          std::string imu_entities;
          std::string ahrs_entities;
          std::string dvl_entities;
          std::string rpm_entities;
        };

        struct Task: public DUNE::Tasks::Periodic
        {
          int task_management;
          float x_ant;
          int flag_init_nu_est;
          double x;
          double y;
          double z;
          double range;
          double bearing;
          float rpms;
          int flag_initial_point;
          int flag_initial_orientation;
          double gps_fix[4];
          double gps_initial_point[4];
          double gps_accuracy[2];
          double gps_treshold;
          double euler_angles[3];
          double euler_angles_est[3];
          double velocities[7];
          double velocities_ant[7];
          double profundity[2];
          double servo_pos[4];
          double thruster;
          double er[2];
          double vel_int_delta;
          double smo_delta;
          double smo_delta1;
          double est_unc;
          double j_delta;
          int flag_valid_pos;
          double dv_dt;
          double delta_v;
          double teste;
          double j_angles[3];
          float delta_x;
          float delta_y;
          double v_tau[6];
          double v_estimado[6];
          double pos_estimado[6];
          double error[6];


          // Entity ID
          int imu_entity;
          int ahrs_entity;
          int dvl_entity;
          int rpm_entity;
          int flag_imu_active;
          int flag_ahrs_active;
          int flag_rpm_active;
          int flag_dvl_active;
          int error_counter;

          // Sliding Mode Observer Matrices
          Math::Matrix nu_dot;
          Math::Matrix nu_dot_ant;
          Math::Matrix nu_dot_est;
          Math::Matrix nu_dot_est_ant;
          Math::Matrix dn_est;
          Math::Matrix nu;
          Math::Matrix nu_ant;
          Math::Matrix nu_est;
          Math::Matrix nu_error;
          Math::Matrix tau;
          Math::Matrix v_est;
          Math::Matrix dv_dt_est;
          Math::Matrix J_ant;
          Math::Matrix J;
          Math::Matrix vel;
          Math::Matrix dJ;

          // Uncertainty Matrices
          Math::Matrix nu_uncertainty;
          Math::Matrix nu_dot_uncertainty;
          Math::Matrix v_est_uncertainty;

          //! Send message to Estimated State and Navigation Uncertainty
          IMC::EstimatedState m_est;
          IMC::NavigationUncertainty m_uncertainty;

          //! Time window between values.
          DUNE::Time::Delta vel_delta;
          DUNE::Time::Delta dj_delta;
          DUNE::Time::Delta est_delta;
          DUNE::Time::Delta est_delta1;
          DUNE::Time::Delta est_uncertainty;
          Arguments m_args;
          Derivative<double> deriv;

          Task(const std::string& name, Tasks::Context& ctx):
            Periodic(name, ctx)
          {
            param("RPM Lateral Attenuator", m_args.rpm_lateral_attenuator)
            .defaultValue("0.2")
            .description("Lateral attenuator with RPM measures only");

            param("Boundary Layer", m_args.boundary_layer)
            .defaultValue("0.05")
            .description("Boundary Layer Size");

            param("RPM factor", m_args.rpm_multiplicative_factor)
            .defaultValue("1.2e-3")
            .description("RPM Multiplicative Factor");

            param("roll on off", m_args.roll_estimation_on_off)
            .defaultValue("1")
            .description("On/off variable to test roll estimation");

            param("Entity Label IMU", m_args.imu_entities)
            .defaultValue("IMU")
            .description("Label of the IMU message");

            param("Entity Label AHRS", m_args.ahrs_entities)
            .defaultValue("AHRS")
            .description("Label of the AHRS message");

            param("Entity Label DVL", m_args.dvl_entities)
            .defaultValue("DVL")
            .description("Label of the DVL message");

            param("Entity Label MOTOR", m_args.rpm_entities)
            .defaultValue("Motor")
            .description("Label of the RPM message");

            param("k1 gain one", m_args.k1[0])
            .defaultValue("0.7")
            .description("Sliding Mode Observer gain");

            param("k1 gain two", m_args.k1[1])
            .defaultValue("0.1")
            .description("Sliding Mode Observer gain");

            param("k1 gain three", m_args.k1[2])
            .defaultValue("0.1")
            .description("Sliding Mode Observer gain");

            param("k1 gain four", m_args.k1[3])
            .defaultValue("1.7")
            .description("Sliding Mode Observer gain");

            param("k1 gain five", m_args.k1[4])
            .defaultValue("0.2")
            .description("Sliding Mode Observer gain");

            param("k1 gain six", m_args.k1[5])
            .defaultValue("0.2")
            .description("Sliding Mode Observer gain");

            param("k2 gain one", m_args.k2[0])
            .defaultValue("0.7")
            .description("Sliding Mode Observer gain");

            param("k2 gain two", m_args.k2[1])
            .defaultValue("0.1")
            .description("Sliding Mode Observer gain");

            param("k2 gain three", m_args.k2[2])
            .defaultValue("0.1")
            .description("Sliding Mode Observer gain");

            param("k2 gain four", m_args.k2[3])
            .defaultValue("1")
            .description("Sliding Mode Observer gain");

            param("k2 gain five", m_args.k2[4])
            .defaultValue("0.2")
            .description("Sliding Mode Observer gain");

            param("k2 gain six", m_args.k2[5])
            .defaultValue("0.2")
            .description("Sliding Mode Observer gain");

            param("alfa1 gain one", m_args.alfa1[0])
            .defaultValue("0.7")
            .description("Luenberger term");

            param("alfa1 gain two", m_args.alfa1[1])
            .defaultValue("0.1")
            .description("Luenberger term");

            param("alfa1 gain three", m_args.alfa1[2])
            .defaultValue("0.1")
            .description("Luenberger term");

            param("alfa1 gain four", m_args.alfa1[3])
            .defaultValue("2")
            .description("Luenberger term");

            param("alfa1 gain five", m_args.alfa1[4])
            .defaultValue("0.2")
            .description("Luenberger term");

            param("alfa1 gain six", m_args.alfa1[5])
            .defaultValue("0.2")
            .description("Luenberger term");

            param("alfa2 gain one", m_args.alfa2[0])
            .defaultValue("0.8")
            .description("Luenberger term");

            param("alfa2 gain two", m_args.alfa2[1])
            .defaultValue("0.7")
            .description("Luenberger term");

            param("alfa2 gain three", m_args.alfa2[2])
            .defaultValue("0.6")
            .description("Luenberger term");

            param("alfa2 gain four", m_args.alfa2[3])
            .defaultValue("1")
            .description("Luenberger term");

            param("alfa2 gain five", m_args.alfa2[4])
            .defaultValue("0.1")
            .description("Luenberger term");

            param("alfa2 gain six", m_args.alfa2[5])
            .defaultValue("0.2")
            .description("Luenberger term");

            task_management = 0;
            x_ant = 0;
            flag_init_nu_est = 0;
            x = 0;
            y = 0;
            z = 0;
            range = 0;
            bearing = 0;
            rpms = 0;
            flag_initial_point = 0;
            flag_initial_orientation = 0;
            std::memset(&velocities_ant, 0, sizeof(velocities_ant));
            std::memset(&j_angles, 0, sizeof(j_angles));
            flag_valid_pos = 0;
            flag_imu_active = 0;
            flag_ahrs_active = 0;
            flag_rpm_active = 0;
            flag_dvl_active = 0;
            error_counter = 0;
            dv_dt = 0;
            delta_v = 0;
            teste = 0;
            delta_x = 0;
            delta_y = 0;
            std::memset(&v_tau, 0, sizeof(v_tau));
            std::memset(&v_estimado, 0, sizeof(v_estimado));
            std::memset(&pos_estimado, 0, sizeof(pos_estimado));
            std::memset(&error, 0, sizeof(error));
            nu_dot.resizeAndFill(6,1,0.0);
            nu_dot_ant.resizeAndFill(6,1,0.0);
            nu_dot_est.resizeAndFill(6,1,0.0);
            nu_dot_est_ant.resizeAndFill(6,1,0.0);
            dn_est.resizeAndFill(6,1,0.0);
            nu.resizeAndFill(6,1,0.0);
            nu_ant.resizeAndFill(6,1,0.0);
            nu_est.resizeAndFill(6,1,0.0);
            nu_error.resizeAndFill(6,1,0.0);
            tau.resizeAndFill(6,1,0.0);
            v_est.resizeAndFill(6, 1, 0.0);
            dv_dt_est.resizeAndFill(6,1,0.0);
            J_ant.resizeAndFill(6,6,0.0);
            J.resizeAndFill(6,6,0.0);
            vel.resizeAndFill(6,1,0.0);
            dJ.resizeAndFill(6,6,0.0);

            // Uncertainty Matrices
            nu_uncertainty.resizeAndFill(6,1,0.0);
            nu_dot_uncertainty.resizeAndFill(6,1,0.0);
            v_est_uncertainty.resizeAndFill(6,1,0.0);

            //Register Consumers
            bind<IMC::EulerAngles>(this);
            bind<IMC::AngularVelocity>(this);
            bind<IMC::GroundVelocity>(this);
            bind<IMC::Depth>(this);
            bind<IMC::ServoPosition>(this);
            bind<IMC::SetThrusterActuation>(this);
            bind<IMC::GpsFix>(this);
            bind<IMC::EntityState>(this);
            bind<IMC::Rpm>(this);
          }

          void
          onEntityResolution(void)
          {
            try
            {
              imu_entity = resolveEntity(m_args.imu_entities);
            }
            catch (...)
            {
              imu_entity = -1;
              flag_imu_active = -1;
            }

            try
            {
              ahrs_entity = resolveEntity(m_args.ahrs_entities);
            }
            catch (...)
            {
              ahrs_entity = -1;
              flag_ahrs_active = -1;
            }

            try
            {
              dvl_entity = resolveEntity(m_args.dvl_entities);
            }
            catch (...)
            {
              dvl_entity = -1;
              flag_dvl_active = -1;
            }

            try
            {
              rpm_entity = resolveEntity(m_args.rpm_entities);
            }
            catch (...)
            {
              rpm_entity = -1;
              flag_rpm_active = -1;
            }
          }

          void
          consume(const IMC::GpsFix* msg)
          {
            gps_accuracy[0] = msg->hacc;

            if (flag_initial_point == 0)
              gps_treshold = gps_accuracy[0] + 1;

            if (flag_initial_point != 0)
              gps_treshold = 7;

            if (msg->validity & IMC::GpsFix::GFV_VALID_POS)
            {
              if (gps_accuracy[0] < gps_treshold)
              {
                gps_fix[1] = msg->lat;
                gps_fix[2] = msg->lon;
                gps_fix[3] = msg->height;
                flag_valid_pos = 1;
              }

              if ((flag_initial_point == 1 && flag_init_nu_est == 0) || flag_init_nu_est == 1)
                flag_init_nu_est++;

              if (flag_initial_point == 0)
              {
                gps_initial_point[0] = gps_fix[1];
                gps_initial_point[1] = gps_fix[2];
                gps_initial_point[2] = gps_fix[3];
                flag_initial_point = 1;
              }

              if (gps_accuracy[0] >= gps_treshold)
                flag_valid_pos = 0;
            }

            if (!(msg->validity & IMC::GpsFix::GFV_VALID_POS)/* || (gps_accuracy[0]>=gps_treshold)*/)
              flag_valid_pos = 0;
          }

          void
          consume(const IMC::EulerAngles* msg)
          {
            euler_angles[0] = msg->phi;
            euler_angles[1] = msg->theta;
            euler_angles[2] = msg->psi;

            if (flag_initial_orientation == 0)
            {
              flag_initial_orientation = 1;
              nu(3,0) = euler_angles[0];
              nu(4,0) = euler_angles[1];
              nu(5,0) = euler_angles[2];
              nu_est(3,0) = euler_angles[0];
              nu_est(4,0) = euler_angles[1];
              nu_est(5,0) = euler_angles[2];
            }
          }

          void
          consume(const IMC::GroundVelocity* msg)
          {
            if (msg->validity & IMC::GroundVelocity::VAL_VEL_X)
            {
              velocities[0] = msg->x;
              velocities_ant[0] = velocities[0];
            }
            if (!(msg->validity & IMC::GroundVelocity::VAL_VEL_X))
              velocities[0] = velocities_ant[0];

            if (msg->validity & IMC::GroundVelocity::VAL_VEL_Y)
            {
              velocities[1] = msg->y;
              velocities_ant[1] = velocities[1];
            }
            if (!(msg->validity & IMC::GroundVelocity::VAL_VEL_Y))
              velocities[1] = velocities_ant[1];

            if (msg->validity & IMC::GroundVelocity::VAL_VEL_Z)
            {
              velocities[2] = msg->z;
              velocities_ant[2] = velocities[2];
            }
            if (!(msg->validity & IMC::GroundVelocity::VAL_VEL_Z))
              velocities[2] = velocities_ant[2];
          }

          void
          consume(const IMC::AngularVelocity* msg)
          {
            if (flag_imu_active == 1 && msg->getSourceEntity() == imu_entity)
            {
              velocities[3] = msg->x;
              velocities[4] = msg->y;
              velocities[5] = msg->z;
            }
          }

          void
          consume(const IMC::Depth* msg)
          {
            profundity[0] = msg->value;
          }

          void
          consume(const IMC::ServoPosition* msg)
          {
            servo_pos[msg->id] = msg->value;
          }

          void
          consume(const IMC::SetThrusterActuation* msg)
          {
            thruster = msg->value;
          }

          void
          consume(const IMC::Rpm* msg)
          {
            rpms = msg->value;
          }

          void
          consume(const IMC::EntityState* msg)
          {
            if (msg->getSourceEntity() == imu_entity)
            {
              if (msg->state == IMC::EntityState::ESTA_NORMAL)
                flag_imu_active = 1 ;
              else
                flag_imu_active = 0 ;
            }

            if (msg->getSourceEntity() == ahrs_entity)
            {
              if (msg->state == IMC::EntityState::ESTA_NORMAL)
                flag_ahrs_active = 1 ;
              else
                flag_ahrs_active = 0 ;
            }

            if (msg->getSourceEntity() == dvl_entity)
            {
              if (msg->state == IMC::EntityState::ESTA_NORMAL)
                flag_dvl_active = 1 ;
              else
                flag_dvl_active = 0 ;
            }

            if (msg->getSourceEntity() == rpm_entity)
            {
              if (msg->state == IMC::EntityState::ESTA_NORMAL)
                flag_rpm_active = 1 ;
              else
                flag_rpm_active = 0 ;
            }
          }

          /*********************Compute Rotation Matrix, is Derivative and Velocity measure Matrix*********************/
          Matrix
          computeJ(double e_angles[])
          {
            // Pass euler angles to row matrix
            Math::Matrix ea(3,1);
            ea(0) = Math::Angles::normalizeRadian(e_angles[0]);
            ea(1) = Math::Angles::normalizeRadian(e_angles[1]);
            ea(2) = Math::Angles::normalizeRadian(e_angles[2]);

            J = ea.toDCMSMO();

            return J;
          }

          Matrix
          computev(void)
          {
            // Create Row matrix from measures
            Math::Matrix v_tmp(6,1);
            v_tmp(0) = velocities[0];
            v_tmp(1) = velocities[1];
            v_tmp(2) = velocities[2];
            v_tmp(3) = velocities[3];
            v_tmp(4) = velocities[4] - er[0];
            v_tmp(5) = velocities[5] - er[1];

            if ((flag_dvl_active == 0 || flag_dvl_active == -1) && (flag_rpm_active == 1))
            {
              v_tmp(0) = rpms * m_args.rpm_multiplicative_factor;
              v_tmp(1) = 0;
            }

            return v_tmp;
          }

          /*********************END Compute Rotation Matrix, is Derivative and Velocity measure Matrix*********************/

          /***********************Task MANAGEMENT**********************/
          void
          state_management(void)
          {
            if(flag_initial_point == 0)
            {
              setEntityState(IMC::EntityState::ESTA_BOOT, Status::CODE_WAIT_GPS_FIX);
              task_management = 0;
            }

            if(flag_initial_point == 1)
            {
              setEntityState(IMC::EntityState::ESTA_NORMAL, Status::CODE_ACTIVE);
              task_management = 1;
            }

            return;
          }

          /************************************************************/

          void
          task(void)
          {

            /***********************Entity State Management**********************/

            state_management();

            /********************************************************************/

            if(task_management == 1)
            {

            /*******************GPS Signal Acquisition*******************/
            Coordinates::WGS84::getNEBearingAndRange(gps_initial_point[0], gps_initial_point[1], gps_fix[1], gps_fix[2], &bearing, &range);

            x = range * std::cos(bearing);
            y = range * std::sin(bearing);
            z = profundity[0];

            if (flag_init_nu_est == 1)
            {
              nu_est(0,0) = x;
              nu_est(1,0) = y;
              nu_est(2,0) = z;
              nu(0,0) = x;
              nu(1,0) = y;
              nu(2,0) = z;
            }
            /*******************END GPS Signal Acquisition*******************/

            /*********************Position Measure from Velocity*********************/

            //Take out earth rotation from angular velocities
            er[0] = ((std::sin(nu(3,0)) * std::sin(nu(4,0)) * std::cos(nu(5,0)) - std::cos(nu(3,0)) * std::sin(nu(5,0))) * std::cos(gps_fix[1]) - std::sin(nu(3,0)) * std::cos(nu(4,0)) * std::sin(gps_fix[1])) * 7.292115e-5;

            er[1] = ((std::sin(nu(3,0)) * std::sin(nu(5,0)) + std::cos(nu(3,0)) * std::sin(nu(4,0)) * std::cos(nu(5,0))) * std::cos(gps_fix[1]) - std::cos(nu(3,0)) * std::cos(nu(4,0)) * std::sin(gps_fix[1])) * 7.292115e-5;

            // Calculate Rotation Matrix
            // Avoid singularaties in Rotation Matrix
            if(nu(4,0)>1.56 && nu(4,0)<1.58)
              nu(4,0) = 1.56;

            if(nu(4,0)<-1.56 && nu(4,0)>-1.58)
              nu(4,0) = -1.56;

            //double j_angles[3] = {nu(3,0),nu(4,0),nu(5,0)};
            std::fill_n (j_angles,1,nu(3,0));
            std::fill_n (j_angles+1,1,nu(4,0));
            std::fill_n (j_angles+2,1,nu(5,0));

            J = computeJ(j_angles);
            vel = computev();

            // Calculate nu_dot
            nu_dot = J * vel;


            // Integrate velocity in Earth-fixed Frame to obtain position
            vel_int_delta = vel_delta.getDelta();

            nu(0,0) = nu(0,0) + ( nu_dot_ant(0,0) + nu_dot(0,0) ) / 2 * vel_int_delta;
            nu(1,0) = nu(1,0) + ( nu_dot_ant(1,0) + nu_dot(1,0) ) / 2 * vel_int_delta;
            nu(2,0) = nu(2,0) + ( nu_dot_ant(2,0) + nu_dot(2,0) ) / 2 * vel_int_delta;

            nu(3,0) = nu(3,0) + ( nu_dot_ant(3,0) + nu_dot(3,0) ) / 2 * vel_int_delta;
            nu(4,0) = nu(4,0) + ( nu_dot_ant(4,0) + nu_dot(4,0) ) / 2 * vel_int_delta;
            nu(5,0) = nu(5,0) + ( nu_dot_ant(5,0) + nu_dot(5,0) ) / 2 * vel_int_delta;

            nu_dot_ant = nu_dot;

            if ((flag_dvl_active == 0 || flag_dvl_active == -1) && (flag_rpm_active == 1))
            {
              delta_x = ( nu(0,0) - x_ant );
              delta_y = std::tan( euler_angles[2]) * delta_x;
              nu_dot(1,0) = delta_y;
              nu(1,0) = nu(1,0) + delta_y * m_args.rpm_lateral_attenuator; //empirical value to reduce the impact of error integration, from delta_x and psi.
            }
            x_ant = nu(0,0);
            /*******************END Position Measure from Velocity*******************/


            /*********************Choose what measure to use in estimation and correct velocity estimation based*********************/
            if (flag_valid_pos == 1)
            {
              nu(0,0) = x;
              nu(1,0) = y;
              nu(2,0) = z;
            }

            if (flag_valid_pos == 0)
            {
              nu(0,0) = nu(0,0);
              nu(1,0) = nu(1,0);
              nu(2,0) = profundity[0];
            }
            if (flag_imu_active == 1)
            {
              nu(3,0) = nu(3,0);
              nu(4,0) = nu(4,0);
              nu(5,0) = nu(5,0);
            }

            if ((flag_imu_active == 0 || flag_imu_active == -1) && (flag_ahrs_active == 1))
            {
              nu(3,0) = euler_angles[0];
              nu(4,0) = euler_angles[1];
              nu(5,0) = euler_angles[2];
            }

            nu(3,0) = Math::Angles::normalizeRadian( nu(3,0) );
            nu(4,0) = Math::Angles::normalizeRadian( nu(4,0) );
            nu(5,0) = Math::Angles::normalizeRadian( nu(5,0) );


            /*********************End Choosing measure to use in estimation and correct velocity estimation based*********************/

            /**************************Sliding Mode Observer*************************/

            // Calculate error for Sliding Mode Observer
            nu_error = nu_est-nu;

            // Standard error when vehicle is at -180 or 180 degrees

            if (nu_error(3,0) <= -3.14)
              nu_error(3,0) = nu_error(3,0)+360*3.14/180;
            if (nu_error(3,0) >= 3.14)
              nu_error(3,0) = nu_error(3,0)-360*3.14/180;

            if (nu_error(4,0) <= -3.14)
              nu_error(4,0) = nu_error(4,0)+360*3.14/180;
            if (nu_error(4,0) >= 3.14)
              nu_error(4,0) = nu_error(4,0)-360*3.14/180;

            if (nu_error(5,0) <= -3.14)
              nu_error(5,0) = nu_error(5,0)+360*3.14/180;
            if (nu_error(5,0) >= 3.14)
              nu_error(5,0) = nu_error(5,0)-360*3.14/180;

            /*************************AUV Model Calculation*************************/

            std::fill_n (v_tau,1,vel(0,0));
            std::fill_n (v_tau+1,1,vel(1,0));
            std::fill_n (v_tau+2,1,vel(2,0));
            std::fill_n (v_tau+3,1,vel(3,0));
            std::fill_n (v_tau+4,1,vel(4,0));
            std::fill_n (v_tau+5,1,vel(5,0));

            std::fill_n (v_estimado,1,v_est(0,0));
            std::fill_n (v_estimado+1,1,v_est(1,0));
            std::fill_n (v_estimado+2,1,v_est(2,0));
            std::fill_n (v_estimado+3,3,v_est(3,0));
            std::fill_n (v_estimado+4,1,v_est(4,0));
            std::fill_n (v_estimado+5,1,v_est(5,0));

            std::fill_n (pos_estimado,1,nu(0,0));
            std::fill_n (pos_estimado+1,1,nu(1,0));
            std::fill_n (pos_estimado+2,1,nu(2,0));
            std::fill_n (pos_estimado+3,1,nu(3,0));
            std::fill_n (pos_estimado+4,1,nu(4,0));
            std::fill_n (pos_estimado+5,1,nu(5,0));


            //Compute k1, k2, alfa1, alfa 2 and signum function for Sliding Mode Observer
            std::fill_n (error,1,nu_error(0,0));
            std::fill_n (error+1,1,nu_error(1,0));
            std::fill_n (error+2,1,nu_error(2,0));
            std::fill_n (error+3,1,nu_error(3,0));
            std::fill_n (error+4,1,nu_error(4,0));
            std::fill_n (error+5,1,nu_error(5,0));

            Math::Matrix K1(6,6);
            K1 = computeK1(m_args.k1);

            Math::Matrix K2(6,6);
            K2 = computeK2(m_args.k2);

            Math::Matrix alfa1(6,6);
            alfa1 = computealfa1(m_args.alfa1);

            Math::Matrix alfa2(6,6);
            alfa2 = computealfa2(m_args.alfa2);

            Math::Matrix signum(6,1);
            signum = computesignum(error);

            Math::Matrix tanghyper(6,1);
            tanghyper = computetanh(error,m_args.boundary_layer);

            j_delta = dj_delta.getDelta();
            dJ = (J-J_ant) / j_delta;
            J_ant = J;

            // Compute AUV Dynamic i Body-fixed Frame
            Math::Matrix M_RB(6,6);
            M_RB = computeM_RB1(m,zG,Ixx,Iyy,Izz);

            Math::Matrix M_A(6,6);
            M_A = computeM_A1(Xdudt,Ydvdt,Zdwdt,Kdpdt,Mdqdt,Ndrdt);

            Math::Matrix C_RB(6,6);
            C_RB = computeC_RB1(m,xg,yg,zG,Ixx,Iyy,Izz,Ixz,Ixy,Iyz,v_estimado);

            Math::Matrix C_A(6,6);
            C_A = computeC_A1(Xdudt,Ydvdt,Zdwdt,Kdpdt,Mdqdt,Ndrdt,v_estimado);

            Math::Matrix D(6,6);
            D = computeD1(v_estimado, X_u, Y_v, Y_r, Z_w, Z_q, K_p, M_q, M_w, N_r, N_v, X_uabsu, Y_vabsv, Y_rabsr, Z_wabsw, Z_qabsq, K_pabsp, M_qabsq, M_wabsw, N_rabsr, N_vabsv);

            Math::Matrix L(6,6);
            L = computeL1(v_estimado);

            Math::Matrix G(6,6);
            G = computeG1(W,B,zG,pos_estimado);

            Math::Matrix tau1(6,1);
            tau = computeTau1(thruster,v_tau,servo_pos);

            // Dynamic of AUV in Eart-fixed Frame
            Math:: Matrix Mn(6,6);
            Mn = inverse (transpose(J) ) * ( M_RB + M_A )  * inverse(J);

            Math:: Matrix Cn(6,6);
            Cn = inverse (transpose(J) ) * ( ( C_RB + C_A ) - ( M_RB +  M_A )  * inverse (J) * dJ ) * inverse (J);

            Math:: Matrix Dn(6,6);
            Dn = inverse (transpose(J) ) * D * inverse (J);

            Math:: Matrix Gn(6,6);
            Gn = inverse (transpose(J) ) * G;

            Math:: Matrix Ln(6,6);
            Ln = inverse (transpose(J) ) * L * inverse (J);

            Math:: Matrix Fn(6,6);
            Fn = inverse (transpose(J) ) * tau;

            /***********************END AUV Model Calculation***********************/

            dn_est = J * v_est;

            Math:: Matrix Mn_tmp = inverse(Mn);
            Mn_tmp(3,0) = m_args.roll_estimation_on_off*Mn_tmp(3,0);
            Mn_tmp(3,1) = m_args.roll_estimation_on_off*Mn_tmp(3,1);
            Mn_tmp(3,2) = m_args.roll_estimation_on_off*Mn_tmp(3,2);
            Mn_tmp(3,3) = m_args.roll_estimation_on_off*Mn_tmp(3,3);
            Mn_tmp(3,4) = m_args.roll_estimation_on_off*Mn_tmp(3,4);
            Mn_tmp(3,5) = m_args.roll_estimation_on_off*Mn_tmp(3,5);
            Fn(3) = m_args.roll_estimation_on_off*Fn(3);

            dv_dt_est = inverse(J) * ( -alfa2 * nu_error + Mn_tmp * Fn + inverse( Mn ) * ( 0*Fn - Cn * dn_est - Dn * dn_est - Ln * dn_est - Gn ) - dJ * v_est - K2 * tanghyper);//signum );

            smo_delta = est_delta.getDelta();

            v_est = v_est + dv_dt_est * smo_delta;

            if (v_est(0) > 2)
              v_est(0) = 2;
            if (v_est(0) < -2)
              v_est(0) = -2;

            nu_dot_est = -alfa1 * nu_error + J * v_est - K1 * tanghyper;

            smo_delta1 = est_delta1.getDelta();

            nu_est = nu_est + ( nu_dot_est_ant + nu_dot_est ) / 2 * smo_delta1;

            nu_dot_est_ant = nu_dot_est;

            // Normalize estimated and measure euler angles
            nu_est(3,0) = Math::Angles::normalizeRadian( nu_est(3,0) );
            nu_est(4,0) = Math::Angles::normalizeRadian( nu_est(4,0) );
            nu_est(5,0) = Math::Angles::normalizeRadian( nu_est(5,0) );

            m_est.x = nu_est(0,0);
            m_est.y = nu_est(1,0);
            m_est.z = gps_initial_point[2] + nu_est(2,0);
            m_est.phi = nu_est(3,0);
            m_est.theta = nu_est(4,0);
            m_est.psi = nu_est(5,0);
            m_est.u = v_est(0,0);
            m_est.v = v_est(1,0);
            m_est.w = v_est(2,0);
            m_est.p = v_est(3,0);
            m_est.q = v_est(4,0);
            m_est.r = v_est(5,0);
            m_est.lat = gps_initial_point[0];
            m_est.lon = gps_initial_point[1];
            m_est.height = gps_initial_point[2];
            m_est.depth = nu_est(2,0);
            dispatch( m_est );

            /*******************END Sliding Mode Observer*******************/

            /*********************Navigation Uncertainty********************/
            error_counter = error_counter + 1;

            v_est_uncertainty(0) = v_est_uncertainty(0) + std::abs( v_est(0)-vel(0) );
            v_est_uncertainty(1) = v_est_uncertainty(1) + std::abs( v_est(1)-vel(1) );
            v_est_uncertainty(2) = v_est_uncertainty(2) + std::abs( v_est(2)-vel(2) );
            v_est_uncertainty(3) = v_est_uncertainty(3) + std::abs( v_est(3)-vel(3) );
            v_est_uncertainty(4) = v_est_uncertainty(4) + std::abs( v_est(4)-vel(4) );
            v_est_uncertainty(5) = v_est_uncertainty(5) + std::abs( v_est(5)-vel(5) );


            nu_dot_uncertainty = J * ( v_est - vel );
            est_unc = est_uncertainty.getDelta();
            nu_uncertainty = nu_uncertainty + nu_dot_uncertainty * est_unc;

            //nu_uncertainty(0) = nu_uncertainty(0) + std::abs( nu_est(0) - nu(0) );
            //nu_uncertainty(1) = nu_uncertainty(1) + std::abs( nu_est(1) - nu(1) );
            //nu_uncertainty(2) = std::abs( nu_est(2) - nu(2) );
            //nu_uncertainty(3) = std::abs( nu_est(3) - nu(3) );
            //nu_uncertainty(4) = std::abs( nu_est(4) - nu(4) );
            //nu_uncertainty(5) = std::abs( nu_est(5) - nu(5) );

            m_uncertainty.x = std::abs( nu_uncertainty(0) );
            m_uncertainty.y = std::abs( nu_uncertainty(1) );
            m_uncertainty.z = std::abs( nu_uncertainty(2) )/error_counter;
            m_uncertainty.phi = std::abs( nu_uncertainty(3) )/error_counter;
            m_uncertainty.theta = std::abs( nu_uncertainty(4) )/error_counter;
            m_uncertainty.psi = std::abs( nu_uncertainty(5) )/error_counter;
            m_uncertainty.u = v_est_uncertainty(0)/error_counter;
            m_uncertainty.v = v_est_uncertainty(1)/error_counter;
            m_uncertainty.w = v_est_uncertainty(2)/error_counter;
            m_uncertainty.p = v_est_uncertainty(3)/error_counter;
            m_uncertainty.q = v_est_uncertainty(4)/error_counter;
            m_uncertainty.r = v_est_uncertainty(5)/error_counter;
            dispatch( m_uncertainty );

            /*****************END Navigation Uncertainty********************/
            }
          }
        };
      }
    }
  }
}

DUNE_TASK
