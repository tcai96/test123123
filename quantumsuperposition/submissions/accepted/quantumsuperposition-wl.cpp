#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000;
int N[2], M[2];
vector<vector<int>> adj[2];

struct Node {
	bool stp[MAXN], vis;
	bool gotstp(int x) {
		return x < MAXN && stp[x];
	}
} nodes[2][MAXN];

void dfs(int u, int n) {
	Node& nd = nodes[u][n];
	if (nd.vis) return;
	nd.vis = true;
	if (n == N[u]-1) nd.stp[0] = true;
	for (int m : adj[u][n]) {
		dfs(u, m);
		for (int i = 0; i < N[u]-1; i++) {
			if (nodes[u][m].stp[i]) nd.stp[i+1]=true;
		}
	}
}

int main() {
	cin >> N[0] >> N[1] >> M[0] >> M[1];
	for (int u = 0; u < 2; u++) {
		adj[u].resize(N[u]);
		for (int m = 0; m < M[u]; m++) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			adj[u][a].push_back(b);
		}
		dfs(u, 0);
	}

	int qs;
	cin >> qs;
	while (qs--) {
		int q;
		cin >> q;
		bool ans = false;
		for (int a = 0; a <= q; a++) {
			if (nodes[0][0].gotstp(a) && nodes[1][0].gotstp(q-a)) {
				ans = true;
				break;
			}
		}
		cout << (ans ? "Yes" : "No") << endl;
	}
}
