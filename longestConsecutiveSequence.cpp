/*
Problem statement
There is an integer array ‘A’ of size ‘N’.

A sequence is successive when the adjacent elements of the sequence have a difference of 1.

You must return the length of the longest successive sequence.

Note:

You can reorder the array to form a sequence.
For example,

Input:
A = [5, 8, 3, 2, 1, 4], N = 6
Output:
5
Explanation:
The resultant sequence can be 1, 2, 3, 4, 5.
The length of the sequence is 5.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
1 <= A[i] <= 10^9
Time Limit: 1 sec

*/
int longestSuccessiveElements(vector<int> &a)
{
  // Write your code here.
  int n = a.size();
  int longest = 1;

  int count = 0;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
  {
    st.insert(a[i]);
  }
  for (auto it : st)
  { // iterating set element
    if (st.find(it - 1) == st.end())
    {
      count = 1;
      int x = it;
      while (st.find(x + 1) != st.end())
      {
        x = x + 1;
        count = count + 1;
      }
      longest = max(longest, count);
    }
  }
  return longest;
}