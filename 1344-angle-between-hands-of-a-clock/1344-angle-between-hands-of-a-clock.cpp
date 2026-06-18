class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour%12;
        double hour_angle = 30*hour + (minutes/2.0);
        double minute_angle = 6*minutes;
        double theta = abs(hour_angle - minute_angle);
        return min(theta, 360-theta);
    }
};