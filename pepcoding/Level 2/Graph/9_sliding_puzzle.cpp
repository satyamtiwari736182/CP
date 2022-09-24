// On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4 directionally adjacent number and swapping it.
// Given the puzzle board, print the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, print -1.

// solved state is : {{1,2,3},{4,5,0}}

#include "../header.h"

int sliding_puzzle(vector<vi> &grid)
{
    queue<string> que;
    string target = "123450";
    string initial_state;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            initial_state = initial_state + to_string(grid[i][j]);
    vector<vi> swapidx = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {4, 2}};

    que.push(initial_state);
    int level = 0;
    set<string> vis_state;

    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            string temp_state = que.front();
            que.pop();

            if (temp_state == target)
                return level;

            int idx = -1;
            for (int i = 0; i < temp_state.size(); i++)
                if (temp_state[i] == '0')
                {
                    idx = i;
                    break;
                }

            vi swapes = swapidx[idx];
            for (int i = 0; i < swapes.size(); i++)
            {
                string temp = temp_state;
                swap(temp[idx], temp[swapes[i]]);
                string new_state = temp;
                if (vis_state.find(new_state) != vis_state.end())
                    continue;

                que.push(new_state);
                vis_state.insert(new_state);
            }
        }
        level++;
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
    cout << sliding_puzzle(grid);
    cout << "\n--------------------------\n";
    pmatrix(grid, n, m);

    return 0;
}

// 2 3
// 4 1 2
// 5 0 3