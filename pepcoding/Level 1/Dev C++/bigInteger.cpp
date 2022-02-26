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



string findSum(string str1, string str2)
{

	if (str1.length() > str2.length())
		swap(str1, str2);

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i=0; i<n1; i++)
	{
		int sum = ((str1[i]-'0') * (str2[i]-'0'))+carry;
		str.push_back(sum%10 + '0');

		carry = sum/10;
	}
	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}
	if (carry)
		str.push_back(carry+'0');

	reverse(str.begin(), str.end());

	return str;
}

int main()
{
	string str1 = "98649";
	string str2 = "198111";
	cout << findSum(str1, str2);
	return 0;
}

