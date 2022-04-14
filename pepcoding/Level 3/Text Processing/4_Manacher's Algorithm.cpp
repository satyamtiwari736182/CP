#include "../header.h"

vi Manacher_algo(string str)
{
  int curr_mirr = 0, right = 0;
  vi LPS(str.size()); // longest palindromic sequence found by using mirror concepts.
  for (int i = 1; i < str.length() - 1; i++)
  {
    int left_mirr = curr_mirr - (i - curr_mirr);

    // provide initial kick-start value from known range
    if (i < right)
      LPS[i] = min(LPS[left_mirr], right - i);

    //               left_side == right_side   of mirror
    while (str[i - 1 - LPS[i]] == str[i + LPS[i] + 1])
      LPS[i]++; // increases LPS length and helps in comparision

    // increase your known range
    if (i + LPS[i] > right)
    {
      curr_mirr = i;
      right = i + LPS[i];
    }
  }
  return LPS;
}

string getModified(string str)
{
  string str2 = "@";
  for (int i = 0; i < str.length(); i++)
    str2 = str2 + "#" + str[i];
  str2 = str2 + "#$";
  return str2;
}

void solve()
{
  string str;
  cin >> str;
  string str2 = getModified(str);

  vi lps = Manacher_algo(str2);
  // parr(lps, lps.size());

  int lenth = 0, idx = 0;
  for (int i = 1; i < lps.size(); i++)
  {
    if (lps[i] > lenth)
    {
      lenth = lps[i];
      idx = i;
    }
  }
  int first_idx = idx - lenth + 1;
  int start_idx = (first_idx - 2) / 2;
  cout << start_idx << " " << lenth;
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

// PQPQPQP

// aabaabaa
