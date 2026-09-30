class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size()-1;

        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[p1] + numbers[p2] == target) {
                return vector<int>{p1+1, p2+1};
            }
            if (numbers[p1] + numbers[p2] > target) {
                p2--;
                continue;
            }
            if (numbers[p1] + numbers[p2] < target) {
                p1++;
                continue;
            }
        }

        return {};
    }
};
