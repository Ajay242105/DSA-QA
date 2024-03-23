// maxDepth of tree using recursive
#include <iostream>
using namespace std;
// tc=0(n)
// sc=0(n)
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
int maxDepth(node *root)
{
  if (root == NULL)
    return 0;
  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);
  return 1 + max(lh, rh);
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->right->left = new node(4);
  root->right->right = new node(5);
  root->right->left->left = new node(6);

  int depth = maxDepth(root);
  cout << "Max Depth of the tree is: " << depth << endl;

  return 0;
}
