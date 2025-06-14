// 크루스칼 알고리즘
// 크루스칼 알고리즘은 간선만 알면된다.
// 간선을 알면, 연결되어있는 두 정점과 가중치만을 알수 있기 때문에
// 간선의 개수만 찾아 정렬하면 된다.

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

struct STARS {
	double x, y;
};

struct EDGE {
	int node1, node2;
	double dist;
};

STARS star[100] = { 0, };
//EDGE edge[100 * 99 / 2] = { 0, }; // 100 * 99 / 2
vector<EDGE> edge;

int parent[100] = { 0, };

double calcDist(STARS* a, STARS* b) {
	double dx = (a->x - b->x) * (a->x - b->x);
	double dy = (a->y - b->y) * (a->y - b->y);

	return sqrt(dx + dy);
}

void quicksort(int left, int right) {
	if (left >= right) return;

	int l = left;
	int r = right;
	EDGE pivot = edge[(l + r) / 2];

	while (true) {
		while (edge[l].dist < pivot.dist) ++l;
		while (pivot.dist < edge[r].dist) --r;

		if (l >= r) break;

		EDGE temp = edge[l];
		edge[l] = edge[r];
		edge[r] = temp;
	}

	quicksort(left, l - 1);
	quicksort(r + 1, right);
}

int getRoot(int x) {
	if (parent[x] == x) return x;

	return parent[x] = getRoot(parent[x]);
}

void unionParent(int a, int b) {
	a = getRoot(a);
	b = getRoot(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(EDGE x) {
	int a = getRoot(x.node1);
	int b = getRoot(x.node2);

	if (a == b) return true;
	else return false;
}

bool compare(EDGE a, EDGE b) {
	return a.dist < b.dist;
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; ++i) {
		scanf("%lf %lf", &star[i].x, &star[i].y);
	}

	// Graph 생성
	//int e = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			EDGE temp;
			temp.node1 = i;
			temp.node2 = j;
			temp.dist = calcDist(&star[i], &star[j]);
			
			edge.push_back(temp);
			/*edge[e].node1 = i;
			edge[e].node2 = j;

			edge[e].dist = calcDist(&star[i], &star[j]);

			++e;*/
		}
	}

	// Parent 생성
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
	}

	int e = edge.size();

	//quicksort(0, e - 1);
	sort(edge.begin(), edge.end(), compare);

	// 최소신장트리 크루스칼 알고리즘
	double min_dist = 0.0;

	for (int i = 0; i < e; ++i) {
		if (!find(edge[i])) {
			unionParent(edge[i].node1, edge[i].node2);
			min_dist += edge[i].dist;
		}
	}

	printf("%.2f\n", min_dist);
	
	return 0;
}
