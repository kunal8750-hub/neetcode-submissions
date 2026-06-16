class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fre(26,0);
        priority_queue<int> pq;
        for(char &f : tasks){
            fre[f-'A']++;
        }
        int time = 0;

        for(int f : fre){
            if(f>0){
                pq.push(f);
            }
        }
        while(!pq.empty()){
            vector<int> temp;

            for(int i=1; i<=n+1; i++){
                if(!pq.empty()){
                    int curr = pq.top();
                    pq.pop();
                    curr--;
                    temp.push_back(curr);
                }
            }
            for(int f : temp){
                if(f>0){
                    pq.push(f);
                }
            }
            if(pq.empty()){
                time+=temp.size();
            }else{
                time += n+1;
            }
        }

        return time;

    }
};
