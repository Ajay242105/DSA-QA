/*
Single Element in a Sorted Array
Easy
0/40
Average time to solve is 15m
Contributed by
227 upvotes
Asked in companies
Problem statement
You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.



Return the number that appears once.



Example:
Input: 'arr' = [1,1,2,2,4,5,5]

Output: 4

Explanation:
Number 4 only appears once the array.


Note :
Exactly one number in the array 'arr' appears once.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
5
1 1 3 5 5


Sample Output 1 :
3


Explanation of Sample Input 1 :
Given array is [1, 1, 3, 5, 5]
Here, 3 occurs once in the array. So, the answer is 3.


Sample Input 2 :
5
1 1 4 4 15


Sample Output 2 :
15


Explanation of Sample Input 2 :
The array is [1, 1, 4, 4, 15].
Here, 15 occurs once in the array. So, the answer is 15.


Expected Time Complexity:
Try to solve this in O(log(n)).


Constraints :
1 <= n <= 10^5
0 <= arr[i] <= 10^9

Time Limit: 1 sec


*/
int singleNonDuplicate(vector<int> &arr)
{
  // Write your code here
  int n = arr.size();
  if (n == 1)
    return arr[0]; // for single element
  if (arr[0] != arr[1])
    return arr[0]; // checking first element
  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];
  int low = 1;
  int high = n - 2;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
      return arr[mid];
    if ((mid % 2 == 1 && arr[mid - 1] == arr[mid]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
      low = mid + 1; // eliminate left half
    else
      high = mid - 1; // eliminate right half
  }
  return -1;
}