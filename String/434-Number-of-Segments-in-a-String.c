/*
*
* 434. Number of Segments in a String
*
*/

// other
int countSegments(char* s) {\
    if(strlen(s)==0)
        return 0;
    int result=0;
    for(int n=0;n<strlen(s)-1;n++)      //通过字符串长度，控制遍历
    {
        if(*(s+n)!=' '&&*(s+n+1)==' ')  //判定分段的依据
            result++;
    }
    if(*(s+strlen(s)-1)!=' ')           //考虑到最后一个字符为非空字符
        result++;
    return result;
}

//me
int countSegments(char* s) {
    char *p = s;
    int segement = 0, len = strlen(s);
    bool  non_space = false;
    if(len == 0)
        return 0;
    while(*p != '\0')
    {
        if(*p == ' ' && non_space)
        {
            non_space = false;
            segement++;
        }
        if(*p != ' ')
            non_space = true;
        p++;
    }
    if(*(s + len -1) != ' ')
        return ++segement;
    return segement;
}