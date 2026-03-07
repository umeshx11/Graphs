#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <cstring>
#include <string>
#include <numeric>
#include <climits>
#include <iomanip>

using namespace std;

#define int long long

void solve(){
    int n,m;
    vector<vector<int>> adjlist(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    // bfs
    queue<int> q;
    int root;
    vector<int> visited(n,0);
    q.push(root);
    visited[root] = 1;
    vector<int> traversal;
    while(q.size()){
        int curr = q.front(); q.pop();
        traversal.push_back(curr);
        for(auto child : adjlist[curr]){
            if(!visited[child]){
                visited[child] = 1;
                q.push(child);
            }
        }
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