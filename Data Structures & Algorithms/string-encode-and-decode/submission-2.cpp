class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedVector;
        string header;

        for (int i = 0; i < strs.size(); i++) {
            header += std::to_string(strs[i].size());
            header += ',';
        }

        header += '.';

        encodedVector += header;

        std::for_each(strs.begin(), strs.end(), [&encodedVector](const string str) {
            for (char c : str) {
                encodedVector += c;
            }
        });

        return encodedVector;
    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        vector<int> characterCount{0};

        string tempCount;
        int headerOffset = 0;

        for (char c : s) {
            if (c == '.') {
                headerOffset++;
                break;
            }
            if (c == ',') {
                characterCount.push_back(std::stoi(tempCount));
                tempCount = "";
                headerOffset++;
                continue;
            }

            tempCount += c;
            headerOffset++;
        }

        for (int i = 0; i < characterCount.size()-1; i++) {
            string curString = s.substr(headerOffset += characterCount[i], characterCount[i+1]);
            decodedString.push_back(curString);
        }

        return decodedString;
    }
};
