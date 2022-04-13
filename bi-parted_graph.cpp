#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
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




void bi_partite_graph(node *adj[],int n){
    srand(time(NULL));
    int z = rand()%(n-2)+2;
    for(int i=0 ;i<n;i++){
        adj[i]=insert_end(adj[i],i+1);
    }
    
    string c="";
    int count=0;
    cout<<"enter(Y/y) If you want to add an edge in bipartite , else (N/n) : "<<endl;
    cin>>c;
    while((c=="y"|| c=="Y")){
        int a1=rand()%z+1;
        int b1=rand()%(n-z)+(z+1);
        adj[a1-1]=insert_end(adj[a1-1],b1);
    cout<<"enter(Y/y) If you want to add an edge in bipartite , else (N/n) : "<<endl;
       cin>>c;
    }
}

 void print_graph(node *adj[],int n){
     cout<<"the  graph is : "<<endl;
     for(int i=0;i<n;i++){
         cout<<i+1<<"-> ";
         node* p=NULL;
         p=adj[i];
         for(;p!=NULL;p=p->nxt){
             cout<<p->v_name<<" ";
         }
         cout<<endl;
     }
 }
int main()
{   
    int n=0;
    cout<<"Please Enter the No of nodes of a graph : ";
    cin>>n;
    node *adj[n];
    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }
    bi_partite_graph(adj,n);
    print_graph(adj,n);



}