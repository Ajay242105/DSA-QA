#include <iostream>
#include <vector>
#include <stack>
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
// left,root,right
vector<int> inOrderTraversal(node *root)
{
  vector<int> inOrder;
  node *rt = root;
  stack<node *> st;
  while (true)
  {
    if (rt != NULL)
    {
      st.push(rt);
      rt = rt->left;
    }
    else
    {
      if (st.empty())
        break;
      rt = st.top();
      st.pop();
      inOrder.push_back(rt->data);
      rt = rt->right;
    }
  }
  return inOrder;
}

int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);

  vector<int> result = preOrderTraversal(root);
  vector<int> result2 = inOrderTraversal(root);

  cout << "Preorder traversal:" << endl;
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << "\nInorder traversal:" << endl;

  for (int i = 0; i < result2.size(); i++)
  {
    cout << result2[i] << " ";
  }
  return 0;
}
