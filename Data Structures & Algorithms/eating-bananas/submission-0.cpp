class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        auto eat = [&](int k) {
            int hours = 0;
            for(auto u : a) 
                hours += u / k + (u%k != 0);
            return hours;
        };
        int lo = 1, hi = 1000000000;
        while(lo != hi) {
            int mid = (lo + hi) / 2;
            if(eat(mid) <= h) 
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
