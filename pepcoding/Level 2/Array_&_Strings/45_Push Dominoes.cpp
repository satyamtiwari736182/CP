// 1. There are n dominoes in a line, and we place each domino vertically upright.
// 2. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
// 3. After each second, each domino that is falling to the left pushes the adjacent domino on the left.
// 4. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
// 5. When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
// 6. For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
// 7. You are given a string dominoes representing the initial state where:
//     a). dominoes[i] = 'L', if the ith domino has been pushed to the left,
//     b). dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//     c). dominoes[i] = '.', if the ith domino has not been pushed.
// 8. Return a string representing the final state.

#include "../header.h"

void solveConfiguration(string &arr, int i, int j)
{
    if (arr[i] == 'L' && arr[j] == 'L')
        // make all dots ar L
        for (int k = i + 1; k < j; k++)
            arr[k] = 'L';
    else if (arr[i] == 'R' && arr[j] == 'R')
        // make all dots ar R
        for (int k = i + 1; k < j; k++)
            arr[k] = 'R';
    else if (arr[i] == 'L' && arr[j] == 'R')
        // nothing to do
        ;
    else
    {
        int diff = j - i, mid = (i + j) / 2;
        if (diff % 2 == 0) // odd dots;
        {
            for (int k = i + 1; k < mid; k++)
                arr[k] = 'R';
            for (int k = mid + 1; k < j; k++)
                arr[k] = 'L';
        }
        else // even dots;
        {
            for (int k = i + 1; k <= mid; k++)
                arr[k] = 'R';
            for (int k = mid + 1; k < j; k++)
                arr[k] = 'L';
        }
    }
}

string pushDominoes(string str)
{
    int n = str.length();
    string charArr = "";
    charArr += 'L';
    for (int i = 1; i < n + 1; i++)
        charArr += str[i - 1];
    charArr += 'R';
    int j = 0, k = 1;

    while (k < charArr.length())
    {
        while (charArr[k] == '.')
            k++;
        if (k - j > 1)
            solveConfiguration(charArr, j, k);
        j = k, k++;
    }

    charArr.pop_back();
    // charArr.pop_back();
    return charArr.substr(1);
}

void solve()
{
    string str;
    cin >> str;
    cout << "--------------------" << endl;
    cout << pushDominoes(str);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*
L.L.R....LR...L.RR
*/

// RR.L