/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.



Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]


Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100
*/
#include <vector>
#include <string>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution
{
private:
  void binaryTreePathsHelper(TreeNode *root, string path, vector<string> &result)
  {
    if (root == nullptr)
      return;

    // Append current node's value to the path
    path += to_string(root->val);

    // If it's a leaf node, add the path to the result
    if (root->left == nullptr && root->right == nullptr)
    {
      result.push_back(path);
      return;
    }

    // Recur for left and right subtrees
    binaryTreePathsHelper(root->left, path + "->", result);
    binaryTreePathsHelper(root->right, path + "->", result);
  }

public:
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> result;
    if (root == nullptr)
      return result;

    binaryTreePathsHelper(root, "", result);
    return result;
  }
};
