/* Sam Townsend
 * sft3hy
 *testPostfixCalc.cpp
 * 9/20/2020
 */

#include "postfixCalculator.h"
#include <string>
#include <iostream>
using namespace std;


int main() {
  string token;
  postfixCalculator pfc;
  string emptyMessage = "No numbers entered. Please press control-C to quit and then restart.";
  string invalid = "You must enter a valid postfix expression";
  int numCount = 0;
  int opCount = 0;
  
  while(cin >> token) {
    int tokenSize = 0;
    while(token[tokenSize]) {
      tokenSize++;
    }
    if(token == "+") {
      opCount++;
      if(opCount >= numCount && (opCount > 0 && numCount > 0)) {
	cout << invalid << endl;
	return 0;
      }
      if(!pfc.isEmpty()) {
	pfc.addition();
	continue;
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "-" && tokenSize == 1) {
      opCount++;
      if(opCount >= numCount && (opCount > 0 && numCount > 0)) {
	cout << invalid << endl;
	return 0;
      }
      if(!pfc.isEmpty()) {
	pfc.subtraction();
	continue;
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "*") {
      opCount++;
      if(opCount >= numCount && (opCount > 0 && numCount > 0)) {
	cout << invalid << endl;
	return 0;
      }
      if(!pfc.isEmpty()) {
	pfc.multiplication();
	continue;
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "/") {
      opCount++;
      if(opCount >= numCount && (opCount > 0 && numCount > 0)) {
	cout << invalid << endl;
	return 0;
      }
      if(!pfc.isEmpty()) {
	pfc.division();
	continue;
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "~") {
      if(!pfc.isEmpty()) {
	pfc.unaryNegation();
	continue;
      } else {
	cout << emptyMessage << endl;
	break;
      }
    }
    if(tokenSize > 1 && (token.find("-") == 0)) {
      numCount++;
      pfc.s.push(stoi(token));
      continue;
    } else {
      numCount++;
      pfc.s.push(stoi(token));
      continue;
    }
  }
  if(pfc.s.size != 1) {
    cout << invalid <<endl;
    return 0;
  } else {
    cout << pfc.s.top() << endl;
  }
  return 0;
}
