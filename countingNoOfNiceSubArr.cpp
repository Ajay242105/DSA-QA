/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.



Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16


Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

*/

class Solution
{
public:
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int n = nums.size();
    int left = 0;
    int count = 0;
    int count_odd_right = 0;
    int result = 0;

    for (int right = 0; right < n; ++right)
    {
      if (nums[right] % 2 == 1)
      {
        ++count;
        count_odd_right = 0; // Reset count_odd_right when encountering a new odd number
      }

      while (count == k)
      {
        ++count_odd_right;
        if (nums[left++] % 2 == 1)
        {
          --count;
        }
      }

      result += count_odd_right;
    }

    return result;
  }
};