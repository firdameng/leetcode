int totalHammingDistance(int* nums, int numsSize) {
    
    
    int totalHamDis=0;
   
    while(true)
    {
        int zero[2]={0};                //每轮都得清0，重新对位重记
        int zeroCount=0;                    //取决于最大的那个数,但每轮重新记录为0的数
        for(int i=0; i<numsSize; i++)
        {
            if(nums[i] == 0)
                zeroCount++;
            zero[nums[i]%2]++;
            nums[i] = nums[i] >> 1;
        }
        totalHamDis += zero[0] * zero[1];
        if(zeroCount == numsSize)
            return totalHamDis;
    }
}