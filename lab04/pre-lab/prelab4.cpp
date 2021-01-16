/*
 * Sam Townsend
 * prelab4.cpp
 * 9/24/2020
 * sft3hy
 */

#include <iostream>
#include <string>
using namespace std;

void sizeOfTest() {
  cout << "Size of int: " + to_string(sizeof(int)) << endl;
  cout << "Size of unsigned int: " + to_string(sizeof(unsigned int)) << endl;
  cout << "Size of float: " + to_string(sizeof(float)) << endl;
  cout << "Size of double: " + to_string(sizeof(double)) << endl;
  cout << "Size of char: " + to_string(sizeof(char)) << endl;
  cout << "Size of bool: " + to_string(sizeof(bool)) << endl;
  cout << "Size of int*: " + to_string(sizeof(int*)) << endl;
  cout << "Size of char*: " + to_string(sizeof(char*)) << endl;
  cout << "Size of double*: " + to_string(sizeof(double*)) << endl;
}

void overflow() {
  unsigned int maxNum = 4294967295;
  int overflowed = maxNum + 1;
  cout << to_string(maxNum) + " + " + "1 = " + to_string(overflowed) << endl;
}

void outputBinary(unsigned int x) {
  unsigned int maximum = 2147483648;
  if(x > maximum) {
    cout << "Number exceeds 32 bit representation" << endl;
  } else {
    int binary[32];
    for(int i = 31; i >= 0; i--) {
      int remainder = x%2;
      x /= 2;
      binary[i] = remainder;
    }  
    for(int i = 0; i < 32; i++) {
      if(i%4 == 0 && i != 0) {
	cout << " ";
      }
      cout << binary[i];
    }
    cout << "" << endl;
  }
}

int main() {
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}
