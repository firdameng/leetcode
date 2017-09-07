/*
*   647. Palindromic Substrings
*
*/

/*
*   In the following code, 
*   when we consider the substring s[i-j, ..., i+j], 
*   i is the middle index of the substring; 
*   When we consider the substring s[i-1-j, ..., i+j], 
*   (i-1, i) is the middle index of the substring.
*/

// 每步判断都是有效的
int countSubstrings(char* s) {
    int res = 0, n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        // 不用计算索引的位置; 简洁的写法；以回文字符串的中间位置向外拓展;
        
        //奇数对，j =0即包括了单独的情况[0,n]
        for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
            res++; //substring s[i-j, ..., i+j]
        //偶数对
        for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)
            res++; //substring s[i-1-j, ..., i+j]
    }
    return res;
}


// O(n^2)
int ispalindrome(char *s,int len)
{
    for(int i = 0; i < len/2; i++)
        if(*(s + i) != *(s + len - i - 1))
            return false;
    return true;
}

int countSubstrings(char* s) {
    int len = strlen(s);
    int count = len;
    for(int step = 2; step <= len; step++)
        for(int i = 0; i <= len - step; i++)
        {
            if(ispalindrome(s + i,step))
                count++;
        }
    return count;
}