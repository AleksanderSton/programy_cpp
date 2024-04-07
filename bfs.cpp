#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, int s, int d, vector<vector<int>> &kingdom){
    vector<pair<int,int>> dist(n);
    for(int i = 0;i<n;i++){
        dist[i].first=i;
    }
    vector<bool> visited(n, false);
    int num_of_castles = 0;
    int time = 0;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    dist[s].second = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u].second <= d){
            num_of_castles++;
        }
        if(dist[u].second>time){
            time = dist[u].second;
        }
        for(int j = 0; j<kingdom[u].size();j++){
            int v = kingdom[u][j];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                dist[v].second = dist[u].second+1 ;
            }
        }
    }
    num_of_castles--;
    cout<<time<<' '<< num_of_castles<<'\n';
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, s, d;
    cin>>n>>m>>s>>d;
    vector<vector<int>> kingdom(n+1);
    for(int i = 0;i < m;i++){
        int a, b;
        cin>>a>>b;
        kingdom[a].push_back(b);
        kingdom[b].push_back(a);
    }
    bfs(n,s,(int)d/2,kingdom);
    return 0;
}