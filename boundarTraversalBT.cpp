bool isLeaf(Node *node)
{
  return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

void addLeftBoundary(Node *root, vector<int> &res)
{
  Node *cur = root->left;
  while (cur)
  {
    if (!isLeaf(cur))
      res.push_back(cur->data);

    // If left child exists, go left, else go right
    if (cur->left)
      cur = cur->left;
    else
      cur = cur->right;
  }
}

void addRightBoundary(Node *root, vector<int> &res)
{
  Node *cur = root->right;
  vector<int> temp;
  while (cur)
  {
    if (!isLeaf(cur))
      temp.push_back(cur->data);

    // If right child exists, go right, else go left
    if (cur->right)
      cur = cur->right;
    else
      cur = cur->left;
  }

  // Add the values in reverse order to maintain the right boundary order
  for (int i = temp.size() - 1; i >= 0; --i)
  {
    res.push_back(temp[i]);
  }
}

void addLeaves(Node *root, vector<int> &res)
{
  if (isLeaf(root))
  {
    res.push_back(root->data);
    return;
  }
  if (root->left)
    addLeaves(root->left, res);
  if (root->right)
    addLeaves(root->right, res);
}

class Solution
{
public:
  vector<int> boundary(Node *root)
  {
    vector<int> res;
    if (root == nullptr)
      return res;

    if (!isLeaf(root))
      res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
  }
};
