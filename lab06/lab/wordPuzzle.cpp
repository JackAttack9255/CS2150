/*
 * Sam Townsend
 * sft3hy
 * wordPuzzle.cpp
 * 10/8/2020
 */
#include "HashTable.h"
#include "timer.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;

    // then the columns
    file >> cols;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}



int main(int argc, char *argv[]) {
  HashTable tester = HashTable();

  timer tim;
  // try to open the file
  ifstream file(argv[1]);
  // upon an error, return false
  if (!file.is_open()) {
    return -1;
  }

  string data;  
  while(file >> data) {
    tester.insert(data);
  }

  file.close();
  
  // to hold the number of rows and cols in the input file
  int rows, cols;

  // attempt to read in the file
  bool result = readInGrid(argv[2], rows, cols);
  // if there is an error, report it
  if (!result) {
    cout << "Error reading in file!" << endl;
    return 1;
  }

  // Get a word (of length 10), starting at position (2,2) in the
  // array, in each of the 8 directions

  string prevWord = "";

  int prevDir = -1;

  int foundCount = 0;

  string dir = "";
  
  tim.start();
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++){
      for (int d = 0; d < 8; d++) {
	for(int l = 3; l <= 22; l++) {
	  string w = getWordInGrid(r, c, d, l, rows, cols);
	  if(prevDir == d && prevWord == w) {
	    break;
	  } else {
	    prevWord = w;
	    if(w.length() > 2) {
	      if(tester.find(w)) {
		foundCount++;
		if(d == 0) {
		  dir = "N ";
		} else if(d == 1) {
		  dir = "NE";
		} else if(d == 2) {
		  dir = "E ";
		} else if(d == 3) {
		  dir = "SE";
		} else if(d == 4) {
		  dir = "S ";
		} else if(d == 5) {
		  dir = "SW";
		} else if(d == 6) {
		  dir = "W ";
		} else if(d == 7) {
		  dir = "NW";
		}
		//cout << dir + "(" + to_string(r) + ", " + to_string(c) + "):	" + w << endl;
		prevDir = d;
	      }
	    }
	  }
	}
      }
    }
  }
  tim.stop();
  cout << to_string(foundCount) + " words found" << endl;
  
  //cout <<"Found all words in " + to_string(tim.getTime()) + " seconds" << endl;
  int out = 1000*tim.getTime();
  //cout << out << endl;
  return 0;
}

