#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <set>
#include <map>


using namespace std;

#define N 35005
#define M 55
#define endl '\n'

int t[4 * N], d[4 * N], w[N],dp[M][N],n, k;

void build(int k, int u, int l, int r){
	if (l == r) return void(t[u] = dp[k][l]);
	int m = (l + r) / 2;
	build(k, 2 * u + 1, l, m);
	build(k, 2 * u + 2, m+1, r);
}

void push(int u, int len){
	if (!d[u]) return;
	t[u] += d[u];
	// if (len > 1) 
	d[2 * u + 1] += d[u], d[2 * u + 2] += d[u];
	d[u] = 0;
}

void update(int u, int l, int r, int L, int R){
	push(u, r - l);
	if (L >= R) return;
	if (l == L && r == R){
		d[u]++;
		push(u, r - l);
		return;
	}
	int m = (l + r) / 2;
	
	update(2 * u + 1, l, m, L, min(m, R));

	update(2 * u + 2, m+1, r, max(L, m+1), R);

	t[u] = max(t[2 * u + 1], t[2 * u + 2]);
}

int get(int u, int l, int r, int L, int R) {
	if (L >= R) return 0;
	push(u, r - l);
	if (l == L && r == R) return t[u];
	int m = (l + r) / 2, ans = 0;
	ans = max(ans, get(2 * u + 1, l, m, L, min(m, R)));
	

	ans = max(ans, get(2 * u + 2, m+1, r, max(L, m+1), R));

	return ans;
}

int p[N];
map<int, int> last;

void solve(int k){
	fill_n(t, 4 * N, 0), fill_n(d, 4 * N, 0);
	build(k - 1, 0, 0, n-1);

	for(int i=0;i<n;i++) {
		if (p[i] < i)update(0, 0, n-1, p[i], i);
		dp[k][i] = max(dp[k - 1][i], get(0, 0, n-1, 0, i));
	}
}


int main() {
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> w[i];

	for(int i=0;i<n;i++) {
		if (last.count(w[i])) p[i] = last[w[i]];
		else p[i] = 0;
		last[w[i]] = i;
	}

	set<int> s;
	for(int i=0;i<n;i++){
		s.insert(w[i]);
		dp[1][i] = s.size();
	}

	for (int i = 2; i <= k; i++) solve(i);
	cout << dp[k][n - 1] << endl;
}

