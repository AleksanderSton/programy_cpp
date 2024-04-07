#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Monkey {
public:
    Monkey(char letter, int number) {
        this->letter = letter;
        this->number = number;
    }

    char letter = ' ';
    int number = 0;
    vector<Monkey* > children;
    void print_monke(){
        cout<<this->letter;
        for(int i =0;i<children.size();i++){
            if(children[i]!= nullptr)
                children[i]->print_monke();
        }
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long k;
    long long n;
    char letter;
    int number;
    cin >> k;

    for (long long i = 0; i < k; i++) {
        Monkey *head_monkey;
        queue<Monkey*> monkeys;
        cin >> n;
        cin>>letter>>number;
        head_monkey = new Monkey(letter,number);
        monkeys.push(head_monkey);
        for (long long j = 1; j < n; j++) {
            cin>>letter>>number;
            Monkey* monke = new Monkey(letter,number);
            monkeys.push(monke);
            if(monkeys.front()->number != 0){
                monkeys.front()->children.push_back(monke);
                monkeys.front()->number--;
            }
            if(monkeys.front()->number==0){
                monkeys.pop();
            }
        }
        head_monkey->print_monke();
        delete head_monkey;
        cout << '\n';
    }
    return 0;
}