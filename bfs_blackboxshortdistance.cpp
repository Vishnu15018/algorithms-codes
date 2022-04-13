#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

class node_w{
    public:
    int v_name;
    int weight;
    node_w* nxt;
    
};
class node{
    public:
    int v_name;
     
    
    

    node* nxt;
    
};
node* create_vertices(int x){
    node* newnode= new node();
    newnode->v_name=x;
    newnode->nxt=NULL;
    return newnode;
}
class Queue
{
    public:
     node* frontptr;
     node* backptr;
    public:
    Queue(){
        frontptr=NULL;
        backptr=NULL;
    }
    int IsEmpty(){
        if(frontptr==NULL && backptr==NULL)
             return 1;
        else 
             return 0;

    }
    void enque(int data){
        if(IsEmpty()){
            node* newptr=create_vertices(data);
            newptr->nxt=NULL;
            frontptr=newptr;
            backptr=newptr;
        }
        else{
            node* newptr=create_vertices(data);

            newptr->nxt=backptr->nxt;
            backptr->nxt=newptr;
            backptr=newptr;
        }
    }
    void deque(){
        if(IsEmpty()){
            cout<< "EMPTY"<<endl;
        
        }
        else if(frontptr==backptr){
            node* p=frontptr;
            frontptr=NULL;
            backptr=NULL;
            p->nxt=NULL;
            delete p;
            p=NULL;
           //cout<<x<<endl;
        }
        else{
            node* p=frontptr;
            frontptr=frontptr->nxt;
            p->nxt=NULL;
            int x = p->v_name;
            delete p;
            p=NULL;
           

        }
    
    }
    int peek(){
        if(IsEmpty()){
            return -1;

            
        }
        return frontptr->v_name;
    }
    void show(){
        if(IsEmpty())
            cout<< "EMPTY"<<endl;
        else{
        node* q=frontptr;
        while(q!=NULL){
            std::cout<<q->v_name<<" ";
            q=q->nxt;
        }
        }
    }
};


node_w* create_vertices_weight(int x,int w){
    node_w* newnode_w= new node_w();
    newnode_w->v_name=x;
    newnode_w->weight=w;
    newnode_w->nxt=NULL;
    return newnode_w;
}
node_w* insert_end(node_w* head , int x,int w){
    if(head==NULL){
            head=create_vertices_weight(x,w);
    }
    else{
           node_w* current=head;
    node_w* p=head;
    while(p!=NULL){
        current=p;
        p=p->nxt;
    }
    node_w* newnode_w=create_vertices_weight(x,w);
    newnode_w->nxt=current->nxt;
    current->nxt=newnode_w;
    }

    return head;
}

int edge_present(node_w* p, int v){
    int c=0;
    while(p!=NULL){
        if(p->v_name==v){
            c=1;
            break;
        }
        p = p->nxt;
    }
    return c;
}
void read_graph_weight(node_w *adj[],int n){
    srand(time(NULL));
    int k=0;
    for(int i=0;i<n;i++){
          adj[i]=insert_end(adj[i],i+1,0);
    }
    for(int i=0;i<n;i++){
        int k = rand()%n +1;
        for(int j=0;j<k;j++){
            int x= rand()%n + 1;
            int w=rand()%4+2;
            if(x!=(i+1) && (edge_present(adj[i],x) ==0 )){
                   adj[i]=insert_end(adj[i],x,w);
                   adj[x-1]=insert_end(adj[x-1],i+1,w);
                   //edge[k]=create_edge_node_w(i+1,x,w);
                   k++;
            }

              
        }
    }
}
void print_graph_weight(node_w *adj[],int n){
    for(int i=0;i<n;i++){
        node_w* x=adj[i]->nxt;
        cout<<adj[i]->v_name<<"-> ";
        for(;x!=NULL;x=x->nxt){
            cout<<" ("<<x->weight<<") "<<x->v_name<<" ";
        }
        cout<<endl;
    }

}
// unweighted graph functions 

node* insert_end(node* head , int x){
    if(head==NULL){
            head=create_vertices(x);
    }
    else{
           node* current=head;
    node* p=head;
    while(p!=NULL){
        current=p;
        p=p->nxt;
    }
    node* newnode=create_vertices(x);
    newnode->nxt=current->nxt;
    current->nxt=newnode;
    }

    return head;
}

