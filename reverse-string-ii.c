char* reverse(char* s, int begin, int end)     //顾前不顾后
{
    for(int i = begin; i< begin + (end - begin)/2; i++)
    {
        char t = s[i];
        s[i] = s[end-(i-begin)-1];
        s[end-(i-begin)-1]  = t;
    }
    return s;
}

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    if(len < k)
        reverse(s,0,len);
    else if(len >= k && len < 2*k)
        reverse(s,0,k);
    else 
    {
        int n = len/(2*k), r = len % (2*k);    //乘除优先级相同，自左向右
        for(int i = 0;i < n; i++)
            reverse(s,i*2*k,i*2*k+k);
        if(r < k)                       //余数是否够k
            reverse(s,n*2*k,len);
        else 
            reverse(s,n*2*k,n*2*k+k);
    }
    
    return s;
}