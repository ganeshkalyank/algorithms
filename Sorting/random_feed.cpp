#include <bits/stdc++.h>

using namespace std;

int main() {
	srand((long int) clock());
	ofstream file("input.txt");
	for (int i=0;i<11000;i++) {
		// file<<rand()%30000<<" ";
		// file << i << " ";
		file << 11000 - i << " ";
	}
	file.close();
	return 0;
}
