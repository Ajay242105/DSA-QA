// better solution=>0(n2)

/*
Problem statement
You are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or jth column of the matrix is 0.

Note:

1) The number of rows should be at least 1.

2) The number of columns should be at least 1.

3) For example, refer to the below matrix illustration:

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 100
1 <= M <= 100
-10^9 <= MATRIX[i][j] <= 10^9

Where 'MATRIX[i][j]' denotes the matrix element.
Follow Up:

Can you solve it with the space complexity of O(1)?

Time limit: 1 sec
*/

#include <bits/stdc++.h>
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
  { // Write your code here.
    int row[n] = {0};
    int col[m] = {0};

    for (int i = 0; i < n; i++)
    {

      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j] == 0)
        {
          row[i] = 1;
          col[j] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (row[i] || col[j] == 1)
        {

          matrix[i][j] = 0;
        }
      }
    }
    return matrix;
  }
}