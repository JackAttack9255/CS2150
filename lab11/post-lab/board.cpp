#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

board::board() {
	zeroPos = -1;
}

board::board(vector<int> vec) {
	v = vec;
}

/*
void board::printBoard(vector<int> vec) {
	for(int i = 0; i < vec.size(); i++) {
		if(i == 3 || i == 6) {
			cout << endl;
		}
		cout << vec.at(i) << " ";
	}
	cout << endl;

}
*/


	

