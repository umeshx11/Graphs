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

void dijkstra(vector<vector<pair<int,int>>>& adjlist, int source,int n){
    vector<int> visited(n,0);
    vector<int> dist(n,LLONG_MAX);
    set<pair<int,int>> s;
    s.insert({0,source});
    dist[source] = 0;
    
    while(s.size()){
        auto x = *s.begin();
        int curr_wt = x.first;
        int curr = x.second;
        s.erase(s.begin());
        if(visited[curr]) continue;
        visited[curr] = 1;

        for(auto child : adjlist[curr]){
            int child_dist = child.second;
            int child_curr = child.first;
            if(dist[curr]+child_dist<dist[child_curr]){
                dist[child_curr] = dist[curr]+child_dist;
                s.insert({dist[child_curr],child_curr});
            }
        }
    }

}

void solve(){
    
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}