// MST(Minimum Spanning Tree)
// 최소 신장 트리는 두 종류 알고리즘으로 풀 수 있다.
// 크루스칼 알고리즘 VS 프림 알고리즘
// 크루스칼 알고리즘은 간선을 선택하며 찾는 알고리즘
// 프림 알고리즘은 정점을 선택하며 찾는 알고리즘이다.

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long V, E;

long long getRoot(vector<long long>& parent, long long x) {
	if (parent[x] == x) return x;
	
	return parent[x] = getRoot(parent, parent[x]);
}

void unionParent(vector<long long>& parent, long long a, long long b) {
	a = getRoot(parent, a);
	b = getRoot(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(vector<long long>& parent, long long a, long long b) {
	a = getRoot(parent, a);
	b = getRoot(parent, b);

	if (a == b) return true;
	else return false;
}

bool compare(vector<long long> a, vector<long long> b) {
	return a[2] < b[2];
}

int main() {
	scanf("%lld %lld", &V, &E);

	vector<vector<long long>> costs;

	// Costs Initialize
	for (long long e = 0; e < E; ++e) {
		vector<long long> temp;
		long long A, B, C;
		
		scanf("%lld %lld %lld", &A, &B, &C);

		temp.push_back(A);
		temp.push_back(B);
		temp.push_back(C);

		costs.push_back(temp);
	}

	sort(costs.begin(), costs.end(), compare);

	// Parent Initialize
	vector<long long> parent(V + 1);

	for (long long i = 1; i <= V; ++i) {
		parent[i] = i;
	}

	int answer = 0;

	for (long long i = 0; i < costs.size(); ++i) {
		if (!find(parent, costs[i][0], costs[i][1])) {
			unionParent(parent, costs[i][0], costs[i][1]);
			answer += costs[i][2];
		}
	}

	printf("%d", answer);

	return 0;
}
