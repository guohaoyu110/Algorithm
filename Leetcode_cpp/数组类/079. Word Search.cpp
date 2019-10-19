class Solution {
public:
    
    //一定要把dfs的功能隔离开来，写一个单独的函数
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool> > mask(board.size(), vector<bool>(board[0].size(), true));
        //这个对mask的定义很重要
        //board是一个二维数组，Word吧他当做字符数组处理
        //这个是典型的深度优先题目
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if (board[i][j]==word[0]&&search(board,word,mask,0,i,j))
                    return true;
            }
        }
        return false;
    }
    bool search (vector<vector<char>>&board,string &word,vector<vector<bool>>mask,int idx,int x,int y)
    {
       if (word[idx]==board[x][y])
       {
           ++idx;
           if (idx==word.length())
               return true;
           //else return false    
       }
        else 
            return false;
        mask[x][y]= false;//一开始定义一个mask
        if (y+1<board[0].size()&&mask[x][y+1]&&board[x][y+1]==word[idx])
            if (search(board,word,mask,idx,x,y+1))
                return true;
        if (x + 1 < board.size() && mask[x+1][y] && board[x+1][y] == word[idx]) {
           if (search(board, word, mask, idx, x + 1, y))
                return true;
        }
        if (x - 1 >= 0 && mask[x-1][y] && board[x-1][y] == word[idx]) {
           if (search(board, word, mask, idx, x - 1, y))
                return true;
        }
        if (y - 1 >= 0 && mask[x][y-1] && board[x][y-1] == word[idx]) {
           if (search(board, word, mask, idx, x, y - 1))
                return true;
        }
        mask[x][y] = true;
        return false;
        
        
        
    }
    
};