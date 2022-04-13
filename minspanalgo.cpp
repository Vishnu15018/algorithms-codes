#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<climits>
using namespace std;

class node{
    public:
    int v_name;
    int wt;
    node *next;
};

node* create(int d, int w){
    node* newnode;
    newnode = new node();
    newnode->v_name = d;
    newnode->wt = w;
    newnode->next = NULL;
    return newnode;
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
        head->next = NULL;
    }
    else{
        node* t;
        t = create(d, w);
        t->next = head;
        head = t;
    }
}

struct edge{
    int f_ind;
    int s_ind;
    int wt;
};

class graph_w{
    public:
    list *adj;
    int n;
    int **adj_m;
    edge *e;
    int p;
    graph_w(int kit){
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
                    adj_m[j][i] = adj_m[i][j];
                    adj[j].insert(i, adj_m[i][j]);
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
                t = t->next;
            }
            cout<<endl;
        }
        cout<<endl;
    }
}; 

class set{
    public:
    int n;
    int *p;
    int *rank;
    set(int k){
        n = k;
        p = new int[n];
        rank = new int[n];
        for(int i = 0; i < n; i++){
            p[i] = -1;
            rank[i] = -1;
        }
    }
    void make_set(int x){
        p[x] = x;
        rank[x] = 0;
    }
    void link(int x, int y){
        if(rank[x] > rank[y]){
            p[y] = x;
        }
        else{
            p[x] = y;
            if(rank[x] == rank[y]){
                rank[y] = rank[y] + 1;
            }
        }
    }
    int find_set(int x){
        if(p[x] != x){
            p[x] = find_set(p[x]);
        }
        return p[x];
    }
    void union_(int x, int y){
        link(find_set(x), find_set(y));
    }
};



void edge_srt(edge *arr, int n){
    int i, j;
    for(i = 0;i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(arr[j].wt > arr[j + 1].wt){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

graph_w kruskal_algo(graph_w g){
    graph_w h(g.n);
    set s(g.n);
    for(int i = 0; i < g.n; i++){
        s.make_set(i);
    }
    edge_srt(g.e, g.p);
    for(int i = 0; i < g.p; i++){
        int u = g.e[i].f_ind;
        int v = g.e[i].s_ind;
        if(s.find_set(u) != s.find_set(v)){
            h.adj[u].insert(v, g.e[i].wt);
            h.adj[v].insert(u, g.e[i].wt);
            h.adj_m[u][v] = g.e[i].wt;
            h.adj_m[v][u] = h.adj_m[u][v];
            s.union_(u, v);
        }
    }
    return h;
}

int is_in(int n, int v, int *a){
    int c = 0;
    for(int i = 0; i <= n; i++){
        if(v == a[i]){
            c = 1;
        }
    }
    return c;
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


graph_w prims(graph_w g){
    int key[g.n];
    int pr[g.n];
    char clr[g.n];
    graph_w nw(g.n);
    for(int i = 0; i < g.n; i++){
        key[i] = INT_MAX;
        pr[i] = -1;
        clr[i] = 'b';
    }
    int r = rand()%g.n;
    key[r] = 0;
    heap_pd hp(g.n);
    hp.heapify(key);
    int ct = 0;
    while(hp.hs > 0){
        int u = hp.delete_min(key);
        clr[u] = 'w';
        node* t;
        t = new node();
        t = g.adj[u].head;
        while(t != NULL){
            int  v = t->v_name;
            if((clr[v] == 'b') & (t->wt < key[v])){
                ct = ct + 1;
                pr[v] = u;
                key[v] = t->wt;
                hp.heapify(key);
            }
            t = t->next;
        }
    }
    for(int i = 0; i < g.n; i++){
        if(pr[i] >= 0){
            nw.adj[i].insert(pr[i], g.adj_m[i][pr[i]]);
            nw.adj[pr[i]].insert(i, g.adj_m[i][pr[i]]);
            nw.adj_m[i][pr[i]] = g.adj_m[i][pr[i]];
            nw.adj_m[pr[i]][i] = g.adj_m[i][pr[i]];
        }
    }
    return nw;
}

int main(){
    double tk[10];
    double tp[10];
    for(int i=0;i<10;i++){
        int p=10;
        clock_t t1;
        cout<<"Please enter the no of v_nametices of "<<i+1<<" instance : ";
        cin>>p;
        graph_w randgraph(p);
        randgraph.create();
        graph_w primsgraph(randgraph.n);
        graph_w kruskalsgraph(randgraph.n);
        randgraph.show();
        t1=clock();
        kruskalsgraph = kruskal_algo(randgraph);

        
        cout<<"MST using Kruskal's algorithm : "<<endl;
        kruskalsgraph.show();
        t1=clock()-t1;
        double t=(double)t1/CLOCKS_PER_SEC;
        tk[i]=t;

        t1=clock();
        primsgraph = prims(randgraph);
;
        cout<<"MST using Prim's algorithm : "<<endl;;
        primsgraph.show();
                t1=clock()-t1;
        t=(double)t1/CLOCKS_PER_SEC;
        tp[i]=t;
    }
        cout<<"\tTime takens : "<<endl;
        cout<<"Kruskals algo "<<" Primsalgo "<<endl;
    for(int i=0;i<10;i++){
        cout<<tk[i]<<"\t\t"<<tp[i]<<endl;
    }
    
}