class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double posMin = minutes*(6.0);
        double posHour = hour*(30.0);
        posHour = posHour + (minutes/60.0) * (30.0);
        
        double ans = abs(posHour - posMin);
        
        return (ans>180)? (360-ans) : ans;
    }
};
