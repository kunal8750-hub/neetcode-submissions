class Solution {
public:
    set<vector<int>> st;
    void solve(int i,  vector<int> &nums, vector<int> temp){
        if(i>=nums.size()){
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1, nums,temp);

        temp.pop_back();
        solve(i+1, nums, temp);
           
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp);

        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
};
