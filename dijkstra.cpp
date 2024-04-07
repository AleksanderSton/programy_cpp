#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;


struct Point {
    int x;
    int y;
    int dist = INT_MAX;
    vector<int> neighbours;
};
vector<Point> locations;
bool comprator(int a, int b){
    return locations[a].x>locations[b].x;
}
bool comprator2(int a, int b){
    return locations[a].y>locations[b].y;
}

void dijkstra(int source, int destination) {
    locations[source].dist = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (u == destination)
            break;

        for (int v : locations[u].neighbours) {
            int alt = dist_u + min(abs(locations[v].x - locations[u].x), abs(locations[v].y - locations[u].y));
            if (alt < locations[v].dist) {
                locations[v].dist = alt;
                pq.push({alt, v});
            }
        }
    }

    cout << locations[destination].dist << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;
    locations = vector<Point>(n);
    for (int i = 0; i < n; ++i) {
        cin >> locations[i].x >> locations[i].y;
    }
    vector<int> x(n);
    vector<int> y(n);
    for(int i =0;i<n;i++){
        x[i] = i;
        y[i] = i;
    }
    sort(x.begin(),x.end(), comprator);
    sort(y.begin(),y.end(), comprator2);


    for(int i = 0;i<n-1;i++){
        locations[x[i]].neighbours.push_back(x[i+1]);
    }
    for(int i = n-1;i>0;i--){
        locations[x[i]].neighbours.push_back(x[i-1]);
    }
    for(int i = 0;i<n-1;i++){
        locations[y[i]].neighbours.push_back(y[i+1]);
    }
    for(int i = n-1;i>0;i--){
        locations[y[i]].neighbours.push_back(y[i-1]);
    }

    int s, d;
    cin >> s >> d;

    dijkstra(s,d);

    return 0;
}