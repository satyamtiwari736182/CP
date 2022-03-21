#include "../header.h"
int getSize(map<string, set<string>> &tree, string mgr, map<string, int> &result)
{
    if (tree.find(mgr) == tree.end())
    {
        result.insert({mgr, 0});
        return 1;
    }
    int sz = 0;
    for (string emp : tree[mgr])
    {
        int count = getSize(tree, emp, result);
        sz += count;
    }
    result.insert({mgr, sz});
    return sz + 1;
}
void findCount(map<string, string> &hashmap)
{
    map<string, set<string>> tree;
    string ceo = "";
    for (auto emps : hashmap)
    {
        string emp = emps.fs;
        string mgr = hashmap[emp];
        if (emp == mgr)
            ceo = mgr;
        else
            tree[mgr].insert(emp);
    }
    map<string, int> count_result;
    getSize(tree, ceo, count_result);

    // for (auto lst : tree)
    // {
    //     cout << lst.first << " -> ";
    //     for (auto st : lst.second)
    //         cout << st << ", ";
    //     cout << endl;
    // }

    for (auto emp_cnt : count_result)
        cout << emp_cnt.fs << " -> " << emp_cnt.se << endl;
    // cout << ceo;
}

int main()
{

    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    map<string, string> hashmap;
    REP(0, n - 1)
    {
        string emp, mgr;
        cin >> emp >> mgr;
        hashmap.insert({emp, mgr});
    }
    cout << "\n============================================\n";
    findCount(hashmap);
    cout << "\n============================================\n";
    return 0;
}

// 6
// A C
// B C
// C F
// D E
// E F
// F F