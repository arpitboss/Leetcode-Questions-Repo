class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        int n=piles.size();
        priority_queue<int> pq;

        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        
        while(k!=0){
           int top=pq.top();
            pq.pop();

            top-=floor(top / 2);

            pq.push(top);

            k--;
            
        }
        
        while (!pq.empty()) {
            sum+=pq.top();
            pq.pop();
        }
        
        return sum;
    }
};