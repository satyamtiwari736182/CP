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

    // proper_pefix == substring
    while (str[z_value[i]] == str[i + z_value[i]])
      z_value[i]++; // increases prefix and substring and helps in comparision

    // increase your known range
    if (i + z_value[i] - 1 > right)
      left = i, right = i + z_value[i] - 1;
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

// 2

// abab
// ab

// aabaabaab
// aab

/*
ll poly_hash(string str)
{
  ll p = 31, pow = 31;
  ll hash_value = str[0] - 'a' + 1;
  for (int i = 1; i < str.length(); i++)
  {
    hash_value = (hash_value + (str[i] - 'a' + 1) * pow) % mod;
    pow = (pow * p) % mod;
  }
  return hash_value;
}

// void get_prefix_hash() {}

vi rabin_karp_algo(string str, string patt)
{
  ll patt_hash = poly_hash(patt);

  // preprocessing
  vector<ll> prefix_hash(str.length()), pow_i(str.length()); // for str, to get hash in O(1) time
  prefix_hash[0] = str[0] - 'a' + 1;
  pow_i[0] = 1;
  int p = 31;
  ll pow = p;

  for (int i = 1; i < str.length(); i++)
  {
    prefix_hash[i] = (prefix_hash[i - 1] + (str[i] - 'a' + 1) * pow) % mod;
    pow_i[i] = pow;
    pow = (pow * p) % mod;
  }

  // Rabin-karp
  // finding patt in str using sliding window and hash string
  vi ans;
  int i = 0, j = patt.length() - 1;

  while (j < str.length())
  {
    ll window_hash = prefix_hash[j];
    ll new_patt_hash = (patt_hash * pow_i[i]) % mod;

    if (i > 0)
      window_hash = (prefix_hash[j] - prefix_hash[i - 1] + mod) % mod;

    if (window_hash == new_patt_hash)
      ans.pb(i);

    i++;
    j++;
    // cout << window_hash << " " << new_patt_hash << ",  ";
  }
  cout << endl;
  return ans;
}

void solve()
{
  string str, patt;
  cin >> str >> patt;
  vi ans = rabin_karp_algo(str, patt);
  parr(ans, ans.size());
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

// 3
// ababab ab
// aaaaa bbb
// aafafaasf aaf
*/