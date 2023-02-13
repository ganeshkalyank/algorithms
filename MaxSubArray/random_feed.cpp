#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream file("input.txt");
    srand((long int) clock());
    int x,y;
    for (int i=0;i<30000;i++) {
        x = rand() % 10;
        y = rand() % 10;
        file << (x-y) << " ";
        // file << x << " ";
        // file << -1*y << " ";
    }
    return 0;
}