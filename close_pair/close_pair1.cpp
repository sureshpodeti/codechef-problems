#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
float compute_distance(pair<int,int> *A, int i, int j);
float bruteforce_closest(pair<int, int> *A, int start, int end);
bool sort_by_first(const pair<int,int> &a, const pair<int,int> &b);
bool sort_by_second(const pair<int,int> &a, const pair<int,int> &b);
float strip_closest(pair<int,int> *strip, int d);
float closest_pair_distance_util(pair<int,int> *A, int start, int end);
float closest_pair_distance(pair<int,int> *A, int N);

float compute_distance(pair<int,int> *A, int i, int j){
  return sqrt(pow(A[i].first - A[j].first, 2) + pow(A[i].second - A[j].second, 2));
}

float bruteforce_closest(pair<int, int> *A, int start, int end){

  float result = 100000.00;
  for(int i=start;i<=end;++i){
    for(int j=i+1;j<=end;++j){
      result = min(result, compute_distance(A, i,j));

    }
  }
  return result;
}

bool sort_by_first(const pair<int,int> &a, const pair<int,int> &b){
  return (a.first < b.first);

}

bool sort_by_second(const pair<int,int> &a, const pair<int,int> &b){
  return (a.second < b.second);

}




float strip_closest(pair<int,int> *strip, int strip_count, int d){
  // sort the strip according to y values
  sort(strip, strip+strip_count, sort_by_second);

  float result = d;

  for(int i=0;i<strip_count;++i){

    for(int j=i+1;j<strip_count && (strip[j].second - strip[i].second)<result;++j){
      float dist = compute_distance(strip, i, j);
      if(dist<result){
	//update the result with the more minimum
	result = min(result, dist); 
      }
    }
  }

  return result;

}



float closest_pair_distance_util(pair<int,int> *A, int start, int end){

  if(end-start+1<=3){
    return bruteforce_closest(A, start, end);
  }
  
  int mid = start + (end-start)/2;
  pair<int,int> mid_point = A[mid];
  float d1 = closest_pair_distance_util(A, 0, mid);
  float d2 = closest_pair_distance_util(A, mid+1, end);

  // get the min of the d1, d2

  float d = min(d1, d2);

  // construct strip
  pair<int,int> *strip;

  // go through each point and push to strip if the distance
  //of that pt from mid is d units
  int strip_count= 0;
  for(int i=start;i<=end;++i){
    if(abs(A[i].first-mid_point.first)< d){
      strip[i].first = A[i].first;
      strip[i].second = A[i].second;
      strip_count++;
    }

  }
return min(d, strip_closest(strip, strip_count, d));
}

float closest_pair_distance(pair<int,int> *A, int N){
  //first sort the array by pairs first element
  sort(A, A+N, sort_by_first);

  return closest_pair_distance_util(A, 0, N-1);
}


int main(){
  int N, a, b;
  cin >> N;
  
  pair<int,int> A[N];
  

  for(int i=0;i<N;++i){
    cin >> a >> b;
    A[i].first = a;
    A[i].second = b;
  }


  cout << closest_pair_distance(A,N) << endl;

  



  
  return 0;
}
