#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>  // Include the file stream header

// Include the Dijkstra class header
#include <Dijkstra.h>
// Replace with the actual path to your Dijkstra header

// Define the type for representing the graph
// Replace this with your actual graph representation
struct Graph {
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;
    std::vector<int> edgeWeights;  // Additional attribute to store edge weights

    // Constructor to initialize the graph
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices), edgeWeights(vertices) {}
};

// Function to load the graph from the DIMACS file
Graph loadGraph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the DIMACS file." << std::endl;
        exit(1);
    }

    int numVertices, numEdges;
    file >> numVertices >> numEdges;
    Graph graph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v, w;
        file >> u >> v >> w;
        // Adjust node labels from 1-based to 0-based
        u--;  // Convert u to 0-based index
        v--;  // Convert v to 0-based index
        graph.adjacencyList[u].emplace_back(v);  // Assuming a directed graph
        graph.edgeWeights.emplace_back(w);  // Store edge weight
    }

    return graph;
}

int main() {
    // Load the Florida graph from the DIMACS file
    Graph floridaGraph = loadGraph("USA-road-d.FLA.gr.co");

    // Initialize the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create an instance of the Dijkstra class with your graph
    Dijkstra<Graph, dijkstra(floridaGraph, floridaGraph.edgeWeights);

    // Initialize variables for tracking total runtime
    double totalRuntime = 0.0;

    // Loop to run Dijkstra's algorithm for 200 random source-destination pairs
    for (int i = 0; i < 200; ++i) {
        // Generate random source and destination nodes
        int source = std::rand() % floridaGraph.numVertices;
        int destination = std::rand() % floridaGraph.numVertices;

        // Run Dijkstra's algorithm from source to destination
        dijkstra.run(source, destination);

        // Measure the runtime for this run (modify Dijkstra class to include runtime measurement)
        double runtimeInSeconds = /* Get the runtime from the Dijkstra class */

        // Add the runtime to the total
        totalRuntime += runtimeInSeconds;

        // Print the shortest path and path length if needed
        std::vector<int> shortestPath = dijkstra.getPath(destination);
        int shortestPathLength = dijkstra.getDistance(destination);

        std::cout << "Source: " << source << ", Target: " << destination << std::endl;
        std::cout << "Shortest Path: ";
        for (int node : shortestPath) {
            std::cout << node + 1 << " ";  // Convert back to 1-based index for printing
        }
        std::cout << std::endl;
        std::cout << "Shortest path length: " << shortestPathLength << std::endl;
    }

    // Print the total runtime for 200 random Dijkstra runs
    std::cout << "Total runtime in seconds for 200 random Dijkstra: " << totalRuntime << std::endl;

    return 0;
}
