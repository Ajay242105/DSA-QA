#include <iostream>
#include <cmath>
using namespace std;

// tc=0(n)
// sc=0(n)//Auxilary space

int diameter = 0;

struct node
{
  int data;
  struct node *left;
  struct node *right;
  node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

int maxHeight(node *root, int &diameter)
{
  if (root == NULL)
    return 0;
  int lh = maxHeight(root->left, diameter);
  int rh = maxHeight(root->right, diameter);
  diameter = max(lh + rh, diameter);
  return 1 + max(lh, rh);
}

int diameterTree(node *root)
{
  maxHeight(root, diameter);
  return diameter;
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->right->left = new node(4);
  root->right->right = new node(5);
  root->right->left->left = new node(6);

  cout << "Diameter: " << diameterTree(root) << endl;
}
