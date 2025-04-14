class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int total_element = m * n;
        
        int startingRow = 0;
        int endingRow = m - 1;
        int startingCol = 0;
        int endingCol = n - 1;
        int count = 0;

        while (count < total_element) {
            // Traverse top row
            for (int i = startingCol; i <= endingCol && count < total_element; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // Traverse right column
            for (int i = startingRow; i <= endingRow && count < total_element; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // Traverse bottom row (right to left)
            for (int i = endingCol; i >= startingCol && count < total_element; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // Traverse left column (bottom to top)
            for (int i = endingRow; i >= startingRow && count < total_element; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};
