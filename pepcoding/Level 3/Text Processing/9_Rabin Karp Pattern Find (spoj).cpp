// https://www.spoj.com/problems/NAJPF/

#include "../header.h"

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
