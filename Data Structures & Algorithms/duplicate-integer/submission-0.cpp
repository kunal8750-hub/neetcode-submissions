class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int val : nums){
            freq[val]++;
        }

        for(auto &p : freq){
            if(p.second > 1){
                return true;
            }
        }
        return false;
    }
};


