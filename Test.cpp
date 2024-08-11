// Nadav034@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "Algorithms.hpp"
#include <vector>
#include <sstream>

using namespace std;


TEST_CASE("Test isConnected") {
    Graph g;

    SUBCASE("Empty graph") {
        vector<vector<int>> emptyGraph = {};
        g.loadGraph(emptyGraph);
        CHECK(Algorithms::isConnected(g) == 0);
    }

    SUBCASE("Single vertex graph") {
        vector<vector<int>> singleVertexGraph = {{0}};
        g.loadGraph(singleVertexGraph);
        CHECK(Algorithms::isConnected(g) == 1);
    }

    SUBCASE("Fully connected graph") {
        vector<vector<int>> fullyConnectedGraph = {
                {0, 1, 1, 1},
                {1, 0, 1, 1},
                {1, 1, 0, 1},
                {1, 1, 1, 0}
        };
        g.loadGraph(fullyConnectedGraph);
        CHECK(Algorithms::isConnected(g) == 1);
    }

    SUBCASE("Disconnected graph") {
        vector<vector<int>> disconnectedGraph = {
                {0, 1, 0, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 1},
                {0, 0, 1, 0}
        };
        g.loadGraph(disconnectedGraph);
        CHECK(Algorithms::isConnected(g) == 0);
    }

    SUBCASE("Graph with multiple components") {
        vector<vector<int>> multipleComponentsGraph = {
                {0, 1, 0, 0, 0},
                {1, 0, 0, 0, 0},
                {0, 0, 0, 1, 1},
                {0, 0, 1, 0, 1},
                {0, 0, 1, 1, 0}
        };
        g.loadGraph(multipleComponentsGraph);
        CHECK(Algorithms::isConnected(g) == 0);
    }
}


TEST_CASE("Test shortestPath") {
    Graph g;

    SUBCASE("Unweighted graph") {
        vector<vector<int>> unweightedGraph = {
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 0}
        };
        g.loadGraph(unweightedGraph);
        CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    }

    SUBCASE("Weighted graph") {
        vector<vector<int>> weightedGraph = {
                {0, 1, 0, 4},
                {1, 0, 2, 0},
                {0, 2, 0, 3},
                {4, 0, 3, 0}
        };
        g.loadGraph(weightedGraph);
        CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
    }

    SUBCASE("Directed graph with no path") {
        vector<vector<int>> directedGraphNoPath = {
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
        };
        g.loadGraph(directedGraphNoPath);
        CHECK(Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
    }

    SUBCASE("Single node graph") {
        vector<vector<int>> singleNodeGraph = {
                {0}
        };
        g.loadGraph(singleNodeGraph);
        CHECK(Algorithms::shortestPath(g, 0, 0) == "0");
    }

    SUBCASE("Graph with multiple shortest paths") {
        vector<vector<int>> multiplePathsGraph = {
                {0, 1, 1, 0},
                {1, 0, 0, 1},
                {1, 0, 0, 1},
                {0, 1, 1, 0}
        };
        g.loadGraph(multiplePathsGraph);
        string result = Algorithms::shortestPath(g, 0, 3);
        bool ans = (result == "0->1->3" || "0->2->3");
        CHECK(ans);
    }

    SUBCASE("Large graph") {
        vector<vector<int>> largeGraph = {
                {0, 1, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0, 0, 1, 0},
                {0, 1, 0, 1, 0, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 1, 0, 0, 0},
                {0, 0, 0, 1, 0, 1, 0, 0, 0},
                {0, 0, 0, 1, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 0, 1, 0, 1, 0},
                {0, 1, 0, 0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 1, 0}
        };
        g.loadGraph(largeGraph);
        CHECK(Algorithms::shortestPath(g, 0, 8) == "0->8");
    }
}



    TEST_CASE("Test isContainsCycle") {
    Graph g;

    SUBCASE("Empty graph") {
        vector<vector<int>> emptyGraph = {};
        g.loadGraph(emptyGraph);
        CHECK(Algorithms::isContainsCycle(g) == "0");
    }
        SUBCASE("Single vertex graph"){
        vector<vector<int>> singleVertexGraph = {{0}};
        g.loadGraph(singleVertexGraph);
        CHECK(Algorithms::isContainsCycle(g) == "0");
    }


    SUBCASE("Graph without a cycle") {
        vector<vector<int>> graphWithoutCycle = {
                {0, 1, 0, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 1},
                {0, 0, 1, 0}
        };
        g.loadGraph(graphWithoutCycle);
        CHECK(Algorithms::isContainsCycle(g) == "0");
    }

    SUBCASE("Directed graph with a cycle") {
        vector<vector<int>> directedGraphWithCycle = {
                {0, 1, 0, 1},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
                {1, 0, 0, 0}
        };
        g.loadGraph(directedGraphWithCycle);
        CHECK(Algorithms::isContainsCycle(g) == "");
    }

    SUBCASE("Directed graph without a cycle") {
        vector<vector<int>> directedGraphWithoutCycle = {
                {0, 1, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
        };
        g.loadGraph(directedGraphWithoutCycle);
        CHECK(Algorithms::isContainsCycle(g) == "0");
    }

    SUBCASE("Complex graph with multiple cycles") {
        vector<vector<int>> complexGraphWithCycles = {
                {0, 1, 0, 0, 1},
                {1, 0, 1, 0, 0},
                {0, 1, 0, 1, 0},
                {0, 0, 1, 0, 1},
                {1, 0, 0, 1, 0}
        };
        g.loadGraph(complexGraphWithCycles);
        // Capture the output
        stringstream buffer;
        streambuf *old = cout.rdbuf(buffer.rdbuf());
        // Run the function
        string result = Algorithms::isContainsCycle(g);
        // Restore the original buffer
        cout.rdbuf(old);
        // Check the result
        CHECK(result == "");
        // Check the output
        string expectedOutput = "The cycle is: 0 1 2 3 4 0 \n";
        CHECK(buffer.str() == expectedOutput);
    }
}

TEST_CASE("Test isBipartite function") {
    Graph g;

    SUBCASE("Bipartite graph") {
        vector<vector<int>> newGraph = {
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 0}
        };
        g.loadGraph(newGraph);
        CHECK(Algorithms::isBipartite(g) == "The graph is bipartite.\nPartition 1: { 0 2 }\nPartition 2: { 1 3 }");
    }

    SUBCASE("Not bipartite graph") {
        vector<vector<int>> newGraph = {
                {0, 1, 1, 0},
                {1, 0, 1, 1},
                {1, 1, 0, 1},
                {0, 1, 1, 0}
        };
        g.loadGraph(newGraph);
        CHECK(Algorithms::isBipartite(g) == "0");
    }

    SUBCASE("Single vertex graph") {
        vector<vector<int>> newGraph = {
                {0}
        };
        g.loadGraph(newGraph);
        CHECK(Algorithms::isBipartite(g) == "The graph is bipartite.\nPartition 1: { 0 }\nPartition 2: { }");
    }

    SUBCASE("Empty graph") {
        vector<vector<int>> newGraph;
        g.loadGraph(newGraph);
        CHECK(Algorithms::isBipartite(g) == "The graph is bipartite.\nPartition 1: { }\nPartition 2: { }");
    }

    SUBCASE("Disconnected bipartite graph") {
        vector<vector<int>> newGraph = {
                {0, 1, 0, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 1},
                {0, 0, 1, 0}
        };
        g.loadGraph(newGraph);
        CHECK(Algorithms::isBipartite(g) == "The graph is bipartite.\nPartition 1: { 0 2 }\nPartition 2: { 1 3 }");
    }
}

