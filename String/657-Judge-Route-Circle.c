/*
*
*leetcoode 657. Judge Route Circle
*
*/

//discuss 1
bool judgeCircle(char* moves) {
    int upCount = 0, rightCount = 0;
    
    for (int i = 0; moves[i] != '\0'; i++){
        switch(moves[i]){
            case 'U':   upCount++;
                        break;
            case 'D':   upCount--;
                        break;
            case 'R':   rightCount++;
                        break;
            case 'L':   rightCount--;
                        break;
        }
    }
    
    return upCount == 0 && rightCount == 0;
}


//me
bool judgeCircle(char* moves) {
    int x = 0, y = 0;
    char *p = moves;
    while(*p != '\0')
    {
        if(*p == 'L')
            x -= 1;
        else if(*p == 'U')
            y += 1;
        else if(*p == 'R')
            x += 1;
        else if(*p == 'D')
            y -= 1;
        p++;
    }
    if(x ==0 && y == 0)
        return true;
    else 
        return false;
}