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
	dp[n] = fibm(n-1,dp) + fibm(n-2,dp);
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

int fact(int n,int *dp){
	if(n==1) {
		dp[n]=1;
		return dp[n];
	}
	if(dp[n]) return dp[n];
	dp[n]=n*fact(n-1,dp);
	return dp[n];
}

//DP - Memoization
int getStair(int n,int *dp){
	if(n<0) return 0;
	if(n==0) {
		dp[n]=1;
		return dp[n];
	};
	if(dp[n]!=0) return dp[n];
	dp[n]=getStair(n-1,dp) + getStair(n-2,dp) + getStair(n-3,dp);
	return dp[n];
}

//DP-Tabulation
int getStairt(int n,int *dp){
	for(int i=0;i<=n;i++){
		if(i==0 || i==1)dp[i]=1;
		else if(i<=2) dp[i]=dp[i-1]+dp[i-2];
		else dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	vector<int> fibo;
	cout<<"hello!"<<endl;
	int arr[27]={0};
	fibm(20,arr);
	print(arr,0,24);
//	cout<<endl<<getStair(4,arr)<<endl;
//	print(arr,0,10);
	return 0;
}