TEST_CASE("Test negativeCycle function") {
    Graph g;

    SUBCASE("Graph with negative cycle") {
        vector<vector<int>> newGraph = {
                {0, -1, 7, 8},
                {10, 0, -1, 6},
                {9, 9, 0, -1},
                {-1, 7, 8, 0}
        };
        g.loadGraph(newGraph);
        std::ostringstream output;
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
        Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldCoutStreamBuf);
        CHECK(output.str().find("Negative cycle found:") != std::string::npos);
    }

    SUBCASE("Graph without negative cycle") {
        vector<vector<int>> newGraph = {
                {0, 1, 1000, 1000},
                {1000, 0, 1, 1000},
                {1000, 1000, 0, 1},
                {1, 1000, 1000, 0}
        };
        g.loadGraph(newGraph);
        std::ostringstream output;
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
        Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldCoutStreamBuf);
        CHECK(output.str().find("No negative cycle found.") != std::string::npos);
    }

    SUBCASE("Graph with false positive negative cycle detection") {
        vector<vector<int>> newGraph = {
                {0, -1, 1000},
                {-1, 0, 1000},
                {1000, 1000, 0}
        };
        g.loadGraph(newGraph);
        std::ostringstream output;
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
        Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldCoutStreamBuf);
        CHECK(output.str().find("False positive detected, not a real negative cycle in a undirected graph.") != std::string::npos);
    }

    SUBCASE("Undirected graph with negative cycle") {
        vector<vector<int>> newGraph = {
                {0, 1, 0,  8},
                {1, 0, 8,  8},
                {8, 3, 0,  -1},
                {0, 8, -1, 0}
        };
        g.loadGraph(newGraph);
        std::ostringstream output;
        std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());
        Algorithms::negativeCycle(g);
        std::cout.rdbuf(oldCoutStreamBuf);
        CHECK(output.str().find("Negative cycle found: 3 2 3") != std::string::npos);
    }
}
