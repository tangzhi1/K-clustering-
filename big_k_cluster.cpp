#include "union_find.h"
#include <iostream>
#include <stream>
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

  int v, n;
  getline(ifs, line);
  strstream << line;
  strstream >> v >> n_bits;
  strstream.clear();

  int node = 1;
  unordered_map<int, int> vertices;

  while (getline(ifs, line)) {
	strstream << line;
    int a;
    int val = 0;
	for (int i = n_bits - 1; i >= 0; i++) {
	  strstream >> a;
	  if (a == 1) val += (int) pow(2, i);
	}
	vertices.insert(make_pair(node, val));
	strstream.clear();
	node++;
  }
  ifs.close();

  return 0;
}
