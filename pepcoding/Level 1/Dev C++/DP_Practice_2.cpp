
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

int fiboR(int n,int *arr){
	if(n==0 || n==1)
		return n;
	return fiboR(n-1,arr) + fiboR(n-2,arr);	
}

int fiboT(int n,int *arr){
	arr[0]=0;arr[1]=1;
	for(int i=2;i<n;i++)
		arr[i] = arr[i-1] + arr[n-2];
	return arr[n];
}

int fiboM(int n,int *arr){
	// 0 1 1 2 3 5 8 13 21
	if(n==0 || n==1) {
		arr[n]=n;
		return arr[n];
	}
	if(arr[n]!=0) return arr[n];
    arr[n]=fiboM(n-1,arr) + fiboM(n-2,arr);
	return arr[n];
}
//---------------------------------------------------

int getstairM(int n,int *dp){
	if(n<0) return 0;
	if(n==0) {
		dp[n]=1;
		return dp[n];
	}
	if(dp[n]!=0) return dp[n];
	dp[n] = getstairM(n-1,dp) + getstairM(n-2,dp) + getstairM(n-3,dp);
	return dp[n];
}

int getStairT(int n,int *dp){
	for(int i=0;i<=n;i++){
		if(i==0 || i==1)dp[i]=1;
		else if(i<=2) dp[i]=dp[i-1]+dp[i-2];
		else dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[n];
}

//----------------------------------------------------------


// Downstair case
int getstairV_D(int n,int *arr)
{
	if(n<0) return 0;
	if(n==0) return 1;
	int count=0;
	for(int i=1;i<=arr[n];i++)
		count+=getstairV_D(n-i,arr);
	return count;
}

// Upstair case
int getstairV_U_M(int n,int *arr,int idx)
{
	if(idx>n) return 0;
	if(n==idx) return 1;
	int count=0;
	for(int i=1;i<=arr[idx];i++)
		count+=getstairV_U_M(n,arr,i+idx);
	return count;
}

int getstairV_U_T(int n,int *arr,int *dp)
{
	dp[n]=1;
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=arr[i];j++)
			dp[i]+=dp[i+j];
	}
	return dp[1];
}

1

//-------------------------------------------------------


// 10
// 3 2 4 2 0 2 3 1 2 2

int getstairminV_U_R(int n,int *arr,int idx)
{
	if(idx>=n) return 0;
	int mini=INT_MAX;
	if(arr[idx] == 0) return -1;
	for(int i=1;i<=arr[idx];i++){
		int g=getstairminV_U_R(n,arr,i+idx);
		if(g!=-1) mini=min(mini,g);
	}
	return mini+1;
}

int getstairminV_U_T(int n,int *arr,int *dp)
{
	dp[n]=0;
	
	for(int i=n-1;i>=1;i--){
		int mini=INT_MAX;
		if(arr[i]==0){
			dp[i]=-1;
			continue;
		}
		for(int j=1;j<=arr[i];j++)
			if(dp[i+j] != -1) mini=min(mini,dp[i+j]);
		
		dp[i]=mini+1;
	}
	return dp[1];
}

//int getstairminV_U_M(int n,int *arr,int idx,int *dp)
//{
//	int mini=INT_MAX;
//	if(idx>n) {
//		dp[idx]=mini;
//		return mini;
//	}
//	if(idx==n) {
//		dp[idx]=1;
//		return 1;
//	}
//	if(dp[idx]) return dp[idx];
//	for(int i=1;i<=arr[idx];i++){
//		if((i+idx)<=n && dp[i+idx]) return dp[i+idx];
//		mini=min(mini,getstairminV_U_M(n,arr,i+idx,dp));	
//	}
//	dp[idx]=mini+1;
//	return dp[idx];
//}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int arr[15]={0};
	cout<<"hello!"<<endl;
	
//	int s=fiboR(7,arr);
//	print(arr,0,14);

//	int s=getstairT(10,arr);
//	print(arr,0,14);
//	cout<<endl<<s;

	int path=0;
	int n;cin>>n;
	int arr2[n+1]={0}; REP(1,n) cin>>arr2[i];
	
//	cout<<getstairV_D(n,arr2)<<endl;
	
	arr[n+1]=0;
//	cout<<getstairminV_U_T(n+1,arr2,arr)<<endl;
//	print(arr,1,n+1);

	cout<<getstairminV_U_M(n,arr2,1,arr)<<endl;
	print(arr,1,n+1);

	return 0;
}

