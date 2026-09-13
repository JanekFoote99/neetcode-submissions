class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, int> sMap(s.size());
        unordered_map<char, int> tMap(t.size());

        for(char c : s){
            sMap[c] += 1;
        }

        for(char c : t){
            tMap[c] += 1;
        }

        for(auto it = sMap.begin(); it != sMap.end(); it++){
            if (it->second != tMap[it->first]) {
                return false;
            }
        }

        return true;
    }
};
