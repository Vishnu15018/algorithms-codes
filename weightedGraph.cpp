#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
class node{
    public:
    int v_name;
    int weight;
    node* nxt;
    
};
class edge_node{
    public:
    int head;
    int tail;
    int weight;

};
void swap(edge_node* e1, edge_node* e2){
    edge_node* t=new edge_node();
    t->head=e1->head;
    t->weight=e1->weight;
    t->tail=e1->tail;
    e1->head=e2->head;
    e1->weight=e2->weight;
    e1->tail=e2->tail;

    e2->head=t->head;
    e2->weight=t->weight;
    e2->tail=t->tail;
    delete  t;
}
edge_node* create_edge_node(int a,int b,int w){
     edge_node* newnode= new edge_node();
     newnode->head=a;
     newnode->tail=b;
     newnode->weight=w;
     return newnode;

}
node* create_vertices(int x,int w){
    node* newnode= new node();
    newnode->v_name=x;
    newnode->weight=w;
    newnode->nxt=NULL;
    return newnode;
}
node* insert_end(node* head , int x,int w){
    if(head==NULL){
            head=create_vertices(x,w);
    }
    else{
           node* current=head;
    node* p=head;
    while(p!=NULL){
        current=p;
        p=p->nxt;
    }
    node* newnode=create_vertices(x,w);
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
    int k=0;
    for(int i=0;i<n;i++){
          adj[i]=insert_end(adj[i],i+1,0);
    }
    for(int i=0;i<n;i++){
        int k = rand()%n +1;
        for(int j=0;j<k;j++){
            int x= rand()%n + 1;
            int w=rand()%100+1;
            if(x!=(i+1) && (edge_present(adj[i],x) ==0 )){
                   adj[i]=insert_end(adj[i],x,w);
                   adj[x-1]=insert_end(adj[x-1],i+1,w);
                   //edge[k]=create_edge_node(i+1,x,w);
                   k++;
            }

              
        }
    }
}
void read_edges(edge_node *edge[],node *adj[],int n,int x){
        int k=0;
        for(int i=0;i<n;i++){
        node* x=adj[i]->nxt;
        for(;x!=NULL;x=x->nxt){
            if(x->v_name>i+1){
             edge[k]=create_edge_node(i+1,x->v_name,x->weight);
             k++;
            }
        }
    
    }
}
void print_graph(node *adj[],int n){
    for(int i=0;i<n;i++){
        node* x=adj[i]->nxt;
        cout<<adj[i]->v_name<<"-> ";
        for(;x!=NULL;x=x->nxt){
            cout<<" ("<<x->weight<<") "<<x->v_name<<" ";
        }
        cout<<endl;
    }

}
void print_edges(edge_node *edge[],int n){
    for(int i=0;i<n;i++){
        if(edge[i]!=NULL){
        cout<<" head of edge : "<<edge[i]->head;
        cout<<" weight of edge : "<<edge[i]->weight;
        cout<<" Tail of edge: "<<edge[i]->tail<<endl;
        }
        else{
            break;
        }
    }
}
void bubble_sort(edge_node *edge[],int n){
    for(int i=0;i<n;i++){ 
        cout<<"hai"<<endl; 
        for(int j=0;j<n-i-1;j++){
            if((edge[j]->weight) > (edge[j+1]->weight)){
                swap(edge[j],edge[j+1]);
            }
        }
    }
    
}
int main(){
    int n=0;
    cout<<"Please enter the no of vertices: ";
    cin>>n;
    node *adj[n];

    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }
    int x=(n*(n-1))/2;
    edge_node *edge[x];
    for(int i=0;i<x;i++){
        edge[i]=NULL;
    }
    read_graph(adj,n);
    print_graph(adj,n);
   read_edges(edge,adj,n,x);
   //cout<<"Before edge sorting : "<<endl;
    //bubble_sort(edge,x);
    for(int i=0;i<x;i++){ 
        //cout<<"hai"<<endl; 
        for(int j=0;j<x-i-1;j++){
            if((edge[j]->weight) > (edge[j+1]->weight)){
                swap(edge[j],edge[j+1]);
            }
        }
    }
    cout<<"After edge sorting: "<<endl;
    print_edges(edge,x);

}

