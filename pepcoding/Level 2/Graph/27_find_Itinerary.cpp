// https://leetcode.com/problems/reconstruct-itinerary/

#include "../header.h"

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
    {
        // priority_queue<string, vector<string>, greater<string>> temp;
        // temp.push(ticket[1]);
        // if (graph.find(ticket[0]) != graph.end())
        graph[ticket[0]].push(ticket[1]);
        // else
        //     graph[ticket[0]] = temp;
    }

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

    // priority_queue<string, vector<string>, greater<string>> pque;
    // for (int i = 0; i < n; i++)
    // {
    //     string str;
    //     cin >> str;
    //     pque.push(str);
    // }
    cout << "\n==========================================\n";
    auto lst = findItinerary(tickets);
    // cout << lst.size();
    for (auto i : lst)
        cout << i << " ";
    // while (!pque.empty())
    // {
    //     cout << pque.top() << " ";
    //     pque.pop();
    // }
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