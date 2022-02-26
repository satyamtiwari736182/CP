#include<bits/stdc++.h>
using namespace std;
#define REP(a,b) for(int i=a;i<=b;i++)
#define all(x) x.begin(),x.end()
#define print(arr,l,r) for(int i=l;i<=r;i++) cout<<arr[i]<<" ";
#define vi vector<int>
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

void display(int n, int *arr){
	if(n<0) return;
	display(n-1,arr);
	cout<<arr[n]<<" ";
}
int findMax(int n,int *arr){
	if(n<0) return INT_MIN;
	int maxi=findMax(n-1,arr);
	if(arr[n] >= maxi) return arr[n];
	return maxi;
}
int findfirst(int n,int *arr,int val){
	if(n<0) return -1;
	int index=findfirst(n-1,arr,val);
	if(index==-1 && arr[n]==val) return n;
	return index;
}

int findlast(int n,int *arr,int val){
	if(n<0) return -1;
	if(arr[n]==val) return n;
	int index=findlast(n-1,arr,val);
	return index;
}


void findall(int n,int *arr,int val){
	if(n<0) return;
	findall(n-1,arr,val);
	if(arr[n]==val) cout<<n<<" ";
}

vector<string> findSeq(string str){
	vector<string> seq;
	
	if(str.length()==0) 
	{
		seq.pb("");
		return seq;
	}
	char ch=str[0];
	vector<string> res=findSeq(str.substr(1));
	for(auto i:res) seq.pb(ch+i);
	for(auto i:res) seq.pb(""+i);
	return seq;
}

vector<string> getKPC(string str,string *key){
	vector<string> comb;
	if(str.length()==0) {
		comb.pb("");
		return comb;
	}
	
	int ch=str[0]-'0';
	auto res=getKPC(str.substr(1),key);
	for(auto i:res)
		for(auto c:key[ch])
			comb.pb(c+i);
	return comb;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int arr6[]={12,56,12,23,50,12};
//	display(6-1,arr);
//	cout<<endl<<findMax(5,arr)<<endl;
//	cout<<endl<<findfirst(5,arr,12)<<endl;
//	cout<<endl<<findlast(5,arr,12)<<endl;
//	findall(5,arr,12);
//	cout<<endl;
	auto seq=findSeq("abc");
//	for(auto i:seq) cout<<i<<" ";
	print(seq,0,seq.size()-1);
	cout<<endl;
	string keypad[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
	auto com=getKPC("576",keypad);
	print(com,0,com.size()-1);
	cout<<endl<<"hello!"<<endl;
	return 0;
}

