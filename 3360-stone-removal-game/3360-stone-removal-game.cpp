class Solution {
public:
    bool canAliceWin(int n) {
        if(n>0 && n<10)
        {
            return false;
        }
        else if(n>9 && n<19)
        {
            return true;
        }
        else if(n>18 && n<27)
        {
            return false;
        }
        else if(n>26 && n<34)
        {
            return true;
        }
        else if(n>33 && n<40)
        {
            return false;
        }
        else if(n>39 && n<45)
        {
            return true;
        }
        else if(n>44 && n<49)
        {
            return false;
        }
        return true;
    }
};