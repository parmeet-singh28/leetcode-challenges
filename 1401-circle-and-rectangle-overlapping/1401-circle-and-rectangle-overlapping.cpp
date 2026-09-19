class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        double x3 = x2, y3 = y2;
        x2 = x1;
        y2 = y3;
        double x4 = x3, y4 = y1;
        double a = xCenter, b = yCenter;

        bool ans = (x1>=a && a+radius>=x1 && b>=y1 && b<=y2) || (a>=x4 && a-radius<=x4 && b>=y1 && b<=y2) || (b<=y1 && b+radius>=y1 && a>=x1 && a<=x4) || (b>=y2 && b-radius<=y2 && a>=x2 && a<=x3) || (a>=x1 && a<=x4 && b>=y1 && b<=y2);

        double d1 = sqrt((a-x1)*(a-x1) + (b-y1)*(b-y1));
        double d2 = sqrt((a-x2)*(a-x2) + (b-y2)*(b-y2));
        double d3 = sqrt((a-x3)*(a-x3) + (b-y3)*(b-y3));
        double d4 = sqrt((a-x4)*(a-x4) + (b-y4)*(b-y4));

        ans |= (d1<=radius) || (d2<=radius) || (d3<=radius) || (d4<=radius);
        return ans;
    }
};