int maxProfit(int* prices, int pricesSize) {
    int min_price = prices[0];
    int max_profit = 0; 
    
    for(int i=1; i<pricesSize; i++)
    {
        if(prices[i] > min_price)
        {
            max_profit = (prices[i] - min_price > max_profit) ? prices[i] - min_price : max_profit;
        }
        else
        {
            min_price = prices[i];
        }
    }
    return max_profit;
}