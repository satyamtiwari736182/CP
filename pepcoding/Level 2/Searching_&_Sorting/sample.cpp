#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> memo;
int find_Sol(int input1, int input2, int input3)
{
    if (input1 == 1)
    {
        return input3 - input2 + 1;
    }
    string key = to_string(input1) + "" + to_string(input2) + "" + to_string(input3);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }
    int count = 0;
    for (int c = input2; c <= input3; c++)
    {
        count += find_Sol(input1 - 1, c, input3);
    }
    count += find_Sol(input1 - 1, input2, input3);
    memo[key] = count;
    return count;
}
// int find_Sol(int input1, int input2, int input3)
// {
//     if (input1 == 1)
//         return input3 - input2 + 1;

//     string key = to_string(input1) + "" + to_string(input2) + "" + to_string(input3);

//     if (memo.find(key) != memo.end())
//         return memo[key];

//     int count = 0;
//     for (int c = input2; c <= input3; c++)
//         count += find_Sol(input1 - 1, c, input3);

//     count += find_Sol(input1, input2, input3 - 1);
//     memo[key] = count;
//     return count;
// }

int main()
{
    int x = 1;
    int a = 4;
    int b = 5;
    int count = find_Sol(x, a, b);
    cout << count << endl;
    return 0;
}