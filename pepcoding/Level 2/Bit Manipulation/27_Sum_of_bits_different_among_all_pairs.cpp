#include "../header.h"

unsigned long sol(vi arr)
{
    unsigned long res = 0;
    for (unsigned long i = 0; i < 31; i++) // number of bits
    {
        unsigned long countONbit = 0;
        // Num of elements whose bits arer on at index i;  {Binary index from right ot left indexing order}
        for (unsigned long val : arr)
        {
            unsigned long mask = 1 << i;

            if (val & mask)
                ++countONbit;
        }

        unsigned long countOFFbit = arr.size() - countONbit;
        unsigned long numDiff_bits = countONbit * countOFFbit * 2;
        // sum of num of different bits made BY ALL possible pairs of element;
        res += numDiff_bits;
    }
    return res;
}
int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vi arr;
    rvarr(arr, 0, n);
    cout << "\n"
         << arr.size();
    cout << "\n========================================\n";
    cout << sol(arr);
    cout << "\n========================================\n";
    return 0;
}
// 5
// 4 8 9 15 16