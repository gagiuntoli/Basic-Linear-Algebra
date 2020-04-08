#include <random>
#include <cblas.h>
#include <chrono>  // for high_resolution_clock
#include <iostream> 
#include <ctime> 
#include <iomanip> 

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{

    // Random numbers
    mt19937_64 rnd;
    uniform_real_distribution<double> doubleDist(0, 1);

    // Create arrays that represent the matrices A,B,C
    const long ns[] = {10, 20, 30, 40, 50, 100, 200, 300, 500, 700, 1000};

    cout << "N^2        FPO          Elapsed time   FPOs [GFLOPs]    FPOs CBLAS [GFLOPs]" << endl;

    for (auto &n : ns) {

	    double * A = new double[n * n];
	    double * B = new double[n * n];
	    double * C = new double[n * n];

	    long n2 = n * n;

	    long double FPOperations = n2 * (2 * n - 1);

	    // Fill A and B with random numbers
	    for(uint i = 0; i < n; i++){
		    for(uint j = 0; j < n; j++){
			    A[i * n + j] = doubleDist(rnd);
			    B[i * n + j] = doubleDist(rnd);
		    }
	    }

	    auto start = high_resolution_clock::now();

	    // Calculate A*B=C
	    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, C, n);

	    auto finish = high_resolution_clock::now();
	    auto elapsed = duration_cast<nanoseconds>(finish - start);

	    start = high_resolution_clock::now();

	    // Calculate A*B=C
	    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, A, n, B, n, 0.0, C, n);

	    finish = high_resolution_clock::now();

	    auto elapsed_CBLAS = duration_cast<nanoseconds>(finish - start);

	    cout << left << setw(10) << setfill(' ') << n2 << " "
		 << scientific << FPOperations << " "
		 << left << setw(14) << setfill(' ') << elapsed.count() << " "
		 << scientific << FPOperations / elapsed.count() << " "
		 << scientific << FPOperations / elapsed_CBLAS.count()
		 << endl;

	    // Clean up
	    delete[] A;
	    delete[] B;
	    delete[] C;
    }

    return 0;
}
