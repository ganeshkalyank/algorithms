#include <bits/stdc++.h>

using namespace std;

class Sort {
    public:
        void mergeSort(int arr[], int l, int r) {
            if (l<r) {
                int m = (l+r)/2;
                mergeSort(arr,l,m);
                mergeSort(arr,m+1,r);
                merge(arr,l,m,r);
            }
        }
        void merge(int arr[], int l, int m, int r) {
            int n1 = m-l+1;
            int n2 = r-m;
            int left[n1+1], right[n2+1];
            for (int i=0;i<n1;i++) left[i] = arr[l+i];
            for (int i=0;i<n2;i++) right[i] = arr[m+1+i];
            left[n1] = INT_MAX; right[n2] = INT_MAX;
            int lt=0,rt=0;
            for (int i=l;i<=r;i++) {
                if (left[lt]<=right[rt]) {
                    arr[i] = left[lt];
                    lt++;
                } else {
                    arr[i] = right[rt];
                    rt++;
                }
            }
        }
        void quickSort(int arr[], int l, int r) {
            if (l<r) {
                int m = partition(arr,l,r);
                quickSort(arr,l,m-1);
                quickSort(arr,m+1,r);
            }
        }
        int partition(int arr[], int l, int r) {
            int x = arr[r];
            int i=l-1;
            for (int j=l;j<r;j++) {
                if (arr[j] <= x) {
                    i++;
                    swap(arr[i],arr[j]);
                }
            }
            swap(arr[i+1],arr[r]);
            return i+1;
        }
};

int main() {
    int arr[] = {3,1,2,4,1,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    Sort sorter;
    sorter.quickSort(arr, 0, n-1);
    for (int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}