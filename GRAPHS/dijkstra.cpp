#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;



void dijkstra(int n, vector<pair<int, int>> adj[], int source) {
	vector<int> distTo(n, INT_MAX);

	//greedy(choosing the minimal first)
	priority_queue < pair<int, int> , vector<pair<int, int>> , greater<pair<int, int> > > pq;
	pq.push(make_pair(0, source));

	distTo[source] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int node = pq.top().second;

		pq.pop();

		for (auto it = adj[node].begin(); it != adj[node].end(); it++) {
			int nextNode = it->first;
			int nextDist = it->second;

			if (distTo[node] + nextDist < distTo[nextNode]) {
				distTo[nextNode] = distTo[node] + nextDist;
				pq.push(make_pair(distTo[nextNode] , nextNode));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << distTo[i] << " ";
	}
	cout << endl;

}
int main() {

	int v, e;
	cin >> v >> e;
	vector< pair<int, int> > adj[v];

	while (e--) {
		int a, b , wt;
		cin >> a >> b >> wt;
		adj[a].push_back({b, wt});
		//undirected and weighted
		adj[b].push_back({a, wt});
	}

	dijkstra(v, adj, 0);
	return 0;
}
