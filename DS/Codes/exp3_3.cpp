#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<list<int>> adj;
public:
    Graph(int V){
        this->V = V;
        adj.resize(this->V);
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void printAdj(){
        for(auto lst: adj){
            for(auto adjacent: lst)
                cout<<adjacent<<" ";
            cout<<"\n";
        }
    }

    void BFS(int v);
    void DFS(int v);
};

void Graph::BFS(int v){
    vector<bool> vis(V,false);

    queue<int> q;
    q.push(v);
    vis[v]=true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";

        for(auto adjacent: adj[curr]){
            if(!vis[adjacent]){
                q.push(adjacent);
                vis[adjacent]=true;
            }
        }
    }
}

void Graph::DFS(int v){
    vector<bool> vis(V,false);

    stack<int> st;
    st.push(v);

    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis[curr]){
            cout<<curr<<" ";
            vis[curr]=true;

            for(auto adjacent: adj[curr]){
                if(!vis[adjacent]){
                    st.push(adjacent);
                }
            }
        }
    }
}

int main(){
    int V,E;cin>>V>>E;
    Graph g(V);
    while(E--){
        int v,w;cin>>v>>w;
        g.addEdge(v,w);
    }

    g.BFS(0);
    cout<<"\n";
    g.DFS(0);
}
