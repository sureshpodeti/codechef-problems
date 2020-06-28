
#include<stdio.h>
#include<string.h>

int main(){
    int N , K, open, close, tweetNum;
    scanf("%d%d", &N, &K);

    int A[N+1];
    for(int i=0;i<=N;++i) A[i] = 0; // initially all closed

    close = N;

    char st[12];

    while(K--){
            scanf("%s", st);
            if(strcmp(st, "CLICK") == 0){
                scanf("%d", &tweetNum);
                if(A[tweetNum]==0){
                    open++;
                    close --;
                    //open it
                    A[tweetNum] = 1;

                }else{
                    close++;
                    open --;
                    A[tweetNum] = 0;

                }

            }else{
                // close all the tweets
                for(int i=0;i<=N;++i)
                    A[i] = 0;

                open = 0;
                close = 0;

            }
            printf("%d\n", open);

    }




    return 0;
}
