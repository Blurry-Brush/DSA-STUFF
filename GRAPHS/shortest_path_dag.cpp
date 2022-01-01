#include <bits/stdc++.h>
#define INF INT_MAX
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

bool checkCyclebfs(int n, vector<int> adj[]) {
	queue<int> q;
	vector<int> indegree(n, 0);

	for (int i = 0; i < n; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	int count = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		count++;
		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0) {
				q.push(it);
			}
		}
	}

	return !(count == n);
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


void shortestpath_undirected_unweighted_BFS(vector<int> adj[] , int n, int source) {
	int dist[n];
	for (int i = 0; i < n; i++) {
		dist[i] = INT_MAX;
	}

	queue<int> q;
	dist[source] = 0;
	q.push(source);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int distance = dist[cur];

		for (auto it : adj[cur]) {
			if (distance + 1 < dist[it]) {
				dist[it] = (distance + 1);
				q.push(it);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
}

void findtoposort(int node, vector<pair<int, int>> adj[], int n, stack<int> &st, int vis[]) {
	vis[node] = 1;

	for (auto it : adj[node]) {
		if (!vis[it.first]) {
			findtoposort(it.first, adj, n, st, vis);
		}
	}
	st.push(node);
}

void shortest_path_dag(int source, int n, vector<pair<int, int> > adj[]) {
	int vis[n] = {0};
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			findtoposort(i, adj, n, st, vis);
		}
	}

	int dist[n];
	for (int i = 0; i < n; i++) {
		dist[i] = 1e9;
	}
	dist[source] = 0;
	while (!st.empty()) {

		int node = st.top();
		st.pop();

		if (dist[node] != INF) {

			for (auto it : adj[node]) {
				if (dist[node] + it.second < dist[it.first]) {
					dist[it.first] = dist[node] + it.second;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		(dist[i] == INF) ? cout << "INF" : cout << dist[i] << " ";
	}
}
int main() {

	int v, e;
	cin >> v >> e;
	vector< pair<int, int> > adj[v];

	while (e--) {
		int a, b , wt;
		cin >> a >> b >> wt;
		adj[a].push_back({b, wt});
		//directed and weighted
		//adj[b].push_back(a);
	}

	shortest_path_dag(0, v, adj);
	return 0;
}
