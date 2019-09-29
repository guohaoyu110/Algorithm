/*class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //不用二重循环，只用一重循环
        vector<vetor<int>> m ;
        vector<int>p1;
        p1.push_back(1);
        m.push_back(p1);
        for (int i=1;i<numRows;i++)
        {
            vector<int>p;
            p.push_back()
        }
        
    }
};
*/
//还是用二重循环先写出来，然后再想其他方法。
class Solution {
public:

    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>vec(numRows); 
        if(!numRows) 
            return vec;

        vec[0].push_back(1);
        if(numRows==1)
            return vec;
        vec[1].push_back(1);
        vec[1].push_back(1);
        if(numRows==2)
            return vec;
        for(int i=2;i!=numRows;++i)
        {
            vec[i].push_back(1);
            for(int j=0;j!=i-1;++j)
            {
                vec[i].push_back(vec[i-1][j]+vec[i-1][j+1]);
            }
            vec[i].push_back(1);
        }
        return vec;
    }
};