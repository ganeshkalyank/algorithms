// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
enum vcolor{White,Gray,Black};
struct node
{
    int ver;
    node *next;
};
struct vnode
{
    string name;
    int d;
    int f;
    int pi;
    vcolor color;
    node *adjptr;
    
};
class graph
{
    int n,m;
    vnode vertex[10];
    node *list;
    int time;
    public:
    void createGraph()
    {
        cout<<"Enter the number of vertices:";
        cin>>n;
        for(int i=1;i<=n;i++)
        {   cout<<"Vertex-"<<i<<" name:";
            cin>>vertex[i].name;
            vertex[i].adjptr=NULL;
        }
        for(int i=1;i<=n;i++)
        {
		
        cout<<"For vertex-"<<i<<" enter the number of adjacent vertices :";
        cin>>m;
        node *cur=NULL;
        
        for(int j=1;j<=m;j++)
        {
            node *t=new node;
            cout<<"For vertex-"<<i<<" enter the index of adjacent vertex:";
            
			      	cin>> t->ver;           //Get index of adjacent vertex
	      			          
	      			t->next=NULL;
	      			if (cur==NULL)
	                    vertex[i].adjptr=t;
			        else
					    cur->next=t;
 			        cur=t;
 			    
            
        }
        }
    }
    void DFS()
    {
        for(int i=1;i<=n;i++)
        {
            vertex[i].color=White;
            vertex[i].pi=-1;
        }
        time=0;
        list=NULL;
        for(int v=1;v<=n;v++)
        {
            if(vertex[v].color==White)
                DFS_VISIT(v);
        }
        

    }
    void TopSort()
    { DFS();
     node *temp=list;
     cout<<endl;
      while(temp!=NULL)
      { 
        cout<<vertex[temp->ver].name<<" ";
        temp=temp->next;
      }
	}
    void DFS_VISIT(int u)
    {
        time=time+1;
        vertex[u].d=time;
        vertex[u].color=Gray;
        node * temp=vertex[u].adjptr;
        
        while(temp!=NULL)
        {
            int v=temp->ver;
            if(vertex[v].color==White)
            {
                vertex[v].pi=u;
                DFS_VISIT(v);
            }
            temp=temp->next;
            
        }
        time=time+1;
        vertex[u].f=time;
        vertex[u].color=Black;
        node * T=new node;
        T->next=list;
        T->ver=u;
        list=T;
        
        
    }
    void displayGraph()
    {
        
        	cout << "Given Graph: " << endl;
        	for (int i=1; i<=n; i++){
        		cout << vertex[i].name << "\t";
        		node *t= vertex[i].adjptr;
        		while (t!=NULL){
        			cout << "--> (" << vertex[t->ver].name  << ") ";
        			t = t->next;
				}
				cout << endl;
			}
		
    }
    
};
int main() {
    graph g;
   g.createGraph();
   g.displayGraph();
   g.TopSort();
    return 0;
}
