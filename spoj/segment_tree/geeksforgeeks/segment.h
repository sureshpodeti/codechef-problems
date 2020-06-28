class SegmentTree{
  int no_of_nodes;
  int *segment_tree;
public:
  SegmentTree(int);
  int CountOfInversions(int, int, int, int, int);
  void Update(int, int, int, int);
  int GetAnswer(int*, int, int);
  int ComputeMidIndex(int, int);
  void Display();
};

SegmentTree::SegmentTree(int max_num){
  int height = int(ceil(log2(max_num)));
  no_of_nodes = 2*int(pow(2,height)) - 1;

  segment_tree = new int[no_of_nodes];

  for(int i=0;i<no_of_nodes;++i)
    segment_tree[i] = 0;
}

int SegmentTree::ComputeMidIndex(int node_left, int node_right){
  return node_left + (node_right - node_left)/2;
}


void SegmentTree::Update(int node, int node_left, int node_right, int index){

  if(index<node_left || index>node_right)
    return;
  
  if(node_left==node_right){
    segment_tree[node] = 1;
    return;
  }

  int mid = ComputeMidIndex(node_left, node_right);
  Update(2*node+1, node_left, mid, index);
  Update(2*node+2, mid+1, node_right, index);

  segment_tree[node] = segment_tree[2*node+1] + segment_tree[2*node+2];
}

int SegmentTree::CountOfInversions(int node, int node_left, int node_right, int left, int right){
  if(left>right) return 0;
  if(left>node_right || right<node_left)
    return 0;

  if(left<=node_left&&right>=node_right)
    return segment_tree[node];

  int mid = ComputeMidIndex(node_left, node_right);
  int a = CountOfInversions(2*node+1, node_left, mid, left, right);
  int b = CountOfInversions(2*node+2, mid+1, node_right, left, right);
  return a+b;
}
int SegmentTree::GetAnswer(int *A, int n, int max_value){
  int ans = 0;
  for(int i=0;i<n;++i){
    ans += CountOfInversions(0, 0, max_value, A[i]+1,  max_value);
    Update(0, 0, max_value, A[i]);
  }
 
  return ans;
}
