#include<iostream>
using namespace std;
int computeDist(int a, int b, int u, int v){
    return (a-u)*(a-u) + (v-b)*(v-b);
}
int main(){
    int N;
    cin >> N;

    int x1, y1, x2, y2, x3, y3;
    int counter = 0;
    for(int i=0;i<N;++i){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int D[3];

        D[0] = computeDist(x1,y1, x2,y2);
        D[1] = computeDist(x1,y1, x3, y3);
        D[2] = computeDist(x2,y2, x3,y3);

        //sum of the squres of two sides equals to square of other side
        //sort the array
        sort(D, D+3);

        if(D[2] == D[1] + D[0]) ++counter;

    }

    cout << counter << endl;


    return 0;

}
