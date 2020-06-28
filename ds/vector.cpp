#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v){
    for(int i=0;i<v.size();++i)
        cout << v[i] << " ";
    cout << endl;


    for(auto it=v.begin();it!=v.end(); ++it)
        cout << *it << " ";
    cout << endl;


    for(int i=0;i<v.size();++i)
        cout << v.at(i) << " ";
    cout << endl;


    int *pt = v.data();

    for(int i=0;i<v.size();++i)
        cout << *(pt+i) << " ";
    cout << endl;


}


void reverseDisplay(vector<int> &v){
    for(auto it=v.rbegin();it!=v.rend(); ++it)
        cout << *it << " ";
    cout << endl;

}
int main(){
    vector<int> V;

    V.push_back(10);
    V.push_back(20);
    V.push_back(30);
    V.push_back(40);
    V.push_back(50);
    V.push_back(60);
    V.push_back(70);
    V.push_back(80);
    V.push_back(90);

    V.resize(13, 300);
    //V.reserve(2);


    //reverseDisplay(V);

   // V.pop_back();
    display(V);
    //cout << V.max_size() << endl;
    cout << V.capacity() << endl;

    cout << V.front() << endl;
    cout << V.back() << endl;





    return 0;
}


