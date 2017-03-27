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
 * ����һ��������λ 
 * 
 * 1. ����LeftShift���������ַ�������λ�Ƶ�β���� 
 * 2. ����m��LeftShift��������ʹ�ַ�����ͷ��m���ַ��Ƶ��ַ�����β���� 
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
 * ��������������ת 
 * 1.����ReverseString�������ɽ��ַ�����ת�� 
 * 2.���ַ�����Ϊ��Ҫ�ƶ��Ĳ��ֺͲ����ƶ��Ĳ��֣��Ƚ������ָ��Է�ת������
 *   abc->cba��def->fed��
 * 3.���ڶ����õ��Ľ�����巴ת����ʵ���ַ����ķ�ת������cbafed->defabc�� 
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
    // ��Ҫ�����ƶ�����nΪ������%n�ȼ�
    m %= n; 
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n -1);
}
