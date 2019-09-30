class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int offset = 0;
        int size = chars.size();
        //滑动窗口法需要两个循环中间夹一下！典型的双指针题目！
        for(int i=0;i<size;++i)
        {
            int count=1;
            for (int j=i+1;j<size;++j)
            {
                if (chars[j]==chars[i])
                {
                    ++count;
                    ++i;
                }
                else break;
            }
            if(count==1)
                chars[offset++]=chars[i];
            else //比如count为3的情况
            {
                chars[offset++]=chars[i];
                string co = to_string(count);
                for(char num:co)
                    chars[offset++] = num;
            }
        }
        return offset;
       }
};

