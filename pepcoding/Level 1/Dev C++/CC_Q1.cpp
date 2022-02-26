#include<bits/stdc++.h>
using namespace std;
#define REP(a,b) for(int i=a;i<=b;i++)
#define print(arr,l,r) for(int i=l;i<=r;i++) cout<<arr[i]<<" ";
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MAX INT_MAX
#define MIN INT_MIN
#define endl '\n'
#define mod 1000000007
const double PI=3.141592653589793238;

int main(){
	int t=1;
	cin>>t;
	int N[t],R[t];
	REP(0,t-1){
		cin>>N[i];
		int res=1,curr_max=1,max_sofar=1;
		int dp[1000000000];
		if(!dp[N[i]]){
			for(int j=2;j<=N[i];j++)
			{
					res&=j;
					curr_max++;
					if(res<=0) 
					{
						curr_max=1;
						res=j;
					}
					if(max_sofar<curr_max)
						max_sofar=curr_max;
			}
		}
			
		
		R[i]=max_sofar;
		dp[N[i]]=max_sofar;
	}
	
	REP(0,t-1) cout<<R[i]<<endl;
	return 0;
}

