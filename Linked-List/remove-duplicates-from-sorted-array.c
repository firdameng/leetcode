int removeDuplicates(int* nums, int numsSize) {
    int i,j;
    for(i=1,j=0;i<numsSize;i++)     
        if(nums[i]!=nums[i-1]) 
            nums[++j]=nums[i];     
    return numsSize>0?j+1:0;        
}