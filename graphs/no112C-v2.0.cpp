// на първите 7 теста дава WA, а след това пак TL
// и не разбирам защо
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int>components;
void connect(int x, int y){
    int comp = components[x];
    for(int i = 0; i < graph[y].size(); i++){
        components[graph[y][i]] = comp;
    }
    components[y] = comp;
}
int main(){
    cin >> n >> m;
    graph.resize(n + 1);
    components.assign(n + 1, -1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(components[x] == -1) components[x] = x;
        if(components[y] == -1) components[y] = y;
        connect(x, y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        cout << (components[x] == components[y]) ? 1 : 0;
    }
}


// ТЕЛЕФОН 112
// http://www.math.bas.bg/infos/files/2013-04-01-C1.pdf
// решение - Стела