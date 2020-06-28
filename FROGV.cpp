#include<iostream>
#include<algorithm>
typedef long long int LLI;
using namespace std;


int getIndex(LLI B[], int N, LLI location){

    // apply binary search to find the index of the location
    int i=0, j = N;
    int index=-1;

    while(i<=j){
        //compute mid
        int mid = i + (j-i)/2;
        if(B[mid]==location){
                index = mid;
                break;

        }else if(B[mid]>location){
            // go left, update j
            j = mid-1;

        }else{
            // go right, update i
            i = mid+1;
        }
    }



    return index;
}
int main(){
    int N, P, p,q;
    LLI K;

    cin >> N >> K >> P;


    LLI A[N];
    for(int i=0;i<N;++i) cin >> A[i];

    LLI B[N];
    //copy all A to B, and work on B
    for(int i=0;i<N;++i) B[i] = A[i];


    //sort array B
    sort(B, B+N);

    //define array C that groups frogs by location
    LLI C[N];

    int g = 0;
    LLI lastPoint=B[0], currPoint;
    C[0] = 0;
    for(int i=1;i<N;++i){
        //set the current Point
        currPoint = B[i];
        if((currPoint-lastPoint)<=K){
            C[i] = g;
        }else{
            ++g;
            C[i] = g;
        }

        //update lastPoint
        lastPoint = currPoint;
    }




    while(P--){
        cin >> p >> q;
        LLI lp = A[p-1]; // location of pth frog
        LLI lq = A[q-1]; // location of qth frog

        //Find the index of lp, and lq from the array B
        int lpIndex = getIndex(B, N, lp);
        int lqIndex = getIndex(B, N, lq);
        if((lpIndex!=-1 && lqIndex!=-1 ) && C[lpIndex]==C[lqIndex]) cout << "Yes" << endl;
        else cout << "No" << endl;

    }


    return 0;
}
