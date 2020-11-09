#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Dynamorph
{
  string code;
  int* encryption;

  Dynamorph& operator=(Dynamorph& dmh)
  {
    code = dmh.code;
    encryption = dmh.encryption;
  }

  Dynamorph(string& code, int size)
  {
    this->code = code;
    this->encryption = new int[size];
  }

  Dynamorph(Dynamorph& dmh)
  {
    code = dmh.code;
    this->encryption = dmh.encryption;
  }
};


int main(int argc, char* argv[])
{
  int A = 128;

  int* ptrA = &A;

  int B = 0;

  int* ptrB = &B;

  cout << "ptr A: " << ptrA << ", A: " << A << endl;
  cout << "ptr B: " << ptrB << ", B " << B << endl << endl;

  ptrB = ptrA;  // SHALLOW COPY, ONLY COPIES ADDRESS

  cout << "ptr A: " << ptrA << ", *ptrA: " << *ptrA << endl;
  cout << "ptr B: " << ptrB << ", *ptrB: " << *ptrB << endl << endl;

  *ptrB = 256;    

  cout << "ptr A: " << ptrA << ", *ptrA: " << *ptrA << endl;
  cout << "ptr B: " << ptrB << ", *ptrB: " << *ptrB << endl << endl;

  cout << "B: " << B << endl;

  ptrB = &B;

  cout << "ptr A: " << ptrA << ", *ptrA: " << *ptrA << endl;
  cout << "ptr B: " << ptrB << ", *ptrB: " << *ptrB << endl << endl;

  *ptrB = *ptrA;  //  DEEP COPY, COPYING ACTUAL VALUE, INTO INDEPENDENT VARIABLE

  cout << "ptr A: " << ptrA << ", *ptrA: " << *ptrA << endl;
  cout << "ptr B: " << ptrB << ", *ptrB: " << *ptrB << endl << endl;

  *ptrA = 0;

  cout << "ptr A: " << ptrA << ", *ptrA: " << *ptrA << endl;
  cout << "ptr B: " << ptrB << ", *ptrB: " << *ptrB << endl << endl;



  Dynamorph A = Dynamorph("get to the choppah", 16);

  Dynamorph B = Dynamorph("dakka dakka", 32);

  B = A; // calls assignment operator

  Dynamorph C = A;




  return 0;
}

  /*
  */