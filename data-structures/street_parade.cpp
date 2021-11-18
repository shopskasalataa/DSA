#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n;
    queue<int> street_in;
    stack<int> street_side;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        street_in.push(x);
    }
    int next = 1;
    bool blocked = false;
    while(next <= n && !blocked){
        if(!street_side.empty()){
            int x = street_side.top();
            if(x == next){
                street_side.pop();
                next++;
            }else if(street_in.empty()) blocked = true;
        }
        bool found = false;
        while(!street_in.empty() && !found){
            int x = street_in.front();
            street_in.pop();
            if(x == next){
                found = true;
                next++;
            }else street_side.push(x);
        }
    }

    cout << !blocked << endl;
    return 0;
}

// STPAR - Street Parade
// https://www.spoj.com/problems/STPAR/