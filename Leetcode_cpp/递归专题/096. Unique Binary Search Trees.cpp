class Solution {
public:
    int numTrees(int n) {
        //这种题目还是有规律可循的，多写几个找规律会比较好一些，直接看看不出来题目的意思！
        int f[n+1];
        memset(f,0,sizeof(int)*(n+1));
        f[0] = 1;
        for(int i = 1;i<=n;i++){
            for(int j=0;j<i;j++){
                f[i] += f[j]*f[i-1-j];
            }

        }
        return f[n];
    }
};