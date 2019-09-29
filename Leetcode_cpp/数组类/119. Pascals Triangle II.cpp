class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rows(rowIndex + 1,1);       
        for(int i = 0 ; i <= rowIndex; ++i){
            for(int j = i - 1 ; j > 0 ; --j){
                rows[j] += rows[j-1];
            }
        }
        return rows; 
    }
};
