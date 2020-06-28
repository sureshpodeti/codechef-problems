#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
/*
Volume, V = lbh
Perimeter, P = 4(l+b+h)
Area, A = 2(lb+lh+bh)

V = lbh
  = l(A/2 - (lb+lh))
  = Al/2 - l^2 (b+h)
  = Al/2 - l^2 (P/4 - l)
  = Al/2 - l^2 * P/4 +l^3

  Differentiate V w.r.t to l
  dv/dl = A/2 - P*l/2 + 3l^2 = 0 ( for maximum volume)
  solving the quadratic equation;
    l = P - Sqrt(P^2 - 24A)/12

    After computing l, put in
    V = Al/2 - l^2*P/4 + l^3 to get V

*/
int main(){
    int T, P, S;
    cin >> T;

    while(T--){
        cin >> P >> S;
        float l = (P - sqrt(pow(P,2)-24*S) ) /12;
        float V = S*l/2 - pow(l,2)*P/4 + pow(l,3);
        printf("%0.2f\n", V);
    }


    return 0;
}
