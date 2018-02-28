#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000;
int N[2], M[2];
vector<vector<int>> adj[2];

bool vis[2][MAXN], instk[2][MAXN], hascyc;

void check(int u, int n) {
	if (instk[u][n]) hascyc = true;
	if (vis[u][n]) return;
	vis[u][n] = true;
	instk[u][n] = true;
	for (int m : adj[u][n]) {
		check(u, m);
	}
	instk[u][n] = false;
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
		check(u, 0);
		if (!vis[u][N[u]-1] || hascyc) return 1;
	}
	return 42;
}
