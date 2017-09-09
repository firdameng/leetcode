
/*
*
* 345. Reverse Vowels of a String
*
**/

// 总体双指针的思想

// other，精炼
char* reverseVowels(char* s) {
    int arr[256] = {0};             //牛逼了，一个字符占8位，所有能表示的字符，O(1)时间查询
    arr['a'] = 1; arr['A'] = 1;
    arr['e'] = 1; arr['E'] = 1;
    arr['i'] = 1; arr['I'] = 1;
    arr['o'] = 1; arr['O'] = 1;
    arr['u'] = 1; arr['U'] = 1;
    int start = 0; int end = strlen(s)-1;      // 遇到指针用下标取值操作是要简单一点
    char temp;
    while(start<end) {
        while(start<end && arr[s[start]] == 0) {
            start++;
        }
        while(start<end && arr[s[end]] == 0) {
            end--;
        }
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
        start++; end--;
    }
    return s;
}

// me，6ms明显不如人家简洁
int isvowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    char *p = s, *q = s + len - 1;
    if(len == 0)
        return "";
    while(q - p > 0)
    {
        if(isvowel(*p) && isvowel(*q))
        {
            swap(p,q);
            p++;
            q--;
        }
        else if(!isvowel(*p) && isvowel(*q))
            p++;
        else if(isvowel(*p) && !isvowel(*q))
            q--;
        else
        {
            p++;
            q--;
        } 
    }
    return s;
}


//超时了，Python代码
/* class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = [c for c in s if c in "aeiouAEIOU"]
        res = ""
        for c in s:
            res += vowels.pop() if c in "aeiouAEIOU" else c
        return res */
