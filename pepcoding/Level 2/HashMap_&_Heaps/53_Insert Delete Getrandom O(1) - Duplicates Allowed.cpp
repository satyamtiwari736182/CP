// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

#include "../header.h"
unordered_map<int, unordered_set<int>> hashmap;
vi arr;
bool insert(int val)
{
    int flag = true;
    if (hashmap.count(val) == true)
        flag = false;
    hashmap[val].insert(arr.size());
    arr.pb(val);
    return flag;
}

bool remove(int val)
{
    if (hashmap.count(val) == false)
        return false;
    int temp_idx = *hashmap[val].begin();
    hashmap[val].erase(val);

    swap(arr[temp_idx], arr[arr.size() - 1]);
    arr.pop_back();
    hashmap[arr.back()].insert(arr.size() - 1);
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
