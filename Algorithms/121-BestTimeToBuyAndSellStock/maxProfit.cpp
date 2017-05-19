int maxProfit(vector<int>& prices) {
    int minPrice = 10000;
    int maxPro = 0;
    for (int i=0; i<prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i]-minPrice);
    }
    else return maxPro;
}