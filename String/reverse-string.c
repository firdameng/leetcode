char* reverseString(char* s) {
    int len = strlen(s);            //len = 0直接不满足跳过循环
    for(int i=0; i<len/2; i++)
    {
        char t = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = t;
    }
    return s;
}