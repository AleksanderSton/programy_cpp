#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Camera{
    int start = 0,end = 0;
};

bool compareCameras(const Camera& c1,const Camera& c2){
    return c1.end<c2.end;
}
void is_possible_to_set_cameras(int n, vector<Camera>& monitoring){
    bool* is_possible;
    is_possible = new bool[n]();
    int j;
    for(int i=0;i<n;i++){
        j=monitoring[i].start;
        while(is_possible[j] && j<monitoring[i].end){
            j++;
        }
          is_possible[j] = true;

    }
    sort(is_possible,is_possible+n);

    if(binary_search(is_possible,is_possible+n, false)){
        cout<<"NIE\n";
    }
    else{
        cout<<"TAK\n";
    }
    delete is_possible;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t,n,a,b;
    cin>>t;
    for(int i =0;i<t;i++){
        cin>>n;
        vector<Camera> monitoring(n);
        for(int j=0;j<n;j++){
            cin>>a>>b;
            monitoring[j].start = a;
            monitoring[j].end = b;
        }
        sort(monitoring.begin(),monitoring.end(), compareCameras);
        is_possible_to_set_cameras(n,monitoring);
    }

    return 0;
}