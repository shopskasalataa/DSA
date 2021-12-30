// за да разберем дали има път от един град до друг град, просто ще използваме алгоритъма за броене на компоненти и ще проверяваме
// дали началния и крайния град, за които искаме да знаем, са в една компонента
#include <iostream>
#include <vector>
#include <queue>
int n, m;

using namespace std;
void BFS(int v, const int cnt, const vector<vector<int>>& graph, vector<int>& component){
    queue<int> q;
    component[v] = cnt;
    q.push(v);

    while(!q.empty()){
        v = q.front();
        q.pop();

        for(int i = 0; i < graph[v].size(); i++){
            if(component[graph[v][i]] == -1){
                component[graph[v][i]] = cnt;
                q.push(graph[v][i]);
            }
        }
    }
}
void is_there_path(const vector<vector<int>>& graph){
    vector<int> component(graph.size(), -1);
    int cnt = 0;
    for(int i = 1; i < graph.size(); i++){
        if(component[i] == -1){
            cnt++;
            BFS(i, cnt, graph, component);
        }
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int s, e;
        cin >> s >> e;
        cout << (component[s] == component[e]) ? 1 : 0;
    }
}
int main(){
    vector<vector<int>> graph;

    cin >> n >> m;

    graph.resize(n + 1);
    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    is_there_path(graph);

    return 0;
}

// ТЕЛЕФОН 112
// http://www.math.bas.bg/infos/files/2013-04-01-C1.pdf