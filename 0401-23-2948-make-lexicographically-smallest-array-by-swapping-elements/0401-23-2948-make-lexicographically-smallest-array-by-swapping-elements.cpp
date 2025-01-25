class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);  
            }
            return parent[x];
        }

        void unionSets(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (size[rootX] > size[rootY]) {
                    parent[rootY] = rootX;
                    size[rootX] += size[rootY];
                } else {
                    parent[rootX] = rootY;
                    size[rootY] += size[rootX];
                }
            }
        }
    };

    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }

        sort(sortedNums.begin(), sortedNums.end());

        UnionFind uf(n);

        for (int i = 0; i < n - 1; i++) {
            if (abs(sortedNums[i].first - sortedNums[i + 1].first) <= limit) {
                uf.unionSets(sortedNums[i].second, sortedNums[i + 1].second);
            }
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            groups[root].push_back(i);
        }

        for (auto& group : groups) {
            vector<int> indices = group.second;
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }

            sort(values.begin(), values.end());

            sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = values[i];
            }
        }

        return nums;
    }
};
