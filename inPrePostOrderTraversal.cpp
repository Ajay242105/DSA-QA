#include <iostream>
using namespace std;

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

// Preorder Traversal
void preOrder(node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

// Inorder Traversal
void inOrder(node *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

// Postorder Traversal
void postOrder(node *root)
{
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->right = new node(5);

  cout << "Preorder: ";
  preOrder(root);
  cout << endl
       << "Inorder: ";
  inOrder(root);
  cout << endl
       << "Postorder: ";
  postOrder(root);

  return 0;
}
