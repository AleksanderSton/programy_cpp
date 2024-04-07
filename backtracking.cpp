#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void possibilities(vector<int>& calories, int target, int& counter, int current, int index){
    if(current == target){
        counter++;
        return;
    }
    for(int i = index;i < calories.size();i++){
        if(current + calories[i] <= target){
            possibilities(calories,target,counter,current + calories[i],i+1);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t,n,k;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        vector<int> calories(n,0);
        for(int j = 0; j < n;j++){
            cin>>calories[j];
        }
        cin>>k;
        int counter = 0;
        sort(calories.begin(),calories.end(), greater<int>());
        possibilities(calories,k, counter,0,0);
        cout<<counter<<'\n';
    }
    return 0;
}