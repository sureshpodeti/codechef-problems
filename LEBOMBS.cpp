#include<iostream>

using namespace std;

int main(){

    int T, N;
    cin >> T;

    string st;
    while(T--){
        cin >> N >> st;
        int bExplodeStat[N];

        // initialize with all zeros
        for(int i=0;i<N;++i) bExplodeStat[i] = 0;
        //corner cases, first room and last room
        if(st[0]=='1') {
                bExplodeStat[0] = 1;
                if(N>1) bExplodeStat[1] = 1;
        }

        if(st[N-1]=='1'){
            bExplodeStat[N-1] = 1;
            if(N>1) bExplodeStat[N-2] = 1;
        }


        // fill the remaining
        for(int i=1;i<N-1;++i){
            // look at the current room, if it has bomb
            // if adjancent rooms explode status is not set to 1, set it
            if(st[i]=='1'){
                bExplodeStat[i] = 1;
                if(bExplodeStat[i-1]!=1) bExplodeStat[i-1] = 1;
                if(bExplodeStat[i+1]!=1) bExplodeStat[i+1] = 1;
            }
        }


        //counting the rooms that will not explode
        int counter = 0;
        for(int i=0;i<N;++i)
            if(!bExplodeStat[i]) ++counter;


        cout << counter << endl;
    }

    return 0;
}
