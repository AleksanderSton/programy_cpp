#include <iostream>

using namespace std;
class List{
public:
    string name;
    unsigned long x=0;
};
void insertSort(List *arr, long long n,long long p){
    List temp;
    long long j;
    for(long long  i=1;i<n;i++){
        if(arr[i].x > arr[i - 1].x){
            temp = arr[i];
            for(j=i-1;(j>=0) && (arr[j].x < temp.x); j--){
                arr[j+1]=arr[j];
            }
            arr[j+1]=temp;
        }
    }
    for(long long i=0;i<p;i++){
        for(j=i+1;j<n;j++){
            if((arr[i].x == arr[j].x) && (arr[i].name > arr[j].name)){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    long long p,n;
    cin>>t;
    cin.ignore();
    List* people;
    for(int i =0;i<t;i++){
        cin>>n>>p;
        people = new List[n];
        for(long long  j=0;j<n;j++){
            cin.ignore();
            cin>>people[j].name;
            cin.ignore();
            cin>>people[j].x;
        }
        insertSort(people,n,p);
        unsigned long max_time=0;
        for(long long k=0;k<n;k++){
            max_time += (1+(people[k].x * k)) % 1000003;
        }
        max_time = max_time % 1000003;
        for(long long l =0;l<p;l++){
            cout<<people[l].name<<' ';
        }
        cout<<'\n'<<max_time<<'\n';
        delete[] people;
    }
    return 0;
}