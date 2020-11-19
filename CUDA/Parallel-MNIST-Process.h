#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"

// the purpose of this header is to utilize the GPU in processing the mnist input, shuffling the data, and modifying images to expand the training data.
// contained at the bottom will be the main programs in quotes
// certain things are hard coded because this is for one particular data set


// convert from an array of double to a binary array, consuming 1/8th the memory
__global__ void to_binary(double* data, bool* binary)
{
	int index = blockIdx.y * blockDim.x + threadIdx.x;

	binary[index] = 0;

	if (data[index] > 0) binary[index] = 1;
	else binary[index] = 0;
}

// wrapper for converting to binary
void to_binary(double* data, bool* binary, int lines)
{
	
	// grid dimensions
	dim3 blocks = dim3(1, lines, 1);

	// block dimensions
	dim3 threads = dim3(784, 1, 1);

	// declare device memory
	double* device_data = new double[lines * 784];
	bool* device_binary = new bool[lines * 784];

	// allocate memory
	allocate<double>(&device_data, lines * 784);
	allocate<bool>(&device_binary, lines * 784);

	// copy memory
	copy_to_device<double>(device_data, data, lines * 784);
	copy_to_device<bool>(device_binary, binary, lines * 784);

	// call kernel
	to_binary<<< blocks, threads>>>(device_data, device_binary);

	// copy back results
	copy_to_host<bool>(binary, device_binary, lines * 784);

	// free memory
	cudaFree(device_data);
	cudaFree(device_binary);


}


// convert an array of doubles to an integer bitmap, using 1/64th the memory
__global__ void to_bitmap(double* data, unsigned int* bitmap)
{
	// get index to data
	int datax = blockIdx.y * blockDim.x + threadIdx.x;

	// get bitmap index, rows of 25
	int bitmapx = blockIdx.y * 28 + (threadIdx.x / 28);


	// if data is greater than 0 call atomic or to set the bit at position % 32 to 1
	if (data[datax] > 0) atomicOr(&bitmap[bitmapx], (1 << datax % 28));

}

// wrapper for to bitmap kernel, converts a double array to a bitmap
void to_bitmap(double* data, unsigned int* bitmap, int lines)
{
	// dimensions for double array
	int datax = lines * 784;

	// dimensions for bitmap
	int bitmapx = lines * 28;

	// grid dimensions
	dim3 blocks = dim3(1, lines, 1);

	// block dimensions
	dim3 threads = dim3(784, 1, 1);

	// declare device memory
	double* d_data = new double[datax];
	unsigned int* d_bitmap = new unsigned int[bitmapx];

	// allocate memory
	allocate<double>(&d_data, datax);
	allocate<unsigned int>(&d_bitmap, bitmapx);

	// copy over values
	copy_to_device<double>(d_data, data, datax);
	copy_to_device<unsigned int>(d_bitmap, bitmap, bitmapx);

	// call kernel
	to_bitmap <<< blocks, threads >>> (d_data, d_bitmap);

	// sync threads
	sync_threads();

	// copy back results
	copy_to_host<unsigned int>(bitmap, d_bitmap, bitmapx);

	// free memory
	cudaFree(d_data);
	cudaFree(d_bitmap);

}

// generate a set of random indexes
__global__ void random_indexes(int* indexes)
{

}

// wrapper for generating a set of random indexes
void random_indexes(int* indexes, int size)
{
	// number of blocks to use = size of the problem / 512 threads + 1
	int blocks = (size / 512) + 1;

	// number of threads per block = size of the problem / number of blocks
	int threads = size / blocks;
}



// kernel for swapping two images based on their index positions in a 1d array
__global__ void swap(int A, int B)
{

}

// kernel for shuffling images in parallel
__global__ void shuffle()
{

}

// wrapper function for shuffling images in parallel
void shuffle(double* data, short int* labels, int images)
{

}









// 'standard' storage method of a double for each value, 784 doubles per line, 6272 bytes per line, for 10,000 lines that's 62,720,000 bytes, ridiculous
// using an int for each would not you 32,000,000 or 15,000,000 if you are using a short
// but a bitmap with unsigned int requires only 25 ints (I used 28 to simplify indexing), using 28 you waste only 4 bits per row of the image
// 28 ints = 112 bytes per image, for 10,000 images 1,120,000 bytes, by using bitwise operations we can consume roughly 1/64th the memory

