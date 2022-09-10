// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: x==y or x!=y. Here x and y represents lowercase letters.

#include "../header.h"

int parent[26];
int ranks[26];
int findParent(int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent[x]);
    parent[x] = temp;
    return temp;
}

bool Union(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);

    if (px != py)
    {
        if (ranks[px] > ranks[py])
            parent[py] = px;
        else if (ranks[px] < ranks[py])
            parent[px] = py;
        else
            parent[px] = py, ranks[py]++;

        return true;
    }
    return false;
}

bool equationsPossible(vs &equations)
{
    for (string eqn : equations)
        if (eqn[1] == '=')
            Union(eqn[0] - 'a', eqn[3] - 'a');

    for (string eqn : equations)
    {
        if (eqn[1] == '!')
        {
            int lx = findParent(eqn[0] - 'a');
            int ly = findParent(eqn[3] - 'a');
            if (lx == ly)
                return false;
        }
    }

    return true;
}

int main()
{
    cout << "\nHello world!" << endl;
    for (int i = 0; i < 26; i++)
        parent[i] = i, ranks[i] = 1;

    int n;
    cin >> n;
    vs str(n);
    rarr(str, 0, n);

    cout << "\n==========================================\n";
    cout << equationsPossible(str);
    cout << "\n==========================================\n";
    return 0;
}

/*

2
b==c
c!=b

*/
