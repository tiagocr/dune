#include <DUNE/DUNE.hpp>

#ifndef MODEL_H
#define MODEL_H

Matrix ComputeK1(float k1[])

Matrix ComputeK2(float k2[])

Matrix Computealfa1(float alfa_1[])

Matrix Computealfa2(float alfa_2[])

Matrix Computesignum(double error[])

Matrix Computetanh(double error[])

#endif



	Matrix
	ComputeK1(float k1[])
	{
		Matrix K1 = Matrix(6, 6, 0.0);
  		K1(0, 0) = k1[0];//0.7;
  		K1(1, 1) = k1[1];//0.1;
  		K1(2, 2) = k1[2];//0.1;
  		K1(3, 3) = k1[3];//1.2;
  		K1(4, 4) = k1[4];//0.1;
  		K1(5, 5) = k1[5];//0.1;

		return K1;
	}

	Matrix
	ComputeK2(float k2[])
	{
		Matrix K2 = Matrix(6, 6, 0.0);
  		K2(0, 0) = k2[0];//1;
  		K2(1, 1) = k2[1];//0.5;
  		K2(2, 2) = k2[2];//0.4;
  		K2(3, 3) = k2[3];//0.7;
  		K2(4, 4) = k2[4];//0.1;
  		K2(5, 5) = k2[5];//0.2;

		return K2;
	}

	Matrix
	Computealfa1(float alfa_1[])
	{
		Matrix alfa1 = Matrix(6, 6, 0.0);
  		alfa1(0, 0) = alfa_1[0];//0.7;
  		alfa1(1, 1) = alfa_1[1];//0.1;
  		alfa1(2, 2) = alfa_1[2];//0.1;
  		alfa1(3, 3) = alfa_1[3];//1.2;
  		alfa1(4, 4) = alfa_1[4];//0.1;
  		alfa1(5, 5) = alfa_1[5];//0.2;

		return alfa1;
	}

	Matrix
	Computealfa2(float alfa_2[])
	{
		Matrix alfa2 = Matrix(6, 6, 0.0);
  		alfa2(0, 0) = alfa_2[0];//1;
  		alfa2(1, 1) = alfa_2[1];//0.3;
  		alfa2(2, 2) = alfa_2[2];//0.1;
  		alfa2(3, 3) = alfa_2[3];//0.7;
  		alfa2(4, 4) = alfa_2[4];//0.1;
  		alfa2(5, 5) = alfa_2[5];//0.2;

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
