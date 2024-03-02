/*
Problem statement
There is an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.

Without altering the relative order of positive and negative numbers, you must return an array of alternative positive and negative values.

Note:

Start the array with a positive number.
For example

Input:
A = [1, 2, -4, -5], N = 4
Output:
1 -4  2 -5
Explanation:
Positive elements = 1, 2
Negative elements = -4, -5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
2 <= N <= 10^5
-10^9 <= A[i] <= 10^9, A[i] != 0
N%2==0

Time Limit: 1 sec
Sample Input 1:
6
1 2 -3 -1 -2 3
Sample Output 1:
1 -3 2 -1 3 -2
Explanation Of Sample Input 1:
Testcase 1:
Input:
A = [1, 2, -3, -1, -2, 3], N = 6
Output:
1 -3 2 -1 3 -2
Explanation:
Positive elements = 1, 2, 3
Negative elements = -3, -1, -2
To maintain relative ordering, 1 should come before 2, and 2 must come before 3.
Also, -3 should come before -1, and -1 must come before -2.
Sample Input 2:
4
-2 -3 4 5
Sample Output 2:
4 -2 5 -3
*/

vector<int> alternateNumbers(vector<int> &a)
{
  // Write your code here.
  int n = a.size();
  vector<int> temp(n, 0);
  int posIndex = 0;
  int negIndex = 1;
  for (int i = 0; i < n; i++)
  {
    if (a[i] < 0)
    {

      temp[negIndex] = a[i];
      negIndex += 2;
    }
    else
    {
      temp[posIndex] = a[i];
      posIndex += 2;
    }
  }
  return temp;
}