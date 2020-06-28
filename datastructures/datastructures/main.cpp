//
//  main.cpp
//  datastructures
//
//  Created by spodeti on 21/03/20.
//  Copyright © 2020 spodeti. All rights reserved.
//

#include <iostream>
#include<map>

using namespace std;

void playStrings(string *ar, int n){
    int open[27], close[27];
    
    for(int i=0;i<27;++i){
        open[i] = 0;
        close[i] = 0;
    }

    for(int i=0;i<n;++i){
        char first_char = ar[i][0];
        char last_char = ar[i][ar[i].length()-1];

        open[first_char-'a'+1] += 1;
        close[last_char-'a'+1] += 1;
    }
    
    for(int i=1;i<=26;++i){
        int val = min(open[i], close[i]);
        open[i] -= val;
        close[i] -= val;
    }

    int st_counter = 0, en_counter= 0;
    int st_sum = 0, en_sum = 0;
    
    for(int i=1;i<=26;++i){
        if(open[i]!=0){
            st_counter++;
            st_sum += open[i];
        }
        
        if(close[i]!=0){
            en_counter++;
            en_sum += close[i];
        }
    }
    
    if((st_counter==1 && st_sum==1) || st_counter==0){
        cout << "Ordering is possible" << endl;
    }else {
        cout << "The door cannot be opened" << endl;
    }
 
    
    
}
int main(int argc, const char * argv[]) {
    
    int t,n;
    cin >> t;
    
    while(t--){
        cin >> n;
        
        string ar[n];
        
        for(int i=0;i<n;++i)
            cin >> ar[i];
        
        playStrings(ar, n);
    }
    
    
    return 0;
}
