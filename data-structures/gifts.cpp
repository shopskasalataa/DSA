#include <iostream>
#include <stack>
using namespace std;
int n;
bool flag;
stack<int> tube_1, tube_2;

void move_from_1_to_2(){
    tube_2.push(tube_1.top());
    tube_1.pop();
    cout << "1";
}
void move_from_1_to_3(){
    tube_1.pop();
    flag = 1;
    cout << "12";
}
void move_from_2_to_1(){
    tube_1.push(tube_2.top());
    tube_2.pop();
    cout << "3";
}
void move_from_2_to_3(){
    tube_2.pop();
    flag = 1;
    cout <<"2";
}
void move_gift(int x){
    flag = 0;
    while(!flag){
        if(!tube_1.empty()){
            if(tube_1.top() > x) move_from_1_to_2();
                else if(tube_1.top() == x) move_from_1_to_3();
                    else if(tube_2.top() == x) move_from_2_to_3();
                        else move_from_2_to_1();
        }else{
            if(tube_2.top() == x) move_from_2_to_3();
                else move_from_2_to_1();
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        tube_1.push(i);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        move_gift(x);
    }
    cout << endl;
    return 0;
}

// Подаръци
// http://www.math.bas.bg/infos/files/2012-05-08-D4.pdf