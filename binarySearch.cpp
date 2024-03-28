/*
 Binary Search
Easy
0/40
Average time to solve is 15m
Contributed by
841 upvotes
Asked in companies
Problem statement
You are given an integer array 'A' of size 'N', sorted in non-decreasing order. You are also given an integer 'target'.



Your task is to write a function to search for 'target' in the array 'A'. If it exists, return its index in 0-based indexing. If 'target' is not present in the array 'A', return -1.



Note:

You must write an algorithm whose time complexity is O(LogN)


Example:


Input: ‘N’ = 7 ‘target’ = 3
‘A’ = [1, 3, 7, 9, 11, 12, 45]

Output: 1

Explanation: A = [1, 3, 7, 9, 11, 12, 45],
The index of element '3' is 1.
Hence, the answer is '1'.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5
1 <= A[i] <= 10^9
1 <= target <= 10^9
Time Limit: 1 sec
Sample Input 1:
7
1 3 7 9 11 12 45
3
Sample Output 1:
1
Explanation of sample output 1:
nums = [1, 3, 7, 9, 11, 12, 45],
The index of element '3' is 1.
Hence, the answer is '1'.


Sample Input 2:
7
1 2 3 4 5 6 7
9
Sample Output 2:
-1
Explanation of sample output 2:
nums = [1, 2, 3, 4, 5, 6, 7],
Element '9' doesn't exist.
Hence, the answer is '-1'.

*/
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums, int left, int right, int target)
{
  if (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
      return mid;
    else if (target < nums[mid])
      return binarySearch(nums, left, mid - 1, target);
    else
      return binarySearch(nums, mid + 1, right, target);
  }
  return -1; // return -1 if the element is not found
}

int search(vector<int> &nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  return binarySearch(nums, left, right, target);
}
