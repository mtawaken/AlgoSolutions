/*
* Only consider
* (1) s[i] >= s[i+1], add s[i]
* (2) s[i] < s[i+1], substract s[i+1] - s[i]
* 44ms
*/

class Solution {
public:
    int mapping(char x) {
        switch(x) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum = 0;
        int cur, next, i = 0;
        while (i < s.size()) {
            cur = mapping(s[i]);
            i = i + 1;
            if (i < s.size()) {
                next = mapping(s[i]);
                if (cur < next) {
                    sum += (next - cur);
                    i++;
                    continue;
                }
            }
            sum += cur;
        }
        return sum;
    }
};
