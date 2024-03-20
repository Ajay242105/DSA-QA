#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
tc=>0(n)
SC=>0(n)
*/
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

vector<int> preOrderTraversal(node *root)
{
  vector<int> preOrder;
  if (root == NULL)
    return preOrder;
  stack<node *> st;
  st.push(root);
  while (!st.empty())
  {
    root = st.top();
    st.pop();
    preOrder.push_back(root->data);
    if (root->right != NULL)
    {
      st.push(root->right);
    }
    if (root->left != NULL)
    {
      st.push(root->left);
    }
  }
  return preOrder;
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(7);

  vector<int> result = preOrderTraversal(root);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}
