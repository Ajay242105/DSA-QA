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

//for n/3
/*
Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.

A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.

Note: The floor function returns the number rounded down to the nearest integer.

Note: Return the array of majority elements in sorted order.

Example:
Input: ‘N’ = 9 ‘A’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

Output: 1

Explanation: The frequency of ‘1’ is 5, which is greater than floor(N / 3), hence ‘1’ is the majority element.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 1e3
-1e9 <= A[i] <= 1e9

Time Limit: 1-sec
Sample Input 1:
6
1 1 1 2 2 2
Sample Output 1:
1 2
Explanation Of Sample Input 1:
Input: ‘N’ = 6, ‘A’ = [1, 1, 1, 2, 2, 2]

Output: [1, 2]

Explanation: The frequency of ‘1’ and ‘2’ is 3, which is greater than floor(N / 3), hence ‘1’ & ‘2’ are the majority elements.
Sample Input 2:
1
4
Sample Output 2:
4

*/

// solution
/*
#include<bits/stdc++.h>>
vector<int> majorityElement(vector<int> v) {

    //better solution=>tc=0(n),sc=0(n)
    // int n = v.size();
    // unordered_map<int, int> arr;
    // vector<int> ls;
    // for (int i = 0; i < n; i++) {
    //     int min = int(n / 3) + 1;

    //     arr[v[i]]++;
    //     if (arr[v[i]] == min) {
    //         ls.push_back(v[i]);
    //     }
    //     if (ls.size() == 2) {
    //         break;
    //     }
    // }
    // sort(ls.begin(), ls.end());
    // return ls;
//optimal
    int cnt1=0;
    int cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 && el2!=v[i]){
            cnt1=1;
            el1=v[i];
        }
        else if(cnt2==0 && el1!=v[i]){
            cnt2=1;
            el2=v[i];
        }
        else if(v[i] == el1)
        {

             cnt1++;

         }
        else if(v[i] == el2)
        {
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }


    }
    vector<int>temp;
     cnt1=0;cnt2=0;
     int mini=int(n/3)+1;

     for(int i=0;i<n;i++){
         if(el1==v[i])cnt1++;
         if(el2==v[i])cnt2++;



     }
     if(cnt1 >=mini)temp.push_back(el1);
    if(cnt2 >=mini)temp.push_back(el2);
    sort(temp.begin(),temp.end());

    return temp;






}


*/
