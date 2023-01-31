#include <bits/stdc++.h>

using namespace std;

class Sort {
	private:
		long int a[11000];
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
				fout<<a[i]<<" ";
			fout.close();
		}
		int insertionSort(int n) {
			int count=0;
			int key,i;
			for (int j=1;j<n;j++) {
				key=a[j];
				i=j-1;
				count++;
				while (i>=0 && a[i]>key) {
					a[i+1] = a[i];
					i--;
					count++;
				}
				a[i+1] = key;
			}
			return count;
		}
		void merge(int p,int q,int r,int &count) {
			int n1 = q-p+1;
			int n2 = r-q;
			int L[n1+1],R[n2+1];
			for (int i=0;i<n1;i++) {
				L[i] = a[p+i];
			}
			for (int j=0;j<n2;j++) {
				R[j] = a[q+j+1];
			}
			L[n1] = INT_MAX;
			R[n2] = INT_MAX;
			int i=0,j=0;
			for (int k=p;k<=r;k++) {
				count++;
				if (L[i]<=R[j]) {
					a[k] = L[i];
					i++;
				}
				else {
					a[k] = R[j];
					j++;
				}
			}
		}
		void mergeSort(int p,int r,int &count) {
			if (p<r) {
				int q = (p+r)/2;
				mergeSort(p,q,count);
				mergeSort(q+1,r,count);
				merge(p,q,r,count);
			}
		}
		void quickSort(int p,int r,int &count) {
			if (p<r) {
				int q = partition(p,r,count);
				quickSort(p,q-1,count);
				quickSort(q+1,r,count);
			}
		}
		int partition(int p,int r,int &count) {
			int x = a[r];
			int i = p-1;
			for (int j=p;j<r;j++) {
				count++;
				if (a[j]<=x) {
					i++;
					swap(a[i],a[j]);
				}
			}
			swap(a[i+1],a[r]);
			return i+1;
		}
		void heapSort(int n,int &count) {
			buildMaxHeap(n,count);
			for (int i=n-1;i>=1;i--) {
				swap(a[0],a[i]);
				maxHeapify(0,i,count);
			}
		}
		void buildMaxHeap(int n, int &count) {
			for (int i=n/2-1;i>=0;i--) {
				maxHeapify(i,n,count);
			}
		}
		void maxHeapify(int i,int n, int &count) {
			int l = 2*i+1;
			int r = 2*i+2;
			int largest;
			count++;
			if (l<n && a[l]>a[i])
				largest = l;
			else
				largest = i;
			count++;
			if (r<n && a[r]>a[largest])
				largest = r;
			if (largest!=i) {
				swap(a[i],a[largest]);
				maxHeapify(largest,n,count);
			}
		}
};

int main() {
	Sort s;
	int len[] = {10,50,100,500,1000,5000,10000};
	char choice;
	do {
		cout<<"Enter your choice:\n1. Insertion Sort\n2. Merge Sort\n3. Quick Sort\n4. Heap Sort\n";
		cin>>choice;
		switch(choice) {
			case '1': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					s.readInput(n);
					count = s.insertionSort(n);
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
					s.mergeSort(0,n-1,count);
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
					s.quickSort(0,n-1,count);
					s.writeOutput(n);
					cout<<"Input size: "<<n<<"\t"<<"No. of comparisons: "<<count<<endl;
				}
				break;
			}
			case '4': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					s.readInput(n);
					s.heapSort(n,count);
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
