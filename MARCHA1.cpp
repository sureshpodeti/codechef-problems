// Recursion solution
// Time complexity: O(2^N)
#include<iostream>

using namespace std;

int change(int A[], int N, int M){
    //base cases
    // if we already made the change
    if(M==0)
        return 1;

    //some times coins are not sufficient to make the change
    if(M<0 || (M>0 && N<=0)) return 0;


    // assuming if the last element present in the subset that gives target sum M
    int a = change(A, N-1, M-A[N-1]);


    // not assuming the element
    int b = change(A, N-1, M);

    return a || b;

}
int main(){
    int T, N;
    cin >> T;

    long long int M;
    while(T--){
            cin >> N >> M;
            int A[N];
            for(int i=0;i<N;++i)
                cin >> A[i];



            cout << (change(A, N, M)?"Yes": "No") << endl;

    }

    return 0;
}
