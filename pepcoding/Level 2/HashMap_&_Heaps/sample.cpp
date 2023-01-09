/*
1. You are given number N and 2*N number of strings that contains mapping of the employee and his manager.
2. An employee directly reports to only one manager.
3. All managers are employees but the reverse is not true.
4. An employee reporting to himself is the CEO of the company.
5. You have to find the number of employees under each manager in the hierarchy not just their direct reports.
*/

#include "../header.h"
int getSize(map<string, set<string>> &tree, string node, map<string, int> &result)
{
    if (tree.find(node) == tree.end())
    {
        result[node] = 0;
        return 1;
    }

    int cnt = 0;
    for (string chld : tree[node])
        cnt += getSize(tree, chld, result);

    result[node] = cnt;
    return cnt + 1;
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
    for (int i = 0; i < n; i++)
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