void inverse(char* str, int n)
{
    for(int i=0; i<n/2; i++)
    {
        char t = *(str + i);
        *(str + i) = *(str + n - i - 1);
        *(str + n - i - 1) = t;
    }
}

char* reverseWords(char* s) {
    
    if(s == NULL)
        return s;
    int pre_index = 0, i = 0;
    for(; *(s+i) != '\0'; i++)
    {
        if(*(s+i) == ' ')
        {
            inverse(s+pre_index,i-pre_index);
            pre_index = i + 1;
        }
    }
    inverse(s+pre_index,i-pre_index);
    return s;
}
