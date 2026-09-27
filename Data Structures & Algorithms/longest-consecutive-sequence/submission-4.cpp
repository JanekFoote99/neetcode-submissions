class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int res = 0;

        for (auto it = numSet.begin(); it != numSet.end(); it++) {
            if (numSet.find(*it-1) != numSet.end()) {
                continue;
            }

            int counter = 1;

            while (numSet.find(*it+counter) != numSet.end()) {
                counter++;
            }

            res = max(counter, res);
        }

        return res;
    }
};
