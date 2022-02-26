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

//
//3 3
//0 0 0
//1 0 1
//0 0 0
const int N=100,M=100;

void floodfill(int arr[N][M],int visited[N][M],int i,int j,int n,int m,string ans){

	if(i<0 || j<0 || i==n || j==m || arr[i][j]==1 || visited[i][j]==1) return;
	
	if(i==n-1 && j==m-1){
		cout<<ans<<" ";
		return;
	}
	visited[i][j]=1;
	
	floodfill(arr,visited,i,j+1,n,m,"r"+ans);
	floodfill(arr,visited,i,j-1,n,m,"l"+ans);
	floodfill(arr,visited,i-1,j,n,m,"u"+ans);
	floodfill(arr,visited,i+1,j,n,m,"d"+ans);
	
	visited[i][j]=0;	
}

void subsetsum(int *arr,int n,int tar,string ans){
	if(n<0) return;
	if(n==0){
		if(tar==0)cout<<ans<<endl;
		else if(tar-arr[n]==0){
			ans=to_string(arr[n])+", "+ans;
			cout<<ans<<endl;
		}
		return;
	}
	subsetsum(arr,n-1,tar-arr[n],to_string(arr[n])+", "+ans);
	subsetsum(arr,n-1,tar,ans);
}

bool issafe(int board[][M],int n,int row,int col){
	
	for(int i=row-1,j=col-1;i>0 && j>0 ;i--,j--)
		if(board[i][j]) return false;
		
	for(int i=row-1,j=col+1;i>0 && j<=n ;i--,j++)
		if(board[i][j]) return false;
	
	for(int i=row-1,j=col;i>0 && j>0 ;i--)
		if(board[i][j]) return false;
	
	for(int i=row,j=col-1;i>0 && j>0 ;j--)
		if(board[i][j]) return false;
		
	return true;
}

void nqueen(int board[][M],int n,int row,string ans){
	
	if(row<0) return;
	if(row==0){
		cout<<ans<<" ";
		return;
	}
	
	for(int col=row;col>0;col--){
		if(board[row][col]==0 && issafe(board,n,row,col)==1) {
			board[row][col]=1;
			nqueen(board,n,row-1,to_string(row)+"-"+to_string(col)+ans);
			board[row][col]=0;
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
//	int i=0,j=0,n,m;cin>>n>>m;
//	int arr[N][M],visited[N][M];
//	REP2(i,0,n-1) REP2(j,0,m-1) cin>>arr[i][j];
//	
//	memset(visited,0,sizeof(visited));
//	floodfill(arr,visited,0,0,n,m,"");


//	int tar=0,n; cin>>n;
//	int arr[n];
//	REP(0,n-1)	cin>>arr[i];
//	cin>>tar;
//	cout<<endl;
//	subsetsum(arr,n,tar,"");

	int n;cin>>n;
	int board[N][M];
	memset(board,0,sizeof(board));
	nqueen(board,n,n,"");
	
	cout<<"hello!"<<endl;
	return 0;
}

