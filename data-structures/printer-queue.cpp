#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int minutes_to_print(priority_queue<pair<int, int>> printer_queue_s, queue<pair<int, int>> printer_queue, int m){
    int count = 0;
    while(!printer_queue.empty()){
        pair<int, int> current = printer_queue.front();
        pair<int, int> current_max = printer_queue_s.top();
        if(current.first != current_max.first){
            printer_queue.pop();
            printer_queue.push(current);
        }else{
            count++;
            if(current.second == m){
                break;
            }
            printer_queue.pop();
            printer_queue_s.pop();
        }
    }
    return count;
}
int main(){
    
    int n, m, test_cases;
    cin >> test_cases;
    for(int i = 0; i < test_cases; i++){
        cin >> n >> m;
        priority_queue<pair<int, int>>printer_queue_s;
        queue<pair<int, int>>printer_queue;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            printer_queue.push(make_pair(x, i));
            printer_queue_s.push(make_pair(x, i));
        }
        cout << minutes_to_print(printer_queue_s, printer_queue, m) << endl;
    }
    return 0;
}