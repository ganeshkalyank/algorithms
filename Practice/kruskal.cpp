#include <bits/stdc++.h>

using namespace std;

struct Edge {
    char from, to;
    int weight;
};

class Kruskal {
    vector<Edge*> edgelist;
    int n,m;
    int *parent;
    int *rank;
    public:
        void createGraph() {
            cout << "Enter number of vertices: ";
            cin>>m;
            cout << "Enter number of edges: ";
            cin >> n;
            parent = new int[m+1];
            rank = new int[m+1];
            for (int i=0;i<n;i++) {
                Edge *newedge = new Edge;
                cout << "Enter from: ";
                cin >> newedge->from;
                cout << "Enter to: ";
                cin >> newedge->to;
                cout << "Enter weight: ";
                cin >> newedge->weight;
                edgelist.push_back(newedge);
            }
        }
        void makeSet(int i) {
            parent[i] = i;
            rank[i] = 0;
        }
        int findSet(int i) {
            while (parent[i] != i)
                i = parent[i];
            return i;
        }
        void unite(int i, int j) {
            if (rank[i] > rank[j])
                parent[j] = i;
            else {
                parent[i] = j;
                if (rank[i] == rank[j])
                    rank[j]++;
            }
        }
        void findMST() {
            for (int i=1;i<=m;i++)
                makeSet(i);
            sort(edgelist.begin(), edgelist.end(), [] (const Edge *a, const Edge *b) -> bool {
                return a->weight < b->weight;
            });
            // for (auto edge = edgelist.begin(); edge!=edgelist.end(); edge++)
            //     cout << (*edge)->from << " -> " << (*edge)->to << " : " << (*edge)->weight << endl;
            int totalweight = 0, count = 1;
            for (auto edge = edgelist.begin(); edge!=edgelist.end() && count <= m-1; edge++) {
                int i = findSet((*edge)->from);
                int j = findSet((*edge)->to);
                if (i!=j) {
                    totalweight += (*edge)->weight;
                    count++;
                    cout << (*edge)->from << " -> " << (*edge)->to << " : " << (*edge)->weight << endl;
                    unite(i,j);
                }
            }
            cout << "Total weight: "<<totalweight<<endl;
        }
};

int main() {
    Kruskal k;
    k.createGraph();
    k.findMST();
    return 0;
}