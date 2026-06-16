class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }
        int count = 0;
        while(pq.size()){
            int t = pq.top();
            pq.pop();
            count++;

            if(count == k){
                return t;
            }
        }
        return 0;
    }
};
