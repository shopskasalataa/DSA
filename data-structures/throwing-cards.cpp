#include <iostream>
#include <queue>
using namespace std;

void throwing_cards(const int &n){
    queue <int> deck;
    for(int i = 1; i <= n; i++){
            deck.push(i);
        }
        cout << "Discarded cards: ";
        while(!deck.empty()){
            int next = deck.front();
            deck.pop();
            deck.push(deck.front());
            deck.pop();
            
            if(deck.empty()){
                cout << endl << "Remaining card: ";
            }
            cout << next << (deck.empty() ? "" : ", ");
        }
        cout << endl;
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