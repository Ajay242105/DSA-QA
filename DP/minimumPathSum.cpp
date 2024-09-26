/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/

class Solution {
public:
//--------recursion solution---------------
// int f(int row,int col,vector<vector<int>>& grid){
//     if(row==0 && col==0)return grid[row][col];
//     if(row<0 || col<0)return 1e9;
    
//     int up=grid[row][col]+f(row-1,col,grid);
//     int left=grid[row][col]+f(row,col-1,grid);
//     return min(up,left);


// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return f(m-1,n-1,grid);
        
//     }
// //---------------memoization dp--------------
// int f(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&dp){
//     if(row==0 && col==0)return grid[row][col];
//     if(row<0 || col<0)return 1e9;
//     if(dp[row][col]!=-1)return dp[row][col];
    
//     int up=grid[row][col]+f(row-1,col,grid,dp);
//     int left=grid[row][col]+f(row,col-1,grid,dp);
//     return dp[row][col]=min(up,left);


// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));

//         return f(m-1,n-1,grid,dp);
        
//     }

//---------------Tabulization dp--------------
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 1e9;
                int left = (j > 0) ? dp[i][j - 1] : 1e9;

                dp[i][j] = grid[i][j] + min(left, up);
            }
        }
    }

    return dp[m - 1][n - 1];
}
};