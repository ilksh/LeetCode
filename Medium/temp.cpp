#include<bits/stdc++.h>

using namespace std;
typedef unordered_map<int, int> mii;
typedef pair<int, int> pii;
typedef priority_queue<pii> pq;

class StockPrice {
private:
    mii timestamp_price; 
    pq max_heap; 
    priority_queue<pii, vector<pii>, greater<>> min_heap;
    int latest_timestamp; 
    int latest_price; 
public:
    StockPrice() : latest_timestamp(0), latest_price(0) {}
    
    void update(int timestamp, int price) {
        if (timestamp >= latest_timestamp) {
            latest_timestamp = timestamp;
            latest_price = price;
        }

        timestamp_price[timestamp] = price;
        max_heap.emplace(price, timestamp);
        min_heap.emplace(price, timestamp);
    }
    
    int current() { 
        return latest_price;
    }
    
    int maximum() {
        while(!max_heap.empty()) {
            auto rst = max_heap.top();
            auto price = rst.first;
            auto timestamp = rst.second;
            auto cur_price = timestamp_price[timestamp];
            if (cur_price == price) break;
            max_heap.pop();
        }
        return max_heap.top().first;
    }
    
    int minimum() {
        while (!min_heap.empty()) {
            auto rst = min_heap.top();
            auto price = rst.first;
            auto timestamp = rst.second;
            auto cur_price = timestamp_price[timestamp];
            if (cur_price == price) break;
            min_heap.pop();
        }
        return min_heap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */