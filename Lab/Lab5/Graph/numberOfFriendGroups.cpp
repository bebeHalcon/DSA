void dfs(vector<vector<int>>& friends, int i, bool* visited)
{
    visited[i] = true;
    for (int v : friends[i])
        if (visited[v] == false)
            dfs(friends, v, visited);
}

int numberOfFriendGroups(vector<vector<int>>& friends) {
    // STUDENT ANSWER
    int len = friends.size();
    bool *visited = new bool[len];
    for (int i = 0; i < len; i++)
        visited[i] = false;
        
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        if (visited[i] == false)
        {
            dfs(friends, i, visited);
            res++;
        }
    }
    return res;
}