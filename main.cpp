#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
private:
    int x;

    void DFSUtils(int i, vector< int > &visited, int count, int& maxCount ) {
        visited.push_back(i);
        count++;
        for(int j : this->graph[i]) {
            if (find(visited.begin(), visited.end(), j) == visited.end()) {
                if (count >= maxCount) {
                    maxCount = count;
                    this->x = j;
                }
                DFSUtils(j, visited, count, maxCount);
            }
        }
    }

public:
    vector< vector<int> > graph;
    Graph() = default;

    void addNode(int i, int j) {
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

    void dfs(int startNode, int& maxCount) {
        vector< int > visited;
        int count = 0;

        this->DFSUtils(startNode, visited, count, maxCount);
    }

    int getDiameter() {
        int maxCount = INT32_MIN;

        this->dfs(0, maxCount);
        this->dfs(this->x, maxCount);



        return maxCount;
    }
};

int main() {
    vector< vector<int> > tab(5);

    Graph graph;
    graph.setGraph(tab);
    graph.addNode(0, 1);
    graph.addNode(0, 2);
    graph.addNode(1, 3);
    graph.addNode(1, 4);

    graph.displayGraph();
    cout << endl << "Diameter : " << graph.getDiameter() << endl;

    return 0;
}