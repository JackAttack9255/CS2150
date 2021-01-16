/* Sam Townsend
 * sft3hy
 * postfixCalculator.cpp
 * 9/20/2020
 */

#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "Stack.h"
using namespace std;

postfixCalculator::postfixCalculator() {
  s = Stack();
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
  if(rightNum == 0) {
    cout << "Error: Division by 0" << endl;
  } else {
    s.pop();
    int leftNum = s.top();
    s.pop();
    int result =  leftNum / rightNum;
    s.push(result);
  }
}

void postfixCalculator::unaryNegation() {
  int negationNumber = s.top();
  negationNumber *= -1;
  s.pop();
  s.push(negationNumber);
}

