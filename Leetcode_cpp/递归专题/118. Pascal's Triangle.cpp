class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>vec(numRows);
        if (!numRows) return vec;
        vec[0].push_back(1);
        if (numRows == 1) return vec;
        vec[1].push_back(1);vec[1].push_back(1);
        if (numRows == 2) return vec;
        for(int i=2;i!=numRows;i++)
        {
            vec[i].push_back(1);
            for(int j = 0;j!=i-1;j++)
            {
                vec[i].push_back(vec[i-1][j]+vec[i-1][j+1]);
            }
            vec[i].push_back(1);
        }
        return vec;
    }
};