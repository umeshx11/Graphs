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
    cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(m+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j) dist[i][j] = 0;
            else{
                dist[i][j] = LLONG_MAX;
            }
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v] = wt;
    }
    // here we include node level by level
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<endl;
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