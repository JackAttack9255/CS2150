#include <iostream>
#include <string>
using namespace std;

int main() {
	float pointsMissed, labsGraded, desiredGrade, neededExamGrade, projectedCurve;
	cout << "Points Missed?" << endl;
	cin >> pointsMissed;
	cout << "Labs Graded" << endl;
	cin >> labsGraded;
	cout << "Desired Grade?" << endl;
	cin >> desiredGrade;
	cout << "Projected Curve?" << endl;
	cin >> projectedCurve;
	double grade = (((labsGraded*30) - pointsMissed)/(labsGraded*30))*70;
	neededExamGrade = desiredGrade - grade - projectedCurve;
	cout << "Your lab average is a " + to_string(grade) + " out of 70" << endl;
	cout << "(That's a " << grade/70.0 << "%)" << endl;
	cout << "You need a " + to_string(neededExamGrade) + " out of 30 on the exam to achieve your grade goal." << endl;
	cout << "(That's a " + to_string((neededExamGrade/30)*100) + "%)" << endl;
}