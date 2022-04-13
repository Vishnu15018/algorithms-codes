#include <iostream>
#include <stdlib.h>
#include<time.h>
#include<queue>
int  tm =0;
using namespace std;
class node{
    public:
    int v_name;
     string color;
     int d;
     int f;
     node* pi;
    node* nxt;
    
};
node* create_vertices(int x){
    node* newnode= new node();
    newnode->v_name=x;
     newnode->color="White";
     int d=0;
     int f=0;
     newnode->pi=NULL;
    newnode->nxt=NULL;
    return newnode;
}
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
     cout<<"the directed graph is : "<<endl;
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
 void dfs_visit(node *adj[],int x){
     tm =tm+1;
     adj[x-1]->d=tm;
     adj[x-1]->color="Gray";
     node* v=adj[x-1]->nxt;
     
    while(v!=NULL){
          cout<<v->color<<endl;
         if(v->color=="White"){
             v->pi=adj[x-1];
             dfs_visit(adj,v->v_name);
         }
         v=v->nxt;
        
     }
     cout<<"hai"<<endl;
     adj[x-1]->color="Black";
     tm=tm+1;
     adj[x-1]->f=tm;
     cout<<" "<<adj[x-1]->v_name;
 }
void dfs(node *adj[],int n){
    // adj[u-1]->pi=NULL;
    
     for(int i=0;i<n;i++){
        //  node* p=adj[i];
        
        if(adj[i]->color=="White"){
            
              dfs_visit(adj,i+1);
        }
           
     }
}
//  void print_dfs(node *adj[],int n){
//      for(int i=0;i<n;i++){
//          node* x=adj[i];
//          while(x!=NULL){
//              if(x->color=="Black"){
//                  cout<<x->v_name<<" ";
//              }
//              x=x->nxt;
//          }
//      }
//  }
int main()
{   
    int n=0;
    cout<<"Please Enter the No of nodes of a graph : ";
    cin>>n;
    node *adj[n];
    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }
    //bi_partite_graph(adj,n);
    read_graph(adj,n);
    // for(int i=0;i<n;i++){
    //     cout<<adj[i]->color<<endl;
    // }
    //print_graph(adj,n);
    dfs(adj,n);
    //cout<<adj[0]->f<<endl;



}