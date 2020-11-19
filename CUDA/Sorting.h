#pragma once
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <math.h>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "CUDA-Interface.h"
#include "Helper-Functions.h"

#include "Sorting-Kernels.h"

//#include "Data-Structures\Array.h"

// Parallel sorting algorithms



// DIY implementation of parallel merge sort

// merge sort
void MergeSort(int* data, int left, int right, int size)
{
	int mid = (left + right) / 2;

	// number of blocks equals size of the problem divided by 512 threads per block
	int blocks = (size / 512) + 1;

	// threads per block equals the size of the problem divided by the number of blocks
	int threads = (size / blocks) / 2;

	// declare device memory
	int* d_data = new int[size];

	// allocate memory
	allocate<int>(&d_data, size);

	// copy
	copy_to_device<int>(d_data, data, size);

	// depth of merge
	int depth = 1;

	// max depth of the merge
	int maxdepth = (int) round(log(size));

	// for each level call merge
	while (depth < maxdepth)
	{
		Merge <<< blocks / depth, threads / depth >>> (d_data, depth++);
	}
	

	// copy back results
	copy_to_host<int>(data, d_data, size);

	// free memory
	cudaFree(d_data);

}
