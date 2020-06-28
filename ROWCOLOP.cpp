#include<iostream>

using namespace std;


int main(){
    int N, Q;
    cin >> N >> Q;

    string op;
    int RC, X;

    long long int row[N], col[N];
    //initialize the array row, and col with all zeros
    for(int i=0;i<N;++i){
        row[i] = 0;
        col[i] = 0;
    }



    for(int i=0;i<Q;++i){
        cin >> op >> RC >> X;

        if(op=="RowAdd") row[RC-1] += X;
        else col[RC-1] += X;

    }

    // get the maximum value in row, col arrays
    long long int maxRow=0, maxCol=0;
    for(int i=0;i<N;++i){
        maxRow = max(maxRow, row[i]);
        maxCol = max(maxCol, col[i]);
    }

    cout << maxRow+maxCol << endl;



    return 0;
}
