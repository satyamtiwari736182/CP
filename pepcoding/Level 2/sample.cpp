#include "./header.h"

// #define ONLINE_JUDGE 
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first+p.second);
        return h1;
    }
};
void solve()
{
    long t,n,x,y;
    cin>>t;
    while(t-->0){
        long res=0,e;
        cin>>n>>x>>y;
        unordered_map<pair<long,long>,long,pair_hash>mp;
        for(int i=0;i<n;i++){
            cin>>e;
            res+=mp[{(x-e%x)%x,e%y}];
            mp[{e%x,e%y}]++;            
        }
        cout<<res<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);                    
    cout.tie(NULL);
    cin.tie(NULL); 
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    solve();
    return 0;
}