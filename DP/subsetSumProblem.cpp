/*
Subset Sum Problem
Difficulty: MediumAccuracy: 32.0%Submissions: 267K+Points: 4
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Examples:

Input: n = 6, arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: 1 
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.
Input: n = 6, arr[] = {3, 34, 4, 12, 5, 2} , sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise. The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.

Expected Time Complexity: O(sum*n)
Expected Auxiliary Space: O(sum*n)

Constraints:
1 <= n <= 100
1<= arr[i] <= 100
1<= sum <= 104


*/

bool f(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = f(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = f(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken || taken;
}
bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1)); 

    return f(n - 1, sum, arr, dp);
}