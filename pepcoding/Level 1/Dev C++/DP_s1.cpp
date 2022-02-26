#include<bits/stdc++.h>
using namespace std;
#define REP(a,b) for(int i=a;i<=b;i++)
#define REP2(i,a,b) for(i=a;i<=b;i++)
#define print(arr,l,r) for(int i=l;i<=r;i++) cout<<arr[i]<<" ";
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define pi pair<int,int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI=3.141592653589793238;
const int M=100,N=100;

//6
//6
//0 1 4 2 8 2
//4 3 6 5 0 4
//1 2 4 1 4 6
//2 0 7 3 2 2
//3 1 5 9 2 4
//2 7 0 8 5 1

int mincost(int arr[][M],int n,int m,int dp[][M]){
	if(n<0 || m<0) return INT_MAX;
	if(n==0 && m==0) return arr[n][m];
	if(dp[n][m]!=0) return dp[n][m];
	dp[n][m] = arr[n][m]+min(mincost(arr,n-1,m,dp),mincost(arr,n,m-1,dp));
	return dp[n][m];
}  
   
int maxgold(int gold[N][M],int i,int j,int n,int m){	
	if(i<0 || j<0 || i>n || j>m) return 0;
	if(j==m) return gold[i][j];
	return gold[i][j] + max(maxgold(gold,i-1,j+1,n,m),max(maxgold(gold,i,j+1,n,m),maxgold(gold,i+1,j+1,n,m)));	
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int i=0,j=0,n,m;cin>>n>>m;
	int arr[N][M],dp[N][M];
	memset(dp,0,sizeof(dp));
	REP2(i,0,n-1) REP2(j,0,m-1) cin>>arr[i][j];
	
	/*cout<<mincost(arr,n,m,dp);
	cout<<"\t"<<dp[n-1][m-1]<<endl<<endl;

	REP2(i,0,n-1){
		REP2(j,0,m-1) cout<<dp[i][j]<<" ";
		cout<<endl;
	}*/


	cout<<endl;
	for(int k=0;k<n;k++)cout<<maxgold(arr,k,0,n-1,m-1,bag)<<" ";

	cout<<endl<<"hello!"<<endl;
	return 0;
}

