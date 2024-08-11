// Nadav034@gmail.com

#include "Graph.hpp"
using namespace std;

// Constructors

/**
 *  Constructs a Graph with the given adjacency matrix, direction, and weight status.
 *
 * @param newGraph 2D vector for the adjacency matrix.
 * @param directed True if the graph is directed.
 * @param weighted True if the graph has weighted edges.
 * @param vertex Number of vertices in the graph.
 */
Graph::Graph(std::vector<std::vector<int>> newGraph, bool directed, bool weighted, int vertex) {
    this->graph = newGraph;
    this->isDirected = directed;
    this->isWeighted = weighted;
    this->numVer = vertex;
}

/**
 * Default constructor for an empty graph.
 */
Graph::Graph() : numVer(0), isDirected(false), isWeighted(false) {}

/**
 * Loads a new adjacency matrix into the graph.
 *
 * @param newGraph 2D vector for the new adjacency matrix.
 * @throws std::invalid_argument if the matrix is not square.
 */
void Graph::loadGraph(const vector<vector<int>>& newGraph) {
    if (newGraph.empty()) {
        graph.clear();
        numVer = 0;
        isDirected = false;
        isWeighted = false;
        return;
    }
    std::size_t rows = newGraph.size();
    for (const auto& row : newGraph) {
        if (row.size() != rows) {
            throw std::invalid_argument("Invalid graph: The provided graph is not a square matrix.");
        }
    }
    graph = newGraph;
    numVer = static_cast<int>(rows);
    isDirected = isGraphDirected();
    isWeighted = isGraphWeighted();
}

/**
 * @brief Prints the graph's adjacency matrix.
 */
void Graph::printGraph() {
    for (int i = 0; i < numVer; ++i) {
        for (int j = 0; j < numVer; ++j) {
            cout << this->graph[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Checks if the graph is directed.
 *
 * @return True if the graph is directed.
 */
bool Graph::isGraphDirected() {
    for (int i = 0; i < this->getVertexNum(); ++i) {
        for (int j = 0; j < this->getVertexNum(); ++j) {
            if (this->getGraph()[i][j] != this->getGraph()[j][i]) {
                this->isDirected = true;
                return true;
            }
        }
    }
    this->isDirected = false;
    return false;
}

/**
 * Checks if the graph has negative weights.
 *
 * @return True if the graph has negative weights.
 */
bool Graph::isGraphNegWeighted() {
    for (int i = 0; i < this->getVertexNum(); ++i) {
        for (int j = 0; j < this->getVertexNum(); ++j) {
            if (this->getGraph()[i][j] < 0) {
                return true;
            }
        }
    }
    return false;
}

/**
 * Checks if the graph has weighted edges.
 *
 * @return True if the graph is weighted.
 */
bool Graph::isGraphWeighted() {
    for (int i = 0; i < this->getVertexNum(); ++i) {
        for (int j = 0; j < this->getVertexNum(); ++j) {
            if ((this->getGraph()[i][j] > 1) || (this->getGraph()[i][j] < 0)) {
                this->isWeighted = true;
                return true;
            }
        }
    }
    this->isWeighted = false;
    return false;
}

// Getters

/**
 * Gets the number of vertices.
 *
 * @return Number of vertices.
 */
int Graph::getVertexNum() const {
    return numVer;
}

/**
 * Checks if the graph is directed.
 *
 * @return True if the graph is directed.
 */
bool Graph::getIsDirected() const {
    return isDirected;
}

/**
 * Checks if the graph is weighted.
 *
 * @return True if the graph is weighted.
 */
bool Graph::getIsWeighted() const {
    return isWeighted;
}

/**
 * Checks if the graph is empty.
 *
 * @return True if the graph is empty.
 */
bool Graph::getIsEmpty() const {
    return numVer == 0;
}

/**
 * Gets the adjacency matrix.
 *
 * @return A reference to the adjacency matrix.
 */
const vector<vector<int>>& Graph::getGraph() const {
    return this->graph;
}
