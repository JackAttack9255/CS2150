#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
  root = NULL;
}

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  if(!find(x)) {
    if(root == NULL) {
      root = insert(root, x);
    } else {
      insert(root, x);
    }
  }
}

AVLNode* AVLTree::insert(AVLNode*& n, const string& x) {
  if(n == NULL) {
    AVLNode* newNode = new AVLNode();
    newNode->value = x;
    return newNode;
  }
  if(x < n->value) {
    n->left = insert(n->left, x);
  } else {
    n->right = insert(n->right, x);
  }
  heightCalc(n);
  balance(n);
  return n;
}
  

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
  root = remove(root, x);
}

string AVLTree::pathTo(const string& x) const {
  return pathTo(root, x);
}

string AVLTree::pathTo(AVLNode* n, const string& x) const{
  AVLNode* tmpN = n;
  string path = "";
  if(find(x)) {
    while(tmpN != NULL) {
      if(x == tmpN->value) {
	path += tmpN->value;
	break;
      } else if(x < tmpN->value) {
	path += (tmpN->value + " ");
	tmpN = tmpN->left;
	continue;
      } else {
	path += (tmpN->value + " ");
	tmpN = tmpN->right;
	continue;
      }
    }
  }
  return path;
}


// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  string found = find(root, x);
  if(found == x) {
    return true;
  } else {
    return false;
  }
}

string AVLTree::find(AVLNode* n, const string& x) const{
  if(n == NULL) {
    return "";
  }
  if(x == n->value) {
    return n->value;
  } else if(x < n->value) {
    return find(n->left, x);
  } else if(x > n->value) {
    return find(n->right, x);
  }
  return "";
}


// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes(){
  return numNodes(root);
}

int AVLTree::numNodes(AVLNode*& n) {
  int nodeCount = 1;
  if(n->left != NULL) {
    nodeCount += numNodes(n->left);
  }
  if(n->right != NULL) {
    nodeCount += numNodes(n->right);
  }
  return nodeCount;
}


// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  int bf = balanceFactor(n);
  if(bf == 2) {
    if(balanceFactor(n->right) < 0) {
      rotateRight(n->right);  
    }
    rotateLeft(n);
  } else if(bf == -2) { 
    if(balanceFactor(n->left) > 0) {
      rotateLeft(n->left);
    }
    rotateRight(n);
  }
}

int AVLTree::balanceFactor(AVLNode*& n) {
  return height(n->right) - height(n->left);
}


// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode* tmpN = n;
  AVLNode* tmpNRight = n->right;
  AVLNode* tmpNRightLeft = n->right->left;

  n = tmpNRight;
  n->left = tmpN;
  n->left->right = tmpNRightLeft;

  heightCalc(n->left);
  heightCalc(n);
  
  return n;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  AVLNode* tmpN = n;
  AVLNode* tmpNLeft = n->left;
  AVLNode* tmpNLeftRight = n->left->right;

  n = tmpNLeft;
  n->right = tmpN;
  n->right->left = tmpNLeftRight;
  
  heightCalc(n->right);
  heightCalc(n);
  
  return n;
}

void AVLTree::heightCalc(AVLNode*& n) {
  n->height = (1 + max(height(n->left), height(n->right)));
}


// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }

  // first look for x
  if (x == n->value) {
    // found
    if (n->left == NULL && n->right == NULL) {
      // no children
      delete n;
      n = NULL;
      return NULL;
    } else if (n->left == NULL) {
      // Single child (left)
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    } else if (n->right == NULL) {
      // Single child (right)
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    } else {
      // two children -- tree may become unbalanced after deleting n
      string sr = min(n->right);
      n->value = sr;
      n->right = remove(n->right, sr);
    }
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }

  // Recalculate heights and balance this subtree
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);

  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
  if (p == NULL) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) {
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);

  delete trunk;
}

void AVLTree::printTree() {
  printTree(root, NULL, false);
}
