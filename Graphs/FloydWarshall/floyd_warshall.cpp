#include <bits/stdc++.h>

using namespace std;

class FloydWarshall {
    int D[100][100],Pi[100][100];
    public:
        void initialize(int W[][5], int n) {
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) {
                    D[i][j] = W[i][j];
                    if (i==j || W[i][j] == INT_MAX)
                        Pi[i][j] = -1;
                    else
                        Pi[i][j] = i;
                }
            }
        }
        void compute(int n) {
            for (int k=0;k<n;k++)
                for (int i=0;i<n;i++)
                    for (int j=0;j<n;j++)
                        if (Pi[i][k]!=-1 && Pi[k][j]!=-1 && D[i][j] > D[i][k] + D[k][j]) {
                            D[i][j] = D[i][k]+D[k][j];
                            Pi[i][j] = Pi[k][j];
                        }
        }
        void PrintAllPairs(int i, int j) {
            if (i==j)
                cout<<i<<"->";
            else if (Pi[i][j] == -1)
                cout<<"Path doesn't exist from "<<i<<" to "<<j<<endl;
            else {
                PrintAllPairs(i,Pi[i][j]);
                cout<<j<<"->";
            }
        }
};

int main () {
    FloydWarshall fw;
    int wm[5][5] = {
        {0,3,8,INT_MAX,-4},
        {INT_MAX,0,INT_MAX,1,7},
        {INT_MAX,4,0,INT_MAX,INT_MAX},
        {2,INT_MAX,-5,0,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,6,0}
    };
    fw.initialize(wm,5);
    fw.compute(5);
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            fw.PrintAllPairs(i,j);
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
