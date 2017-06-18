void parseComplexNumber(char* s, int *a, int *b)
{
    int len = strlen(s);
    char *padd = strchr(s,'+');
    char a_str[5], b_str[5];
    
    strncpy(a_str,s,padd - s);
    a_str[padd - s] = '\0';
    *a = atoi(a_str);
    
    strncpy(b_str,padd+1,len - (padd - s) - 2);   //除去+，i两字符
    b_str[len - (padd - s) - 2] = '\0';
    *b = atoi(b_str);
}

char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
}
char* complexNumberMultiply(char* a, char* b) {
    
    int a_x, a_y, b_x, b_y;
    parseComplexNumber(a,&a_x,&a_y);
    parseComplexNumber(b,&b_x,&b_y);
    
    int n_x = a_x*b_x - a_y*b_y, n_y = a_x*b_y + a_y*b_x;
    
    char x_str[6], y_str[6];
    itoa(n_x,x_str,10);
    itoa(n_y,y_str,10);
    
    char *result = (char*)malloc(sizeof(char)*15);   //单独开辟内存，否则栈空间变量返回为空
    int x_str_len = strlen(x_str), y_str_len = strlen(y_str);

    strncpy(result,x_str,x_str_len);
    result[x_str_len] = '+';
    strncpy(result + x_str_len + 1, y_str,y_str_len);
    result[x_str_len + y_str_len + 1] = 'i';
    result[x_str_len + y_str_len + 2] = '\0';

    return result;
}