// visited array -> to prevent to go in loop
#include <iostream>
#include <vector>
using namespace std;
#define int long long
vector<int> vis;
vector<vector<int>> adjlist;

void dfs(int vertex){
    /* take action on vertex after entering the vertex
     */
    vis[vertex] = 1;
    for(auto child : adjlist[vertex]){
        if(vis[vertex]) continue;
        /* take action on child before entering the child node
        */
       dfs(child);
       /* take action on child after exiting
       */
    }
    /* take action on vertex before exiting the vertex
    */
}
// O(v+e)
void solve(){
    int n,m;
    cin>>n>>m;

    vis.assign(n,0);
    adjlist.assign(n,vector<int>());

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}


signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}