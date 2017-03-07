int hammingDistance(int x, int y) {
    int k = x^y;
    if(k == 0 || k == 1)
            return k;
    int count=1;
    while(k != 1)
    {
        if(k%2)
            count++;
        k = k/2;
    }
    return count;
}