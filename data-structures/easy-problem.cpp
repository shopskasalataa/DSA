#include <iostream>
#include <queue>
#include <utility>
using namespace std;
void reset_queue(queue<int>& q){
    while(q.front() != 0){
        q.push(q.front());
        q.pop();
    }
    q.push(q.front());
    q.pop();
}
void find_occurence(queue<int>q, queue<pair<int, int>>queries){
    int occurence = 0, index = 1;
    while(q.front() != 0 && !queries.empty()){
        int k = queries.front().first, v = queries.front().second;
        if(q.front() == v){
            occurence++;
            if(occurence == k){
                cout << index << endl;
                index = 1;
                occurence = 0;
                reset_queue(q);
                queries.pop();
                continue;
            }
        }
        index++;
        q.push(q.front());
        q.pop();
        if(q.front() == 0){
            cout << "0" << endl;
            index = 1;
            occurence = 0;
            reset_queue(q);
            queries.pop();
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    queue<int>q;
    queue<pair<int, int>>queries;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    q.push(0);

    for(int i = 0; i < m; i++){
        int k, v;
        cin >> k >> v;
        queries.push(make_pair(k, v));
    }

    find_occurence(q, queries);
}

// 11991 Easy Problem from Rujia Liu?
// https://onlinejudge.org/external/119/11991.pdf