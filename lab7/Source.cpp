#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

double Phi1(double y) {
	return (0.5 - cos(y - 1));
}
double Phi2(double x) {
	return (3 + cos(x));
}

void SimpleIterationMethod(int a, int b, double eps) {
	cout.precision(4);
	double X1 = a;
	double Y1 = a;
	double dX;
	int counter = 1;
	double Prev_X, Prev_Y;
	
	cout << "--== Simple Itrations Method ==--\n";
	
	do {
		Prev_Y = Y1;
		Prev_X = X1;

		X1 = Phi1(Prev_Y);
		Y1 = Phi2(Prev_X);
	
		counter++;
		
		dX = (fabs(X1 - Prev_X) + fabs(Y1 - Prev_Y));
	} while (dX > eps);

	cout << "Number of iterations: " << counter << endl << "X = " << X1 << "\tY = " << Y1 << endl;
}

void NeutonsMethod(int a, int b, double eps) {
	cout.precision(4);
	double Y1 = 1, X1 = 1;
	double det2;
	double det1;
	double dX;
	double dY;
	double detMain;
	int num = 1;
	cout << "\n--== Newtons` method ==--\n";
	
	do {
		double J[2][2] = { {1, -sin(Y1 - 1)},
						   {sin(X1),     1}};
		double FreeMem[2] = { (cos(Y1 - 1) + X1 - 0.5), (Y1 - cos(X1) - 3) };
		
		detMain = J[0][0] * J[1][1] - J[0][1] * J[1][0];
		det1 = FreeMem[0] * J[1][1] - FreeMem[1] * J[0][1];
		det2 = J[0][0] * FreeMem[1] - J[1][0] * FreeMem[0];

		dX = -(det1 / detMain);
		dY = -(det2 / detMain);

		X1 += dX;
		Y1 += dY;

		num++;
		cout << "dX = " << dX << "\t" << "dY = " << dY << endl;
	} while (sqrt(dX*dX + dY*dY) > eps);

	cout << "\nNumber of iterations: " << num << endl;
	cout << "X = " << X1 << "\tY = " << Y1 << endl;
}
 