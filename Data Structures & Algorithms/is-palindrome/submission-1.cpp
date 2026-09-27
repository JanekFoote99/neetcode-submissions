class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }

        int startP = 0;
        int endP = s.size()-1;

        while (startP < endP) {
            if (!isalnum(s[startP])) {
                startP++;
                continue;
            }
            if (!isalnum(s[endP])) {
                endP--;
                continue;
            }

            char tempB = tolower(s[startP]);
            char tempT = tolower(s[endP]);

            if (tempB != tempT)
                return false;

            startP++, endP--;
        }

        return true;
    }
};
