#include <iostream>
using namespace std;

int n = 0;

long threexplusone(long x) {
  if(x == 1) {
    return n;
  }
  n++;
  if(x%2 == 0) {
    return threexplusone(x/2);
  } else {
    return threexplusone((3*x)+1);
  }
}

int main() {

  long x, n, once, avg;
  once = 0;

  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  once = threexplusone(x);


  cout << "Iterations: " + to_string(once) << endl;

  return 0;
}
