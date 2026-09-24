#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the integer overflow edge case: -2^31 / -1 = 2^31 (exceeds INT_MAX)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        // True if both have the same sign, false if signs are different
        bool isPositive = (dividend > 0 == divisor > 0);
        
        // Convert to long long to handle absolute value of INT_MIN safely
        long long dvd = std::abs((long long)dividend);
        long long dvs = std::abs((long long)divisor);
        
        long long quotient = 0;
        
        // Bit manipulation loop
        while (dvd >= dvs) {
            long long tempDivisor = dvs;
            long long multiple = 1;
            
            // Double the divisor until it exceeds the remaining dividend
            while (dvd >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest doubled divisor value found
            dvd -= tempDivisor;
            quotient += multiple;
        }
        
        return isPositive ? quotient : -quotient;
    }
};