// MAIN FUNCTION FOR CONVERSION FROM CSV TO TEXT, DONE TO SAVE READ IN TIME
/*
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cs344\Lesson Code Snippets\Lesson 2 Code Snippets\gputimer.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"
#include "Map.h"
#include "Parallel-MNIST-Process.h"

using namespace std;

int main()
{
// stream to read in csv file
ifstream mnist_test;

// open file
mnist_test.open("mnist_test.csv");

// number of lines to get
int lines = 10000;

// host data from file
double** mnist = new double*[lines];

// initialize mnist
for (int i = 0; i < lines; i++)
{
mnist[i] = new double[785];

for (int j = 0; j < 785; j++)
{
mnist[i][j] = 0;
}
}

// get lines from csv
getlinesCSV(mnist_test, lines, mnist);

// close ifstream
mnist_test.close();

// declare an ofstream for files and labels
ofstream mnist_labels;
ofstream mnist_data;

// open files
mnist_labels.open("mnist_labels.txt");
mnist_data.open("mnist_data.txt");

// send data to ostream
for (int i = 0; i < lines; i++)
{
//mnist_labels << mnist[i][0] << "\n";

// for the width
for (int j = 1; j < 785; j++)
{
mnist_data << mnist[i][j] << " ";
}

mnist_data << "\n";
}


// close stream
mnist_labels.close();
mnist_data.close();






return 0;
}*/

// MAIN FUNCTION FOR READING LABELS AND IMAGES INTO 2D ARRAYS
/*
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cs344\Lesson Code Snippets\Lesson 2 Code Snippets\gputimer.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"
#include "Map.h"
#include "Parallel-MNIST-Process.h"

using namespace std;

int main()
{
	// stream to read in csv file
	ifstream mnist_test;

	// open file
	mnist_test.open("mnist_test.csv");

	// number of lines to get
	int lines = 100;

	// labels
	double* labels = new double[lines];

	// patterns in 1d
	double** patterns1d = new double*[lines];

	// initialize labels
	zero_initialize(labels, lines);

	// zero initialize patterns
	zero_initialize(patterns1d, lines, 784);

	// declare an ifstream for files and labels
	ifstream mnist_labels;
	ifstream mnist_data;

	// open files
	mnist_labels.open("mnist_labels.txt");
	mnist_data.open("mnist_data.txt");

	// call get labels
	getlabels(mnist_labels, lines, labels);

	// call get images
	getimages(mnist_data, lines, patterns1d);

	// reset device	
	cudaDeviceReset();

	return 0;
}*/

// MAIN FUNCTION FOR READING LABELS AND IMAGES INTO A 1D ARRAY
/*
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cs344\Lesson Code Snippets\Lesson 2 Code Snippets\gputimer.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"
#include "Map.h"
#include "Parallel-MNIST-Process.h"

using namespace std;

int main()
{
// number of lines to get
int lines = 10;

// labels
double* labels = new double[lines];

// patterns in 2d
double** patterns2d = new double*[lines];

// patterns in 1d
double* patterns = new double[lines * 784];

// initialize labels
//zero_initialize(labels, lines);

// zero initialize patterns
//zero_initialize(patterns1d, lines, 784);

// declare an ifstream for files and labels
ifstream mnist_labels;
ifstream mnist_data;

// open files
mnist_labels.open("mnist_labels.txt");
mnist_data.open("mnist_data.txt");

// call get labels
getlabels(mnist_labels, lines, labels);

// call get images
getimages(mnist_data, lines, patterns);

printImages(10, patterns);



// reset device
cudaDeviceReset();


return 0;
}*/

