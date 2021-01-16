/*
 * Sam Townsend
 * 9/28/2020
 * bitCounter.cpp
 * sft3hy
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string outsideStart = "That number is outside the start base";
string invalidBase = "You entered an invalid base";

string baseConverter(string n, int startBase, int endBase) {
  if(startBase < 2 || endBase > 36) {
    return invalidBase;
  }
  if(n == "0") {
    return "0";
  }
  int baseTen = 0;
  int position = n.length() - 1;
  //convert from start base to base ten
  if(startBase != 10) {
    for(int i = 0; i < n.length(); i++) {
      char element = n[i];
      int converted = element - '0' - 7;
      if(converted < 0) {
	converted += 7;
      }
      if(converted > startBase - 1) {
	return outsideStart;
      }
      int value = converted * pow(startBase, position);
      position--;
      baseTen += value;
    }
  } else if(startBase == 10) {
    for(int z = 0; z < n.length(); z++) {
      char el = n[z];
      if(!isdigit(el)) {
	return outsideStart;
      }
    }
    baseTen = stoi(n);
  }
  //convert from base ten to end base
  string endString = "";
  string baseTenString = to_string(baseTen);
  for(int j = 0; j < baseTenString.length(); j++) {
    while(baseTen > 0) {
      int remainder = baseTen%endBase;
      baseTen /= endBase;
      if(remainder > 9) {
	int asciiNum = remainder + '0' + 7;
	char letterRemainder  = asciiNum;
	endString += letterRemainder;
	continue;
      } else {
	endString += to_string(remainder);
      }
    }
  }
  char swapper;
  for(int k = 0; k < endString.length() / 2; k++) {
    swapper = endString[k];
    endString[k] = endString[endString.length() - k - 1];
    endString[endString.length() - k - 1] = swapper;
  }
  return endString;
}

int bitCounter(int n) {
  if(n == 0) {
    return 0;
  } else if(n == 1) {
    return 1;
  } else if(n%2 == 0) {
    return bitCounter(n/2.0);
  } else if(n%2 == 1) {
    return bitCounter(n/2) + 1;
  } else {
    return 0;
  }
}

int main(int argc, char **argv) {
  if(argv[1] ==  NULL || argv[2] == NULL || argv[3] == NULL) {
    cout << "Please enter command line parameters" << endl;
    return 0;
  } else {

    int argOneInt = atoi(argv[1]);
    string argOneString = argv[1];

    string argTwoString = argv[2];
    
    int sBase = atoi(argv[3]);
    int eBase = atoi(argv[4]);

    string converted = baseConverter(argTwoString, sBase, eBase);

    cout << argOneString + " has " + to_string(bitCounter(argOneInt)) + " bit(s)" << endl;
    if(converted != outsideStart && converted != invalidBase) {
      cout << argTwoString + " (base " + to_string(sBase) + ") = " + converted +  " (base " + to_string(eBase) + ")" << endl;
    } else {
      if(converted == outsideStart) {
	cout << outsideStart << endl;
      } else if(converted == invalidBase) {
	cout << invalidBase << endl;
      }
    }
    return 0;
  }
}
