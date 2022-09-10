// https://leetcode.com/problems/insert-delete-getrandom-o1/


#include "../header.h"
unordered_map<int, int> hashmap;
vi arr;
bool insert(int val)
{
    if (hashmap.count(val)==true)
        return false;
    hashmap[val] = arr.size();
    arr.pb(val);
    return true;
}

bool remove(int val)
{
    if (hashmap.count(val) == false)
        return false;
    int temp_idx = hashmap[val];
    hashmap.erase(val);
    swap(arr[temp_idx], arr[arr.size() - 1]);
    arr.pop_back();
    hashmap[arr.back()] = arr.size() - 1;
    return true;
}

int getRandom()
{
    int random_idx = rand() % arr.size();
    return arr[random_idx];
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {

        cout << "\n============================================\n";

        cout << "\n============================================\n";
    }

    return 0;
}
