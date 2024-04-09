/*
Capacity To Ship Packages Within D Days
Moderate
0/80
Average time to solve is 15m
Contributed by
106 upvotes
Asked in companies
Problem statement
You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.



The weights of the packages are given in an array 'weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.



Find out the least-weight capacity so that you can ship all the packages within 'd' days.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
8 5
5 4 5 2 3 4 5 6
Sample Output 1:
9
Explanation for Sample Input 1:
In the test case, the given weights are [5,4,5,2,3,4,5,6] and these are needed to be shipped in 5 days. We can divide these weights in the following manner:
Day         Weights            Total
1        -   5, 4          -    9
2        -   5, 2          -    7
3        -   3, 4          -    7
4        -   5             -    5
5        -   6             -    6
The least weight capacity needed is 9, which is the total amount of weight that needs to be taken on Day 1.
Sample Input 2:
10 1
1 2 3 4 5 6 7 8 9 10
Sample Output 2:
55
Constraints:
1 <= n <= 10^5
1 <= d <= 10^5
1 <= weights[i] <= 500

Time Limit: 1 sec

*/

int fun(vector<int> &weights, int cap)
{
  int load = 0;
  int day = 1;
  for (int i = 0; i < weights.size(); i++)
  {
    if (weights[i] + load > cap)
    {
      day += 1;
      load = weights[i];
    }
    else
      load += weights[i];
  }
  return day;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
  int low = *max_element(weights.begin(), weights.end());
  int high = accumulate(weights.begin(), weights.end(), 0);
  int ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int no_of_day = fun(weights, mid);
    if (no_of_day <= d)
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
  // Write your code here.
}
