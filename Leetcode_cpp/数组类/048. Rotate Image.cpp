class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //顺时针旋转90度
        //这个没有用原地旋转图像，不过先写出来再说
        int size = matrix.size();
        vector<vector<int>> matrix1;
        vector<int>res;
        for(int i=0;i<size;i++)
        {
            
            for(int j=0;j<size;j++)
            {
                res.push_back(matrix[size-j-1][i]);
            }
            matrix1.push_back(res);
            res.clear();
        }
        matrix = matrix1;
        
    }
};