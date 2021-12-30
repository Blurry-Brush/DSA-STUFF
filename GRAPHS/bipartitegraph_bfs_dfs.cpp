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

void runDFS(int ** edges, int n, int start, bool * visited, vector<int> &fill) {
	visited[start] = true;
	fill.push_back(start);

	for (int i = 0; i < n; i++) {
		if (i != start and !visited[i] and edges[start][i] == 1) {
			runDFS(edges, n, i, visited, fill);
		}
	}
}


vector<vector<int>> connectedComponents(int ** edges, int n) {
	vector<vector<int>> ans;

	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		if (!visited[i]) {
			runDFS(edges, n, i, visited, temp);
		}
		ans.push_back(temp);
	}

	return ans;
}

bool cycleDetectionBFS(int **edges, bool * visited, int n, int start) {
	queue<pair<int, int>> q;

	visited[start] = true;
	q.push(make_pair(start, -1));

	while (!q.empty()) {

		int node = q.front().first;
		int parent = q.front().second;
		q.pop();

		for (int i = 0; i < n; i++) {

			if (!visited[i] and edges[i][node] == 1) {
				visited[i] = true;
				q.push(make_pair(i, node));
			}
			else if (parent != i and edges[i][node] == 1) {
				return true;
			}
		}
	}
	return false;
}

bool cycleDetectionDFS(int node, int parent, bool * visited, int ** edges, int n) {
	visited[node] = true;

	for (int i = 0; i < n; i++) {
		if (edges[i][node] == 1) {
			if (!visited[i]) {
				if (cycleDetectionDFS(i, node, visited, edges, n)) return true;
			}
			else {
				if (i != parent) return true;
			}


		}
	}
	return false;
}

bool isCyclebfs(int n, int ** edges) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (cycleDetectionBFS(edges, visited, n, i)) {
				return true;
			}
		}
	}

	return false;

}

bool isCycledfs(int n, int ** edges) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (cycleDetectionDFS(i, -1, visited, edges, n)) {
				return true;
			}
		}
	}

	return false;

}
//bipartite graph
bool bipartitebfs(int ** edges, int n, int * color, int start) {

	queue<int> q;
	q.push(start);
	color[start] = 0;

	while (q.size() != 0) {
		int node = q.front();
		int nodecolor = color[node];
		//cout << nodecolor << endl;
		q.pop();

		for (int i = 0; i < n; i++) {
			if (color[i] == -1 and edges[node][i] == 1) {
				q.push(i);
				//color it alternatively
				if (nodecolor == 0) {
					color[i] = 1;
				}
				else {
					color[i] = 0;
				}
			}
			else if (color[i] == nodecolor and edges[node][i] == 1) {
				return false;
				//its not bipartite
			}
		}
	}


	return true;

}

bool bipartitedfs(int ** edges, int n, int node, int nodecolor, int* color) {
	color[node] = nodecolor;

	for (int i = 0; i < n; i++) {
		if (edges[i][node] == 1) {
			if (color[i] == -1) {
				if (!bipartitedfs(edges, n, i, 1 - nodecolor, color)) return false;
			}
			else {
				if (color[i] == nodecolor) {
					return false;
				}
			}
		}
	}
	return true;

}

bool isBipartitedfs(int ** edges, int n) {
	int * color = new int[n];
	for (int i = 0; i < n; i++) {
		color[i] = -1;
	}
	return bipartitedfs(edges, n, 0, 0, color);
}
bool isBipartitebfs(int ** edges, int n) {
	int * color = new int[n];
	for (int i = 0; i < n; i++) {
		color[i] = -1;
	}
	return bipartitebfs(edges, n, color, 0);
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
	if (isBipartitedfs(edges, n)) {
		cout << "Turu" << endl;
	}
	else {
		cout << "False" << endl;
	}
	return 0;
}
