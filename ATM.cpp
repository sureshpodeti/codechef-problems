
#include<iostream>
using namespace std;

int main(){
    int X;
    double Y;
    cin >> X >> Y;


    if(X%5!=0)
        printf("%0.2f\n", Y);
    else if(X>Y)
        printf("%0.2f\n", Y);
    else if(X+0.50>Y)
       printf("%0.2f\n", Y);
    else
        printf("%0.2f\n", Y-(X+0.50));

    return 0;
}
