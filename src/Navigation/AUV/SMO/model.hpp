#include <DUNE/DUNE.hpp>

#ifndef MODEL_H
#define MODEL_H

Matrix ComputeM_RB1(float m,float zG,float Ixx,float Iyy,float Izz);

Matrix ComputeM_A1(float Xdudt,float Ydvdt,float Zdwdt,float Kdpdt,float Mdqdt,float Ndrdt);

Matrix ComputeC_RB1(float m,float xg,float yg,float Ixx,float Iyy,float Izz,float Ixz,float Ixy,float Iyz,double v_estimado[]);

Matrix ComputeC_A1(float Xdudt,float Ydvdt,float Zdwdt,float Kdpdt,float Mdqdt,float Ndrdt,double v_estimado[]);

Matrix ComputeD1(double v_estimado[]);

Matrix ComputeL1(double v_estimado[]);

Matrix ComputeG1(float W,float B,float zG,double pos_estimado[]);

Matrix ComputeTau1(double thruster,double velocities[],double servo_pos[]);

#endif

/****************************************AUV MODEL MATRICES****************************************/

 	  Matrix	
	  ComputeM_RB1(float m,float zG,float Ixx,float Iyy,float Izz)//Function checked, inertia matrix is good
	  {
	  //Inertia Matrix
		double MRB_vector[36]={m,0,0,0,m*zG,0,0,m,0,-m*zG,0,0,0,0,m,0,0,0, 0,-m*zG,0,Ixx,0,0,m*zG,0,0,0,Iyy,0,0,0,0,0,0,Izz};	
		return ( Matrix(MRB_vector, 6, 6) );
	  }


 	  Matrix	
	  ComputeM_A1(float Xdudt,float Ydvdt,float Zdwdt,float Kdpdt,float Mdqdt,float Ndrdt)//Function checked, inertia matrix is good
	  {
	  //Inertia Matrix
		double MA_vector[6]={-Xdudt,-Ydvdt,-Zdwdt,-Kdpdt,-Mdqdt,-Ndrdt};	
		return ( Matrix(MA_vector, 6) ); // Creates diagonal Matrix 
	  }

 	  Matrix
	  ComputeC_RB1(float m,float xg,float yg,float zG,float Ixx,float Iyy,float Izz,float Ixz,float Ixy,float Iyz,double v_estimado[])//Function checked, coriolis matrix is good
	  {
	  // Coriolis Matrix

		 //double u = vel[0];//m_args.velocities[0];
		 double u = v_estimado[0];
     		 double v = v_estimado[1];
     		 double w = v_estimado[2];
     		 double p = v_estimado[3];
     		 double q = v_estimado[4];
     		 double r = v_estimado[5];

	  	 double CRB_vector[36]={0,0,0,m*(yg*q+zG*r),-m*(xg*q-w),-m*(xg*r+v),0,0,0,-m*(yg*p+w),m*(zG*r+xg*p),-m*(yg*r-u),0,0,0,-m*(zG*p-v),-m*(zG*q+u),m*(xg*p+yg*q),-m*(yg*q+zG*r),m*(yg*p+w),m*(zG*p-v),0,Iyz*q-Ixz*p+Izz*r,Iyz*r+Ixy*p-Iyy*q,m*(xg*q-w),-m*(zG*r+xg*p),m*(zG*q+u),Iyz*q+Ixz*p-Izz*r,0,-Ixz*r-Ixy*q+Ixx*p,m*(xg*r+v),m*(yg*r-u),-m*(xg*p+yg*q),-Iyz*r-Ixy*p+Iyy*q,Ixz*r+Ixy*q-Ixx*p,0};


		return (Matrix(CRB_vector, 6, 6) );
	  }

  	  Matrix
	  ComputeC_A1(float Xdudt,float Ydvdt,float Zdwdt,float Kdpdt,float Mdqdt,float Ndrdt,double v_estimado[])//Function checked, coriolis matrix is good
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
	  ComputeD1(double v_estimado[]) //Function checked, damping matrix is good
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
	  ComputeL1(double v_estimado[])//Function checked, lift matrix is good
	  {
	  // Lift Matrix

		 double ur = v_estimado[0];

		 double L_vector[36]={0,0,0,0,0,0,0,30*ur,0,0,0,-7.7*ur,0,0,30*ur,0,7.7*ur,0,0,0,0,0,0,0,0,0,9.9*ur,0,3.1*ur,0,0,-9.9*ur,0,0,0,3.1*ur};

		/*inf("value L");
		std::cout << Matrix(L_vector, 6, 6) << std::endl;*/

		return (Matrix(L_vector, 6, 6) );

	   }


 	  Matrix
	  ComputeG1(float W,float B,float zG,double pos_estimado[]) //Function checked, restoring forces matrix is good
	  {
	  // Restoring forces Matrix
		
		double phi = Angles::normalizeRadian(pos_estimado[3]);
     		double theta = Angles::normalizeRadian(pos_estimado[4]);
     		double psi = Angles::normalizeRadian(pos_estimado[5]);

		 // Pass euler angles to row matrix
	       	 Matrix G(6,1);
     		 G(0) = (W-B)*sin(theta);
     		 G(1) = -(W-B)*cos(theta)*sin(phi);
     		 G(2) = -(W-B)*cos(theta)*cos(phi);
     		 G(3) = zG*W*cos(theta)*sin(phi);
     		 G(4) = zG*W*sin(theta);
     		 G(5) = 0;

		return G;

	  }


	Matrix
    	ComputeTau1(double thruster,double velocities[],double servo_pos[])
    	{
      	Matrix tau_tmp(6, 1, 0.0);
      	Matrix deflections(3, 1, 0.0);
	Matrix m_fin_lift(5,1);
	double m_motor_friction = 0.06;
	double fincoef[5] = {9.6, -9.6, 1.82, -3.84, -3.84};
	m_fin_lift= Matrix(fincoef, 5, 1);
	

     	  deflections(0) = servo_pos[3] - servo_pos[0] + servo_pos[1] - servo_pos[2];
    	  deflections(1) = servo_pos[1] + servo_pos[2];
    	  deflections(2) = servo_pos[0] + servo_pos[3];

     	  tau_tmp(0) = thruster * 10; // Times 10 to compute thruster force between -10 and 10
    	  tau_tmp(1) = m_fin_lift(0) * velocities[0] * velocities[0] * deflections(2);
    	  tau_tmp(2) = m_fin_lift(1) * velocities[0] * velocities[0] * deflections(1);
    	  tau_tmp(3) = 1 * (m_fin_lift(2) * velocities[0] * velocities[0] * deflections(0) + m_motor_friction * tau_tmp(0) );
    	  tau_tmp(4) = m_fin_lift(3) * velocities[0] * velocities[0] * deflections(1);
    	  tau_tmp(5) = m_fin_lift(4) * velocities[0] * velocities[0] * deflections(2);


     	 return tau_tmp;
   	 }

/**************************************************************************************************/


