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

struct Node{
	vector<Node *>children;
	int data;
};

void display(Node *node) {
    string str = to_string(node->data )+ " -> ";
    for (auto child : node->children) {
      str += to_string(child->data ) + " ";
    }

    cout<<str<<endl;

    for (auto child : node->children) {
      display(child);
    }
}
  
Node* insert(int *arr,int n){
	Node *root=new Node;
	root->data=arr[0];
	stack<Node *> st;
	st.push(root);
	
	REP(1,n-1){
		struct Node *t=new Node;
		if(arr[i]==-1) st.pop();
		else
		{
			t->data=arr[i];
			if(st.size()) st.top()->children.pb(t);
			st.push(t);
		}			
	}
	return root;
}

int countNode(Node *root){
//	if(!root) return 0;
	int sum=1;
	for(auto child:root->children)
		sum+=countNode(child);
	return sum;
}

int findMax(Node *root){
//	if(!root) return 0;
	int mx=root->data;
	for(auto child:root->children){
		int temp=findMax(child);
		if(mx<temp) mx=temp;
	}
	return mx;
}

int getHeight(Node *root){
//	if(!root) return 1;

	int ht=-1;
	for(auto child:root->children){
		int temp=getHeight(child);
		ht=max(ht,temp);
	}
	return ht+1;
}

int getSum(Node *root){
//	if(!root) return 0;
	int sum=0;
	for(auto child:root->children){
		sum+=getSum(child);
	}
	return sum+root->data;
}

void preOrder(Node *root){
//	cout<<root->data<<" ";
	queue<Node*> q;
//	q.push(root);
	for(auto child:root->children){
		cout<<child->data<<" ";
		q.push(child);
	}
	cout<<endl;
	while(!q.empty()){
		preOrder(q.front());
		q.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int arr[] = {10,20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
//	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
	int n=sizeof(arr)/sizeof(*arr);
	
	Node *root=insert(arr,n);
	display(root);

	int size=countNode(root);
	int mx=findMax(root);
	int ht=getHeight(root);
	int sum=getSum(root);
	cout<<endl;
	preOrder(root);
	cout<<endl;
	
	cout<<endl<<"Size of tree = "<<size<<endl;
	cout<<endl<<"Max vlaue in tree = "<<mx<<endl;
	cout<<endl<<"Height of tree = "<<ht<<endl;
	cout<<endl<<"Sum of tree nodes= "<<sum<<endl;
	cout<<"hello! "<<n<<endl;
	
	return 0;
}

