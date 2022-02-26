#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(i=a;i<=b;i++)
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


int maxgold(int gold[N][M],int i,int j,int n,int m){	
	if(i<0 || j<0 || i>n || j>m) return 0;
	if(j==m) return gold[i][j];
	return gold[i][j] + max(maxgold(gold,i-1,j+1,n,m),max(maxgold(gold,i,j+1,n,m),maxgold(gold,i+1,j+1,n,m)));	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout<<"hello!"<<endl;
	
	int i=0,j=0,n,m;cin>>n>>m;
	int arr[N][M],dp[N][M];
	memset(dp,0,sizeof(dp));
	REP2(i,0,n-1) REP2(j,0,m-1) cin>>arr[i][j];
	
	cout<<endl;
	for(int k=0;k<n;k++)cout<<maxgold(arr,k,0,n-1,m-1)<<" ";

	
	// Minimum cost while travelling from left to right corner with right and down move.
	/*int i=1,j=1,n,m;cin>>n>>m;
	int arr[n+1][m+1]; REP(i,1,n) REP(j,1,m) cin>>arr[i][j];
	int dp[n+1][m+1];
	
	for(int r=n;r>0;r--){
		for(int c=m;c>0;c--){
			if(r==n && c==m) dp[r][c]=arr[r][c];
			else if(c==m) dp[r][c] = arr[r][c] + dp[r+1][c];
			else if(r==n) dp[r][c] = arr[r][c] + dp[r][c+1];
			else dp[r][c] = arr[r][c] + min( dp[r+1][c] , dp[r][c+1] );	
		}
	}
	
	cout<<endl<<dp[1][1]<<endl;
	
	REP(i,1,n) {
		REP(j,1,m) cout<<dp[i][j]<<" ";
		cout<<endl;
	}
*/

	
	return 0;
}

