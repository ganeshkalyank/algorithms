#include <bits/stdc++.h>

using namespace std;

struct node {
    int from;
    int to;
    int weight;
    node* next;
};

struct vnode {
    string name;
    int d;
    int pi;
};

class Graph {
    int n,m;
    node *elist;
    public:
        vnode vertex[10];
        void createGraph() {
            cout << "Enter number of vertices: ";
            cin >> n;
            for (int i=0; i<n; i++) {
                cout << "Enter name of vertex " << i+1 << ": ";
                cin >> vertex[i].name;
            }
            cout << "Enter number of edges: ";
            cin >> m;
            elist = NULL;
            node *last = NULL;
            for (int i=0; i<m; i++) {
                node *temp = new node;
                cout << "Enter edge " << i+1 << ": ";
                cin >> temp->from >> temp->to >> temp->weight;
                temp->next = NULL;
                if (last == NULL) {
                    elist = temp;
                } else {
                    last->next = temp;
                }
                last = temp;
            }
        }
        void initializeSingleSource(int s) {
            for (int i=0; i<n; i++) {
                vertex[i].d = INT_MAX;
                vertex[i].pi = -1;
            }
            vertex[s].d = 0;
        }
        void relax(int u, int v, int w) {
            if (vertex[v].d > vertex[u].d + w) {
                vertex[v].d = vertex[u].d + w;
                vertex[v].pi = u;
            }
        }
        bool BellmanFord(int s) {
            initializeSingleSource(s);
            for (int i=0; i<n-1; i++) {
                node *temp = elist;
                while (temp != NULL) {
                    relax(temp->from, temp->to, temp->weight);
                    temp = temp->next;
                }
            }
            node *temp = elist;
            while (temp != NULL) {
                if (vertex[temp->to].d > vertex[temp->from].d + temp->weight) {
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }
        void printGraph() {
            cout << "Vertex\tDistance\tParent" << endl;
            for (int i=0; i<n; i++) {
                cout << vertex[i].name << "\t" << vertex[i].d << "\t\t" << vertex[i].pi << endl;
            }
        }
        void printShortestPath(int s, int v) {
            if (v == s) {
                cout << vertex[s].name << " ";
            } else if (vertex[v].pi == -1) {
                cout << "No path from " << vertex[s].name << " to " << vertex[v].name << " exists" << endl;
            } else {
                printShortestPath(s, vertex[v].pi);
                cout << vertex[v].name << " ";
            }
        }
};

int main() {
    Graph g;
    g.createGraph();
    int s;
    cout << "Enter source vertex: ";
    cin >> s;
    if (g.BellmanFord(s)) {
        g.printGraph();
        int v;
        cout << "Enter destination vertex: ";
        cin >> v;
        cout << "Shortest path from " << g.vertex[s].name << " to " << g.vertex[v].name << " is: ";
        g.printShortestPath(s, v);
    } else {
        cout << "Graph contains negative weight cycle" << endl;
    }
    return 0;
}