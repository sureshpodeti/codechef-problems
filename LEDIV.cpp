    #include<iostream>

    using namespace std;

    int gcd(int a, int b){
        // assumes a<b
        if(a==0) return b;
        return gcd(b%a, a);
    }

    int main(){
        int T, N;
        cin >> T;

        while(T--){
            cin >> N;
            int A[N];
            for(int i=0;i<N;++i) cin >> A[i];

            int ans = A[0];
            for(int i=1;i<N;++i){
                //check the relation b/w ans and  A[i]
                if(ans>A[i]) ans = gcd(A[i], ans);
                else ans = gcd(ans, A[i]);

            }

            // ans could be 1 or greater than 1
            if(ans==1) cout << -1 << endl;
            else cout << ans << endl;
        }
        return 0;
    }

