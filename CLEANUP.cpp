
#include<iostream>
#include<vector>

using namespace std;


int main(){
    int T, n,m;
    cin >> T;

    while(T--){
        cin >> n >> m;
        int completed[m];
        for(int i=0;i<m;++i)
            cin >> completed[i];

        // define an array of size n
        int allStatus[n];

        // initializing the unfinished array with all 0's
        // 1 indicated finshed job, 0 unfinished
        for(int i=0;i<n;++i)
            allStatus[i] = 0;

        // update the information of finished jobs
        for(int i=0;i<m;++i)
            allStatus[completed[i]-1] = 1;


        // vector for unfinished jobs
        vector<int> unfinished;
        for(int i=0;i<n;++i)
            if(allStatus[i]==0) unfinished.push_back(i+1);


        int sze = n-m;
        if(sze>0){
            //printout the chefs jobs
        for(int i=0;i<sze;i=i+2)
            cout << unfinished[i] << " ";
        cout << endl;

        if(sze>=2){
            for(int i=1;i<sze;i=i+2)
                cout << unfinished[i] << " ";
            cout << endl;
        }else cout << endl;

        }else cout << endl;


    }


    return 0;
}
