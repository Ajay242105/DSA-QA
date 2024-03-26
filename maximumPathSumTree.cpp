#include <iostream>
#include <cmath>
using namespace std;
// tc=0(n)
// sc=0(n)
int maxi = 0;

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

int maxHeight(node *root, int &maxi)
{
  if (root == NULL)
    return 0;
  int lh = max(0, maxHeight(root->left, maxi));
  int rh = max(0, maxHeight(root->right, maxi));
  maxi = max(root->data + lh + rh, maxi);
  return root->data + max(lh, rh);
}

int maxPathSum(node *root)
{
  maxHeight(root, maxi);
  return maxi;
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->right->left = new node(4);
  root->right->right = new node(5);
  root->right->left->left = new node(6);

  cout << "Max Path Sum: " << maxPathSum(root) << endl;

  return 0;
}
