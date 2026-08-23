class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        for(int i = 0; i < v.size(); i++) 
            for(int j = i + 1; j < v.size(); j++)
                if(v[i] + v[j] == t) 
                    return vector<int>{i, j};
    }
};
