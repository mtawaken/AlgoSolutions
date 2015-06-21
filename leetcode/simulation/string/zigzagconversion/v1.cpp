/*
* 模拟拉链。 注意到每个字符的位置都是可以计算出来的，所以只要把每行字母出现的式子找出来就可以了。
* 边界条件：1. 注意别越界 2. n=1退化成输出字符串
*/


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        stringstream ss;
        int grap = 2 * numRows - 2;
        if (grap == 0) {
            grap = 1;
        }
        int size = s.size();
        for (int i = 0; i < numRows; i++) {
            int index = 0;
            while (index < size) {
                if (i == 0) {
                    ss << s[index];
                    index += grap;
                } else if (i == numRows - 1) {
                    if (index + i < size) {
                        ss << s[index + i];
                    }
                    index += grap;
                } else {
                    if (index + i < size) {
                        ss << s[index + i];
                    }
                    if (index + grap - i < size) {
                        ss << s[index + grap - i];
                    }
                    index += grap;
                }
            }
        }
        string result;
        ss >> result;
        return result;
    }
};

int main() {
    string output = (new Solution())->convert("A", 1);
    cout << output << endl;
    assert(output == "A");
}
