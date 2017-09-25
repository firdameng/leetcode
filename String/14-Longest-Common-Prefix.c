
/*
*   14. Longest Common Prefix
*  
*/

// other 
char* longestCommonPrefix(char** strs, int strsSize) {
    char curr;
    int len0,idx,i;
    char *result;
    
    if(!strs || !strsSize)      // 字符串组为空的时候
        return "";
    
    len0 = strlen(strs[0]);     //取任意一个字符串长度就够了，最大公共串前缀不会超出这个数
    
    for(idx=0;idx<len0;idx++)
    {
        curr = strs[0][idx];
        //vertical scanning
        for(i=1;i<strsSize;i++)
        {
            if(strs[i][idx] != curr)
                break;
        }
        
        if(i != strsSize)
            break;
    }

    if(!idx)
        return "";
    
    result = (char *)malloc(sizeof(char)*(idx+1));      
    
    strncpy(result,strs[0],idx);                    //这个用得6啊，字符串拷贝函数
    result[idx] = '\0';
    
    return result;
}


//me
char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    if(strsSize == 0)
        return "";
    else if(strsSize == 1)
        return strs[0];
    else
    {
        while(1)
        {
            int j = 1;
            for(; j < strsSize && strs[j-1][i] != '\0' && strs[j][i] != '\0' && strs[j-1][i] == strs[j][i]; j++);
            if(j < strsSize)
                break;
            i++;
        }
        if(i == 0)
            return "";
        char *s = (char*)malloc(sizeof(char) * (i+1));
        int j = 0;
        for(; j < i; j++)
            s[j] = strs[0][j];
        s[j] = '\0';
        return s;
    }
}