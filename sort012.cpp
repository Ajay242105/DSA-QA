/*
 Problem statement
        You have been given an array /
    list 'arr' consisting of 'n' elements.

    Each element in the array is either 0,
    1 or 2.

             Sort this array /
             list in increasing order.

             Do not make a new array /
             list.Make changes in the given array / list.

                                                    Example : Input : 'arr' = [ 2, 2, 2, 2, 0, 0, 1, 0 ]

    Output : Final 'arr' = [ 0, 0, 0, 1, 2, 2, 2, 2 ]

                           Explanation : The array is sorted in increasing order.Detailed
                                         explanation(Input / output format, Notes, Images)
Sample Input 1 : 8 2 2 2 2 0 0 1 0

    Sample Output 1 : 0 0 0 1 2 2 2 2

    Explanation of sample input 1 : The initial array 'arr' is[2, 2, 2, 2, 0, 0, 1, 0]
                                        .

                                    After sorting the array in increasing order,
    'arr' is equal to : [ 0, 0, 0, 1, 2, 2, 2, 2 ]

                        Sample Input 2 : 5 1 1 1 1 1

                        Sample Output 2 : 1 1 1 1 1

                        Expected time complexity : The expected time complexity is
                                                   O(n)
                                                       .

                                                   Constraints : 1 <= 'n' <= 10 ^
        4 0 <= 'arr[i]' <= 2

            Time limit : 1 second
*/

#include <bits/stdc++.h>
void sortArray(vector<int> &arr, int n)
{
  // Write your code here
  /*
  //brute method
  int c0=0;
  int c1=0;
  int c2=0;
  for(int i=0;i<n;i++){
      if(arr[i]==0){
          c0++;
      }
      else if(arr[i]==1){
          c1++;

      }
      else{
          c2++;
      }
  }
  int i;
  for(i=0;i<c0;i++){
      arr[i]=0;
  }
  for(int i=c0;i<(c0+c1);i++){
     arr[i]=1;
  }
   for(i=c0+c1;i<n;i++){
arr[i]=2;
  }
  */
  // optimal
  int low = 0;
  int left = 0;
  int right = n - 1;
  while (left <= right)
  {
    if (arr[left] == 0)
    {
      swap(arr[low], arr[left]);
      low++;
      left++;
    }
    else if (arr[left] == 1)
    {
      left++;
    }
    else
    {
      swap(arr[left], arr[right]);
      right--;
    }
  }
}
