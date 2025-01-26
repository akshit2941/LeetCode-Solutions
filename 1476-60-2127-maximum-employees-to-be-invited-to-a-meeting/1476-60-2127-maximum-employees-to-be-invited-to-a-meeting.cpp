class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        return max(findMaxCycle(favorite), topologicalSortAndPairSum(favorite));
    }
  
    int findMaxCycle(vector<int>& favorites) {
        int numStudents = favorites.size();
        vector<bool> visited(numStudents, false);
        int maxCycleLength = 0;
      
        for (int i = 0; i < numStudents; ++i) {
            if (visited[i]) continue;
            vector<int> cycle;
            int current = i;
          
            while (!visited[current]) {
                cycle.push_back(current);
                visited[current] = true;
                current = favorites[current];
            }
          
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == current) {
                    maxCycleLength = max(maxCycleLength, (int)cycle.size() - k);
                    break;
                }
            }
        }
        return maxCycleLength;
    }

    int topologicalSortAndPairSum(vector<int>& favorites) {
        int numStudents = favorites.size();
        vector<int> inDegree(numStudents, 0);
        vector<int> distance(numStudents, 1);
      
        for (int fav : favorites) ++inDegree[fav];
      
        queue<int> queue;
      
        for (int i = 0; i < numStudents; ++i) {
            if (inDegree[i] == 0) queue.push(i);
        }
      
        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            distance[favorites[current]] = max(distance[favorites[current]], distance[current] + 1);
          
            if (--inDegree[favorites[current]] == 0) {
                queue.push(favorites[current]);
            }
        }
      
        int pairSum = 0;
        for (int i = 0; i < numStudents; ++i) {
            if (i == favorites[favorites[i]]) {
                pairSum += distance[i];
            }
        }
        return pairSum;
    }
};