#include <random>
#include <cblas.h>
#include <iostream> 
#include <iomanip> 
#include "bla.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    const unsigned int n = 10;
    const long n2 = n * n;
    constexpr long double FPOperations = n2 * (2 * n - 1);

    // Create arrays that represent the matrices A,B,C
    double * A = new double[n2];
    double * B = new double[n2];
    double * C = new double[n2];

    // Fill A and B with random numbers
    for(uint i = 0; i < n2; i++){
	    A[i] = 0.0d;
	    B[i] = 0.0d;
    }

    // Calculate A*B=C
    gemm(A, B, C, n);

    cout << "This code should be performing about " << FPOperations << " FLOPs" << endl;

    // Clean up
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
