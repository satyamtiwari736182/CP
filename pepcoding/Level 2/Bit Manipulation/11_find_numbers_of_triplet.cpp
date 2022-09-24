// 1. You are given an array(arr) of N numbers.
// 2. You have to select three indices i,j,k following this condition -> 
//       0 <= i < j <= k < arr.length
// 3. Two numbers X and Y as defined as :
//       X = arr[i] ^ arr[i+1] ^ ... ^ arr[j - 1]
//       Y = arr[j] ^ arr[j+1] ^ ... ^ arr[k]
// 4. You have to print the number of triplets where X is equal to Y.


#include "../header.h"

int sol(vi arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = arr[i];
        for (int k = i + 1; k < arr.size(); k++)
        {
            val = val ^ arr[k];
            if (val == 0)
                count += (k - i);
        }
    }
    return count;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vi arr;
    rvarr(arr, 0, n);

    cout << "\n========================================\n";
    cout << sol(arr);
    cout << "\n========================================\n";
    return 0;
}
// 10
// 1 3 2 5 7 2 7 5 6 4


