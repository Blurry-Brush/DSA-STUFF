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

vector<int> getPathdfs(int ** edges, int n, int start, int end, bool * visited) {


	if (start == end) {
		vector<int> ans;
		visited[end] = true;
		ans.push_back(end);
		return ans;
	}
	visited[start] = true;

	for (int i = 0; i < n; i++) {

		if (i != start and !visited[i] and edges[start][i] == 1) {
			vector<int> smallans = getPathdfs(edges, n, i, end, visited);
			visited[i] = true;
			if (smallans.size() != 0) {
				smallans.push_back(start);
				return smallans;
			}
		}
	}


	vector<int>ans;
	return ans;
}

vector<int> getPathbfs(int ** edges, int n, int start, int end, bool * visited) {
	queue<int> pn;
	pn.push(start);
	visited[start] = true;
	unordered_map<int, int> mpp;
	vector<int> ans;

	while (!pn.empty()) {
		int curr = pn.front();
		pn.pop();

		for (int i = 0; i < n; i++) {
			//add adjacent

			if (!visited[i] and edges[curr][i] == 1) {
				visited[i] = true;
				pn.push(i);
				mpp[i] = curr;

				if (i == end) {
					//stop
					int x = end;
					while (x != start) {
						ans.push_back(x);
						x = mpp[x];
					}
					//ans.push_back(x);

					ans.push_back(start);
					return ans;

				}
			}
		}
	}

	return ans;
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

	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	vector<int> v = getPathdfs(edges, n, 0, 4, visited);
	for (auto value : v) {
		cout << value << " ";
	}

	delete []visited;
	return 0;
}
