//Samuel Townsend
//sft3hy
//9/1/2020
//xToN.cpp
#include <iostream>
using namespace std;

int power (int a, int b) {
  if(b == 0){
    return 1;
  } else{
    int tmp = b-1;
    return a*power(a, tmp);
  }
}

int main () {
    int x, n, z;
    cin >> x;
    cin >> n;
    z = power(x, n);
    cout << z << endl;
    return 0;
}
