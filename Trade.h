#ifndef TRADE_H
#define TRADE_H


#include "vector.h"
using pep::vector;


class Trade {
protected:
    int buyTime;
    int sellTime;

public:
    Trade(const int buyTimeIn, const int sellTimeIn)
        : buyTime(buyTimeIn), sellTime(sellTimeIn) {
    }

    int getBuyTime() const {
        return buyTime;
    }

    int getSellTime() const {
        return sellTime;
    }

};

// TODO your code goes here:

Trade bestBuySellTime(const vector<int>& prices);


Trade bestBuySellTime(const vector<int>& prices){

    int max = 0;
    int buy = 0;
    int sell = 0;
    int i = 0;
    int j = 0;

    for(i = 0; i < prices.size() - 1; i++){

        for(j = i + 1; j <= prices.size() - 1; j++){


            if((prices[j] - prices[i]) >= max){

                max = prices[j] - prices[i];

                buy = i;

                sell = j;


            }
        }
    }

    Trade bestTrade(buy, sell);

    return bestTrade;
}












// Don't write any code below this line

#endif
