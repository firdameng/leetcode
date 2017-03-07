class Solution {
public:
    
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
        int count=0 ,a[32],b[32] ;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        
        int2binary(x,a);
        int2binary(y,b);
        for(int i=0; i < 32; i++)
            if(a[i] != b[i])
                count++;
        return count;
    }

    int totalHammingDistance(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
            for(int j = i+1;j<nums.size();j++)
                result+=hammingDistance(nums[i],nums[j]);
        return result;
    }
};