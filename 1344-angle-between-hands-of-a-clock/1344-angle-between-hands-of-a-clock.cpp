class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour, min = minutes;
        double x = min/5.0;
        double y = x*30;

        double z = hr*30 + (x/12.0)*30;
        double ans = abs(z-y);
        double tp = 360-ans;
        if(tp<ans) ans = tp;
        return ans;
    }
};