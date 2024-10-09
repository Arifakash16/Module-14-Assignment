class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        //Build the graph using an adjacency list
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        //Use BFS to check if there's a path from source to destination
        queue<int> q;
        q.push(source);
        unordered_set<int> visited;
        visited.insert(source);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // If we reach the destination, return true
            if (node == destination) {
                return true;
            }

            // Visit all the neighbors of the current node
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        // If terminates the queue and never find the destination, return false
        return false;
    }


    
};


// Time Comlexity: O(V+E) V is the number of nodes and E is the number of Edges
// Space Comlexity: O(V+E) V is the number of nodes and E is the number of Edges