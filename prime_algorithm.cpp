#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

class Point
{
public:
    vector<pair<int, double>> connectionsAndChances;
    bool visited = false;
};

struct PointComparator {
    bool operator()(const pair<int, double>& p1, const pair<int, double>& p2) {
        return p1.second < p2.second;
    }
};

double prime(vector<Point>& locations) {
    double total_chance = 1.0;
    priority_queue<pair<int, double>, vector<pair<int, double>>, PointComparator> pq;
    int start = 0;
    locations[start].visited = true;
    for (pair<int,double> connection : locations[start].connectionsAndChances) {
        pq.push({connection.first, connection.second});
    }
    while (!pq.empty()) {
        pair<int,double> current_edge = pq.top();
        pq.pop();
        int next_vertex = current_edge.first;
        double weight = current_edge.second;
        if (!locations[next_vertex].visited) {
            locations[next_vertex].visited = true;
            total_chance *= weight;
            for (pair<int,double> connection : locations[next_vertex].connectionsAndChances) {
                pq.push({connection.first, connection.second});
            }
        }
    }

    return total_chance;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m,x,y;
    double possibility;
    cin>>n>>m;
    vector<Point> locations(n);
    for(int i = 0;i<m;i++){
        cin>>x>>y>>possibility;
        locations[x].connectionsAndChances.push_back({y,possibility});
        locations[y].connectionsAndChances.push_back({x,possibility});
    }
    double result = prime(locations);
    cout<<fixed<<setprecision(5)<<result<<endl;
    return 0;
}