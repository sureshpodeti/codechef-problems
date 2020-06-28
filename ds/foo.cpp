
#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int A[] = {10,2,3,5,6,67,90};
    sort(A, A+7);
    cout << binary_search(A, A+7, 10) << endl;



    return 0;
}
