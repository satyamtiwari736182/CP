#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int>> prq;
	cout<<"hello!"<<endl;
	cout<<prq.empty()<<endl;
	prq.push(23);
	prq.push(45);
	prq.push(20);
	prq.push(10);
	prq.push(15);
	cout<<prq.size()<<endl;
	while(!prq.empty()){
		cout<<prq.top()<<" ";
		prq.pop();
	}
	
	return 0;
}
