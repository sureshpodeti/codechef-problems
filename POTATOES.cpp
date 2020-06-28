
#include<iostream>
#include<cmath>
using namespace std;

bool prime(int n)
{
    int flag=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=0;
            break;
        }
        }

            if(flag==1)
            return true;

    return false;

}
int main(){
    int T, x,y;
    cin >> T;

    while(T--){
        cin >> x >> y;
        int S = x +y;
        int i = S+1;
        int ans;
        while(1){
            if(prime(i)){
                ans = i;
                break;
            }

           ++i;

        }
        cout << i-S << endl;
    }


    return 0;
}
