#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool bfs(int startNode, int targetNode) {
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == targetNode) {
            return true; // Целевой узел достигнут, поиск успешен
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // Очередь пуста, целевой узел недостижим, поиск неудачен
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Пример графа в виде списка смежности
    int numNodes, numEdges;
    cout << "Введите количество вершин: ";
    cin >> numNodes;
    cout << "Введите количество ребер: ";
    cin >> numEdges;

    // Инициализация графа и массива посещенных вершин
    graph.resize(numNodes);
    visited.resize(numNodes, false);

    // Ввод ребер
    cout << "Введите ребра (вершина1 вершина2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        // Добавление ребер в список смежности
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode, targetNode;
    cout << "Введите начальную вершину: ";
    cin >> startNode;
    cout << "Введите целевую вершину: ";
    cin >> targetNode;

    // Выполнение обхода в ширину, начиная с начальной вершины, и проверка достижимости целевой вершины
    if (bfs(startNode, targetNode)) {
        cout << "Целевая вершина достижима." << endl;
    }
    else {
        cout << "Целевая вершина недостижима." << endl;
    }

    return 0;
}