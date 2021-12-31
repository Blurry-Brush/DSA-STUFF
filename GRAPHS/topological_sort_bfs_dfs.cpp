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

//topological sorts
void toposort(int node, vector<int> adj[], int n, stack<int> &st, int vis[]) {
	vis[node] = 1;

	for (auto it : adj[node]) {
		if (!vis[it]) {
			toposort(it, adj, n, st, vis);
		}
	}
	st.push(node);
}

vector<int> toposortbfs(int n, vector<int> adj[]) {
	queue<int> q;
	vector<int> indegree(n, 0);

	for (int i = 0; i < n; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}
	//indegree zero wale se start hoga
	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topo;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
	}
	return topo;
}


vector<int> topohelper(vector<int> adj[], int n) {
	stack<int> st;
	int vis[n];
	memset(vis, 0, sizeof vis);

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			toposort(i, adj, n, st, vis);
		}
	}
	vector<int> t;
	while (!st.empty()) {
		t.push_back(st.top());
		st.pop();
	}
	return t;
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

	vector<int> arr = toposortbfs(v, adj);
	for (auto value : arr) {
		cout << value << " ";
	}

	// if (isCycledfs(adj, v)) {
	// 	cout << "Turu" << endl;
	// }
	// else {
	// 	cout << "False" << endl;
	// }
	return 0;
}
