/*
문제 5.7
주식 두번 사고 팔기
*/

#include <vector>
#include <algorithm>
#include <limits>
#include <iterator>s

using namespace std;

double BuyAndSellStockTwice(const vector<double>& prices)
{
    double max_total_profit = 0;
    vector<double> first_buy_sell_profits(size(prices), 0);
    double min_price_so_far = numeric_limits<double>::infinity();

    //앞으로 읽는 부분
    //각 날짜마다, 해당 날짜에 주식을 팔았을 떄의 최대 이익 값을 구해 놓는다.
    for (int i = 0; i < size(prices); ++i)
    {
        min_price_so_far = min(min_price_so_far, prices[i]);
        max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
        first_buy_sell_profits[i] = max_total_profit;
    }

    //뒤로 읽는 부분
    //각 날짜마다, 두 번째 주식을 해당 날짜에 샀을 때의 최대 이익 값을 구해 놓는다.
    double max_price_so_far = numeric_limits<double>::min();
    for( int i = size(prices) -1; i>= 0; 
    {
        max_price_so_far = max(max_price_so_far, prices[i]);
        max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profits[i]);
    }
    return max_total_profit;
}