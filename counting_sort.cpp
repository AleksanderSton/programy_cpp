#include <iostream>
#include <cmath>

struct Dish{
    std::string name ;
    int calories;
    int a,b;
};
void counting_sort( Dish * dishes, int n){
    int * first_col =  new int[n]{0};
    Dish * result = new Dish[n];
    for(int i=0;i<n;i++){
        first_col[dishes[i].a]++;
    }
    for(int i=1;i<n;i++){
        first_col[i] += first_col[i-1];
    }
    for(int i=n-1;i>=0;i--){
        result[--first_col[dishes[i].a]] = dishes[i];
    }
    for(int i =0;i<n;i++){
        first_col[i]=0;
    }
    for(int i =0;i<n;i++){
        first_col[dishes[i].b]++;
    }
    for(int i =0;i<n;i++){
        first_col[i] += first_col[i-1];
    }
    for(int i =n-1;i>=0;i--){
        dishes[--first_col[result[i].b]] = result[i];
    }
    for(int i=0;i<n;i++){
        std::cout<<dishes[i].name<<' ';
    }
    std::cout<<'\n';
    delete[] first_col;
    //delete[] second_col;
    delete[] result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin>>n;
    Dish* dishes = new Dish[n];
    for(int i=0;i<n;i++){
        std::cin>>dishes[i].name;
        std::cin>>dishes[i].calories;
        dishes[i].a = dishes[i].calories%n;
        dishes[i].b = floor(dishes[i].calories/n);
    }
    counting_sort(dishes,n);
    delete[]dishes;
    return 0;
}