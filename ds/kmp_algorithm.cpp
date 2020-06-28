#include<iostream>
using namespace std;



void KMPSearch(char *pat, char *txt){
  int M = strlen(pat);
  int N = strlen(txt);

  int lps[M];
  ComputeLPSArray(pat, lps, M);

  int i=0, j=0; // i for txt, and j for pat

  while(i<N){
    if(pat[j]==txt[i]){
      ++j;
      ++i;
    }

    if(j==M){
      cout << "Found Pattern at index:"<< i << endl;
      j = lps[j-1];
    }else if(i<N && pat[j]!=txt[i]){
      if(j!=0) j = lps[j-1];
      else ++i;

    }
  }

}
void ComputeLPSArray(char *pat, int *ls, int n){
  //first element ls value is 0
  ls[0] = 0;
  // set previous length proper profix that is also suffix
  int len = 0;

  int i=1;

  while(i<n){
    if(pat[i] == pat[len]){
      len++;
      ls[i] = len;
      ++i;
    }else{
      if(len!=0){
	len=ls[len-1];
      }else{
	ls[i] = 0;
        ++i;

      }
    }

  }
  


}
int main(){
  char pat[] = "ABABCABAB";
  int n = sizeof(pat)/sizeof(char);

  //define ls array
  int ls[n];
  ComputeLSArray(pat, ls, n);

  for(int i=0;i<n;++i)
    cout << ls[i] << " ";
  cout << endl;

    return 0;
}
