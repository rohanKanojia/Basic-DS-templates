#ifndef DISJOINT_SET
#define DISJOINT_SET
typedef struct Subset { int parent, rank; } Subset;
class DisjointSet {
  vector<Subset> subsets;
public:
  DisjointSet(long long V) {
    for(long long i = 0; i < V; i++) {
      Subset aSubset;
      aSubset.parent = i;
      aSubset.rank = 0;
      subsets.push_back(aSubset);
    }
  }
  void Union(long long x, long long y) {
    long long xRt = Find(x);
    long long yRt = Find(y);

    if(subsets[xRt].rank < subsets[yRt].rank)
      subsets[xRt].parent = yRt;
    else if(subsets[xRt].rank > subsets[yRt].rank)
      subsets[yRt].parent = xRt;
    else {
      subsets[yRt].parent = xRt;
      subsets[xRt].rank++;
    }
  }
  long long Find(long long x) {
    if(subsets[x].parent != x)
      subsets[x].parent = Find(subsets[x].parent);
    return subsets[x].parent;
  }
};
#endif
