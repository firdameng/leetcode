
/*
  时间复杂度O(n)

*/
bool detectCapitalUse(char* word) {
    int len = strlen(word);

    if(len == 1)
        return true;
    if(islower(word[0]) && isupper(word[len-1]))
        return false;
    else if(!islower(word[0]) && isupper(word[len-1]))
    {
        for(int i = 1; i< len-1; i++)
            if(islower(word[i]))
                return false;
    }
    else if(islower(word[0]) && !isupper(word[len-1]))
    {
        for(int i = 1; i< len-1; i++)
            if(isupper(word[i]))
                return false;
    }
    else
    {
        for(int i = 1; i< len-1; i++)
            if(isupper(word[i]))
                return false;
    }
    return true;
}