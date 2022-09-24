// 1. You are given an integer N.
// 2. You have to find the N-th number whose binary representation is a palindrome.

// Note -> First binary number whose representation is a palindrome is 1.

#include "../header.h"

int getRev(int n)
{
    int rev = 0;
    while (n != 0)
    {
        int left_bit = (n & 1);
        rev |= left_bit;
        rev <<= 1;
        n >>= 1;
    }
    rev >>= 1;
    return rev;
}

int Nth_PalindromicBinary(int n)
{
    int count_element = 1;
    int len = 1;
    while (count_element < n)
    {
        len++;
        int num_elementsForThis_len = (1 << (len - 1) / 2);
        count_element += num_elementsForThis_len;
    }
    count_element -= (1 << (len - 1) / 2);
    int offset = n - count_element - 1;
    int ans = (1 << len - 1);
    ans |= (offset << (len / 2));
    int value_for_rev = (ans >> (len / 2));
    int rev = getRev(value_for_rev);
    ans |= rev;
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    cout << "\n========================================\n";
    int res = Nth_PalindromicBinary(n);
    bitset<10> val(res);
    cout << res << "\t" << val;
    cout << "\n========================================\n";
    return 0;
}
