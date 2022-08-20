
#include "header.h"
typedef map<string, priority_queue<string, vector<string>, greater<string>>> grphType;
void dfs(grphType &graph, list<string> &ans, string src)
{
    auto &nbrs = graph[src];
    while (!nbrs.empty())
    {
        string nbr = nbrs.top();
        nbrs.pop();
        dfs(graph, ans, nbr);
    }
    ans.push_front(src);
}

list<string> findItinerary(vector<vector<string>> &tickets)
{
    grphType graph;
    list<string> ans;
    for (auto ticket : tickets)
        graph[ticket[0]].push(ticket[1]);
    dfs(graph, ans, "jfk");
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    vector<vector<string>> tickets;
    int n;
    cin >> n;
    tickets.resize(n);

    for (int i = 0; i < n; i++)
    {
        string src, desti;
        cin >> src >> desti;
        tickets[i].pb(src);
        tickets[i].pb(desti);
    }

    cout << "\n==========================================\n";
    auto lst = findItinerary(tickets);
    for (auto i : lst)
        cout << i << " ";

    cout << "\n==========================================\n";
    return 0;
}

/*

5
jfk sfo
jfk atl
sfo atl
atl jfk
atl sfo

*/