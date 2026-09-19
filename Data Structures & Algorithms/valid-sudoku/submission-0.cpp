class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check if each row is valid
        for (int i = 0; i < board.size(); i++) {
            unordered_map<char, int> rowMap;
            vector<char> curRow = board[i];

            for (int j = 0; j < curRow.size(); j++) {
                rowMap[curRow[j]] += 1;
            }

            for (auto it = rowMap.begin(); it != rowMap.end(); it++) {
                if (it->second >= 2 && it->first != '.') return false;
            }
        }

        // check if each column is valid
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> colMap;

            for (int j = 0; j < 9; j++) {
                colMap[board[j][i]] += 1;
            }

            for (auto it = colMap.begin(); it != colMap.end(); it++) {
                if (it->second >= 2 && it->first != '.') return false;
            }
        }

        // check if each 3x3 Box is valid
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> boxMap;

            for (int j = 0; j < 9; j++) {
                int rowI = ((i / 3) * 3) + j / 3;
                int colI = j % 3 + (i % 3) * 3;

                boxMap[board[rowI][colI]] += 1;
            }

            for (auto it = boxMap.begin(); it != boxMap.end(); it++) {
                if (it->second >= 2 && it->first != '.') return false;
            }
        }

        return true;
    }
};
