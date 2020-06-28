#include<iostream>
#include<map>
#include<set>
using namespace std;


int main(){
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;

    int A[N1], B[N2], C[N3];
    for(int i=0;i<N1;++i)
        cin >> A[i];

    for(int i=0;i<N2;++i)
        cin >> B[i];

    for(int i=0;i<N3;++i)
        cin >> C[i];

    map<int, int> m;
    for(int i=0;i<N1;++i)
        if(m.find(A[i])==m.end())
            m.insert(pair<int ,int>(A[i],1));
        else m[A[i]]++;

    for(int i=0;i<N2;++i)
        if(m.find(B[i])==m.end())
            m.insert(pair<int ,int>(B[i],1));
        else m[B[i]]++;

    for(int i=0;i<N3;++i)
        if(m.find(C[i])==m.end())
            m.insert(pair<int ,int>(C[i],1));
        else m[C[i]]++;

    set<int> S;
    for(auto it=m.begin();it!=m.end();++it)
        if(it->second>=2) S.insert(it->first);

    cout << S.size() << endl;
    for(auto it=S.begin();it!=S.end();++it)
        cout << *it << endl;






    return 0;
}
