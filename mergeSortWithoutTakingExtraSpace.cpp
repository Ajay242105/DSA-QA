/*
Problem statement
Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.



You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.



Note:
You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
For example:
When ‘N’ = 4, ‘A’ = {1, 4, 5, 7} and ‘M’ = 3, ‘B’ = {2, 3, 6}.
We can merge these two arrays into {1, 2, 3, 4, 5, 6, 7} (The elements of ‘A’ are {1, 2, 3, 4} ).
Hence, the answer is {1, 2, 3, 4, 5, 6, 7}.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3 4
1 8 8
2 3 4 5
Sample Output 1:
1 2 3 4 5 8 8
Explanation Of Sample Input 1:
We have ‘A’ = {1, 8, 8} and ‘B’ = {2, 3, 4, 5}.
Merging the two arrays results in {1, 2, 3, 4, 5, 8, 8}.
Hence the answer is {1, 2, 3, 4, 5, 8, 8}, where ‘A’ contains {1, 2, 3} and ‘B’ contains {4, 5, 8, 8}.
Sample Input 2:
4 5
1 1 1 1
2 2 3 3 5
Sample Output 2:
1 1 1 1 2 2 3 3 5
Constraints:
1 <= N <= 10^5
1 <= M <= 10^5
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9

The sum of ‘N + M’ over all test cases does not exceed 2 * 10^5.
Time Limit: 1-sec
*/

#include <vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
  int n = a.size();
  int m = b.size();
  int left = n - 1;
  int right = 0;
  while (left >= 0)
  {
    if (a[left] > b[right])
    {
      swap(a[left], b[right]);
      left--;
      right++;
    }
    else
    {
      break;
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  // Write your code here.
}