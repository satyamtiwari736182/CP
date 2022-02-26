#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<string>
#define MAX 1e5
using namespace std;
	
/*int main(){
	int a=90,b=100;
	cout<<"Hello world"<<endl;
	// sample programming
	cout<<a+b<<endl;
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.emplace_back(50);
	vec.pop_back();
	vec.insert(begin(vec)+3,897);
	vec.erase(begin(vec));
	for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
	cout<<"\nsize: "<<vec.size()<<"  capacity: "<<vec.capacity()<<endl;
	cout<<endl<<vec.front()<<'\t'<<vec.back()<<endl;
	char str[100];
//	cin>>str;
	cout<<"Enter a line:";
	cin.getline(str,90,'.');
	cout<<endl<<str<<endl;
	char ch;
//	getchar(cin,ch);
	cin>>ch;
	cout<<ch;
	return 0;
}*/



//int main(){
//	cout<<"hello!"<<endl;
//	list<int> dq;
//	dq.push_back(10);
//	dq.push_back(20);
//	dq.push_back(30);
//	dq.push_front(1);
//	dq.push_front(2);
//
////	dq.insert(begin(dq)+2,56);
////	cout<<dq[2]<<endl;
//
////	for(auto i:dq) cout<<i<<" ";
//	list<int> :: const_iterator it=dq.cbegin();
//	for(;it!=dq.cend();it++) cout<<*it<<" ";
//	cout<<endl;
//	cout<<dq.size()<<endl;
//	
//	return 0;
//}


/*
int main(){
	cout<<"hello!"<<endl;
	multiset<int> st;
	st.insert(10);
	st.insert(20);
	st.insert(30);
	st.insert(10);
	st.insert(30);
	st.insert(10);
	auto it=st.begin();
	while(it!=end(st)){
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	auto res=st.find(20);
	cout<<*res<<endl;
	auto range=st.count(10);
//	cout<<*range.first<<'\t'<<*range.second<<endl;
	cout<<range;
	return 0;
}
*/
int main(){
	/* 0 1 2 
	0000
	0001
	0010
	----
	0011
	----
	4
	*/
	
	int res=0 | 1 | 2 ;
	cout<<res; // 3-1=2
	return 0;
}



