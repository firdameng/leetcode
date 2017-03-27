char *s[10] = {"",
    "1","11","111","-51","5",
    "15","115","1115","-101"
};

char result[16];

char int2char(int k)
{
    switch(k)
    {
        case 1 : return 'I';
        case 5 : return 'V';
        case 10 : return 'X';
        case 50 : return 'L';
        case 100 : return 'C';
        case 500 : return 'D';
        case 1000 : return 'M';
        default : return '#';
    }
}

//根据权重，解析阿拉伯数字对应的罗马数字拼接规则
int parseRule(char *rule, int weight, char *t_res)
{
    int len = 0;
    if(rule[0] == '-')
    {
        if(rule[1] == '5')
            t_res[len++] = int2char(5*weight);
        else
            t_res[len++] = int2char(10*weight);
         t_res[len++] = int2char(1*weight);
        
    }
    else
    {
        for(int i = 0; rule[i] != '\0';i++)
            t_res[len++] = int2char((rule[i]-'0')*weight);
    }
    t_res[len] = '\0';
    return len;
}

int my_pow(int base,int exponent)           //pow函数好像用得有点问题，(int)pow(10,3) 传参成了99
{
    int sum = 1;
    if(exponent ==0)
        return 1;
    for(int i = 0; i<exponent;i++)
        sum*=base;
    return sum;
}
char* intToRoman(int num) {
    int len = 0,power = 0;
    while(num)
    {
        char t_res[5];
        int t_len = parseRule(s[num%10],my_pow(10,power++),t_res);
        strncpy(result + len,t_res,t_len);
        num = num/10;
        len += t_len;
        
    }
    result[len] = '\0'; 
    for(int i = 0; i < len/2; i++)
    {
        char c = result[i];
        result[i] = result[len-i-1];
        result[len-i-1] = c;
    }
    return result;
}