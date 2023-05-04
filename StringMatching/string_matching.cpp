#include <bits/stdc++.h>

using namespace std;

class StringMatching {
public:
void NaiveStringMatching(string T, string P) {
int n = T.length();
int m = P.length();
for (int i=0; i<=n-m; i++)
if (P == T.substr(i,m))
cout<<"String found after "<< i <<" shifts"<<endl;
if (P != T.substr(n-m+1,m))
cout << "Pattern not found" << endl;
}
void RobinKarpMatcher(string T, string P, int d=256, int q=97) {
int n = T.length(),
m = P.length(),
h = ((long int) pow(d,m-1)) % q,
p = 0,
t[n-m+2];
t[0]=0;
for (int i=0; i<m; i++) {
p = (dp + (int)P[i]) % q;
t[0] = (dt[0] + (int)T[i]) % q;
}
for (int s=0; s<=n-m; s++) {
if (p==t[s])
if (P==T.substr(s,m))
cout<<"String found after "<< s <<" shifts"<<endl;
if (s<n-m) {
int temp = (d*(t[s]-((int)T[s])*h) + (int)T[s+m]);
if (temp<0) {
temp *= -1;
t[s+1] = temp%q;
t[s+1] = q-t[s+1];
} else
t[s+1] = temp%q;
}
}
if (P != T.substr(n-m+1,m))
cout << "Pattern not found" << endl;
}
void KnuthMorrisPratt(string T, string P) {
int n = T.length();
int m = P.length();
int pi[m];
pi[0] = 0;
int k = 0;
for (int q=1; q<m; q++) {
while (k>0 && P[k]!=P[q])
k = pi[k-1];
if (P[k]==P[q]) k++;
pi[q] = k;
}
int q = 0;
for (int i=0; i<n; i++) {
while (q>0 && P[q]!=T[i])
q = pi[q-1];
if (P[q]==T[i]) q++;
if (q==m) {
cout<<"String found after "<< i-m+1 <<" shifts"<<endl;
q = pi[q-1];
}
}
if (P != T.substr(n-m+1,m))
cout << "Pattern not found" << endl;
}
};

int main() {
string txt = "kalyan hey! i am kalyan and kalyan here kalyan";
string ptr = "kalyan";
StringMatching sm;
sm.KnuthMorrisPratt(txt,ptr);
return 0;
}
