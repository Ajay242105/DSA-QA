/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  bool isSymmetric(TreeNode *root)
  {
    // Check if the tree is empty or a single node
    if (root == NULL)
      return true;

    return isSymmetricHelp(root->left, root->right);
  }

  bool isSymmetricHelp(TreeNode *left, TreeNode *right)
  {
    // If both nodes are null, they are symmetric
    if (left == NULL && right == NULL)
      return true;

    // If one of the nodes is null but the other isn't, they are not symmetric
    if (left == NULL || right == NULL)
      return false;

    // If the values of the nodes are not equal, they are not symmetric
    if (left->val != right->val)
      return false;

    // Recursively check if the subtrees are symmetric
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
  }
};
