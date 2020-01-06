class Solution {
//private:
    
public:
    bool isHappy(int n) {
        //这个过程肯定是要递归
        if (n<1) return false;
        if (n==1) return true;
        unordered_set<int>showedNums;
        showedNums.insert(n);
        while(true)
        {
            int s=0;
            while(n)
            {
                s+=(n%10)*(n%10);
                n=n/10;
            }
            if (s==1) return true;
            else if (showedNums.find(s)!=showedNums.end())
                return false;
            n=s;
            showedNums.insert(s);
            
        }
    }
};