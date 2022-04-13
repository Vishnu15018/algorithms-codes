#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

struct node* create(int d){
    struct node* n;
    n = new node();
    n->data = d;
    n->next = NULL;
    return n;
}

class list{
    public:
    struct node* head;
    list(){
        head = NULL;
    }
    void insert(int d);
};

void list::insert(int d){
    if(head == NULL){
        head = new node();
        head->data = d;
        head->next = NULL;
    }
    else{
        struct node* t;
        t = create(d);
        t->next = head;
        head = t;
    }
}


class graph{
    public:
    list *adj;
    int n;
    int **adj_m;
    int e;
    graph(){
        cout<<"Enter no of vertices: ";
        cin>>n;
        adj = new list[n];
        adj_m = new int*[n];
        for(int i = 0; i < n; i++){
            adj_m[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj_m[i][j] = 0;
            }
        }
        e = 0;
    }
    graph(int p){
        n = p;
        adj = new list[n];
        adj_m = new int*[n];
        for(int i = 0; i < n; i++){
            adj_m[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj_m[i][j] = 0;
            }
        }
        e = 0;
    }
    void create(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k;
                k = rand()%2;
                if(((k == 1) & (i != j)) & adj_m[i][j] == 0){
                    adj[i].insert(j);
                    adj_m[i][j] = 1;
                    adj_m[j][i] = 1;
                    adj[j].insert(i);
                    e = e + 1;
                }
            }
        }
    }
    void show(){
        for(int i = 0; i < n; i++){
            cout<<i<<"-->";
            struct node* t;
            t = new node();
            t = adj[i].head;
            while(t != NULL){
                cout<<t->data<<" ";
                t = t->next;
            }
            cout<<endl;
        }
    }
};

void is_c4_free(graph g){
    int v = g.n;
    int c4 = 0;
    for(int i = 0;((i < v) & (c4 == 0)); i++){
        for(int j = 0; ((j < v) & (c4 == 0)); j++){
            if(g.adj_m[i][j] == 1){
                struct node* adj_i;
                struct node* adj_j;
                adj_i = new node();
                adj_j = new node();
                adj_i = g.adj[i].head;
                adj_j = g.adj[j].head;
                while((adj_i != NULL) & (c4 == 0)){
                    if((g.adj_m[adj_i->data][j] != 1) & (j != adj_i->data)){
                        while((adj_j != NULL) & c4 == 0){
                            if((g.adj_m[adj_j->data][i] != 1) & (i != adj_j->data)){
                                if(g.adj_m[adj_i->data][adj_j->data] == 1){
                                    c4 = 1;
                                    cout<<"Vertices in c4 are "<<i<<","<<j<<","<<adj_i->data<<","<<adj_j->data<<endl;
                                }
                            }
                            adj_j = adj_j->next;
                        }
                    }
                    adj_i = adj_i->next;
                }
            }
        }
    }
    if(c4 == 0){
        cout<<"Given graph is induced c4 free"<<endl;
    }
    else{
        cout<<"Given graph contains induced c4"<<endl;
    }
}


int main(){
    graph g1(5);
    g1.create();
    g1.show();
    is_c4_free(g1);
    graph g2;
    g2.create();
    g2.show();
    is_c4_free(g2);
}