/*Problem statement
You are given an array 'a' of 'n' integers.



A majority element in the array ‘a’ is an element that appears more than 'n' / 2 times.



Find the majority element of the array.



It is guaranteed that the array 'a' always has a majority element.



Example:
Input: ‘n’ = 9, ‘a’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

Output: 1

Explanation: The frequency of ‘1’ is 5, which is greater than 9 / 2.
Hence ‘1’ is the majority element.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
9
2 2 1 3 1 1 3 1 1


Sample Output 1:
1


Explanation Of Sample Input 1:
Input: ‘n’ = 9, ‘a’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

Output: 1

Explanation: The frequency of ‘1’ is 5, which is greater than 9 / 2.
Hence ‘1’ is the majority element.


Sample Input 2:
1
4


Sample Output 2:
4


Sample Input 3:
5
-53 75 56 56 56


Sample Output 3:
56


Expected time complexity :
The expected time complexity is O(n).


Constraints :
1 <= 'n' <= 10000
0 <= 'arr[i]' <= 10^9

Time limit: 1 second*/

#include <bits/stdc++.h>
int majorityElement(vector<int> v)
{
  // Write your code here

  /*
//brute
        int n=v.size();

  for(int i=0;i<n;i++){
      int count =0;

for(int j=0;j<n;j++){
  if(v[i]==v[j])count++;
}
if(count>n/2){
    return v[i];
  }
  }
  */

  /*
  //better sol->0(nlogn)
  map<int,int>mpp;
  for(int i=0;i<v.size();i++){
    mpp[v[i]]++;
  }
  for(auto it:mpp){
    if(it.second>v.size()/2){
      return it.first;
    }
  }
  return -1;
  */

  // optimal solution->0(n)
  int el;
  int count = 0;
  for (int i = 0; i < v.size(); i++)
  {
    if (count == 0)
    {
      count = 1;
      el = v[i];
    }
    else if (v[i] == el)
      count++;
    else
    {
      count--;
    }
  }
  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] == el)
      count++;
  }
  if (count > v.size() / 2)
  {
    return el;
  }
}