// Nadav034@gmail.com

#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Graph {
private:
    int numVer;
    bool isDirected;
    bool isWeighted;
    vector<vector<int>> graph;

public:
    //Constructor
    Graph(vector<vector<int>> newGraph, bool directed, bool weighted, int vertex);
    //default constructor
    Graph();
    void loadGraph(const vector<vector<int>>& newGraph);
    void printGraph();
    //for default constructed graphs
    bool isGraphDirected();
    bool isGraphWeighted();
    bool isGraphNegWeighted();
    //Getters
    int getVertexNum() const;
    bool getIsDirected() const;
    bool getIsWeighted() const;
    bool getIsEmpty() const;
    const std::vector<std::vector<int>>& getGraph() const;
};




