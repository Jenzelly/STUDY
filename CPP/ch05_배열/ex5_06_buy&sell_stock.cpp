/*
문제 5.6
주식 한 번 사고팔기
*/

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double BuyAndSellStockOnce ( const vector<double>& prices)
{
    double min_price_so_far = numeric_limits<double>::infinity(), max_profit = 0;
    for (double price : prices)
    {
        double max_profit_sell_today = price - min_price_so_far;
        max_profit = max(max_profit, max_profit_sell_today);
        min_price_so_far = min(min_price_so_far, price);
    }
    return max_profit;
}