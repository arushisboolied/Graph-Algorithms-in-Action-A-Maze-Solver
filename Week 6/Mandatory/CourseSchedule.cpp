class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prereqs) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int u = 0; u < numCourses; u++)
            if (indeg[u] == 0)
                q.push(u);
        int done = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            done++;
            for (int v : adj[u])
                if (--indeg[v] == 0)
                    q.push(v);
        }
        return done == numCourses;
    }
};
