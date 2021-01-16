#include <iostream>
#include "timer.h"
#include <string>
using namespace std;

extern "C" long long threexplusone(long long x);

int main() {
  long long x, n, once;
  double avg;
  double avgMilli;
  timer tim;
  once = 0;

  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  once = threexplusone(x);

  tim.start();
  for(int i = 0; i < n; i++) {
    threexplusone(x);
  }
  tim.stop();

  cout << "Iterations: " + to_string(once) << endl;
  avg = tim.getTime()/n;
  avgMilli = 1000*avg;
  //cout << "Average time: " + to_string(avgMilli) + " milliseconds" << endl;
  
  return 0;
}
