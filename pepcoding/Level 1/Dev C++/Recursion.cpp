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

void printDeceresing(int n){
	if(n==0) return;
	cout<<n<<" ";
	printDeceresing(n-1);
	cout<<n<<" ";
}

int fact(int n){
	if(n==0 || n==1) return 1;
	return fact(n-1)*n;
}

int powLinear(int x,int n){
	if(n==0) return 1;
	return x*powLinear(x,n-1);
}

int powLog(int x,int n){
	if(n==0) return 1;
	int p=n&1?x:1;
	int res=powLog(x,n/2);
	return p*res*res;
}

void printZigZag(int n){
	if(n==0) return;
	cout<<n<<" ";
	printZigZag(n-1);
	cout<<n<<" ";
	printZigZag(n-1);
	cout<<n<<" ";
}

void TOH(int n,char a,char b,char c){
	if(n==0) return;
	TOH(n-1,a,c,b);
	cout<<n<<"--> "<<a<<","<<b<<endl;
	TOH(n-1,c,b,a);
}

void display(int *arr,int n){
	if(n<0)return;
	display(arr,n-1);
	cout<<arr[n]<<" ";
}

void displayR(int *arr,int n){
	if(n<0)return;
	cout<<arr[n]<<" ";
	displayR(arr,n-1);
	
}

int findMax(int *arr,int n){
	if(n<0) return -1;
	int b=arr[n];
	int a=findMax(arr,n-1);
	return a>b?a:b;
}

int firstIndex(int *arr,int n,int val){
	
	if(n<0) return -1;
	int idx=firstIndex(arr,n-1,val);
	if(idx==-1 && arr[n]==val) return n+1;
	return idx;
}

int lastIndex(int *arr,int n,int val){
	
	if(n<0) return -1;	
	if(arr[n]==val) return n+1;	
	int idx=lastIndex(arr,n-1,val);	
	return idx;
}
vector<string> allSubseq(string str){
	vector<string> samm;
	samm.pb("");
	if(str.length()==0) return samm;
	char ch=str[0];
	
	auto rres=allSubseq(str.substr(1));
	
	vector<string> sam;
	for(auto i:rres) sam.pb(ch+i);
	for(auto i:rres) sam.pb(""+i);
	
	return sam;
}

vector<string> kpc(string str){
	vector<string> samm;samm.pb("");
	if(str.length()==0) return samm;
	string keypad[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
	int ch=str[0]-'0';
	auto rres=kpc(str.substr(1));

	vector<string> res;
	for(int i=0;i<keypad[ch].length();i++)
		for(auto j:rres)
			res.pb(keypad[ch][i]+j);					
	return res;	
}

vector<string> getStairPath(int n){
	vector<string> samm;samm.pb("");
	if(n==0) return samm;
	samm.clear();
	if(n<0) return samm;	
	
	vector<string> path;
	auto path1=getStairPath(n-1);
	auto path2=getStairPath(n-2);
	auto path3=getStairPath(n-3);
	for(auto i:path1) path.pb("1"+i);
	for(auto i:path2) path.pb("2"+i);
	for(auto i:path3) path.pb("3"+i);
	return path;
}

vector<string> getMazePath(int row,int col){
	vector<string> samm;samm.pb("");
	if(row==0 && col==0) return samm;
	samm.clear();
	if(row<0 || col<0) return samm;
	
	auto path1=getMazePath(row,col-1);
	auto path2=getMazePath(row-1,col);
	vector<string> path;
	for(auto i:path1) path.pb("h"+i);
	for(auto i:path2) path.pb("v"+i);
	return path;
}

//void printSubseq(string ques,string ans){
//	if(ques.length()==0){
//		cout<<ans<<" ";
//		return;
//	}
//	char ch=ques[0];
//	
//	printSubseq(ques.substr(1),""+ans);
//	printSubseq(ques.substr(1),ch+ans);
//}

void printSubseq(string ques,string ans){
	cout<<ans<<"\t";
	if(ques.length()){
		char ch=ques[0];
//		cout<<ans<<"\t";
		printSubseq(ques.substr(1),ans+ch);
//		cout<<ans<<" ";
		printSubseq(ques.substr(1),ans+".");
//		cout<<ans<<" ";
	}
//	else cout<<ans<<" ";
}

void printMazePath(int row,int col,string path){
	if(row==0 && col==0) {
		cout<<path<<" "; 
		return;
	}
	if(col>0) printMazePath(row,col-1,"h"+path);
	if(row>0) printMazePath(row-1,col,"v"+path);
	
}

void printkpc(string str,string res){
	string keypad[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
	cout<<res<<" ";
	if(str.length()==0) {
//		cout<<res<<" ";  
		return;
	}
	int ch=str[0]-'0';
	for(int i=0;i<keypad[ch].length();i++)
		printkpc(str.substr(1),res+keypad[ch][i]);
//	cout<<res<<" ";
}

void printStairPath(int n,string path){
	if(n<=0){
		if(n==0) cout<<path<<" ";
		return;
	}
	printStairPath(n-1,"1"+path);
	printStairPath(n-2,"2"+path);
	printStairPath(n-3,"3"+path);
}

void printPermutation(string str,string res){	
	if(str.length()==0){
		cout<<res<<" "; return;
	}	
	for(int i=0;i<str.length();i++)
		printPermutation(str.substr(0,i)+str.substr(i+1),res+str[i]);			
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

//	int n;cin>>n;
//	printDeceresing(n);
//	cout<<fact(6)<<endl<<powLinear(2,10)<<endl<<powLog(5,5);	
//	printZigZag(5);
//	TOH(3,'A','B','C');
	int arr[]={5,2,3,4,2,1,0};
//	displayR(arr,6);
//	cout<<findMax(arr,6);
//	cout<<firstIndex(arr,6,2)<<endl;
//	cout<<endl<<lastIndex(arr,6,2);
	
	string str="abc";
	vector<string> subseq;
//	subseq.pb("");	allSubseq(str,subseq);
//	subseq=allSubseq(str);
//	cout<<endl;
//	sort(all(subseq));
//	print(subseq,0,subseq.size()-1);
//	str="6546";
//	subseq=getStairPath(3);
//	subseq=getMazePath(6,6);
//	print(subseq,0,subseq.size()-1);
//	cout<<endl<<subseq.size();
//	printSubseq(str,"");
//	printMazePath(3,3,"");
//	printkpc("578","");
//	printStairPath(3,"");
	printPermutation("abc","");
	return 0;
	
	
}



