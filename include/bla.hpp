#pragma once

template<typename T>
void gemm(const T *A, const T *B, T *C, unsigned int n);

template<typename T>
void matadd(const T *A, const T *B, T *C, unsigned int n);

extern template void gemm<double>(const double *A, const double *B, double *C, unsigned int n);
extern template void matadd<double>(const double *A, const double *B, double *C, unsigned int n);
