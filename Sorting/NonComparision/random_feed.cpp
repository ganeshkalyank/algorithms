#include <bits/stdc++.h>

using namespace std;

int main() {
	srand((long int) clock());
	ofstream file("input.txt");
	for (int i=0;i<11000;i++) {
		// file<<100+rand()%900<<" ";
		// file<<rand()%10<<" ";
		file<<(rand()%100)*0.01f<<" ";
	}
	file.close();
	return 0;
}
