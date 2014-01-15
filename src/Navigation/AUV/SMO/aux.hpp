#include <DUNE/DUNE.hpp>

#ifndef MODEL_H
#define MODEL_H

Matrix ComputeJ(double euler_angles_est[])

#endif


	  Matrix
	  ComputeJ(double euler_angles_est[])
	  {
		// Pass euler angles to row matrix
	       	Matrix ea(3,1);
     		 ea(0) = Angles::normalizeRadian(euler_angles_est[0]);
     		 ea(1) = Angles::normalizeRadian(euler_angles_est[1]);
     		 ea(2) = Angles::normalizeRadian(euler_angles_est[2]);

     		 // Create 6x6 Rotation Matrix
     		// Math::Matrix J(6,6);
    		 //J = ea.toDCMSMO();

		return ea.toDCMSMO;
	  }
