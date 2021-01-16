#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
using namespace std;


class board {
public:
	board();
	board(vector<int> vec);
	vector<int> v;
	//void printBoard(vector<int> vec);
	int zeroPos;
	vector<int> canSwapWithIndexes;
	int indegree;
	vector<board> neighbors;
	vector<int> generateCanSwapWithIndexes(board& b);
};

#endif