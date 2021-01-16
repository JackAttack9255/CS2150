#include <iostream>
#include <string>
using namespace std;

int product(int x, int y) {
  int n = 0;
  int prod = 0;
  while(n < y) {
    prod += x;
    n++;
  }
  return prod;
}

int power(int a, int b) {
  if(b != 0) {
    b--;
    return product(a, power(a,b));
  } else {
    return 1;
  }
}

int main() {
  long x, y;
  cout << "Enter argument 1: ";
  cin >> x;
  cout << "Enter argument 2: ";
  cin >> y;
  int prod = product(x,y);
  int pow = power(x,y);
  
  cout << "Product: " + to_string(prod) << endl;
  cout << "Power: " + to_string(pow) << endl;

}
