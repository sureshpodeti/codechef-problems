#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int T, N, a, b;
    cin >> T;

    while(T--){
        cin >> N;
	vector<pair<int, int> > vect;
      
        for(int i=0;i<N;++i){
	  cin >> a >> b;
	  vect.push_back(pair<int, int>(b, a));
	}
            
        sort(vect.begin(), vect.end());

	
	int slot_begin = vect[N-1].second;
	

        int bombs  = 1;
        for(int i=N-2;i>=0;--i){
	  if(slot_begin<=vect[i].first){
	    continue;
	 
	  }else{
	    ++bombs;
	    slot_begin = vect[i].second;

	  }

        }

        cout << bombs << endl;



    }

    return 0;
}
