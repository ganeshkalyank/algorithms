#include <bits/stdc++.h>

using namespace std;

class StringMatching {
    public:
        void NaiveStringMatching(string T, string P) {
            int n = T.length();
            int m = P.length();
            for (int i=0; i<=n-m; i++) {
                if (P == T.substr(i,m)) {
                    cout<<"String found after "<< i <<" shifts"<<endl;
                }
            }
        }
        void RobinKarpMatcher(string T, string P, int d=256, int q=97) {
            int n = T.length(),
                m = P.length(),
                h = ((long int) pow(d,m-1)) % q,
                p = 0,
                t[n-m+2];
                t[0]=0;
            for (int i=0; i<m; i++) {
                p = (d*p + (int)P[i]) % q;
                t[0] = (d*t[0] + (int)T[i]) % q;
            }
            for (int s=0; s<=n-m; s++) {
                // cout<<P<<" - "<<T.substr(s,m)<<" p="<<p<<" t="<<t[s]<<endl;
                if (p==t[s]) {
                    if (P==T.substr(s,m)) {
                        cout<<"String found after "<< s <<" shifts"<<endl;
                    }
                }
                if (s<n-m) {
                    int temp = (d*(t[s]-((int)T[s])*h) + (int)T[s+m]);
                    if (temp<0) {
                        temp *= -1;
                        t[s+1] = temp%q;
                        t[s+1] = q-t[s+1];
                    } else {
                        t[s+1] = temp%q;
                    }
                }
            }
        }
};

int main() {
    string txt = "kalyan hey! i am kalyan and kalyan here kalyan";
    string ptr = "kalyan";
    StringMatching sm;
    sm.RobinKarpMatcher(txt,ptr);
    return 0;
}
