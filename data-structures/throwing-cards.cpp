#include <iostream>
#include <queue>
using namespace std;

void throwing_cards(const int &n){
    queue <int> deck;
    for(int i = 1; i <= n; i++){
            deck.push(i);
        }
        cout << "Discarded cards:";
        bool first_output = true;
        while(!deck.empty()){
            int next = deck.front();
            deck.pop();
            deck.push(deck.front());
            deck.pop();

            if(deck.empty()){
                cout << endl << "Remaining card:";
                first_output = true;
                cout << (first_output ? " " : ", ") << next << endl;
                break;
            }

            cout << (first_output ? " " : ", ") << next;

            first_output = false;
        }
}
int main(){
    int n;
    queue <int> instructions;

    cin >> n;
    while(n != 0){
        instructions.push(n);
        cin >> n;
    }
    while(!instructions.empty()){
        throwing_cards(instructions.front());
        instructions.pop();
    }
    return 0;
}

// 10935 Throwing Cards Away
// https://onlinejudge.org/external/109/10935.pdf