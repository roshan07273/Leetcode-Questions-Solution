class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        int mask = 1 << k;
        bool set = mask & n;
        if(set != 0 ) return true;
        else false;
    }
};
