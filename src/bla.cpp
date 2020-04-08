#include "bla.hpp"

template<typename T>
void gemm(const T *A, const T *B, T *C, unsigned int n)
{
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < n; j++) {
			T tmp{};
			for (unsigned k = 0; k < n; k++) {
				tmp += A[i * n + k] * B[k * n + j];
			}
			C[i * n + j] = tmp;
		}
	}
}

template void gemm<double>(const double *A, const double *B, double *C, unsigned int n);
