#include<iostream>

using namespace std;


int main(){
    int T, N;
    cin >> T;

    string S;

    while(T--){
         cin >> N;
         char G[N][N];

         int row = 0;
         int EAST[N][N], SOUTH[N][N];

         int sze = N;

         while(N--){
            cin >> S;
            for(int i=0;i<sze;++i)
                G[row][i] = S[i];

            ++row;
         }


         int isBlocked = 0;
         //fill the east grid
         for(int i=0;i<sze;++i){
                isBlocked = 0;
            for(int j=sze-1;j>=0;--j){
                    if(G[i][j]=='#')
                        isBlocked = 1;
                    EAST[i][j] = isBlocked;
            }
         }


         //fill the south grid
         for(int j=0;j<sze;++j){
                isBlocked = 0;
            for(int i=sze-1;i>=0;--i){
                    if(G[i][j]=='#')
                        isBlocked = 1;
                    SOUTH[i][j] = isBlocked;
            }
         }


        int result = 0;



         // counting the locations to place the mirror
         for(int i=0;i<sze;++i){
            for(int j=0;j<sze;++j){
                    if(G[i][j]=='.'){
                        if(i==sze-1 && j==sze-1) ++result;
                        else if(i==sze-1&&j<sze-1 && EAST[i][j+1]==0) ++result;
                        else if(j==sze-1 && i<sze-1&& SOUTH[i+1][j]==0) ++result;
                        else if(SOUTH[i+1][j]==0 && EAST[i][j+1]==0) ++result;
                    }


            }
         }
         cout << result << endl;





    }
    return 0;
}
