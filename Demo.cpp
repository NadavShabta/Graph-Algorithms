// Nadav034@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    Graph g;
    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #1 //////////" << endl;
    cout << "//////////////////////////////" << endl;
//     3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #2 //////////" << endl;
    cout << "//////////////////////////////" << endl;
    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2); // Load the graph to the object.
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).


    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #3 //////////" << endl;
    cout << "//////////////////////////////" << endl;
    // 5x5 matrix that represents a connected weighted graph.
    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 0},
            {1, 0, 3, 0, 0},
            {0, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.
    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."


    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #4 //////////" << endl;
    cout << "//////////////////////////////" << endl;
    // 5x4 matrix that represents invalid graph.
    vector<vector<int>> graph4 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
    try {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }


    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #5 //////////" << endl;
    cout << "//////////////////////////////" << endl;
     // Graph with a negative cycle
    vector<vector<int>> graphWithNegativeCycle = {
            {0,  1, 0,  0,  0},
            {0,  0, -1, 0,  1},
            {0,  0, 0,  -1, 0},
            {-1,  0, -1,  0, 0},
            {0, 0, 0,  0,  0}
    };
    g.loadGraph(graphWithNegativeCycle);
    g.printGraph();
    cout << "Checking graph with negative cycle:" << endl;
    Algorithms::negativeCycle(g);
    cout << endl;


    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #6 //////////" << endl;
    cout << "//////////////////////////////" << endl;
    // Graph without a negative cycle
    vector<vector<int>> graphWithoutNegativeCycle = {
            {0, 1, 4, 0},
            {1, 0, 2, 6},
            {4, 2, 0, 3},
            {0, 6, 3, 0}
    };
    g.loadGraph(graphWithoutNegativeCycle);
    g.printGraph();
    cout << "Checking graph without negative cycle:" << endl;
    Algorithms::negativeCycle(g);
    cout << endl;


    cout << "//////////////////////////////" << endl;
    cout << "////////// GRAPH #7 //////////" << endl;
    cout << "//////////////////////////////" << endl;
    vector<vector<int>> graph7 = {
            {0, 1, 0, 0,  0},
            {1, 0, 3, 0,  0},
            {0, 3, 0, 4,  0},
            {0, 0, 4, 0,  -5},
            {0, 0, 0, -5, 0}
    };
    g.loadGraph(graph7);
    cout << "Graph with false negative cycle:" << endl;
    g.printGraph();
    Algorithms::negativeCycle(g);
    cout << endl;
}
