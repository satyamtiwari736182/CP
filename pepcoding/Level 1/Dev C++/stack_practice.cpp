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

int *nge(int *arr,int n){
	stack<int> st;
	int *gre=new int[n+1];
	gre[n]=n+1;
	st.push(n);
	for(int i=n-1;i>=0;i--){
		while(st.size() && arr[st.top()]<=arr[i]) st.pop();
		if(st.empty()) gre[i]=n+1;
		else gre[i]=st.top();
		st.push(i);
	}
	return gre;	
}

int *pge(int *arr,int n){
	stack<int> st;
	int *gre=new int[n+1];
	gre[0]=-1;
	st.push(0);
	for(int i=1;i<=n;i++){
		while(st.size() && arr[st.top()]<=arr[i]) st.pop();
		if(st.empty()) gre[i]=-1;
		else gre[i]=st.top();
		st.push(i);
	}
	return gre;	
}

int *nse(int *arr,int n){
	stack<int> st;
	int *gre=new int[n+1];
	gre[n]=-1;
	st.push(n);
	for(int i=n-1;i>=0;i--){
		while(st.size() && arr[st.top()]>=arr[i]) st.pop();
		if(st.empty()) gre[i]=-1;
		else gre[i]=st.top();
		st.push(i);
	}
	return gre;	
}

int *pse(int *arr,int n){
	stack<int> st;
	int *gre=new int[n+1];
	gre[0]=-1;
	st.push(0);
	for(int i=1;i<=n;i++){
		while(st.size() && arr[st.top()]>=arr[i]) st.pop();
		if(st.empty()) gre[i]=-1;
		else gre[i]=st.top();
		st.push(i);
	}
	return gre;	
}

int MAH(int *arr,int n){
	int *ns_idx=nse(arr,n);
	int *ps_idx=pse(arr,n);
	int area=0;
	for(int i=0;i<=n;i++){
		int r=ns_idx[i];
		int l=ps_idx[i];
		int tempArea=arr[i]*(r-l-1);
		if(tempArea>area) area=tempArea;
		cout<<tempArea<<" ";
	}
	
	return area;
}

int *max_k(int *arr,int n,int k){
	int *maxWindow_k=new int[n-k+1+1];
	int *nge_idx=nge(arr,n);
	int i=0;
	for(int w=0;w<=n-k+1;w++){
		if(i<w) i=w;
		while(nge_idx[i]<w+k) i=nge_idx[i];
		maxWindow_k[w]=arr[i];
	}
	return maxWindow_k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int arr[]={10,8,5,4,7,21,6};
//	int *ngre=max_k(arr,6,3);
	int *ngre=nge(arr,6);
	REP(0,6) cout<<ngre[i]<<" ";
//	cout<<endl<<MAH(arr,6)<<endl;
	cout<<"hello!"<<endl;
	return 0;
}

