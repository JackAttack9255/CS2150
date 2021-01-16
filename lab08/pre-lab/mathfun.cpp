/*
 * Sam Townsend
 * sft3hy
 * 10/25/20
 * mathfun.cpp
 */

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);


int  main () {

    // delcare the local variables
  long  x, y, prod, pow;

    // how big is the array we want to use?
    cout << "Enter integer 1: ";
    cin >> x;
    cout << "Enter integer 2: ";
    cin >> y;


    // sum up the array and print out results
    prod = product(x, y);
    pow = power(x,y);
    
    cout << "Product: " << prod << endl;
    cout << "Power: " << pow << endl;

    // all done!
    return 0;
}
