#include<bits/stdc++.h>
using namespace std;
#define REP(a,b) for(int i=a;i<=b;i++)
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

// Recursion
int fib(int n){
	if(n==0 || n==1) return n;
	return fib(n-1) + fib(n-2);
}

//DP - Memoization
int fibm(int n,int *dp){
	if(n==0 || n==1) {
		dp[n]=n;
		return dp[n] ;	
	}
	if(dp[n] != 0) return dp[n];
	dp[n] = fib(n-1,dp) + fib(n-2,dp);
	return dp[n];
}

//DP-Tabulation
void fibt(int n,int *dp){
	dp[0]=0,dp[1]=1;
	for(int i=0;i<n;i++){
		if(i==0 || i==1) dp[i]=i;
		else
			dp[i]=dp[i-1]+dp[i-2];	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> fibo;
	cout<<"hello!"<<endl;
	int arr[25]={0};
	fibt(20,arr);
	print(arr,0,24);
	return 0;
}

