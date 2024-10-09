class Solution {
public:
    int countComponents(int A, vector<vector<int>>& B) {

        //Build the graph using an adjacency list
        vector<vector<int>> graph(A + 1); // Using 1-based indexing

        for (const auto& edge : B) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        //Keep track of visited nodes
        vector<bool> visited(A + 1, false);
        int componentCount = 0;

        //Perform DFS for each unvisited node
        for (int i = 1; i <= A; ++i) {
            if (!visited[i]) {
                // Found a new component
                componentCount++;
                dfs(graph, visited, i);
            }
        }

        return componentCount;
    }


    //Helper function to perform DFS
    void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true; //Mark the current node as visited

        // Visit all the neighbors
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }



};

// Time Comlexity: O(V+E) V is the number of nodes and E is the number of Edges
// Space Comlexity: O(V+E) V is the number of nodes and E is the number of Edges