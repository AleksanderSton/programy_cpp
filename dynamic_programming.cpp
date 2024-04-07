#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n,m, a,b,c,d;
    cin>>n>>m;
    cin.ignore();
    string family[1500];

    for(int i = 0;i<m;i++){
        getline(cin,family[i%1500]);
    }
    for(int i = m%1500;i < n;i++){
        cin>>a>>b>>c>>d;
        for(int j = 0;j < 3;j++){
            family[i%1500][j] = family[a%1500][j];
        }
        for(int j = 3;j < 6;j++){
            family[i%1500][j] = family[b%1500][j];
        }
        for(int j = 6;j < 9;j++){
            family[i%1500][j] = family[c%1500][j];
        }
        for(int j = 9;j < 12;j++){
            family[i%1500][j] = family[d%1500][j];
        }
    }
    for(int i=0;i<12;i++){
        cout<<family[(n-1)%1500][i];
    }
    cout<<'\n';
    return 0;
}