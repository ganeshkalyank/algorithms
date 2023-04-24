#include <bits/stdc++.h>

using namespace std;

class MCM {
    public:
        int dp[100][100];
        int bracket[100][100];
        int mcm_dc(int p[], int i, int j, int &opCount) {
            if (i==j) return 0;
            int count, mini = INT_MAX;
            for (int k=i;k<j;k++) {
                opCount++;
                count = mcm_dc(p,i,k,opCount) + mcm_dc(p,k+1,j,opCount) + p[i-1]*p[k]*p[j];
                if (count < mini) {
                    mini = count;
                    bracket[i][j] = k;
                }
            }
            return mini;
        }
        int mcm_dp(int p[], int i, int j, int &opCount) {
            if (i==j) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            dp[i][j] = INT_MAX;
            for (int k=i;k<j;k++) {
                opCount++;
                int q = mcm_dp(p,i,k,opCount) + mcm_dp(p,k+1,j,opCount) + p[i-1]*p[k]*p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    bracket[i][j] = k;
                }
            }
            return dp[i][j];
        }
        int mcm_bu(int p[], int n, int &opCount) {
            for (int i=1; i<n; i++)
                dp[i][i] = 0;
            for (int l=2; l<n; l++) {
                for (int i=1; i<n-l+1; i++) {
                    int j = i + l - 1;
                    dp[i][j] = INT_MAX;
                    for (int k=i; k<=j-1; k++) {
                        opCount++;
                        int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                        if (q<dp[i][j]) {
                            dp[i][j] = q;
                            bracket[i][j] = k;
                        }
                    }
                }
            }
            return dp[1][n-1];
        }
        void pop(int i, int j) {
            if (i==j) {
                cout << "A" << i;
            } else {
                cout << "(";
                pop(i,bracket[i][j]);
                pop(bracket[i][j]+1, j);
                cout << ")";
            }
        }
};

int main() {
    MCM mcm;
    int arr[] = { 1,2,3,4,3,7,6,1,3 };
    int inputs[] = {2,3,5,7,9};
    int count;
    cout << setw(20) << "Input size" << setw(20) << "D & C" << setw(20) << "Topdown" << setw(20) << "Bottom up" << endl;
    for (int i=0;i<5;i++) {
        cout << setw(20) << inputs[i];
        memset(mcm.dp, -1, sizeof(mcm.dp));
        count = 0;
        cout << setw(20) << mcm.mcm_dc(arr,1,inputs[i]-1,count);
        memset(mcm.dp, -1, sizeof(mcm.dp));
        count = 0;
        cout << setw(20) << mcm.mcm_dp(arr,1,inputs[i]-1,count);
        memset(mcm.dp, -1, sizeof(mcm.dp));
        count = 0;
        cout << setw(20) << mcm.mcm_bu(arr,inputs[i],count);
        cout << endl;
    }
    return 0;
}