#include <bits/stdc++.h>

using namespace std;

class MatrixChainMultiplication {
    private:
        int p[15];

    public:
        void Set_Random_Matrix() {
            for (int i = 0; i < 15; i++) {
                p[i] = rand() % 10 + 1;
                cout<<p[i]<<" ";
            }
            cout<<endl;
        }
        // dynamic programming approach
        int Bottom_up_MCM(int s[15][15], int n, int &count) {
            int m[n + 1][n + 1];
            int i, j, k, l, q;

            for (i = 1; i <= n; i++) {
                m[i][i] = 0;
            }

            for (l = 2; l <= n; l++) {
                for (i = 1; i <= n - l + 1; i++) {
                    j = i + l - 1;
                    m[i][j] = INT_MAX;
                    for (k = i; k <= j - 1; k++) {
                        count++;
                        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                        if (q < m[i][j]) {
                            m[i][j] = q;
                            s[i][j] = k;
                        }
                    }
                }
            }

            return m[1][n];
        }
        void Print_Optimal_Parens(int s[15][15], int i, int j) {
            if (i == j) {
                cout << "A" << i;
            }
            else {
                cout << "(";
                Print_Optimal_Parens(s, i, s[i][j]);
                Print_Optimal_Parens(s, s[i][j] + 1, j);
                cout << ")";
            }
        }
        // brute force approach
        int Brute_Force_MCM(int i, int j, int &opCount) {
            if (i == j) {
                return 0;
            }
            int min = INT_MAX;
            int count;
            for (int k = i; k < j; k++) {
                opCount++;
                count = Brute_Force_MCM(i, k, opCount) + Brute_Force_MCM(k + 1, j, opCount) + p[i - 1] * p[k] * p[j];
                if (count < min) {
                    min = count;
                }
            }
            return min;
        }
};

int main() {
    MatrixChainMultiplication mcm;
    int lens[] = {1, 3, 5, 7, 9};
    int s[15][15];
    char choice;
    do {
        cout << "1. Matrix Chain using Dynamic Programming" << endl;
        cout << "2. Matrix Chain using Brute Force Approach" << endl;
        cout << "3. Set Random Matrix" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case '1':
            for (int i = 0; i < 5; i++) {
                int count = 0;
                cout << "Input Size: " << lens[i] << " Minimum number of multiplications is " << mcm.Bottom_up_MCM(s, lens[i],count) << endl;
                cout << "Optimal Parenthesization is: ";
                mcm.Print_Optimal_Parens(s, 1, lens[i]);
                cout << endl << "Operation Count: " << count << endl;
            }
            break;
        case '2':
            for (int i = 0; i < 5; i++) {
                int count = 0;
                cout << "Input Size: " << lens[i] << " Minimum number of multiplications is " << mcm.Brute_Force_MCM(1, lens[i],count) << endl;
                cout << "Operation Count: " << count << endl;
            }
            break;
        case '3':
            mcm.Set_Random_Matrix();
            break;
        case '4':
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != '4');
    return 0;
}
