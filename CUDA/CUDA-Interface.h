#pragma once
#include <iostream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

// allocate size of type x in bytes for n elements pointed to by data 
template <class x> void allocate(x** data, int elements)
{
	cudaMalloc(data, elements * sizeof(x));
}

// copy size amount of elements to the device 
template <class x> void copy_to_device(x* device, x* host, int size)
{
	cudaMemcpy(device, host, size * sizeof(x), cudaMemcpyHostToDevice);
}

// copy size amount of elements to the host
template <class x> void copy_to_host(x* host, x* device, int size)
{
	cudaMemcpy(host, device, size * sizeof(x), cudaMemcpyDeviceToHost);
}


// synchronize threads
void sync_threads()
{
	cudaDeviceSynchronize();
}

