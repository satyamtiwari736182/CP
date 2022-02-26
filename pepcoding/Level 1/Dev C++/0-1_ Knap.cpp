#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
	return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));

	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}

int main()
{
	cout<<endl<<"No. of objects: ";
	int n; cin>>n; 
	cout<<endl<<"Enter the values : ";
	int val[n]; for(int i=0;i<n;i++) cin>>val[i];
	cout<<endl<<"Enter the weights: ";
	int wt[n]; for(int i=0;i<n;i++) cin>>wt[i];
	cout<<endl<<"Knapsack Size: ";
	int W;cin>>W;
	cout <<endl<<"Maximum possible values: " <<knapSack(W, wt, val, n);
	return 0;
}



