#include<stdio.h>

int main(){
    int T, N, M;
    scanf("%d", &T);

    while(T--){
        scanf("%d%d", &N, &M);
        int A[N];

        int maxNum = 0;

        for(int i=0;i<N;++i){
                scanf("%d", &A[i]);
                maxNum = (maxNum<A[i])?A[i]: maxNum;
        }

        //get the filling required to match the highest number
        long long int S = 0;
        for(int i=0;i<N;++i){
            if(A[i]==maxNum) continue;
            else S += maxNum-A[i];
        }

        long long int diff = M-S;
        if(diff<0) printf("No\n");
        else{
            if(diff%N==0) printf("Yes\n");
            else printf("No\n");
        }




    }


    return 0;
}
