#pragma once
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "CUDA-Interface.h"
#include "Helper-Functions.h"

// this header is to store the non parallel helper functions for parallel mnist process

// print out images for a binary array
void printImages(int images, bool* data)
{
	int size = images * 784;

	for (int i = 0; i < size; i++)
	{
		cout << data[i] << " ";

		if ((i + 1) % 28 == 0)
		{
			cout << endl;
		}

		if ((i + 1) % 784 == 0)
		{
			cout << endl;
		}
	}

}

// print out an int 
void printBitRow(unsigned int row)
{
	for (int i = 0; i < 28; i++)
	{
		if (row & (1 << (i % 28))) cout << 1 << " ";
		else cout << 0 << " ";
	}
	cout << endl;
}

// print out images from the bitmap
void printBitmap(int images, unsigned int* data)
{

	for (int i = 0; i < images; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			printBitRow(data[i * 28 + j]);
		}
		cout << endl;

	}
}

// get a single line of input and feed it into data
void getlineCSV(ifstream& stream, double* line)
{
	// dummy to read in comma
	char dummy = ' ';

	// for each of 785 values (1 label + 28 * 28 pixels)
	for (int i = 0; i < 785; i++)
	{
		// read input to line
		stream >> line[i];

		// if we aren't at the end of the line get the comma
		if (i < 784) stream >> dummy;
	}
}

// read in a certain number of lines of the mnist csv into 
void getlinesCSV(ifstream& stream, int lines, double** data)
{
	// for each line
	for (int i = 0; i < lines; i++)
	{
		getlineCSV(stream, data[i]);
	}
}

// get a certain amount of labels
void getlabels(ifstream& stream, int lines, short int* labels)
{
	for (int i = 0; i < lines; i++)
	{
		labels[i] = 0;

		stream >> labels[i];
	}
}

// get line from text file
void getimage(ifstream& stream, double* line)
{
	for (int i = 0; i < 784; i++)
	{
		line[i] = 0;

		stream >> line[i];
	}
}

// get so many lines from the file
void getimages(ifstream& stream, int lines, double** data)
{

	for (int i = 0; i < lines; i++)
	{
		data[i] = new double[784];

		getimage(stream, data[i]);
	}
}

// get so many lines, 1d
void getimages(ifstream& stream, int lines, double* data)
{
	int size = lines * 784;

	for (int i = 0; i < size; i++)
	{
		data[i] = 0;

		stream >> data[i];
	}
}

// get so many lines of bitmap
void getbitmap(ifstream& stream, int lines, unsigned int* data)
{
	// for each line
	for (int i = 0; i < lines; i++)
	{
		// for each column
		for (int j = 0; j < 28; j++)
		{
			stream >> data[i * 28 + j];
		}
	}
}