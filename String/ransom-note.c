bool canConstruct(char* ransomNote, char* magazine) {
    int a[26] = {0};
    int maga_len = strlen(magazine),ran_len = strlen(ransomNote);
    
    for(int i = 0; i < maga_len; i++)
        ++a[magazine[i]-'a'];
    for(int i = 0; i < ran_len; i++)
        --a[ransomNote[i]-'a'];
    for(int i = 0; i < 26; i++)
        if(a[i] < 0)
            return false;
    return true;
}