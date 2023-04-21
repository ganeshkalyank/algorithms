#include <bits/stdc++.h>

using namespace std;

int main(){
    char S[] = {'A', 'B', 'C'};
    ofstream fout("lcs_input.txt");
    for (int i=0; i<30; i++)
        fout << S[rand()%3];
    fout << endl;
    for (int i=0; i<30; i++)
        fout << S[rand()%3];
    fout.close();
    return 0;
}