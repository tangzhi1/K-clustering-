#ifndef UNION_FIND_H
#define UNION_FIND_H

#include<vector>
using namespace std;

class UnionFind {
	private:
		vector<int> father;
		vector<int> rank;
		
	public:
		UnionFind();
		UnionFind(int n);
		int find(int x);
		void unite(int x, int y);
};

#endif
