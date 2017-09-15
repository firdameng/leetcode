#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* c++  other  真他妈精简
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int a_len = a.size(), b_len = b.size();
        if(a_len == 0 && b_len == 0)
            return "0";
        if(a_len == 0 && b_len != 0)
            return b;
        if(a_len != 0 && b_len == 0)
            return a;
        
        string s = "";
        int c = 0, i = a_len - 1, j = b_len - 1;  // 避免指针而转用下标操作
        while(i >= 0 || j >= 0 || c == 1)       //考虑只剩进位的情况
        {
            c += i >= 0 ? a[i --] - '0' : 0;    //叠加的思路
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;          //c++字符串相加功能
            c /= 2;
        }
        
        return s;
    }
};
*/

//c me 本地是通过的啊，leetcode没通过
char* addBinary(char* a, char* b) {
    
    if(strlen(a) == 0 && strlen(b) == 0)
        return "0";
    if(strlen(a) == 0 && strlen(b) != 0)
        return b;
    if(strlen(a) != 0 && strlen(b) == 0)
        return a;
    
    int a_len = strlen(a), b_len = strlen(b);
    int max = a_len > b_len ? a_len : b_len;
    char *res = (char*)malloc(sizeof(char) * (max + 1));
    char *p = a + a_len - 1, *q = b + b_len - 1, *r = res;
    int curr = 0, rema = 0;
    
    while(p - a >= 0 && q - b >= 0)
    {
        rema = (*p - '0' + *q - '0' + curr) % 2;
        curr = (*p - '0' + *q - '0' + curr) / 2;
        *r++ = rema + '0';
        p--;
        q--;
    }
    while(p - a >= 0 && q - b < 0)
    {
        
        rema = (*p - '0'  + curr) % 2;
        curr = (*p - '0'  + curr) / 2;
        *r++ = rema + '0';
        p--;
    }
    while(p - a < 0 && q - b >= 0)
    {
        
        rema = (*q - '0' + curr) % 2;
        curr = (*q - '0'  + curr) / 2;
        *r++ = rema + '0';
        q--;
    }
    
    if(curr)
        *r++ = curr + '0';
    *r = '\0';
    int res_len = r - res;
    for(int i = 0; i < res_len / 2; i++)
    {
        char t = *(res + i);
        *(res + i) = *(res + res_len -i -1);
        *(res + res_len -i -1) = t;
    }
    return res;
    
}

int main()
{
    char *a = "1011111111110101010111111100100100011101000010001010001";
    char *b = "1110101001110001001111100010001101011111110111011000101";
    printf("%s\n",addBinary(a,b));
}
