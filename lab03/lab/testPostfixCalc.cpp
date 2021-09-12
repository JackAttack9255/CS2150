/* Sam Townsend
 * sft3hy
 *testPostfixCalc.cpp
 * 9/20/2020
 */

#include "postfixCalculator.h"
#include <stack>
#include <string>
#include <iostream>
using namespace std;


int main() {
  string token;
  postfixCalculator pfc;
  string emptyMessage = "No numbers entered. Please press control-C to quit and then restart.";
  
  while(cin >> token) {
    
    if(token.length() > 1 && token.find("-")) {
      pfc.s.push(stoi(token));	
      continue;
    } else if(token == "+") {
      if(!pfc.isEmpty()) {
	pfc.addition();
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "-") {
      if(!pfc.isEmpty()) {
	pfc.subtraction();
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "*") {
      if(!pfc.isEmpty()) {
	pfc.multiplication();
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "/") {
      if(!pfc.isEmpty()) {
	pfc.division();
      } else {
	cout << emptyMessage << endl;
	break;
      }
    } else if(token == "~") {
      if(!pfc.isEmpty()) {
	pfc.unaryNegation();
      } else {
	cout << emptyMessage << endl;
	break;
      }
    }
    else {
      pfc.s.push(stoi(token));	
    }
  }
  if(pfc.s.size() != 1) {
    cout << "Please enter a valid postfix expression." <<endl;
  } else {
    cout << pfc.s.top() << endl;
  }
  return 0;
}
