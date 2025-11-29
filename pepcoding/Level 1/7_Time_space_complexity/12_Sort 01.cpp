// 1. You are given an array(arr) containing only 0's and 1's.
// 2. You have to sort the given array in increasing order and in linear time.
#include "../header.h"
void solve(vi &arr){
    int l=0,r=arr.size()-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0)swap(arr[i],arr[l++]);
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
        cout<<x<<endl;
    }
}
// 5
// 0
// 1
// 0
// 1
// 0