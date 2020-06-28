#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int T, d;
    cin >> T;

    string N;
    while(T--){
        cin >> N >> d;
        int sze = N.length();
        int A[sze];
        for(int i=0;i<sze;++i){
            A[i] = N[i] - 48;
        }

        string ans = "";
        //get the least element of the array and its index
        int index, least=9;
        for(int i=sze-1;i>=0;--i){
            if(least>=A[i]){
                    least = A[i];
                    index = i;
            }
        }

        if(least>=d){
                // every thing can replaced by 1
                for(int i=0;i<sze;++i)
                    ans.push_back(48+d);



        }else{

            // define one more array B, same as A
            int B[sze];
            for(int i=0;i<sze;++i) B[i] = A[i];

            //sort the array B
            sort(B, B+sze);

            int c = 0, i=0, j=0, z=0;
            //arrray to store the answer
            int C[sze];
            while(i<sze && j<sze){
                //compare elements of A and B
                if(A[j]!=B[i]){
                    ++c;
                    ++j;
                }else{
                    if(B[i]<d)
                        C[z] = B[i];
                    else C[z] = d;
                    ++j;
                    ++i;
                    ++z;

                }
            }

            // now c holds the count of deleted elements
            // and C holds the elements of the final answer
            for(int i=0;i<c;++i){
                C[z] = d;
                ++z;
            }



            // write the array into a string
            for(int i=0;i<sze;++i){
                ans.push_back(48+C[i]);
            }

        }

        cout << ans << endl;
    }


    return 0;
}
