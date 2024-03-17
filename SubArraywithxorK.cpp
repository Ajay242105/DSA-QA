/*
Problem statement
Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.



A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.



Example:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 2
1 2 3 2
Sample Output 1 :
3
Explanation Of Sample Input 1:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
Sample Input 2:
4 3
1 2 3 3
Sample Output 2:
4
Sample Input 3:
5 6
1 3 3 3 5
Sample Output 3:
2
Constraints:
1 <= N <= 10^3
1 <= A[i], B <= 10^9

Time Limit: 1-sec
*/
//
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b)
{
  // int n = a.size();
  // int count = 0;
  // for (int i = 0; i < n; i++) {
  //     int XOR = 0; // Move initialization here
  //     for (int j = i; j < n; j++) {
  //         XOR ^= a[j]; // Accumulate XOR for each subarray
  //         if (XOR == b) {
  //             count++;
  //         }
  //     }
  // }
  // return count;

  // optimal
  // tc=>0(n) or 0(nlogn)=>dependent on map ds
  // sc=0(n)

  int n = a.size();
  int count = 0;
  int xr = 0;
  map<int, int> mpp; // xor,count
  mpp[xr]++;         // for storing 0,1 initially
  for (int i = 0; i < n; i++)
  {
    xr ^= a[i];
    int x = xr ^ b;
    count += mpp[x];
    mpp[xr]++;
  }
  return count;
}
