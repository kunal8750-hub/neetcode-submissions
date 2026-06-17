class Solution {
public: 
    int sum(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum = sum+digit*digit;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> seen;
        while(n!=1){
            if(seen.count(n)){
                return false;
            }
            seen.insert(n);
            n = sum(n);
        }
        return true;
    }
};
