class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0) return 1; 
        if (n == 1) return 2; 

        int bulb = 1;
        if (n > 1) bulb++; 
        if (n > 2) bulb++; 

        if (presses == 1) {
            if (n == 2) return 3; 
            return 4; 
        } else if (presses == 2) {
            if (n == 2) return 4; 
            return 7; 
        }
        if (n == 2) return 4; 
        return 8;
    }
};