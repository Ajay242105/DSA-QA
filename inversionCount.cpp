/*
Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.

Examples:

Input: n = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: n = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: n = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Expected Time Complexity: O(nLogn).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ n ≤ 5*105
1 ≤ arr[i] ≤ 1018
*/

long long count = 0;

void merge(long long start, long long middle, long long end, long long arr[])
{
  long long i = start;
  long long j = middle + 1;
  long long temp[end - start + 1];
  long long k = 0;

  while (i <= middle && j <= end)
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      count += (middle - i + 1); // Count inversions
    }
  }

  while (i <= middle)
  {
    temp[k++] = arr[i++];
  }

  while (j <= end)
  {
    temp[k++] = arr[j++];
  }

  // Copy the merged array back to original array
  for (i = start, k = 0; i <= end; ++i, ++k)
  {
    arr[i] = temp[k];
  }
}

long long mergeSort(long long start, long long end, long long arr[])
{
  long long inversionCount = 0;

  if (start < end)
  {
    long long middle = (start + end) / 2;
    inversionCount += mergeSort(start, middle, arr);
    inversionCount += mergeSort(middle + 1, end, arr);
    merge(start, middle, end, arr);
  }

  return inversionCount;
}

long long inversionCount(long long arr[], int n)
{
  count = 0; // Reset count before each call
  mergeSort(0, n - 1, arr);
  return count;
}

// Example usage:
}
;