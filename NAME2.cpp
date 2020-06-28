#include<iostream>

using namespace std;



// O(m) or O(n) based on m>n or n>m
int isMarryBetter(string a,string b){

    int i=0, counter1=0, counter2=0;
    for(int j=0;i<a.length() && j<b.length();++j){
        if(a[i]==b[j]){
            ++counter1;
            ++i;
        }
    }


    i = 0;
    for(int j=0;i<b.length() && j<a.length();++j){
        if(a[j]==b[i]){
                ++counter2;
                ++i;

        }
    }
    return (counter1==a.length() || counter2==b.length()) ;
}
int main(){

    int T;
    cin >> T;


    string a, b;
    while(T--){
        cin >> a >> b;
        cout << ((isMarryBetter(a,b))?"YES":"NO") << endl;
    }
    return 0;
}
