/* Sam Townsend
 * sft3hy
 * postfixCalculator.h
 * 9/20/2020
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class postfixCalculator {

 public:
  postfixCalculator();

  bool isEmpty();

  void addition();

  void subtraction();

  void multiplication();

  void division();

  void unaryNegation();

  stack <int> s;
  
};

#endif
