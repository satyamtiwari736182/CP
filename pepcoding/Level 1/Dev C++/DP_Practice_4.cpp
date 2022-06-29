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

vector<string> getseq(string str,vector<string> res){
	vector<string> temp;
	if(str.length()==0) {
		temp.pb("");
		return temp;
	}
	
	temp=getseq(str.substr(1),res);
	
	for(auto item:temp) res.pb(""+item);
	for(auto item:temp) res.pb(str[0]+item);
	
	return res;
}

vector<string> kpc(string *keypad,string str){
	vector<string> temp,res;
	if(str.length()==0){
		temp.pb("");
		return temp;
	}
	int n=str[0]-'0';
	cout<<n<<endl;
	temp=kpc(keypad,str.substr(1));
	for(auto item:temp)
		for(auto ch:keypad[n])
			res.pb(ch+item);
	return res;
}

vector<string> getdownstair(int n){
	vector<string> temp;
	if(n<0) {
		temp.pb("");
		return temp;
	}
	if(n==0){
		temp.pb("1");
		return temp;
	}
	auto temp1=getdownstair(n-1);
	auto temp2=getdownstair(n-2);
	auto temp3=getdownstair(n-3);
	for(auto itm:temp1) temp.pb("1"+itm);
	for(auto itm:temp2) temp.pb("2"+itm);
	for(auto itm:temp3) temp.pb("3"+itm);
	
	return temp;
}

vector<string> getdownmaze(int m,int n)
{ 
	vector<string> temp;
	if(m==1 && n==1){
		temp.pb("");
		return temp;
	}
	temp.clear();
	if(m<1 || n<1) return temp;
	
	auto tempv=getdownmaze(m,n-1);
	auto temph=getdownmaze(m-1,n);
	for(auto itm:tempv) temp.pb("v"+itm);
	for(auto itm:temph) temp.pb("h"+itm);
	return temp;
}

vector<string> getdownmazefreemove(int m,int n){
	cout<<"satyam"<<endl;
	vector<string> temp;
	if(m==1 && n==1){
		temp.pb("");
		return temp;
	}
	if(m<1 || n<1) return temp;
	vector<string> tempv,temph,tempd;
//	auto tempv=getdownmazefreemove(m-1,n);
//	auto temph=getdownmazefreemove(m,n-1);
//	auto tempd=getdownmazefreemove(m-1,n-1);
	
	for(int i=1;i<m;i++) tempv=getdownmazefreemove(m-i,n);
	for(int i=1;i<n;i++) temph=getdownmazefreemove(m,n-i);
//	for(int i=1,j=1;i<n && j<m;i++,j++) temph=getdownmazefreemove(m-j,n-i);
	
	for(int i=0;tempv.size();i++) temp.pb("v"+i+tempv[i]);
	for(int i=0;temph.size();i++) temp.pb("h"+i+temph[i]);
//	for(int i=0;tempd.size();i++) temp.pb("d"+i+tempd[i]);
	
	
	return temp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	vector<string>seqs;
	vector<string> seq;
	
//	seq=getseq("abc",seqs);
//	REP(0,seq.size()-1) cout<<seq[i]<<", ";

	
	// string keypad[]={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
	// seq=kpc(keypad,"5670");

//	seq=getdownstair(3);
//	REP(0,seq.size()-1) cout<<seq[i]<<", ";
	
//	seq=getdownmaze(3,3);

	seq=getdownmazefreemove(5,5);
	REP(0,seq.size()-1) cout<<seq[i]<<", ";
	cout<<endl<<"hello!"<<endl;
	return 0;
}

