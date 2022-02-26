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


int MEX(int *arr,int a,int b){
	int res=0;
	int hash[5000];
	for(int i=a;i<=b;i++)
		hash[i]=1;
	for(int i=0;i<=5000;i++)
	{
		if(!hash[i]){
			res=i;
			break;
		}
	}
	return res;
		
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
//	cin>>t;
	int N,K;
	vi R;
	REP(0,t-1){
		cin>>N>>K;
		int A[N];
		vi temp;
		for(int j=0;j<N;j++)
			cin>>A[i];
		for(int m=0;m<N;m++)
		{
			for(int n=m+1;n<N;n++)
			{
				int x=MEX(A,m,n);
				R.PB(x);
			}
		}
//		R.PB(temp[K]);
				
	}
	REP(0,R.size()-1)cout<<R[i]<<endl;
	return 0;
}


//
//3
//3 4
//1 0 2
//3 2
//2 1 3
//3 6
//0 1 2

//
//1
//0
//3

