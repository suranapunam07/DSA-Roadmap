class StockSpanner {
public:
    stack<pair<int,int>>st;

    StockSpanner() {
    }

    int next(int price) 
    {
        int span = 1;

        while(!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
     
        return span;
    }
};

/*
class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {
    }

    int next(int price) {

        prices.push_back(price);

        int span = 1;

        for (int i = prices.size() - 2; i >= 0; i--) {

            if (prices[i] <= price) {
                span++;
            }
            else {
                break;
            }
        }

        return span;
    }
};
*/