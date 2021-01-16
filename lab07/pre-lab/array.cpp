#include <iostream>
using namespace std;

int main() {
  int size = 0;
  int inAm = 0;
  int i;
  int j;
  int x;

  cin >> size;
  int arr[size];

  //put user input in array
  while(inAm < size) {
    cin >> x;
    arr[inAm]= x;
    inAm++;
  }

  //print array forwards
  cout << "printing forwards" << endl;
  while(i <= size - 1) {
    cout << arr[i] << endl;
    i++;
  }
  
  j = size - 1;
  //print array backwards
  cout << "printing backwards" << endl;
  while(j >= 0) {
    cout << arr[j] << endl;
    j--;
  }
  
  return 0;
}
