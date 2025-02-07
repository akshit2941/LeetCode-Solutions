class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColorMap;
        unordered_map<int, int> colorCount;
        vector<int> result;
        int distinctColors = 0;

        for(auto& query:queries){
            int ball = query[0], newColor=query[1];

            if(ballColorMap.count(ball)){
                int oldColor = ballColorMap[ball];
                colorCount[oldColor]--;

                if(colorCount[oldColor] == 0){
                    distinctColors--;
                }
            }

            ballColorMap[ball] = newColor;
            colorCount[newColor]++;

            if(colorCount[newColor] == 1){
                distinctColors++;
            }

            result.push_back(distinctColors);
        }
        return result;
    }
};