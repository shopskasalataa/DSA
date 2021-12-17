#include <iostream>
#include "Queue.hpp"
using namespace std;

int main(){
    Queue<int> s;
    s.push(3);
    s.push(1);
    s.push(4);
    cout << s.size() << endl;
    cout << s.back() << " " << endl;
    while(!s.empty()){
        cout << s.front() << " " << endl;
        
        s.pop();
    }
    return 0;
}
