#include <bits/stdc++.h>

using namespace std;

struct resSet {
    int x,y,z;
    resSet(int x=0,int y=0,int z=0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class MaxSubArray {
    int a[11000];
    public:
        void readInput(int n) {
			ifstream fin("input.txt");
			for (int i=0;i<n;i++) {
				fin >> a[i];
			}
			fin.close();
		}
        resSet BruteForceMaxSubArray(int n, int &count) {
            int maxsofar = 0,firstindex = 1, lastindex = 1,sum;
            for (int i=0;i<n;i++) {
                sum=0;
                count++;
                for (int j=i;j<n;j++) {
                    sum+=a[j];
                    count++;
                    if (sum>maxsofar) {
                        maxsofar = sum;
                        firstindex = i;
                        lastindex = j;
                    }
                }
            }
            return resSet(firstindex,lastindex,maxsofar);
        }
        resSet FindMaxCrossingSubArray(int low, int mid, int high, int &count) {
            int leftsum=INT_MIN,sum=0,maxleft;
            for (int i=mid;i>=low;i--) {
                sum = sum+a[i];
                if (sum>leftsum) {
                    leftsum = sum;
                    maxleft = i;
                }
                count++;
            }
            int rightsum=INT_MIN,maxright;sum=0;
            for (int i=mid+1;i<=high;i++) {
                sum+=a[i];
                if (sum>rightsum) {
                    rightsum = sum;
                    maxright = i;
                }
                count++;
            }
            return resSet(maxleft,maxright,leftsum+rightsum);
        }
        resSet FindMaximumSubArray(int low,int high,int &count) {
            int mid;
            if (high == low)
                return resSet(low,high,a[low]);
            else {
                mid = (low+high)/2;
                resSet left = FindMaximumSubArray(low,mid,count);
                resSet right = FindMaximumSubArray(mid+1,high,count);
                resSet midset = FindMaxCrossingSubArray(low,mid,high,count);
                if (left.z >= right.z && left.z >= midset.z)
                    return resSet(left.x,left.y,left.z);
                else if (right.z >= left.z && right.z >= midset.z)
                    return resSet(right.x,right.y,right.z);
                else
                    return resSet(midset.x,midset.y,midset.z);
            }
        }
};

int main() {
    MaxSubArray msa;
    int len[] = {10,50,100,500,7000,8000,10000};
	char choice;
    resSet res;
    do {
		cout<<"Enter your choice:\n1. Brute Force\n2. Divide and Conquer\n";
		cin>>choice;
		switch(choice) {
			case '1': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					msa.readInput(n);
                    res = msa.BruteForceMaxSubArray(n,count);
					cout<<"Input size: "<<n<<"\t"<<"No. of Comparisons: "<<count<<"\t"<<"Max Sum: "<<res.z<<endl;
				}
				break;
            }
			case '2': {
				for (int i=0;i<7;i++) {
					int count = 0;
					int n = len[i];
					msa.readInput(n);
                    res = msa.FindMaximumSubArray(0,n-1,count);
					cout<<"Input size: "<<n<<"\t"<<"No. of Comparisons: "<<count<<"\t"<<"Max Sum: "<<res.z<<endl;
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
    } while(choice == 'y');
    return 0;
}