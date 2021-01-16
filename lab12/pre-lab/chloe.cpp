#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
  string input = "";
  cout << "Enter a food that chloe wants to eat today" << endl;
  cin >> input;
  cout << "Chloe will eat " + input + " today" << endl;
  int n = rand() % 10 + 1;
  if(5 > n) {
    cout << input + " is a bad food" << endl;
  } else {
    cout << input + " is a good food" << endl;
  }
  cout << "N: " + to_string(n) << endl;
}
