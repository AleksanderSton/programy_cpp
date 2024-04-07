#include <iostream>
using namespace std;

class Actor{
public:
    string name=" ";
    long long f;
    Actor * next = nullptr;
};

class List{
private:
    Actor * first = nullptr ;
    Actor * last = nullptr;
public:
    ~List(){
        Actor * pom;
        while(first!= nullptr){
            pom=first;
            first = first->next;
            delete pom;
        }
    }

    void push_front(Actor newA){
        Actor* pom = new Actor;
        pom->name=newA.name;
        pom->f = newA.f;
        if(first== nullptr){
            first = pom;
            last = pom;
            cout<<"TAK"<<'\n';
            return;
        }
        Actor *temp = first;
        while(temp != nullptr){
            if(temp->name==newA.name && temp->f==newA.f){
                cout<<"NIE"<<'\n';
                return;
            }
            temp=temp->next;
        }
        pom->next=first;
        first = pom;
        cout<<"TAK"<<'\n';
    }
    void erase(Actor *act){
        Actor * temp = first;
        if(temp==act){
            temp = first->next;
            delete act;
            first = temp;
            return;
        }
        while(temp->next){
            if(temp->next==act){
                temp->next = act->next;
                delete act;
                return;
            }
            if (temp->next==last && act == last){
                last = temp;
                delete act;
                return;
            }
            temp = temp->next;
        }
    }
    void find(long long p) {
        Actor* temp = first;
        Actor* result = nullptr;  // Initialize result to nullptr
        bool to_erase = false;

        while (temp) {
            if (temp->f <= p && (result == nullptr || (temp->f > result->f) || (temp->f == result->f && temp->name < result->name))) {
                result = temp;
                to_erase = true;
            }
            temp = temp->next;
        }

        if (to_erase && result) {  
            cout << result->name << '\n';
            erase(result);
        } else {
            cout << "NIE" << '\n';
        }
    }

};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    int op;
    long long p;
    Actor temp;
    List actor_list;
    string converter;

    getline(cin,converter);
    n=stoi(converter);
    for(long long i =0;i<n;i++){
        getline(cin,converter);
        op=stoi(converter);
        if(op==1){
            getline(cin,temp.name);
            getline(cin,converter);
            temp.f=stoi(converter);
            actor_list.push_front(temp);
        }
        if(op == 2){
            getline(cin,converter);
            p=stoi(converter);
            actor_list.find(p);
        }
    }
    return 0;
}