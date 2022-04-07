// 1. You are provided with marks of N students in Physics, Chemistry and Maths.
// Perform the following 3 operations:
// a). Sort the students in Ascending order of their Physics marks.
// b). Once this is done, sort the students having same marks in Physics in the descending order of their Chemistry marks.
// c). Once this is also done, sort the students having same marks in Physics and Chemistry in the ascending order of their Maths marks.

#include "../header.h"

class Marks
{
public:
    Marks(int pp, int cc, int mm) : p(pp), c(cc), m(mm) {}
    int p, c, m;
};

bool comp(Marks stud1, Marks stud2)
{
    if (stud1.p != stud2.p)
        return stud1.p < stud2.p;
    else if (stud1.c != stud2.c)
        return stud1.c > stud2.c;
    else
        return stud1.m < stud2.m;
}

int solve(vector<vi> &arr)
{
    vector<Marks> marks;

    for (int i = 0; i < arr[0].size(); i++)
        marks.pb(Marks(arr[0][i], arr[1][i], arr[2][i]));

    sort(all(marks), comp);

    for (Marks stud : marks)
        cout << stud.p << " " << stud.c << " " << stud.m << endl;

    return 0;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vi> arr(3);
        rvmatrix(arr, 3, n);
        cout << "\n============================================\n";
        solve(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 10
// 14 1 10 3 4 2 1 10 1 11
// 5 12 9 6 3 10 2 9 14 10
// 12 3 6 5 2 10 16 32 10 4