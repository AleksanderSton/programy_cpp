#include <iostream>
#include <algorithm>

using namespace std;

void sort_proggrams(long long &max, int c, int d ,int* end,int* start,int n){
    sort(end,end+n);
    sort(start,start+n);
    bool* is_used;
    long long temp_start;
    is_used= new bool[n]();
    for(int i = n-1;i>=0;i--){
        temp_start = upper_bound(start,start+n,end[i]) - start;
        for(long long j = temp_start;j<n;j++){
            if(!is_used[j]){
                if((((start[j]-end[i]) * d) < c)){
                    is_used[j] = true;
                    max=max-c+(d*(start[j]-end[i]));

                }
                break;
            }
        }
    }
    cout<<max<<'\n';
    delete[] is_used;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,t,c,d;
    long long max;
    cin>>t;
    int * end;
    int * start;
    for(int i=0;i<t;i++){
        cin>>n>>c>>d;
        end = new int[n];
        start = new int[n];
        max = n*c;
        for(int j=0;j<n;j++){
            cin>>start[j]>>end[j];
            if(start[j]!=end[j]) {
                max += (end[j] - start[j]) * d;
            }
        }
        sort_proggrams(max, c, d,end,start,n);
        delete[] end;
        delete[] start;
    }
    return 0;
}