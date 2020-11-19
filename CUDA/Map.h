#pragma once
#include <iostream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "CUDA-Interface.h"

// mapping functions, applying some operation to each element in an array


// square the elements of an array, must have * operator defined
template <class x> __global__ void square(x* data)
{
	int index = threadIdx.x + (blockIdx.x * blockDim.x);

	data[index] = data[index] * data[index];
}


// initialize data with the thread index
__global__ void index_initialize(int* data)
{
	int index = threadIdx.x + (blockIdx.x * blockDim.x);

	// set data at index to index
	data[index] = index;
}

// wrapper for index initialize
void index_initialize(int* data, int size)
{
	// number of blocks to use = size of the problem / 512 threads + 1
	int blocks = (size / 512) + 1;

	// number of threads to use = size of problem / number of blocks
	int threads = size / blocks;

	// declare device memory
	int* d_data = new int[size];

	// allocate memory
	allocate<int>(&d_data, size);

	// copy data
	copy_to_device<int>(d_data, data, size);

	// call kernel
	index_initialize <<< blocks, threads >>> (d_data);

	// copy back results 
	copy_to_host<int>(data, d_data, size);

	// free memory
	cudaFree(d_data);
}


