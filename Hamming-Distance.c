class Solution {
public:
    int a[32],b[32];
    void int2binary(int k,int a[]){
        if(k == 0 || k == 1)
        {
            a[0] = k;
            return;
        }
        int i = 0, m;
        while(k != 1)
        {
            m = k%2;
            a[i++] = m;
            k = k/2;
        }
        a[i] = 1;
    }
    int hammingDistance(int x, int y) {
        int count=0 ;
        int2binary(x,a);
        int2binary(y,b);
        for(int i=0; i < 32; i++)
            if(a[i] != b[i])
                count++;
        return count;
    }
};