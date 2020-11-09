#include <iostream>
#include <fstream>
#include <string>
#define MAX_DICT_SIZE 3000
#define MAX_WORDS 10000
#define MAX_SENTENCES 1000
using namespace std;

struct entry
{
	int count;
	string cword;
	entry()
	{
		count = 0;
		cword = "";
	}
	entry(string _word)
	{
		count = 0;
		cword = _word;
	}
};

int readwords(string filename, entry* _array)
{
	int counter = 0;
	ifstream file;
	file.open(filename);
	string word = "";
	while (file >> word)
	{
		_array[counter] = entry(word);
		counter++;
		if (counter == MAX_DICT_SIZE - 1)
			break;
	}
	file.close();
	return counter;
}

int binarysearch(entry dictionary[MAX_DICT_SIZE], int size, string find) 
{ 
  int l = 0 ; 
  int r = size - 1; 
  while (l <= r)  
  { 
    int m = l + (r - l) / 2; 

    int result; 
    if (find == (dictionary[m].cword)) 
      result = 0; 
        
      // Check if x is present at mid 
      if (result == 0) 
          return m; 

      // If x greater, ignore left half 
      if (find > (dictionary[m].cword)) 
          l = m + 1; 

      // If x is smaller, ignore right half 
      else
          r = m - 1; 
  } 

    return -1; 
} 


int main()
{
	entry dictionary[MAX_DICT_SIZE];

	int words = readwords("words.txt", dictionary);

	cout << words << endl;

  int index = binarysearch(dictionary, words, "works");

  if(index >= 0)
  {
    cout << "Found at: " << index << endl;
  }
  else
  {
    cout << "Not found." << endl;
  }
  


	return 0;
}