/*
 * Sam Townsend
 * 9/30/2020
 * sft3hy
 * TreeCalc.cpp
 */
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree != NULL) {
    cleanTree(tree->left);
    cleanTree(tree->right);
    delete tree;
  }
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  // insert a value into the tree
  TreeNode* t = new TreeNode();
  t->value = val;
  if(val != "+" && val != "-" && val != "*" && val != "/") {
    expressionStack.push(t);
  } else {
    TreeNode* rightChild = expressionStack.top();
    expressionStack.pop();
    TreeNode* leftChild = expressionStack.top();
    expressionStack.pop();
    t->left = leftChild;
    t->right = rightChild;
    expressionStack.push(t);
  }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
  // print the tree in prefix format
  if(tree != NULL) {
    cout << tree->value + " ";
    printPrefix(tree->left);
    printPrefix(tree->right);
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
  // print tree in infix format with appropriate parentheses
  if(tree != NULL){
    bool op = false;
    if(tree->value == "+" || tree->value == "-" || tree->value == "/" || tree->value == "*") {
      op = true;
    }
    if (op){
      cout << "(";
    }
    printInfix (tree->left);
    if(op) {
      cout << " ";
    }
    cout << tree->value;
    if(op) {
      cout << " ";
    }
    printInfix (tree->right);
    if(op) {
      cout << ")";
    }
  }
}


//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
  // print the tree in postfix form
  if(tree != NULL) {
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout << tree->value + " ";
  }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}


// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) {
  // Traverse the tree and calculates the result
  if(tree != NULL) {
    calculate(tree->left);
    calculate(tree->right);
    bool op = false;
    if(tree->value == "+" || tree->value == "-" || tree->value == "/" || tree->value == "*") {
      op = true;
    }
    if(op) {
      string rator = tree->value;
      int rightNum = stoi(expressionStack.top()->value);
      expressionStack.pop();
      int leftNum = stoi(expressionStack.top()->value);
      expressionStack.pop();
      
      if(rator == "+") {
	tree->value = to_string(leftNum + rightNum);
	expressionStack.push(tree);
      } else if(rator == "-") {
	tree->value =  to_string(leftNum - rightNum);
	expressionStack.push(tree);
      } else if(rator == "*") {
	tree->value =  to_string(leftNum * rightNum);
	expressionStack.push(tree);
      } else if(rator == "/") {
	tree->value =  to_string(leftNum / rightNum);
	expressionStack.push(tree);
      }
    } else {
      expressionStack.push(tree);
    }
    return stoi(expressionStack.top()->value);
  }
  return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  // call private calculate method here
  int answer = calculate(expressionStack.top());
  expressionStack.pop();
  return answer;
}
