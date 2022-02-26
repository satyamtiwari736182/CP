#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "\n\nhello world\n\n";

    vector<int> vec = {1, 2, 3, 10, 20, 30};
    vector<int>::iterator itr;

    for (itr = vec.begin(); itr < vec.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;

    pair<int, int> pr(56, 7896);
    cout << pr.first << " -> " << pr.second << endl;
    vector<pair<int, int>> vec2={{1,10}};
    cout<<0<<") "<<vec2[0].first<<" -> "<<vec2[0].second;
    cout << "\n\n";
    return 0;
}

// #include <iostream>
// // #include <iterator>
// // #include <vector>
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> ar ;
//     vector<int>::iterator ptr;

//     cout << "The vector elements are : ";
//     for (ptr = ar.begin(); ptr < ar.end(); ptr++)
//         cout << *ptr << " ";

//     return 0;
// }
