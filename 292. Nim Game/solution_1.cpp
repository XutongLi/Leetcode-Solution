class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};
//当n%4为0，a先取，a每次取i，则b每次取4-i，最后必为b胜
//当n%4不为0，a先取n%4，b取i，a每次取4-i，最后必为a胜