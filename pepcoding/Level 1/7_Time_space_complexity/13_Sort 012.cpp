// 1. You are given an array(arr) containing only 0's, 1's, and 2's.
// 2. You have to sort the given array in increasing order and in linear time.

#include "../header.h"
void solve(vi &arr){
    int l=0,r=arr.size()-1,idx=0;
    while(idx<r){
        if(arr[idx]==0)swap(arr[l++],arr[idx]);
        else if(arr[idx]==2)swap(arr[r--],arr[idx]);
        else idx++;
    }
}
int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\n==========\n";
    //------------------------------------------------------
    solve(arr);
    for(int x:arr){
        cout<<x<<", ";
    }
}
// 10
// 1
// 0
// 2
// 2
// 1
// 0
// 2
// 1
// 0
// 2