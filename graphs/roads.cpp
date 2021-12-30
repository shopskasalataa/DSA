// целта на задачата е да направим граф само от новите пътища и да проверим колко компоненти имаме тогава, тъй 
// като нямаме път между дадени две компоненти единственото решение е да оставим едно от старите пътища, защото
// знаем, че при старите пътища има път от всеки до всеки град
#include <iostream>
#include <vector>
#include <queue>
int n, m;

using namespace std;
void BFS(int v, const int cnt, const vector<vector<int>>& graph, vector<int>& component) {
    queue<int>q;
    // началният ни връх принадлежи към моментната компонента
    component[v] = cnt;
    // тук не използваме матрица за обходените върхове, а използваме вектора за компонентите, 
    // ако връх не принадлежи все още към никоя компонента, той е и необходен
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int i = 1; i < graph[v].size(); i++) {
            // ако връх не принадлежи към никоя компонента и това е връх, до който има път, го добавяме към
            // моментната компонента и го слагаме в опашката за обхождане
            if (component[graph[v][i]] == -1 && graph[v][i] != 0) {
                component[graph[v][i]] = cnt;
                q.push(graph[v][i]);
            }
        }
    }
}
int save_roads(const vector<vector<int>>& graph) {
    // в момента ако няма път от един град до друг град, те са в отделни компоненти и трябва да преброим колко
    // Компоненти имаме, за да знаем колко пътища да запазим
    vector<int> component(graph.size(), -1);
    int cnt = 0;
    // в началото компонентите ни са 0 и във вектора component сме обозначили, че никой връх не принадлежи към
    // някаква компонента
    for (int i = 1; i < graph.size(); i++) {
        if (component[i] == -1) {
            // ако връх не принадлежи към някаква компонента, значи увеличаваме броя на компонентите (имаме нова) и 
            // пускаме BFS, за да проверим кои други върхове принадлежат към тази компонента
            cnt++;
            BFS(i, cnt, graph, component);
        }
    }
    return cnt - 1;
}
int main() {
    vector<vector<int>>graph;

    cin >> n >> m;
    graph.resize(n + 1);
    // правим си един пълен граф без примки (има ребро от всеки до всеки град) и махаме старите пътища, за да останат
    // само новите
    for (int i = 1; i <= n; i++) {
        graph[i].resize(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                graph[i][j] = j;
                graph[j][i] = i;
            }
            else {
                graph[i][i] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        graph[v][u] = 0;
        graph[u][v] = 0;
    }

    cout << save_roads(graph) << endl;
    return 0;
}

// ШОСЕТА
// http://www.math.bas.bg/infos/files/2009-01-25-A2.pdf