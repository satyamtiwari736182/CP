
#include "../header.h"

vector<vi> ftree, arr;

void getInputs()
{

    int n, m;
    cin >> n >> m;
    arr.resize(n + 1);
    arr[0].resize(m + 1);
    ftree.resize(n + 1);
    ftree[0].resize(m + 1);
    for (int i = 1; i <= n; i++)
    {
        arr[i].resize(m + 1);
        ftree[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    }
}

void update_2D_ftree(Point pt, int val)
{
    int xdash = pt.x;
    while (xdash < ftree.size())
    {
        int ydash = pt.y;
        while (ydash < ftree[0].size())
        {
            ftree[xdash][ydash] += val;
            ydash += ydash & -ydash;
        }
        xdash += xdash & -xdash;
    }
}

void build_2D_ftree()
{
    for (int i = 1; i < arr.size(); i++)
        for (int j = 1; j < arr[0].size(); j++)
            update_2D_ftree(Point(i, j), arr[i][j]);
}

int query_2D_ftree(Point pt)
{
    int sum = 0;
    int xdash = pt.x;
    while (xdash > 0)
    {
        int ydash = pt.y;
        while (ydash > 0)
        {
            sum += ftree[xdash][ydash];
            ydash -= ydash & -ydash;
        }
        xdash -= xdash & -xdash;
    }
    return sum;
}

int find_sum(Point p1, Point p2)
{
    int ans = query_2D_ftree(p2) - query_2D_ftree(Point(p1.x - 1, p2.y)) - query_2D_ftree(Point(p2.x, p1.y - 1)) + query_2D_ftree(Point(p1.x - 1, p1.y - 1));

    return ans;
}

void solve()
{
    getInputs();

    build_2D_ftree();

    //------Query-----
    int q;
    cin >> q;
    test(q)
    {
        char type;
        cin >> type;
        if (type == 'q')
        {
            Point p1 = getCoordinates();
            Point p2 = getCoordinates();
            int ans = find_sum(p1, p2);
            cout << ans << "  **\n";
        }
        else if (type == 'u')
        {
            Point pt = getCoordinates();
            int val;
            cin >> val;
            int delta = -ftree[pt.x][pt.y] + val;
            update_2D_ftree(pt, delta);
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }
    // pmatrix(ftree, ftree.size(), ftree[0].size());
    return 0;
}

// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 4
// q 1 1 2 2
// q 1 2 3 3
// u 2 2 50
// q 2 1 3 2

//*********************

// 6 6
// 1 2 3 4 5 6
// 6 5 4 3 2 1
// 1 2 3 4 5 6
// 6 5 4 3 2 1
// 1 2 3 4 5 6
// 6 5 4 3 2 1