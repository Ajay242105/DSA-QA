/*

Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


Example 1:

Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()
Example 2:
Input:
N = 1
Output:
()

Your Task:
You don't need to read input or print anything. Complete the function AllParenthesis() which takes N as input parameter and returns the list of balanced parenthesis.

Expected Time Complexity: O(2N * N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

Constraints:
1 ≤ N ≤ 12

*/

class Solution
{
private:
  vector<string> ans;
  vector<char> parenthesis;

  void recursion(int index, int l, int sum)
  {
    // Base case
    if (index == l)
    {
      if (sum == 0)
      {
        string result = "";
        for (int i = 0; i < parenthesis.size(); i++)
        {
          result += parenthesis[i];
        }
        ans.push_back(result);
      }
      return;
    }

    // Recursive case
    if (l > sum / 2)
    {
      // Opening bracket
      parenthesis.push_back('(');
      recursion(index + 1, l, sum + 1);
      parenthesis.pop_back();
    }
    if (sum > 0)
    {
      // Closing bracket
      parenthesis.push_back(')');
      recursion(index + 1, l, sum - 1);
      parenthesis.pop_back();
    }
  }

public:
  vector<string> AllParenthesis(int n)
  {
    ans.clear();
    parenthesis.clear();
    recursion(0, 2 * n, 0);
    return ans;
  }
};