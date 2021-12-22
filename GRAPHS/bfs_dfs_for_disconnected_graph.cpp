#include <bits/stdc++.h>

using namespace std;

void printDFS(int ** edges, int n, int sv, bool * visited) {
	//dfs
	cout << sv << endl;
	visited[sv] = true;

	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}

		if (edges[sv][i] == 1) {
			if (visited[i]) {
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void printBFS(int ** edges, int n, int sv, bool * visited) {
	//bfs
	queue<int> q;
	q.push(sv);
	visited[sv] = true;

	while (q.size() != 0) {
		int front = q.front();
		q.pop();
		cout << front << endl;

		for (int i = 0; i < n; i++) {
			if (i != front and edges[front][i] == 1 and !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void BFS(int ** edges, int n) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			printBFS(edges, n, i, visited);
		}
	}
	delete []visited;
}

void DFS(int ** edges, int n) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			printDFS(edges, n, i, visited);
		}
	}
	delete []visited;
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

	BFS(edges, n);

	return 0;
}