// MAIN FUNCTION FOR READING DATA INTO A BITMAP AND STORING IT IN A TEXTFILE
/*
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cs344\Lesson Code Snippets\Lesson 2 Code Snippets\gputimer.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"
#include "Map.h"
#include "Parallel-MNIST-Process.h"

using namespace std;

int main()
{
// number of lines to get
int lines = 10000;

// labels
double* labels = new double[lines];

// patterns in 2d 6280 bytes per line
double** patterns2d = new double*[lines];

// patterns in 1d 6272 bytes per line
double* patterns = new double[lines * 784];

// patterns in binary 784 bytes per line
bool* binaryPatterns = new bool[lines * 784];

// pattern bitmap 112 bytes per line
unsigned int* bitPatterns = new unsigned int[lines * 28];

for (int i = 0; i < lines * 28; i++)
{
bitPatterns[i] = 0;
}

// declare an ifstream for files and labels
ifstream mnist_labels;
ifstream mnist_data;

// open files
mnist_labels.open("mnist_labels.txt");
mnist_data.open("mnist_data.txt");

// call get labels
getlabels(mnist_labels, lines, labels);

// call get images
getimages(mnist_data, lines, patterns);

// close stream
mnist_labels.close();
mnist_data.close();

// get patterns in binary
to_binary(patterns, binaryPatterns, lines);

// get patterns in bitmap form
to_bitmap(patterns, bitPatterns, lines);

//printBitmap(lines, bitPatterns);

// declare an ofstream
ofstream mnist_bitmap;

// open file
mnist_bitmap.open("mnist_bitmap.txt");

// write each int to file
for (int i = 0; i < lines; i++)
{
for (int j = 0; j < 28; j++)
{
mnist_bitmap << bitPatterns[i * 28 + j] << " ";
}
mnist_bitmap << endl;
}



// reset device
cudaDeviceReset();


return 0;
}
*/

// MAIN FUNCTION FOR READING BITMAP FROM A FILE
/*
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cs344\Lesson Code Snippets\Lesson 2 Code Snippets\gputimer.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"
#include "Map.h"
#include "Parallel-MNIST-Process.h"

using namespace std;

int main()
{
// number of lines to get
int lines = 10;

// labels
double* labels = new double[lines];

// patterns in 2d 6280 bytes per line
double** patterns2d = new double*[lines];

// patterns in 1d 6272 bytes per line
double* patterns = new double[lines * 784];

// patterns in binary 784 bytes per line
bool* binaryPatterns = new bool[lines * 784];

// pattern bitmap 112 bytes per line
unsigned int* bitPatterns = new unsigned int[lines * 28];

for (int i = 0; i < lines * 28; i++)
{
bitPatterns[i] = 0;
}

// declare an ifstream for files and labels
ifstream mnist_labels;
ifstream mnist_bitmap;

// open files
mnist_labels.open("mnist_labels.txt");
mnist_bitmap.open("mnist_bitmap.txt");


// get labels
getlabels(mnist_labels, lines, labels);

// get bitmap
getbitmap(mnist_bitmap, lines, bitPatterns);

// close stream
mnist_labels.close();
mnist_bitmap.close();


printBitmap(10, bitPatterns);




// reset device
cudaDeviceReset();


return 0;
}

*/

// MAIN FUNCTION FOR GENERATING RANDOM INDEXES
/*
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <random>
#include <math.h>
#include <time.h>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "cs344\Lesson Code Snippets\Lesson 2 Code Snippets\gputimer.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"
#include "Map.h"
#include "Parallel-MNIST-Process.h"
#include "Parallel-MNIST-Helper.h"

using namespace std;

int main()
{
srand(time(NULL));

// number of lines to get
int lines = 10000;

// labels
short int* labels = new short int[lines];

// pattern bitmap 112 bytes per line
unsigned int* bitPatterns = new unsigned int[lines * 28];

for (int i = 0; i < lines * 28; i++)
{
bitPatterns[i] = 0;
}

// declare an ifstream for files and labels
ifstream mnist_labels;
ifstream mnist_bitmap;

// open files
mnist_labels.open("mnist_labels.txt");
mnist_bitmap.open("mnist_bitmap.txt");

// get labels
getlabels(mnist_labels, lines, labels);

// get bitmap
getbitmap(mnist_bitmap, lines, bitPatterns);

// close stream
mnist_labels.close();
mnist_bitmap.close();


int* indexes = new int[lines];

index_initialize(indexes, lines);

//random_indexes(indexes, lines);


for (int i = 0; i < 100000; i++)
{
int A = rand() % 10000;

int B = rand() % 10000;

int temp = indexes[A];

indexes[A] = indexes[B];

indexes[B] = temp;
}

for (int i = 0; i < 100; i++)
{
cout << indexes[i] << endl;
}

cout << endl;










// reset device
cudaDeviceReset();


return 0;
}


*/