int edge_present(node* p, int v){
    int c=0;
    while(p!=NULL){
        if(p->v_name==v){
            c=1;
            break;
        }
        p = p->nxt;
    }
    return c;
}
void read_graph(node *adj[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
          adj[i]=insert_end(adj[i],i+1);
    }
    for(int i=0;i<n;i++){
         int k = rand()%n +1;
        for(int j=0;j<k;j++){

            int x= rand()%n + 1;
            if(x!=(i+1) && (edge_present(adj[i],x)==0 )){
                   adj[i]=insert_end(adj[i],x);
                   adj[x-1]=insert_end(adj[x-1],i+1);
            }

              
        }
    }
}
 void print_graph(node *adj[],int n){
     cout<<"the  graph is : "<<endl;
     for(int i=0;i<n;i++){
         cout<<i+1<<"-> ";
         node* p=NULL;
         p=adj[i]->nxt;
         for(;p!=NULL;p=p->nxt){
             cout<<p->v_name<<" ";
         }
         cout<<endl;
     }
 }
int size_h(node_w *adj[],int n){
    int c=0;
    for(int i=0;i<n;i++){
         node_w* x=adj[i]->nxt;
         for(;x!=NULL;x=x->nxt){
             if(x->v_name>i+1){
                 c=c+x->weight-1;
             }
         }
    }
    return c+n;
}
int edge_present_new(node *h[],int x1,int x2){
    node* x=h[x1-1]->nxt;
    for(;x!=NULL;x=x->nxt){
        if(x->v_name==x2){
            return 1;
        }
    }
    return 0;
    
}
void add_edge(node *h[],int x1,int x2){
    // adj[x1-1]=create_vertices(x1);
    node *x=h[x1-1]->nxt;
    if(x1!=x2 && edge_present_new(h,x1,x2)==0){
        h[x1-1]=insert_end(h[x1-1],x2);
        h[x2-1]=insert_end(h[x2-1],x1);
    }
}

void read_h_graph(node_w *adj[],int n,node* h[]){
    int k=n;

    for(int i=0;i<n;i++){    
        node_w* x=adj[i]->nxt;
        for(;x!=NULL;x=x->nxt){
            if(x->v_name> (i+1)){
                if(x->weight > 1){
                    ++k;
                    add_edge(h,i+1,k);
                    for(int j=1;j<= (x->weight - 2);j++){
                       int  x1=k;
                        int x2=++k;
                        add_edge(h,x1,x2);

                    }
                    add_edge(h,k,x->v_name);
            

                    
                }
                else{
                    add_edge(h,i+1,x->v_name);
                }
            }
        } 
    }
}
void   bfs(node* adj[],int s,int n,int p ){
      
    string color[n];
    int d[n];
    node* parent[n];
            for(int i=0 ;i<n;i++){
                if(i+1 !=s){
                    color[i]="White";
                    d[i]=-1;
                    parent[i]=NULL;
                }
                
            }
            color[s-1]="Grey";
            d[s-1]=0;
            parent[s-1]=NULL;
            Queue Q;
            Q.enque(s);
            
            while(!(Q.IsEmpty())){
                int u= Q.peek();
                Q.deque();
                node *x=adj[u-1];
                node *v=x->nxt;
                for(;v!=NULL;v=v->nxt){
                    if(color[v->v_name -1]=="White"){
                        color[v->v_name-1]="Grey";
                        d[v->v_name-1] = 1 + d[u-1];
                        parent[v->v_name-1]=x;
                        Q.enque(v->v_name);
                        
                    }
                }
                color[u-1]="Black";
                
            }
            cout<<"sourcevertex is : "<<s<<endl;
            for(int i=0;i<n;i++){
                if(d[i]>=0 && i>=0 && i<p ){
                    cout<<" node: "<<i+1<<" "<<" Distance from source vertex  is : "<<d[i]<<endl;
                }
            }


}
int main(){
    int n=0;
    cout<<"Please enter the no of vertices: ";
    cin>>n;
    node_w *adj[n];

    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }

    read_graph_weight(adj,n);
    print_graph_weight(adj,n);
    int x=size_h(adj,n);

    
    node *h[x];
    for(int i=0;i<x;i++){
        h[i]=NULL;
    }
    for(int i=0;i<x;i++){
        h[i]=insert_end(h[i],i+1);
    }


    
    // add_edge(h,4,5);
    //  read_graph(h,x);
    
     read_h_graph(adj,n,h);
     print_graph (h,x);
     bfs(h,1,x,n);
}

