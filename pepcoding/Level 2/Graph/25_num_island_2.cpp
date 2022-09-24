// Given an m*n matrix mat, Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid mat[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size K.


#include "header.h"

int findParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp;
    return temp;
}

bool Union(int *rank, int *parent, int x, int y)
{
    int px = findParent(parent, x);
    int py = findParent(parent, y);

    if (px != py)
    {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else
        {
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
    return false;
}

int num_of_island_II(int m, int n, vector<vi> &position)
{
    vi ans;
    int dirs[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int *parent=new int[m * n];
    int *rank=new int[m * n];

    fill(rank, rank + m * n, 0);
    fill(parent, parent + m * n, -1);

    int count = 0;

    for (int i = 0; i < position.size(); i++)
    {
        int row = position[i][0];
        int col = position[i][1];

        int cell_num = row * n + col;

        if (parent[cell_num] != -1)
        {
            ans.push_back(count);
            continue;
        }

        parent[cell_num] = cell_num;
        rank[cell_num] = 1;
        count++;

        for (auto dir : dirs)
        {
            int rowdash = row + dir[0];
            int coldash = col + dir[1];
            int celldash = rowdash * n + coldash;

            if (rowdash < 0 || coldash < 0 || rowdash >= m || coldash >= n || parent[celldash] == -1)
                continue;

            bool merged = Union(rank, parent, cell_num, celldash);
            if (merged)
                count--;
        }
        ans.pb(count);
    }

    for (int i : ans)
        cout << i << " ";
    return 0;
}

int main()
{
    cout << "\nHello world!" << endl;

    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> pos;
    pos.resize(q);

    for (int i = 0; i < q; i++)
    {
        int row, col;
        cin >> row >> col;
        pos[i].push_back(row);
        pos[i].push_back(col);
    }

    cout << "\n==========================================\n";
    num_of_island_II(n, m, pos);
    cout << "\n==========================================\n";
    return 0;
}

/*
3 5 7
0 3
1 2
0 2
1 4
2 3
1 3
1 2

*/