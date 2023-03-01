#include <bits/stdc++.h>

using namespace std;

class Sort {
	private:
		int a[11000],b[11000];
	public:
		void readInput(int n) {
			ifstream fin("input.txt");
			for (int i=0;i<n;i++) {
				fin >> a[i];
			}
			fin.close();
		}
		void writeOutput(int n) {
			ofstream fout("output.txt");
			for (int i=0;i<n;i++)
				fout<<b[i]<<" ";
			fout.close();
		}
        void countingSort(int n, int k) {
            int c[k+1];
            for (int i=0;i<=k;i++) c[i]=0;
            for (int j=0;j<=n-1;j++)
                c[a[j]]++;
            for (int i=1;i<=k;i++)
                c[i] = c[i]+c[i-1];
            for (int j=n-1;j>=0;j--) {
                b[c[a[j]]-1] = a[j];
                c[a[j]]--;
            }
        }
        void radixSort(int n, int d) {
            int c[10];
            for (int i=1;i<=d;i++) {
                for (int j=0;j<10;j++) c[j]=0;
                for (int j=0;j<=n-1;j++)
                    c[(a[j]/(int)pow(10,i-1))%10]++;
                for (int j=1;j<10;j++)
                    c[j] = c[j]+c[j-1];
                for (int j=n-1;j>=0;j--) {
                    b[c[(a[j]/(int)pow(10,i-1))%10]-1] = a[j];
                    c[(a[j]/(int)pow(10,i-1))%10]--;
                }
            }
        }
};

int main() {
	Sort s;
	int len[] = {10,50,100,500,1000,5000,10000};
	char choice;
	do {
		cout<<"Enter your choice:\n1. Counting Sort\n2. Radix Sort\n3. Bucket Sort\n";
		cin>>choice;
		switch(choice) {
			case '1': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					s.readInput(n);
					s.countingSort(n,10);
					s.writeOutput(n);
					cout<<"Input size: "<<n<<"\t"<<"No. of comparisons: "<<count<<endl;
				}
				break;
			}
			case '2': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					s.readInput(n);
                    s.radixSort(n,3);
					s.writeOutput(n);
					cout<<"Input size: "<<n<<"\t"<<"No. of comparisons: "<<count<<endl;
				}
				break;
			}
			case '3': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					s.readInput(n);
					// s.quickSort(0,n-1,count);
					s.writeOutput(n);
					cout<<"Input size: "<<n<<"\t"<<"No. of comparisons: "<<count<<endl;
				}
				break;
			}
			default: {
				cout<<"Invalid choice!\n";
				break;
			}
		}
		cout<<"Do you want to continue? (y/n): ";
		cin>>choice;
	} while (choice=='y');
	return 0;
}