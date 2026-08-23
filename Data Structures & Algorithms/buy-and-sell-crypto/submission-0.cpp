class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxProfit = 0;
        
        for(int i = 1; i < n ; i++){
            int curr_profit = prices[i] - buy;
            
            if(curr_profit > maxProfit){
                maxProfit = curr_profit;
            }
            if(prices[i] < buy){
              buy = prices[i];
            }
        }
        return maxProfit;
    }
};
