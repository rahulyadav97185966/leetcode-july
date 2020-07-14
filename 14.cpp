//Angle Between Hands of a Clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        return min(abs(((11*minutes)/2.0)-(30*hour)),360-abs(((11*minutes)/2.0)-(30*hour)));
    }
};
