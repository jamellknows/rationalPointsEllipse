#include <iostream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <complex>

using namespace std;

double solveX(double a, double b)
{


}

std::complex<double> sqrt0(double theta, double omega)
{
   std::complex<double> sqrt0 = (exp(omega)*cos(theta), exp(omega)*sin(theta));
   cout << std::real(sqrt0) << endl;
}


int main(int argc, char ** argv)
{
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    //solving for x 
    double x = 1.2;
    double y = 0.9;
    sqrt0(x, y);
}