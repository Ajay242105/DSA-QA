/*
Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.



Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 4
0 3 4 7 10 9


Sample Output 1 :
3


Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.


Sample Input 2 :
5 2
4 2 1 3 6


Sample Output 2 :
5


Expected time complexity:
Can you solve this in O(n * log(n)) time complexity?


Constraints :
2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.
*/
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> &arr, int dis, int cow)
{
  int cntCow = 1;
  int cowPlace = arr[0];
  int n = arr.size();
  for (int i = 1; i < n; i++)
  {
    if (arr[i] - cowPlace >= dis)
    {
      cntCow++;
      cowPlace = arr[i];
    }
    if (cntCow >= cow)
      return true;
  }
  return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
  sort(stalls.begin(), stalls.end());
  int n = stalls.size();
  int low = 1;                          // Minimum possible distance between cows
  int high = stalls[n - 1] - stalls[0]; // Maximum possible distance between cows
  int ans = -1;                         // Initialize answer to an invalid value

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (canWePlace(stalls, mid, k))
    {
      ans = mid;
      low = mid + 1; // Try to maximize the distance
    }
    else
    {
      high = mid - 1; // Try to minimize the distance
    }
  }
  return ans;
}
