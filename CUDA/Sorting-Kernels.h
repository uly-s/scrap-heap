#pragma once
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "CUDA-Interface.h"
#include "Helper-Functions.h"

//#include "Data-Structures\Array.h"


// parallel merge kernel for merging two arrays
__global__ void Merge(int* A, int* B, int sizeA, int sizeB)
{
	// combined array
	int* C = new int[sizeA + sizeB];

	// indexes
	int a = 0;  // A index
	int b = 0;  // B index
	int c = 0;  // C index

				// while A and B aren't fully copied
	while (a < sizeA && b < sizeB)
	{
		if (A[a] < B[b]) C[c++] = A[a++];
		else C[c++] = B[b++];
	}

	// while A isn't fully copied
	while (a < sizeA)
	{
		C[c++] = A[a++];
	}

	// while B isn't fully copied
	while (b < sizeB)
	{
		C[c++] = B[b++];
	}

	//return C;
}

// parallel merge kernel styled after merge sort merge
__global__ void Merge(int* data, int left, int mid, int right)
{
	int* sorted = new int[right - left];

	// indexes
	int i = left;
	int j = mid + 1;
	int k = left;

	// while a and b arent fully copied
	while (i <= mid && j <= right)
	{
		if (data[i] < data[j]) sorted[k++] = data[i++];

		else sorted[k++] = data[j++];
	}

	// while a isn't fully copied
	while (i <= mid)
	{
		sorted[k++] = data[i++];
	}

	// while b isn't fully copied
	while (j <= right)
	{
		sorted[k++] = data[j++];
	}

	// copy over the elements to data
	for (i = left; i < k; i++) data[i] = sorted[i];

	return;
}

__global__ void Merge(int* data, int depth)
{
	// left = thread index
	int left = threadIdx.x;

	//  |    NEED ABILITY TO EXPOTENTIATE HERE
	//  V

	// right = Left + 2 ^ depth - 1
	int right = left + depth;

	// if right is greater than size, set right to size
	if (right > (gridDim.x * blockDim.x)) right = gridDim.x * blockDim.x;

	// temporary combined array
	int* sorted = new int[right - left];

	// mid range
	int mid = (left + right) / 2;

	// indexes
	int i = left;
	int j = mid + 1;
	int k = left;

	// while a and b arent fully copied
	while (i <= mid && j <= right)
	{
		if (data[i] < data[j]) sorted[k++] = data[i++];

		else sorted[k++] = data[j++];
	}

	// while a isn't fully copied
	while (i <= mid)
	{
		sorted[k++] = data[i++];
	}

	// while b isn't fully copied
	while (j <= right)
	{
		sorted[k++] = data[j++];
	}

	// copy over the elements to data
	for (i = left; i < k; i++) data[i] = sorted[i];

	return;

}

// parallel merge sort kernel
__global__ void MergeSort(int* data, int left, int right)
{
	


}