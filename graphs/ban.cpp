// решението на тази задача е да се намери броя на мостовете и да се изведе, това са пътищата, които свързват градовете и ако се ремонтират
// не може да се стигне от един град до друг
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m, time_, cnt;
vector<vector<int>>graph;
vector<bool>used;
vector<int>from, in_time;

void DFS(int v, int p){
    used[v] = true;
    in_time[v] = from[v] = time_;
    time_++;
    for(int i = 0; i < graph[v].size(); i++){
        int x = graph[v][i];
        if(x == p) continue;
        if(used[x] == true){
            from[v] = min(in_time[x], from[v]);
        }else{
            DFS(x, v);
            from[v] = min(from[v], from[x]);
            if(from[x] > in_time[v]) cnt++;
        }
    }


}
int main(){
    cin >> n >> m;
    graph.resize(n + 1);
    used.resize(n + 1);
    from.resize(n + 1);
    in_time.resize(n + 1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(used[i] == 0){
            DFS(i, -1);
        }
    }
    
    cout << cnt << endl;
}