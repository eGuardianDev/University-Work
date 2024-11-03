class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max =0 ;
        int min = prices[0];
        int profit= 0;
        for(int i =1 ;i <prices.size();i ++){
            //if(min > prices[i]) min = prices[i];
             if(prices[i-1] > prices[i]){
                profit += prices[i-1] - min;
                min = prices[i];
            }
            
            if(i== prices.size()-1){
                profit += prices[i] - min;
            }
        
        }
        
        
        return profit;
    }
};