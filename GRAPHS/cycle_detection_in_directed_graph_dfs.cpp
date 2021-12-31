#include <bits/stdc++.h>

using namespace std;

bool checkCycledfs(int node, vector<int> adj[], int vis[], int dfsvis[]) {
	vis[node] = 1;
	dfsvis[node] = 1;

	for (auto it : adj[node]) {
		if (!vis[it]) {
			if (checkCycledfs(it, adj, vis, dfsvis)) return true;
		}
		else {
			if (dfsvis[it]) {
				return true;
			}
		}
	}
	//backtrack stuff
	dfsvis[node] = 0;
	return false;
}

bool isCycledfs(vector<int> adj[], int n) {
	int vis[n], dfsvis[n];
	memset(vis, 0, sizeof vis);
	memset(dfsvis, 0, sizeof dfsvis);

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (checkCycledfs(i, adj, vis, dfsvis)) return true;
		}
	}

	return false;
}
int main() {

	int v, e;
	cin >> v >> e;
	vector<int> adj[v];

	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		//directed
		//adj[b].push_back(a);
	}

	if (isCycledfs(adj, v)) {
		cout << "Turu" << endl;
	}
	else {
		cout << "False" << endl;
	}
	return 0;
}
