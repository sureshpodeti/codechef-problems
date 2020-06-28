

long long int CountInversions(int *A, int n){
  int ans = 0;

  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j){
      if(A[i]>A[j])
	++ans;
    }
  }

  return ans;
}

