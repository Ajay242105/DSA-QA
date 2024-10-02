/*
Partition Equal Subset Sum
Difficulty: MediumAccuracy: 30.24%Submissions: 242K+Points: 4
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
N*sum of elements ≤ 5*106


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

bool equalPartition(int N, int arr[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) sum += arr[i];
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    vector<int> arrVec(arr, arr + N); 
    vector<vector<int>> dp(N, vector<int>(target + 1, -1)); 

    return f(N - 1, target, arrVec, dp);
}