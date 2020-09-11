#include <math.h>
#include <stdlib.h>
#include <iostream>

double Get_Discr (double* koef);
int Sign_Discr (int Discr);
void Linear_equation (double* koef);
double* Get_Solution(double* koef, double Discr);

int main() {
	double* solution;
    double* koef = (double*)malloc(3 * sizeof(double));
    std::cout << "Please enter coefficients" << std::endl;
	for (int i = 0; i < 3; i++) 
	    std::cin >> koef[i];
    if (koef[0] != 0) {
        double discr = Get_Discr (koef);
        if (Sign_Discr(discr) == -1) {
            std::cout << "No solutions" << std::endl;
        }
        else {
            solution = Get_Solution(koef, discr);
            if (Sign_Discr(discr) == 1) {
                std::cout << "Eqiation has 2 solutions" << std::endl;
                std::cout << "Solution are " << solution[0] << " and " << solution[1] << std::endl;
            }
            else {
                std::cout << "Eqiation has 1 solution" << std::endl;
                std::cout << "Solution is " << solution[0] << std::endl;
            }
        }
    }
    else {
        Linear_equation(koef);
    }
    return 0;
}

double Get_Discr (double* koef) {
    double Discr = 0;
    Discr = koef[1] * koef[1] - 4 * koef[0] * koef[2];
    return Discr;
}
int Sign_Discr (int Discr) {
    if (Discr > 0) return 1;
    if (Discr == 0) return 0;
    if (Discr < 0) return -1;
}
void Linear_equation (double* koef) {
    double x = 0;
    x = -koef[2] / koef[1];
    std::cout << "Eqiation has 1 solution" << std::endl;
    std::cout << "Solution is " << x << std::endl;
}
double* Get_Solution(double* koef, double Discr) {
	double* solution = (double*)malloc(2 * sizeof(double));
	solution[0] = (-koef[1] + sqrt(Discr)) / (2 * koef[0]);
	solution[1] = (-koef[1] - sqrt(Discr)) / (2 * koef[0]);
	return solution;
}