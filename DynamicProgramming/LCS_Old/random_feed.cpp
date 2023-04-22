#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream file("input.txt");
    srand((long int) clock());
    int n = 100;
    for (int i = 0; i < n; i++) {
        file << (char) (rand() % 26 + 'a');
    }
    file.close();
    return 0;
}