/* Sam Townsend
 * sft3hy
 * postfixCalculator.cpp
 * 9/20/2020
 */

#include <iostream>
#include <stack>
#include <string>
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator() {
  stack <int> s;
}

bool postfixCalculator::isEmpty() {
  if(s.empty()) {
    return true;
  } return false;
}

void postfixCalculator::addition() {
  int rightNum = s.top();
  s.pop();
  int leftNum = s.top();
  s.pop();
  int result =  leftNum + rightNum;
  s.push(result);
}

void postfixCalculator::subtraction() {
  int rightNum = s.top();
  s.pop();
  int leftNum = s.top();
  s.pop();
  int result =  leftNum - rightNum;
  s.push(result);
}


void postfixCalculator::multiplication() {
  int rightNum = s.top();
  s.pop();
  int leftNum = s.top();
  s.pop();
  int result =  leftNum * rightNum;
  s.push(result);
}

void postfixCalculator::division(){
  int rightNum = s.top();
  s.pop();
  int leftNum = s.top();
  s.pop();
  int result =  leftNum / rightNum;
  s.push(result);
}

void postfixCalculator::unaryNegation() {
  int negationNumber = s.top();
  negationNumber *= -1;
  s.pop();
  s.push(negationNumber);
}

