#include <iostream>
#include <cmath>

using namespace std;

//double P(int i,int j){
//    return 30-sqrt(pow((i-5),2)+pow((j-5),2));
//}
double MAX(int n,int m){

    int temp=P(n,0);
    int temp_m=0;
    for(int i = 1;i<m;i++){
        if(temp<P(n,i)){
            temp = P(n,i);
            temp_m = i;
        }
    }if(n<2){
        return temp;
    }
    if(P(n-1,temp_m)>temp && P(n-1,temp_m) > P(n+1,temp_m) ){//left side
        return MAX((n/2),m);
    }
    else if(P(n+1,temp_m)>temp && P(n-1,temp_m) < P(n+1,temp_m)){//right side;
        n+=n/2;
        return MAX(n,m);
    }
    else if(P(n-1,temp_m)>temp && P(n+1,temp_m)>temp && P(n-1,temp_m) == P(n+1,temp_m)){
        return MAX(n/2,m);
    }
    else{
        return temp;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    cout<<(int)floor(MAX(n/2,m));
    return 0;
}