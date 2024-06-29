/*
Possible Words From Phone Digits
Difficulty: MediumAccuracy: 52.79%Submissions: 60K+Points: 4
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.


Example 1:

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi
bdg bdh bdi beg beh bei bfg bfh bfi
cdg cdh cdi ceg ceh cei cfg cfh cfi
Explanation: When we press 2,3,4 then
adg, adh, adi, ... cfi are the list of
possible words.
Example 2:

Input: N = 3, a[] = {3, 4, 5}
Output:
dgj dgk dgl dhj dhk dhl dij dik dil
egj egk egl ehj ehk ehl eij eik eil
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then
dgj, dgk, dgl, ... fil are the list of
possible words.
Your Task:
You don't need to read input or print anything. You just need to complete the function possibleWords() that takes an array a[ ] and N as input parameters and returns an array of all the possible words in lexicographical increasing order.

Expected Time Complexity: O(4N * N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10
2 ≤ a[i] ≤ 9
*/

class Solution
{
public:
  vector<string> ans;
  vector<char> currentSeq;
  map<char, vector<char>> m = {
      {'2', {'a', 'b', 'c'}},
      {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}},
      {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}},
      {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}},
      {'9', {'w', 'x', 'y', 'z'}}};

  void recursion(int index, string digit)
  {
    // base case
    if (index == digit.size())
    {
      string result = "";
      for (int i = 0; i < currentSeq.size(); i++)
      {
        result += currentSeq[i];
      }
      if (result.length() > 0)
      {
        ans.push_back(result);
      }
      return;
    }

    // recursive case
    char currentChar = digit[index];
    for (auto value : m[currentChar])
    {
      currentSeq.push_back(value);
      recursion(index + 1, digit);
      currentSeq.pop_back();
    }
  }

  vector<string> possibleWords(int a[], int N)
  {
    string digit = "";
    for (int i = 0; i < N; i++)
    {
      digit += to_string(a[i]);
    }
    recursion(0, digit);
    return ans;
  }
};