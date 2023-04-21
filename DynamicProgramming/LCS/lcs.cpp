#include <bits/stdc++.h>

using namespace std;

class LCS {
    string x,y;
    int c[100][100];
    char b[100][100];
    public:
        LCS() {
            ifstream fin("lcs_input.txt");
            fin >> x >> y;
            fin.close();
        }
        int lcs_length_bu(int m, int n, int &count) {
            for(int i=0; i<=m; i++) {
                c[i][0] = 0;
            }
            for(int j=0; j<=n; j++) {
                c[0][j] = 0;
            }
            for(int i=1; i<=m; i++) {
                for(int j=1; j<=n; j++) {
                    count++;
                    if(x[i] == y[j]) {
                        c[i][j] = c[i-1][j-1] + 1;
                        b[i][j] = '\\';
                    }
                    else if(c[i-1][j] >= c[i][j-1]) {
                        c[i][j] = c[i-1][j];
                        b[i][j] = '|';
                    }
                    else {
                        c[i][j] = c[i][j-1];
                        b[i][j] = '-';
                    }
                }
            }
            return c[m][n];
        }
        void print_lcs(int i, int j) {
            if (i == 0 || j == 0) {
                return;
            }
            if (b[i][j] == '\\') {
                print_lcs(i - 1, j - 1);
                cout << x[i - 1];
            } else if (b[i][j] == '|') {
                print_lcs(i - 1, j);
            } else {
                print_lcs(i, j - 1);
            }
        }
        int lcs_length_td(int i, int j, int &count) {
            if (c[i][j] > 0) {
                return c[i][j];
            }
            count++;
            if (i == 0 || j == 0) {
                c[i][j] = 0;
                return c[i][j];
            }
            if (x[i] == y[j]) {
                c[i][j] = lcs_length_td(i - 1, j - 1, count) + 1;
                b[i][j] = '\\';
            } else {
                int t1 = lcs_length_td(i-1, j, count);
                int t2 = lcs_length_td(i, j-1, count);
                if (t1 >= t2) {
                    c[i][j] = t1;
                    b[i][j] = '|';
                } else {
                    c[i][j] = t2;
                    b[i][j] = '-';
                }
            }
            return c[i][j];
        }
        int lcs_length_dc(int i, int j, int &count) {
            count++;
            if (i==0 || j==0)
                return 0;
            if (x[i] == y[j])
                return lcs_length_dc(i-1,j-1, count) + 1;
            else {
                return max(lcs_length_dc(i-1, j, count), lcs_length_dc(i, j-1, count));
            }
        }
};

int main() {
    LCS lcs;
    int input_sizes[] = {5, 7, 10, 12, 15, 17};
    int count;
    cout << setw(20) << "Input Size" << setw(20) << "D & C" << setw(20) << "Topdown" << setw(20) << "Bottom Up" << endl;
    for (int i=0; i<6; i++) {
        cout << setw(20) << input_sizes[i];
        count = 0;
        lcs.lcs_length_dc(input_sizes[i], input_sizes[i], count);
        cout << setw(20) << count;
        count = 0;
        lcs.lcs_length_td(input_sizes[i], input_sizes[i], count);
        cout << setw(20) << count;
        lcs.lcs_length_bu(input_sizes[i], input_sizes[i], count);
        cout << setw(20) << count;
        cout << endl;
    }
    return 0;
}