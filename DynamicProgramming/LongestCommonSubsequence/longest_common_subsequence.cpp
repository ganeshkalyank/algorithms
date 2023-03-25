#include <bits/stdc++.h>

using namespace std;

class LCS {
    public:
        string x, y;
        int m, n;
        int c[100][100];
        char b[100][100];
        
        LCS(string x = "", string y = "") {
            this->x = x;
            this->y = y;
            this->m = x.length();
            this->n = y.length();
        }

        void readInputFromFile(int n) {
            ifstream file("input.txt");
            for (int i = 0; i < n; i++) {
                char c;
                file >> c;
                x += c;
            }
            for (int i = 0; i < n; i++) {
                char c;
                file >> c;
                y += c;
            }
            this->m = x.length();
            this->n = y.length();
        }

        void lcs_length() {
            for (int i = 0; i <= m; i++) {
                c[i][0] = 0;
            }
            for (int j = 0; j <= n; j++) {
                c[0][j] = 0;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (x[i - 1] == y[j - 1]) {
                        c[i][j] = c[i - 1][j - 1] + 1;
                        b[i][j] = '\\';
                    } else if (c[i - 1][j] >= c[i][j - 1]) {
                        c[i][j] = c[i - 1][j];
                        b[i][j] = '|';
                    } else {
                        c[i][j] = c[i][j - 1];
                        b[i][j] = '-';
                    }
                }
            }
        }

        void print_lcs() {
            print_lcs(m, n);
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

        void print_c() {
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
        }

        void print_b() {
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
        }

        int lcs_length_brute_force(int i, int j) {
            if (i == 0 || j == 0) {
                return 0;
            }
            if (x[i - 1] == y[j - 1]) {
                return 1 + lcs_length_brute_force(i - 1, j - 1);
            } else {
                return max(lcs_length_brute_force(i - 1, j), lcs_length_brute_force(i, j - 1));
            }
        }

        void print_lcs_brute_force(int i, int j) {
            if (i == 0 || j == 0) {
                return;
            }
            if (x[i - 1] == y[j - 1]) {
                print_lcs_brute_force(i - 1, j - 1);
                cout << x[i - 1];
            } else if (lcs_length_brute_force(i - 1, j) > lcs_length_brute_force(i, j - 1)) {
                print_lcs_brute_force(i - 1, j);
            } else {
                print_lcs_brute_force(i, j - 1);
            }
        }

        void print_lcs_brute_force() {
            print_lcs_brute_force(m, n);
        }
};

int main() {
    int input_sizes[] = {5,10,15,20,25};
    LCS lcs;

    do {
        cout << "1. Dynamic Programming" << endl;
        cout << "2. Brute Force" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    lcs.readInputFromFile(input_sizes[i]);
                    lcs.lcs_length();
                    cout << "Input size: " << input_sizes[i] << endl;
                    cout << "Length of LCS: " << lcs.c[lcs.m][lcs.n] << endl;
                    cout << "LCS: ";
                    lcs.print_lcs();
                    cout << endl << endl;
                }
                break;
            case 2:
                for (int i = 0; i < 5; i++) {
                    lcs.readInputFromFile(input_sizes[i]);
                    cout << "Length of LCS: " << lcs.lcs_length_brute_force(lcs.m, lcs.n) << endl;
                    cout << "LCS: ";
                    lcs.print_lcs_brute_force();
                    cout << endl;
                }
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    } while (true);
    return 0;
}