class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> indicesMap;

        for (int i = 0; i < strs.size(); i++) {
            string curString = strs[i];
            string curStringSorted = strs[i];
            std::sort(curStringSorted.begin(), curStringSorted.end());
            indicesMap[curStringSorted].push_back(curString);
        }

        for (auto it : indicesMap) {
            res.push_back(it.second);
        }

        return res;
    }
};
