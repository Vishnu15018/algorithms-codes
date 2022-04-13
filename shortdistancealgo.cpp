#include <iostream>
#include<climits>
using namespace std;

class node{
    public:
    int v_name;
    int wt;
    node *nxt;
};

node* create(int d, int w){
    node* n;
    n = new node();
    n->v_name = d;
    n->wt = w;
    n->nxt = NULL;
    return n;
}

class list{
    public:
    node* head;
    list(){
        head = NULL;
    }
    void insert(int d, int w);
};

void list::insert(int d, int w){
    if(head == NULL){
        head = new node();
        head->v_name = d;
        head->wt = w;
        head->nxt = NULL;
    }
    else{
        node* t;
        t = create(d, w);
        t->nxt = head;
        head = t;
    }
}

struct edge{
    int f_ind;
    int s_ind;
    int wt;
};

class graph_wd{
    public:
    list *adj;
    int n;
    int **adj_m;
    edge *e;
    int p;
    graph_wd(int kit){
        n = kit;
        adj = new list[n];
        adj_m = new int*[n];
        int k =( n * (n - 1)) / 2;
        e = new edge[k];
        for(int i = 0; i < n; i++){
            adj_m[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                adj_m[i][j] = 0;
            }
        }
    }
    void create(){
        int k =( n * (n - 1)) / 2;
        e = new edge[k];
        p = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                k = rand()%2;
                if(((i != j) & (k == 1)) & (adj_m[i][j] == 0)){
                    adj_m[i][j] = rand()%10 + 1;;
                    adj[i].insert(j, adj_m[i][j]);
                    e[p].f_ind = i;
                    e[p].s_ind = j;
                    e[p].wt = adj_m[i][j];
                    p++;
                }                
            }
        }
    }
    void show(){
        for(int i = 0; i < n; i++){
            cout<<i<<"-->";
            node* t;
            t = new node();
            t = adj[i].head;
            while(t != NULL){
                cout<<t->v_name<<"("<<t->wt<<")"<<" ";
                t = t->nxt;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}; 

int Belm_ford(graph_wd g, int s){
    int d[g.n];
    int pr[g.n];
    int k = 1;
    for(int i = 0; i < g.n; i++){
        d[i] = INT_MAX - 1000;
        pr[i] = -1;
    }
    d[s] = 0;
    for(int i = 1; i < g.n; i++){
        for(int j = 0; j < g.n; j++){
            for(int q = 0; q < g.n; q++){
                if(g.adj_m[j][q] > 0){
                    if(d[q] > d[j] + g.adj_m[j][q]){
                        d[q] = d[j] + g.adj_m[j][q];
                        pr[q] = j;
                    }
                }
            }
        }
    }
    for(int j = 0; j < g.p; j++){
        if(d[g.e[j].s_ind] > d[g.e[j].f_ind] + g.e[j].wt){
            k = 0;
        }
    }
    if(k == 1){
        cout<<"Single source shortest paths from source "<<s<<" using Bellman ford algorithm : "<<endl;

        for(int i = 0; i < g.n; i++){
            cout<<"Distance To vertice "<<i<<" from source is : "<<d[i]<<endl;
        }
        cout<<endl;
    }
    else{
        cout<<"There is a negative cycle"<<endl;
    }
    return k; 
}

class heap_pd{
    public:
    int hs;
    int *arr;
    heap_pd(int n){
        hs = n;
        arr = new int[hs + 1];
        for(int i = 0; i <= hs; i++){
            arr[i] = i - 1;
        }
    }
    void percolate_dn(int k, int* key){
        int child;
        int hole = k;
        int t = arr[hole];
        while((hole * 2) <= hs){
            child = hole * 2;
            if((child + 1 <= hs) && (key[arr[child + 1]] < key[arr[child]])){
                ++child;
            }
            if(key[arr[child]] < key[arr[hole]]){
                arr[hole] = arr[child];
                hole = child;
            }
            else{
                break;
            }
            arr[hole] = t;
        }
    }
    int delete_min(int *key){
        int r = arr[1];
        arr[1] = arr[hs];
        hs = hs - 1;
        percolate_dn(1, key);
        return r;
    }
    void heapify(int* key){
        int t = hs / 2;
        while(t >= 1){
            percolate_dn(t, key);
            t--;
        }
    }
};

void dikstra_algo(graph_wd g, int s){
    int d[g.n];
    int pr[g.n];
    for(int i = 0; i < g.n; i++){
        d[i] = INT_MAX - 1000;
        pr[i] = -1;
    }
    d[s] = 0;
    heap_pd q(g.n);
    q.heapify(d);
    while(q.hs > 0){
        int u = q.delete_min(d);
        node* t;
        t = new node();
        t = g.adj[u].head;
        while(t != NULL){
            int v = t->v_name;
            if(d[v] > d[u] + g.adj_m[u][v]){
                d[v] = d[u] + g.adj_m[u][v];
                q.heapify(d);
                pr[v] = u;
            }
            t = t->nxt;
        }
    }
    cout<<" Shortest paths from Single source "<<s<<" using Dijskstra's algo : "<<endl;

    for(int i = 0; i < g.n; i++){
         cout<<"Distance To vertice "<<i<<" from source is : "<<d[i]<<endl;
        }
        
}

int main(){
    
        graph_wd randgraph(10);
        randgraph.create();
        cout<<"Given Main Graph"<<endl;
        randgraph.show();
        Belm_ford(randgraph, 3);
        dikstra_algo(randgraph, 3);
    

}