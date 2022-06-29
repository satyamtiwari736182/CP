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

vector<string> getdownmazefreemove(int m,int n){
	vector<string> temp;
	if(m<1 || n<1) return temp;
	if(m==1 && n==1){
		temp.pb("");
		return temp;
	}

	for(int i=1;i<m;i++){
		auto tempv=getdownmazefreemove(m-i,n);	
		for(auto itm:tempv) temp.pb("v"+to_string(i)+itm);
	}
	
	for(int i=1;i<n;i++){
		auto temph=getdownmazefreemove(m,n-i);
		for(auto itm:temph) temp.pb("h"+to_string(i)+itm);
	}
	
	for(int i=1;i<m;i++){
		auto tempd=getdownmazefreemove(m-i,n-i);
		for(auto itm:tempd) temp.pb("d"+to_string(i)+itm);
	}
	
	return temp;
}

void printseq(string str,string ans){
	if(str.length()==0){
		cout<<ans<<" ";
		return;
	}
	printseq(str.substr(1),ans+str[0]);
	printseq(str.substr(1),ans+"");
}

void printkpc(string *keypad,string str,string ans){
	if(str.length()==0){
		cout<<ans<<" ";
		return;
	}
	int n=str[0]-'0';
	for(auto ch:keypad[n])
		printkpc(keypad,str.substr(1),ans+ch);
}

void printstair(int n,string ans){
	if(n<0) return;
	if(n==0){
		cout<<ans<<" ";
		return;
	}
	for(int i=1;i<=3;i++) printstair(n-i,ans+to_string(i));
}

void printmazepath(int n,int m,string ans)
{
	if(m<0 || n<0) return;
	if(n==1 && m==1){
		cout<<ans<<" ";
		return;
	}
	printmazepath(n-1,m,"v"+ans);
	printmazepath(n,m-1,"h"+ans);
	printmazepath(n-1,m-1,"d"+ans);
}

void printmazepathfreely(int n,int m,string ans){
	if(m<0 || n<0) return;
	if(n==1 && m==1){
		cout<<ans<<" ";
		return;
	}
	for(int i=1;i<n;i++) printmazepathfreely(n-i,m,"v"+to_string(i)+ans);
	for(int i=1;i<n;i++) printmazepathfreely(n,m-i,"h"+to_string(i)+ans);
	for(int i=1;i<n;i++) printmazepathfreely(n-i,m-i,"d"+to_string(i)+ans);
}

void permute(string str,string ans){
	if(str.length()==0){
		cout<<ans<<" "; return;
	}
	for(int i=0;i<str.length();i++) permute(str.substr(0,i)+str.substr(i+1),ans+str[i]);
}

void printencoding(string ques,string ans){
	if(ques.length()==0){
		cout<<ans<<" ";
		return;
	}
	else if(ques.length()==1){
		int val=stoi(ques.substr(0,1));
		if(val==0) return;
		char ch=char(val+'a'-1);
		ans=ans+ch;
		cout<<ans<<" ";
		return;
	}
	else{
		int ch1=stoi(ques.substr(0,1));
		int ch2=stoi(ques.substr(0,2));
		if(ch1==0 || ch2>26) return;
		ch1=ch1;
		char ch=char(ch1+'a'-1);
		printencoding(ques.substr(1),ans+ch);
		ch=char(ch2+'a'-1);
		printencoding(ques.substr(2),ans+ch);
	}
}
const int N=100;
void check(string arr[][N],int n,int m){
	int i=0,j=0;
	REP2(i,0,n){
		REP2(j,0,m) cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr); 
	int i=0,j=0,n,m;cin>>n>>m;
	
	string arr[N][N];
	
	
	REP2(i,0,n-1) REP2(j,0,m-1) cin>>arr[i][j];
	cout<<"-----------------------"<<endl;
	check(arr,n-1,m-1);
//	int *arr2[2];
//	&arr[1]=&arr[0][1];
	cout<<endl<<"hello!"<<endl;
	
//	auto seq=getdownmazefreemove(3,2);
//	REP(0,seq.size()-1) cout<<seq[i]<<", ";

//	printseq("abc","")

//	string keypad[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
//	printkpc(keypad,"567","");

//	printstair(5,"");

//	printmazepathfreely(3,3,"");

//	permute("abcd","");

//	printencoding("123","");

//	string str="123";
//	int str1=int((str[0]-'0')*10+str[1]-'0');
//	cout<<str1*1<<endl<<char(stoi(str.substr(0,2))+'a'-1);

	return 0;
}

