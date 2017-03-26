
int char2int(char c)
{
    switch(c)
    {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return -1;        //测试用的
    }
}

int romanToInt(char* s) {
    int len = strlen(s);
    int sum = 0,i;
    for( i = len - 1; i > 0; i--)
    {
        int a = char2int(s[i]), b = char2int(s[i-1]);
        sum += a;
        if(a > b)           //大数左边只可能有一个小数
        {
            sum -= b;
            i--;
        }
    }
    if(i == 0)      //表示剩余首位数
        sum += char2int(s[0]);
    
    return sum;
}