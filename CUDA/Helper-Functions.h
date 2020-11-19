#pragma once
#include <iostream>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "CUDA-Interface.h"

using namespace std;


// raise var to a power
int power(int var, int pow)
{
	if (pow > 0) return power(var * var, pow - 1);
	else return 1;
	

}

// multiply 


// swap two variables
template <class x> void swap(x& A, x& B)
{
	// declare C set it to A
	x C = A;

	// set A to B
	A = B;

	// set B to C = A
	B = C;
}

// zero out array kernel
__global__ void zero_initialize(double* data)
{
	data[threadIdx.x] = 0;
}

// zero out matrix kernel, lazy implementation
__global__ void zero_initialize(double** data)
{
	data[blockIdx.x][threadIdx.x] = 0;
}

// wrapper for function for zero array kernel
void zero_initialize(double* data, int size)
{
	// device memory
	double* device = new double[size];

	// number of blocks to use
	int blocks = size / 512 + 1;

	// number of threads to use per block, size of problem divided by number of blocks
	int threads = size / blocks;

	// allocate memory
	allocate<double>(&device, size);

	// launch kernel
	zero_initialize <<< blocks, threads >>> (device);

	// copy over results
	copy_to_host(data, device, size);

	cudaFree(device);
}

// wrapper for zero matrix kernel, very lazy DOES NOT WORK FOR WIDTHS > 1024
void zero_initialize(double** data, int height, int width)
{
	double** device = new double*[height];

	for (int i = 0; i < height; i++)
	{
		device[i] = new double[width];
	
		cudaMalloc(&data[i], width * sizeof(double));
	}

	zero_initialize <<< height, width >>> (device);
	
	cudaMemcpy(data, device, height * width * sizeof(double), cudaMemcpyDeviceToHost);

	cudaFree(device);
}


// zero out array
void zero_initialize(int* data, int size)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

// print out array
void print_array(int* data, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";

		if (i % 20 == 0 && i > 0) std::cout << '\n';
	}

	std::cout << std::endl;
}