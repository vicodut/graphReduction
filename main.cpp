#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
private:
    void DFSUtils(int i, vector< int > &visited) {
        visited.push_back(i);
        for(int j : this->graph[i]) {
            if (find(visited.begin(), visited.end(), this->graph[i][j]) == visited.end()) {
                DFSUtils(this->graph[i][j], visited);
            }
        }
    }

public:

    vector< vector<int> > graph;
    Graph() = default;

    void addNode(int i, int j) {
        cout << Graph::graph.capacity() << endl;
        if (Graph::graph.capacity() < (i > j ? i : j) ) {
            for (int a = Graph::graph.capacity(); a < (i > j ? i : j); a++)
                Graph::graph.emplace_back();
        }
        Graph::graph[i].push_back(j);
        Graph::graph[j].push_back(i);
    }

    const vector<vector<int>> &getGraph() const {
        return graph;
    }

    void setGraph(const vector<vector<int>> &graph) {
        this->graph = graph;
    }

    void displayGraph() {
        for (int i = 0; i < this->graph.capacity(); i++) {
            cout << "Node " << i << endl;
            for (int j = 0; j < this->graph[i].capacity(); ++j) {
                cout << "\tLink with : " << this->graph[i][j] << endl;
            }
        }
    }

    void DFS(int startNode) {
        cout << "Node accessible by : " << startNode << endl;
        vector< int > visited;
        this->DFSUtils(startNode, visited);

        for (int j : visited) {
            cout << j << "";
        }

        cout << endl;
    }
};

int main() {
    cout << "Hello, World !" << endl;
    vector< vector<int> > tab = {
            {1, 2},
            {0, 2, 3},
            {0, 1, 3},
            {1, 2}
    };

    Graph graph;
    graph.setGraph(tab);

    graph.displayGraph();
    graph.DFS(0);

    return 0;
}