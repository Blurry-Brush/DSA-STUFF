#include <bits/stdc++.h>

using namespace std;

class edge {
public:
	int source;
	int dest;
	int weight;

	edge(int source, int dest, int weight) {
		this->source = source;
		this->dest = dest;
		this->weight = weight;
	}
};

bool comp(edge a, edge b) {
	return a.weight < b.weight;
}

int findPar(vector<int> & parent, int node) {
	//int ans = parent[element];
	// while (element != parent[element]) {
	// 	element = parent[element];
	// }
	// return element;
	if (parent[node] == node) {
		return parent[node];
	}

	return parent[node] = findPar(parent, parent[node]);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
	u = findPar(parent, u);
	v = findPar(parent, v);

	if (rank[u] < rank[v]) {
		parent[u] = v;

	}
	else if (rank[u] > rank[v]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}

int main() {

	int n, e;
	cin >> n >> e;

	vector<edge>input;
	vector<edge>mst;

	while (e--) {
		int s, d, w;
		cin >> s >> d >> w;
		input.push_back(edge(s, d, w));
	}
	//sort the input array according to the weight
	sort(input.begin(), input.end(), comp);

	//implementing disjoint set union
	vector<int> parent(n);
	vector<int> rank(n, 0);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int countformst = 0;
	//implementing the find parent function

	for (int i = 0; i < input.size(); i++) {
		if (countformst == n - 1) {
			//tree property
			break;
		}
		if (findPar(parent, input[i].source) != findPar(parent, input[i].dest)) {
			mst.push_back(input[i]);
			//parent[input[i].source] = input[i].dest;
			unionn(input[i].source, input[i].dest, parent, rank);
			countformst++;
		}
		//check for parents.
	}

	for (auto it : mst) {
		cout << it.source << " " <<  it.dest << " " << it.weight << endl;
	}

	return 0;
}
