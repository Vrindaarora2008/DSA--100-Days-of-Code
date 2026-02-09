void reverseString(char* s, int sSize) 
{
    int start = 0, end = sSize - 1;
    char temp;
    while (start < end) 
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}