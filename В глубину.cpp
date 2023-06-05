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
            return true; // ������� ���� ���������, ����� �������
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // ������� �����, ������� ���� ����������, ����� ��������
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ������ ����� � ���� ������ ���������
    int numNodes, numEdges;
    cout << "������� ���������� ������: ";
    cin >> numNodes;
    cout << "������� ���������� �����: ";
    cin >> numEdges;

    // ������������� ����� � ������� ���������� ������
    graph.resize(numNodes);
    visited.resize(numNodes, false);

    // ���� �����
    cout << "������� ����� (�������1 �������2):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        // ���������� ����� � ������ ���������
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    int startNode, targetNode;
    cout << "������� ��������� �������: ";
    cin >> startNode;
    cout << "������� ������� �������: ";
    cin >> targetNode;

    // ���������� ������ � ������, ������� � ��������� �������, � �������� ������������ ������� �������
    if (bfs(startNode, targetNode)) {
        cout << "������� ������� ���������." << endl;
    }
    else {
        cout << "������� ������� �����������." << endl;
    }

    return 0;
}