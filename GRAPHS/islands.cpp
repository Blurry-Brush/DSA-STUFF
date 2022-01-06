#include <bits/stdc++.h>

using namespace std;


void islandsDFS(int ** edges, int n, int start, bool * visited) {
	visited[start] = true;

	for (int i = 0; i < n; i++) {
		if (edges[i][start] == 1 and !visited[i]) {
			islandsDFS(edges, n, i, visited);
		}
	}
}

int islands(int n, int ** edges) {
	int count = 0;
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			islandsDFS(edges, n, i, visited);
			count++;
		}
	}

	return count;
}
int main() {

	int n, e;
	cin >> n >> e;

	int ** edges = new int*[n];

	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];

		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	//matrix completed

	// bool * visited = new bool[n];
	// for (int i = 0; i < n; i++) {
	// 	visited[i] = false;
	// }

	// vector<vector<int>> p = connectedComponents(edges, n);

	// for (int i = 0; i < p.size(); i++) {
	// 	for (int j = 0; j < p[i].size(); j++) {
	// 		cout << p[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// vector<int> v = getPathdfs(edges, n, 0, 4, visited);
	// for (auto value : v) {
	// 	cout << value << " ";
	// }

	//delete []visited;

	cout << islands(n, edges);

	return 0;
}
