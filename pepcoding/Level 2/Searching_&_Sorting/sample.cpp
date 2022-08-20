
#include "../header.h"
bool shouldYouPunish(vi &roll, vi &marks, double avg)
{
    int swap_cnt = 0;
    int n = roll.size();

    for (int pass = 0; pass <= n - 2; pass++)
        for (int i = 0; i <= n - pass - 1; i++)
            if (roll[i] > roll[i + 1])
                swap(roll[i], roll[i + 1]), swap_cnt += 2;

    int totalOldMarks = 0;
    for (int val : marks)
        totalOldMarks += val;

    int newTotalMarks = totalOldMarks - swap_cnt;
    double navg = (newTotalMarks * 1.0) / n;

    return navg > avg;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi roll(n), marks(n);
        rarr(roll, 0, n);
        rarr(marks, 0, n);

        double avg;
        cin >> avg;

        cout << "\n============================================\n";
        cout << shouldYouPunish(roll, marks, avg);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
5
3 2 4 1 5
50 67 89 79 58
68
*/