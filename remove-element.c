void swap(int *x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    for(int i=0; i<numsSize - count; i++)
        while(nums[i] == val)
        {
            if(i == numsSize - count -1)
            {
                count++;
                break;
            }
            else
            {
                swap(&nums[i],&nums[numsSize - count++-1]);
            }
        }
           
    return numsSize - count;
}