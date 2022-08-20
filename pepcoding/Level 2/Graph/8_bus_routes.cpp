#include "../header.h"

int num_buses_to_destination(vector<vi> &routes, int src, int desti)
{
    map<int, vi> buses_from_stop;
    for (int i = 0; i < routes.size(); i++)
        for (int j = 0; j < routes[0].size(); j++)
        {
            int busStop = routes[i][j];
            int bus = i;
            buses_from_stop[busStop].push_back(bus);
        }

    queue<int> que; // travelled path.Let's take decesion after Reaching the bus stop
    set<int> bus_stop_vis, bus_vis;
    int number_buses = 0;

    que.push(src);
    bus_stop_vis.insert(src);

    while (!que.empty())
    {
        int size = que.size();

        while (size--)
        {
            int temp = que.front();
            que.pop();

            if (temp == desti)
                return number_buses;

            vi buses_to_bored = buses_from_stop[temp];

            for (int bus_chosen : buses_to_bored)
            {
                if (bus_vis.find(bus_chosen) != bus_vis.end())
                    continue;

                vi bus_stops = routes[bus_chosen];
                for (auto stops : bus_stops)
                {
                    if (bus_stop_vis.find(stops) != bus_stop_vis.end())
                        continue;

                    que.push(stops);
                    bus_stop_vis.insert(stops);
                }
                bus_vis.insert(bus_chosen);
            }
        }
        number_buses++;
    }

    return -1;
}

int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    cout << num_buses_to_destination(grid, 1, 5) << endl;
    pmatrix(grid, n, m);

    return 0;
}

// 4 3
// 1 2 3
// 1 4 5
// 5 8 7
// 3 6 7
