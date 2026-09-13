class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> frequencyMap;

        for (int i = 0; i < nums.size(); i++) {
            frequencyMap[nums[i]]++;
        }

        vector<pair<int, int>> sortVector(frequencyMap.begin(), frequencyMap.end());

        std::sort(sortVector.begin(), sortVector.end(), [](auto& left, auto& right) {
            return left.second > right.second;
        });
        
        for (int i = 0; i < k; i++) {
            res.push_back(sortVector[i].first);
        }

        return res;
    }
};
