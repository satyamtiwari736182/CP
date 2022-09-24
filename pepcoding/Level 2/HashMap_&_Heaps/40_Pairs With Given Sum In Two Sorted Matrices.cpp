// 1. You are given a number N and two sorted matrices(A and B) of N*N dimensions.
// 2. You are also given a number X.
// 3. You have to find the count of all valid pairs from matrices whose sum is equal to X.
// 4. A pair is called valid if one element of the pair is selected from A and the second element is selected from B.



#include "../header.h"

int solve(vector<vi> &matrix1, vector<vi> &matrix2, int x)
{
    int count = 0;
    map<int, int> hashmap;
    for (vi row : matrix2)
        for (int val : row)
            hashmap[val]++;

    for (vi row : matrix1)
        for (int val : row)
            if (hashmap.count(x - val))
                count++;

    return count;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n, x;
        cin >> n;
        vector<vi> matrix1(n), matrix2(n);
        rvmatrix(matrix1, n, n);
        rvmatrix(matrix2, n, n);
        cin >> x;

        cout << "\n============================================\n";
        cout << solve(matrix1, matrix2, x);

        cout << "\n============================================\n";
    }

    return 0;
}

// 1

// 3
// 1 5 6
// 8 10 11
// 15 16 18

// 2 4 7
// 9 10 12
// 13 16 20
// 21
