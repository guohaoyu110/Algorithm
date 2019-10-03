class WordDistance {
private:
    unordered_map<string,vector<int>>m;
public:
    //因为题目写了，会调用shortest函数非常多次，所以使用hashmap来存储words，key为word，value为index组成的list
    //使用双指针来遍历一次    
    WordDistance(vector<string>& words) {   
        int index=0;
        for(auto w:words) 
            m[w].push_back(index++);
    }
    
    int shortest(string word1, string word2) {
        int min = INT_MAX;
        vector<int> index1=m[word1],index2=m[word2];
        int minDist = INT_MAX;
        for(auto i:index1) 
            for (auto j:index2)
                minDist = std::min(minDist,abs(i-j));
        return minDist;
        
    }
};
/*
class WordDistance {
private:
    unordered_map<string, vector<int> > mp;
public:
    WordDistance(vector<string>& ws) {
        int index = 0;
        for(auto w : ws) mp[w].push_back(index++);
    }
    
    int shortest(string word1, string word2) {
        vector<int> index1 = mp[word1], index2 = mp[word2];
        int minDist = INT_MAX;
        for(auto i : index1) for(auto j : index2) minDist = min(minDist, abs(i - j));
        return minDist;
    }
};

*/