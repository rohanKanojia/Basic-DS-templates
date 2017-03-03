#ifndef SEGMENT_TREE
#define SEGMENT_TREE

#define SIZE 100000
struct Node { 
  // Structure for segment tree node :
  long long val
};

class SegmentTree {
  Node tree[4*SIZE];
  long long parents[SIZE];
  long long size;
  vector<long long> elements;
  Node mergeNodes(Node a, Node b) {
    Node res;
    // merge logic for two nodes
    res.val = a.val + b.val;
    return res;
  }
public:
  SegmentTree(vector<long long> arr) : size(arr.size()) {
    elements = arr;
    buildTree(0, 0, size-1);
  }
  void buildTree(long long curNode, long long start, long long end) {
    if(start == end) {
      // logic for a single leaf Node 
      tree[curNode].val = elements[start];
      parents[start] = curNode;
    }
    else {
      long long l = curNode * 2 + 1;
      long long r = curNode * 2 + 2;

      long long mid = (start + end)/2;
      buildTree(l, start, mid);
      buildTree(r, mid+1, end);

      tree[curNode] = mergeNodes(tree[l], tree[r]);
    }
  }
  Node query(long long curNode, long long start, long long end, long long qx, long long qy) {
    if(qx == start && qy == end)
      return tree[curNode];

    long long l = curNode*2 + 1;
    long long r = curNode*2 + 2;
    long long mid = (start+end)/2;

    if(qy <= mid)
      return query(l, start, mid, qx, qy);
    else if(qx > mid)
      return query(r, mid+1, end, qx, qy);
    else
      return mergeNodes(query(l, start, mid, qx, mid), query(r, mid+1, end, mid+1, qy));
  }
  void update(long long x, long long val) {
    long long curNode = parents[x];
    tree[curNode].maxVal = val;
    tree[curNode].secondMax = 0;

    curNode = (curNode-1)/2;
    while(curNode > 0) {
      tree[curNode] = mergeNodes(tree[2*curNode+1], tree[2*curNode+2]);
      curNode = (curNode-1)/2;
    }
    tree[0] = mergeNodes(tree[1], tree[2]);
  }
};
#endif
