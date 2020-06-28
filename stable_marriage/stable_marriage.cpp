#include<iostream>
#define N 4
using namespace std;

bool wPrefersM1OverM(int prefer[2*N][N], int women, int m, int m1){
  for(int i=0;i<N;++i){
    if(prefer[women][i] == m1)
      return true;

    if(prefer[women][i]==m)
      return false;
  }

  return false;
}

void StableMarriage(int prefer[2*N][N]){
  // define an array to store the final answer, indexes will be women identity
  // values will be men to whose ith women married

  int women_partner[N]; // -1 default that says not assigned any men

  // array to store if ith men is free or not; i.e not married
  bool free_men[N];


  memset(women_partner, -1,sizeof(women_partner));
  memset(free_men, true, sizeof(free_men));

  int free_men_count = N;

  while(free_men_count>0){
    int m;
    //get the men who is free
    for(m=0;m<N;++m)
      if(free_men[m])
	break;


    // assign women for the mth men
    for(int i=0;i<N && free_men[m];++i){
      int women = prefer[m][i];

      //check if the parnters
      if(women_partner[women-N]==-1){
	// women not picked already
	women_partner[women-N] = m;
	free_men[m] = false;
	free_men_count--;
      }else{
	// if women is already assigned to any men
	//get the current women assignment
	int m1 = women_partner[women-N];

	if(!wPrefersM1OverM(prefer, women, m, m1)){
	  women_partner[women-N] = m;
	  free_men[m] = false;
	  free_men[m1] = true;
         }
	
      }

    }

  }

  cout << "Women Men" << endl;

  for(int i=0;i<N;++i)
    cout << " " << i+N << "\t" << women_partner[i] << endl;  
  
}


int main(){
  
  // first N rows tells the preference list of men (men prefer women)
  // next N rows tells the preference list of women ( women prefer men)
  int prefer[2*N][N] = { {7, 5, 6, 4}, 
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
    };

  StableMarriage(prefer);

  return 0;
}
