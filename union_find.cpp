#include "union_find.h"
#include <vector>
#include <iostream>
using namespace std;

UnionFind :: UnionFind() {}

UnionFind :: UnionFind(int n) {
	father.reserve(n + 1);
	rank.reserve(n + 1);
	for (int i = 0; i <= n; i++) {
		father.push_back(i);
		rank.push_back(0);
	}
}

int UnionFind :: find(int x) {
	if (x != father[x]) {
		father[x] = find(father[x]);
	}
	return father[x];
}

void UnionFind :: unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rank[x] > rank[y]) {
		father[y] = x;
	}
	else {
		if (rank[x] == rank[y]) rank[y]++;
		father[x] = y;
	}
}
