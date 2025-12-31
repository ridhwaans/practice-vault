class Solution {
public:
        int check(int max, vector<int>& arr){
                
            int cur_max = max;
            for(int i=0; i < arr.size(); i++){
                    if ((arr[i] - arr.front()) > cur_max){
                        cur_max = arr[i] - arr.front();
                    }
            }
            return cur_max;
        }

    int maxProfit(vector<int>& prices) {
        int cur_max = 0;
        for(int i =0; i < prices.size(); i++){
                vector<int> subset(prices.begin() + i, prices.end());
                int i_max = check(cur_max, subset);
                if (i_max > cur_max){
                        cur_max = i_max;
                }

    }
        return cur_max;
}
};
