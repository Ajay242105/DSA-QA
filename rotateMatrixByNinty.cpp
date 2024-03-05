/*
Problem statement
You are given a square matrix ‘Mat’ of size ‘N’. You need to rotate ‘Mat’ by 90 degrees in the clockwise direction.

Note:

You must rotate the matrix in place, i.e., you must modify the given matrix itself. You must not allocate another square matrix for rotation.
For example

When,
‘N’ = 2 and ‘Mat’ = {{1, 2}, {3, 4}}, we must modify ‘Mat’ to {{3, 1}, {4, 2}}.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 100
1 <= Mat[i][j] <= 10^9

Time Limit: 1 sec
*/

#include <vector>

void rotateMatrix(vector<vector<int>> &mat)
{
  int n = mat.size();
  // bruteforce=>tc:0(n2),sc=>0(n2)
  /*
    vector<vector<int>> ans(n,vector<int>(n)); // Initialize ans with the same size as mat

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n - i - 1] = mat[i][j];
        }
    }

    // Copy the rotated matrix back to mat
    mat = ans;
  */

  // better and optimal solution
  // tc=>0(n2)
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      // transposing matrix
      swap(mat[i][j], mat[j][i]);
    }
  }
  // reverse the transpose
  for (int i = 0; i < n; i++)
  {
    reverse(mat[i].begin(), mat[i].end());
  }
}
