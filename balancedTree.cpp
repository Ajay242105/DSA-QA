#include <iostream>
#include <cmath>
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

// Function to calculate the height of the tree
int height(node *root)
{
  if (root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

// Function to check if the tree is balanced
bool isBalanced(node *root)
{
  if (root == NULL)
    return true;

  int leftHeight = height(root->left);
  int rightHeight = height(root->right);

  // Check if the current node is balanced and recursively check subtrees
  return (abs(leftHeight - rightHeight) <= 1) &&
         isBalanced(root->left) &&
         isBalanced(root->right);
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->right->left = new node(4);
  root->right->right = new node(5);
  root->right->left->left = new node(6);

  if (isBalanced(root))
    cout << "The tree is balanced." << endl;
  else
    cout << "The tree is not balanced." << endl;

  return 0;
}
