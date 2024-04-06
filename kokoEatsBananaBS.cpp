/*
Koko Eating Bananas
Moderate
0/80
Average time to solve is 25m
Contributed by
137 upvotes
Asked in company
Problem statement
A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.



Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.



Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.



Example:

Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7

Output: 3

Explanation: If ‘m’ = 3, then
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 2 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 3 hour.
Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
7 15 6 3
8

Sample Output 1:
5


Explanation Of Sample Input 1:
Input: ‘n’ = 4, ‘a’ = [7, 15, 6, 3], ‘h’ = 8

Output: 5

Explanation: If ‘m’ = 5, then
The time taken to empty the 1st pile is 2 hour.
The time taken to empty the 2nd pile is 3 hour.
The time taken to empty the 3rd pile is 2 hour.
The time taken to empty the 4th pile is 1 hour.
Therefore a total of 8 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 8 hours.


Sample Input 2:
5
25 12 8 14 19
5


Sample Output 2:
25


Explanation Of Sample Input 2:
Input: ‘n’ = 5, ‘a’ = [25,12,8,14,19], ‘h’ = 5

Output: 25

Explanation: If ‘m’ = 25,
The time taken to empty the 1st pile is 1 hour.
The time taken to empty the 2nd pile is 1 hour.
The time taken to empty the 3rd pile is 1 hour.
The time taken to empty the 4th pile is 1 hour.
The time taken to empty the 5th pile is 1 hour.
Therefore a total of 5 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 5 hours.


Expected Time Complexity:
Try to solve the problem in O(log n).


Constraints:
1 <= n <= 10^4
1 <= a[i] <= 10^9
n <= h <= 10^9

Time Limit: 1 sec
*/
#include <bits/stdc++.h>
// function for finding max element in array
int findMax(vector<int> &v)
{
  int maxi = INT_MIN;
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, v[i]);
  }
  return maxi;
}
// finding total hour taking the piles
int calculateTotalHour(vector<int> v, int mid)
{
  int tHour = 0;
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    tHour += ceil(double(v[i]) / double(mid));
  }
  return tHour;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
  // Write Your Code Here
  // int ans=MAX_INT;
  int low = 1;
  int high = findMax(v);
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int totalhour = calculateTotalHour(v, mid);
    if (totalhour <= h)
    {
      // ans=mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return low;
}