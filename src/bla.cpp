#include "bla.hpp"

template<typename T>
void gemm(const T *A, const T *B, T *C, const unsigned int n)
{
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < n; j++) {
			T tmp{A[i * n + 0] * B[0 * n + j]};
			for (unsigned k = 1; k < n; k++) {
				tmp += A[i * n + k] * B[k * n + j];
			}
			C[i * n + j] = tmp;
		}
	}
}

template<typename T>
void matadd(const T *A, const T *B, T *C, const unsigned int n)
{
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < n; j++) {
			C[i * n + j] = A[i * n + j] * B[i * n + j];
		}
	}
}

template void gemm<double>(const double *A, const double *B, double *C, const unsigned int n);
template void matadd<double>(const double *A, const double *B, double *C, const unsigned int n);
