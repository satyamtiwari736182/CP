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

//((a+b)+(c+d)) -> false
//((a+b))+(c+d) -> true
bool hasRedundant(string str){
	stack<char>st;
	for(char ch:str){
		if(ch!=')')
			st.push(ch);
		else{
			if(st.top()=='(' && ch==')') return true;
			while(st.top()!='(')
				st.pop();
			st.pop();
		}
	}
	
	return false;
}

bool isBalance(string str){
	stack<char>st;
	for(char ch:str){
		
		if(ch=='(' || ch=='{' || ch=='[')
			st.push(ch);
			
		else if(ch==')'){
			if(st.empty() || st.top()!='(') return false;
				st.pop();
		}

		else if(ch=='}'){
			if(st.empty() || st.top()!='{') return false;
			    st.pop();
		}

		else if(ch==']'){
			if(st.empty() || st.top()!='[') return false;
				st.pop();
		}
	}
	if(st.size()!=0) return false;
	
	return true;
}

void NGE(int *arr,int n){
	stack<int> st;
	int nge[n+1];
	nge[n]=-1;
	st.push(arr[n]);
	
	for(int i=n-1;i>=0;i--)
	{
		while(st.size() && st.top()<arr[i]) st.pop();
		if(st.empty()) nge[i]=-1;
		else nge[i]=st.top();
		st.push(arr[i]);
	}
	for(int i=0;i<=n;i++) cout<<nge[i]<<" ";
}

void stockSpan(int *arr,int n){
	stack<int> st;
	int nge[n+1];
	nge[0]=1;
	st.push(0);
	
	for(int i=1;i<=n;i++)
	{
		while(st.size() && arr[st.top()]<arr[i]) st.pop();
		if(st.empty()) nge[i]=i+1;
		else nge[i]=i-st.top();
		st.push(i);
	}
	
	for(int i=0;i<=n;i++) cout<<nge[i]<<" ";
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
//	string str;cin>>str;
//	cout<<(hasRedundant(str)?"True":"False")<<endl;
//	cout<<(isBalance(str)?"True":"False")<<endl;

//	int n;cin>>n;
//	int arr[n]; 
//	REP(0,n-1) cin>>arr[i];
	
	cout<<"start"<<endl;
	
//	NGE(arr,n-1);
//	stockSpan(arr,n-1);
	l
	// int *tem=nge();
	// cout<<tem[0];
	
	cout<<"\nhello!"<<endl;
	return 0;
}

