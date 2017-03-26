int findMinDifference(char** timePoints, int timePointsSize) {
    int minimum = 24*60 ;
    for(int i = 0; i < timePointsSize; i++)
    {
        int minutes_i = (*(*(timePoints+i))-'0')*10*60 +(*(*(timePoints+i)+1)-'0')*60 + atoi(*(timePoints+i)+3);
        for(int j = i + 1; j < timePointsSize; j++)
        {
            int minutes_j = (*(*(timePoints+j))-'0')*10*60 +(*(*(timePoints+j)+1)-'0')*60 + atoi(*(timePoints+j)+3);
            int  d_value = abs(minutes_i - minutes_j);
            d_value = 24*60 - d_value < d_value ? 24*60  - d_value : d_value;  //根据一圈取其小者。
            if(d_value == 0)
                return 0;
            else
            {
                if(d_value < minimum)
                    minimum = d_value;
            }
        }
    }
        
    return minimum;
}