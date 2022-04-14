// 1. You are given two strings s1 and s2.
// 2. s1 represents a text and s2 represents a pattern. 
// 3. You have to print the starting index for all occurrences of the pattern in the given text string.


#include "../header.h"

vi z_func(string str) // longest substring which is also a proper prefix starting from that idx of substring.
{
  int i = 1, lenth = 0, left = 0, right = 0; // i dosen't backtrack.It keeps on moving forward
  vi z_value(str.length());                  // uses dp-like approarch to find z_fnc() of the string.

  for (int i = 1; i < str.length(); i++)
  {

    // provide initial kick-start value from known range
    if (i <= right)
      z_value[i] = min(right - i + 1, z_value[i - left]);

    //        proper_pefix == substring
    while (str[z_value[i]] == str[i + z_value[i]])
      z_value[i]++; // increases prefix and substring and helps in comparision

    // increase your known range
    if (i + z_value[i] - 1 > right)
    {
      left = i;
      right = i + z_value[i] - 1;
    }
  }

  return z_value;
}

vi Z_algo(string text, string patt)
{
  string str = patt + "#" + text;
  int n = patt.length();
  vi z_values = z_func(str);
  vi ans;
  for (int i = 0; i < z_values.size(); i++)
    if (z_values[i] == n)
      ans.pb(i - n - 1);
  return ans;
}

void solve()
{
  string str, patt;
  cin >> str >> patt;
  vi res = Z_algo(str, patt);
  parr(res, res.size());
}

int main()
{
  cout << "\nHello world!" << endl;
  int t = 1;
  cin >> t;
  test(t)
  {
    solve();
    cout << "\n------------------------------\n";
  }

  return 0;
}

// 2

// abab
// ab

// aabaabaab
// aab