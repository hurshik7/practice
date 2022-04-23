class Solution {
public:
    void printArr(const vector<vector<int>>& arr) {
        for (vector<int> row : arr) {
            for (int i : row) {
                cout << setw(5) << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        printArr(matrix);
        double matrixSize = matrix.size() + 2;
        double rowMax = matrix.size() / 2;
        int lastIndex = matrix.size() - 1;
        cout << "rowMax : " << rowMax << endl;
        for (int i = 0; i < rowMax; i++) {
            matrixSize -= 2;
            for (int j = i; j < i + matrixSize - 1; j++) {
                int temp1 = matrix[j][lastIndex - i];
                matrix[j][lastIndex - i] = matrix[i][j];
                int temp2 = matrix[lastIndex - i][lastIndex - j];
                matrix[lastIndex - i][lastIndex - j] = temp1;
                temp1 = matrix[lastIndex - j][i];
                matrix[lastIndex - j][i] = temp2;
                matrix[i][j] = temp1;
            }
        }    
        printArr(matrix);
    }
};
