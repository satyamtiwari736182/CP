// 1. A Professor conducts a Computer Science paper for N students. He had strictly instructed all students to sit according to their roll numbers. However when he started checking the papers, he found out that all the papers were randomly ordered because the students had sat randomly during the exam instead of sitting according to their roll numbers. The order is given in list of integers roll[ ]. The professor became very angry and he wanted to teach the students a lesson.
// 2. He decided to sort the papers according to roll numbers by Bubble Sort and count the number of swaps required for each and every student and deduct as many marks of a student as were the number of swaps required for that student. The marks of every student is given in list of integers marks[ ] in the order in which they were sitting. However he also has to maintain the class average greater than or equal to a set minimum avg, else he may lose his job.
// 3. The Professor wants to know whether he should punish the students or save his job.

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