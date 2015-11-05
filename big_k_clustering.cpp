#include "union_find.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

int main(int argc, char *argv[]) {
  char *filename = argv[1];
  ifstream ifs;
  ifs.open(filename);
  if (!ifs) {
    cerr << "File not found." << endl;
	exit(1);
  }  

  string line;
  stringstream strstream;

  int v, n_bits;
  getline(ifs, line);
  strstream << line;
  strstream >> v >> n_bits;
  strstream.clear();

  int node = 0;
  unordered_map<int, int> vertices;
  unordered_map<int, int>::iterator it;
  while (getline(ifs, line)) {
	strstream << line;
    int a;
    int val = 0;
	for (int i = n_bits - 1; i >= 0; i--) {
	  strstream >> a;
	  if (a == 1) val += (int) pow(2, i);
	}
	it = vertices.find(val);
	if (it == vertices.end())
	  node++;
	  vertices.insert(make_pair(val, node));
	strstream.clear();
  }
  ifs.close();

  UnionFind connected(node);
  int cluster_count = node;

  unordered_map<int, int>::iterator it1 = vertices.begin(), it2 = vertices.begin();
  //find edges with cost = 1;
  for (it = vertices.begin(); it != vertices.end(); it++) {

	cout << cluster_count << " " << node << endl;
    for (int i = 0; i < n_bits; i++) {
      int a = (int) pow(2, i);
	  int hd_one = a ^ it->first;
	  it1 = vertices.find(hd_one);
	  if (it1 != vertices.end()) {
        if (connected.find(it->second) != connected.find(it1->second)) {
          connected.unite(it->second, it1->second);
		  cluster_count--;
	    }
	  }

      for (int j = i + 1; j < n_bits; j++) {
        int b = (int) pow(2, j);
		int hd_two = hd_one ^ b;
		it2 = vertices.find(hd_two);
		if (it2 != vertices.end()) {
		  if (connected.find(it->second) != connected.find(it2->second)) {
            connected.unite(it->second, it2->second);
		    cluster_count--;
		  }
		}

      }
    }
  }
  
  cout << cluster_count << endl;
  //cout << vertices.begin()->first << endl;
  /*
  unordered_map<int, int>::iterator it = vertices.begin();
  while (it != vertices.end()) {
    cout << it->first << " " << it->second << endl;
	it++;
  }
  */
  return 0;
}
