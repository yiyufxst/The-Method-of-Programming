#include <stdio.h>

int main()
{
    void LeftShift(char* s, int n);
    void LeftRotateStringOne(char* s, int n, int m);
    void ReverseString(char* s, int from, int to);
    void LeftRotateStringTwo(char* s, int n, int m);
    char s[] = "abcdef";
    //LeftRotateStringOne(s, strlen(s), 3);
    LeftRotateStringTwo(s, strlen(s), 3);
    printf(s);
    return 0;
}

/**
 * 方法一：蛮力移位 
 * 
 * 1. 定义LeftShift函数，将字符串的首位移到尾部。 
 * 2. 调用m次LeftShift函数，可使字符串开头的m个字符移到字符串的尾部。 
 */
void LeftShift(char* s, int n)
{
    int i; 
    char temp = s[0];
    for (i = 1; i < n; i++)
    {
        s[i - 1] = s[i];
    } 
    s[n - 1] = temp;
}

void LeftRotateString(char* s, int n, int m)
{
    while (m--)
    {
        LeftShift(s, n);
    }
}

/**
 * 方法二：三步反转 
 * 1.定义ReverseString函数，可将字符串反转。 
 * 2.将字符串分为需要移动的部分和不需移动的部分，先将两部分各自反转，例如
 *   abc->cba，def->fed。
 * 3.将第二步得到的结果整体反转即可实现字符串的反转，例如cbafed->defabc。 
 */
void ReverseString(char* s, int from, int to)
{
    while (from < to)
    {
        char t = s[from];  
        s[from++] = s[to];
        s[to--] = t;
    }
} 

void LeftRotateStringTwo(char* s, int n, int m)
{
    // 若要向左移动大于n为，则与%n等价
    m %= n; 
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n -1);
}
