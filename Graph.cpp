//
// Created by nadav on 6/20/2024.
//

#include "Graph.hpp"
using namespace std;

//Constructors

Graph::Graph(std::vector<std::vector<int>> newGraph, bool directed, bool weighted, int vertex) {
    this->graph=newGraph;
    this->isDirected=directed;
    this->isWeighted = weighted;
    this->numVer = vertex;
}
Graph::Graph() : numVer(0), isDirected(false), isWeighted(false) {}

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
void Graph::printGraph() {
    for (int i = 0; i < numVer; ++i) {
        for (int j = 0; j < numVer; ++j) {
            cout<< this->graph[i][j] << " ";
        }
        cout<<endl;
    }
}

 bool Graph:: isGraphDirected() {
     for (int i = 0; i < this->getVertexNum(); ++i) {
         for (int j = 0; j < this->getVertexNum(); ++j) {
             if (this->getGraph()[i][j]!= this->getGraph()[j][i]){
                 this->isDirected= true;
                 return true;
             }
         }
     }
     this->isDirected = false;
     return false;
}

bool Graph :: isGraphWeighted() {
    for (int i = 0; i < this->getVertexNum(); ++i) {
        for (int j = 0; j < this->getVertexNum(); ++j) {
            if ((this->getGraph()[i][j]>1) || (this->getGraph()[i][j]<0 )){
                this->isWeighted = true;
                return true;
            }
        }
    }
    this->isWeighted= false;
    return false;
}
//Getters

int Graph:: getVertexNum() const{
    return numVer;
}
bool Graph :: getIsDirected() const{
    return isDirected;
}
bool Graph :: getIsWeighted() const{
    return isWeighted;
}
bool Graph :: getIsEmpty() const{
    return numVer == 0;
}
const vector<vector<int>>& Graph :: getGraph() const {
    return this->graph;
}
int Graph::getNumberOfEdges() const {
    int numEdges = 0;
    for (int i = 0; i < numVer; ++i) {
        for (int j = 0; j < numVer; ++j) {
            if (graph[i][j] != 0) {
                numEdges++;
            }
        }
    }
    // For undirected graphs, each edge is counted twice
    if (!isDirected) {
        numEdges /= 2;
    }
    return numEdges;
}



