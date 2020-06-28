
#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int T, U, N, M, C;
    scanf("%d", &T);
    double D, R;
    while(T--){
            cin >> D >> U >> N;
            int ans=0;
            double bill = D*U;
            double lst = INT_MAX;
            for(int i=1;i<=N;++i){
                cin >> M >> R >> C;

                // current monthly plan
                double newBill = (C + R*U)/M ;


                if(newBill<bill && newBill < lst){
                    ans = i;
                    lst = newBill;
                }
            }

            printf("%d\n", ans);

    }



    return 0;
}
