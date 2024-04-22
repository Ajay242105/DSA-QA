/*
Rohan has a special love for the matrices especially for the first element of the matrix. Being good at Mathematics, he also loves to solve the different problem on the matrices. So one day he started to multiply the matrix with the original matrix.  The elements of the original matrix a are given by [a00=1 , a01=1, a10=1, a11=0].
Given the power of the matrix, n calculate the an and return the a10 element mod 1000000007.

Example 1:

Input:
n = 3
Output:
2
Explanation: Take the cube of the original matrix
i.e a3 and the (a10)th element is 2.
Example 2:

Input:
n = 4
Output:
3
Explanation: Take the cube of the original matrix
i.e a4 and the (a10)th element is 3.
Your Task:
You dont need to read input or print anything. Complete the function firstElement() which takes n as input parameter and returns the a10 element mod 1000000007 of an.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<= n <=106
*/
class Solution
{
public:
  int firstElement(int n)
  {
    // code here
    const int MOD = 1000000007;
    if (n <= 0)
      return 0;

    int a00 = 1, a01 = 1, a10 = 1, a11 = 0;
    int b00 = 1, b01 = 1, b10 = 1, b11 = 0;

    for (int i = 2; i <= n; ++i)
    {
      int temp00 = (a00 * b00 + a01 * b10) % MOD;
      int temp01 = (a00 * b01 + a01 * b11) % MOD;
      int temp10 = (a10 * b00 + a11 * b10) % MOD;
      int temp11 = (a10 * b01 + a11 * b11) % MOD;

      a00 = temp00;
      a01 = temp01;
      a10 = temp10;
      a11 = temp11;
    }

    return a10;
  }
};