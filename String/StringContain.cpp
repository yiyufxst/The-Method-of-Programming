#include <iostream>
#include <string>

using namespace std;

/**
 * ����һ��������ѯ 
 * 
 * ˼·����ѯ���ַ���b��ÿ���ַ��������볤�ַ���a�е�ÿ���ַ����бȽϡ� 
 *
 * ʱ�临�Ӷȣ�O(mn) 
 */
bool StringContain(string &a, string &b)
{   
    for (int i = 0; i < b.length(); i++)
    {
        int j;
        for (j = 0; (j < a.length()) && (a[j] != b[i]); j++);
        if (j >= a.length())
        {
            return false;
        }
    } 
    return true;
}


/**
 * ���������������ѯ 
 * 
 * ˼·���������ַ����Ƚ�������Ȼ��������ַ���������ѯ�� 
 *
 * ʱ�临�Ӷȣ�O(mlogm)+O(nlogn)+O(m+n) 
 */
bool StringContainSort(string &a, string &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int pa = 0, pb = 0; pb < b.length();)
    {
        while ((pa < a.length()) && (a[pa] < b[pb]))
        {
            pa++; 
        }
        if ((pa >= a.length()) || (a[pa] > b[pb]))
        {
            return false;
        } 
        pb++;
    }
    return true;
}


/**
 * ��������������� 
 * 
 * ˼·�� 
 * 1.���մ�С�����˳����26�������ֱ���泤�ַ���a�е�������ĸ�� 
 * 2.�������ַ���a�����a��������ĸ��Ӧ�������ĳ˻��� 
 * 3.�������ַ���b���жϵڶ����õ��ĳ˻��Ƿ��ܱ�b����ĸ��Ӧ������������ 
 * 
 * ʱ�临�Ӷȣ�O(m+n) 
 *
 * ע��������չ˼·���ҽ�������ȫ��Ϊ��д��ĸ��������˽����������������
 * �����ǰ16����ĸ��Ӧ��������˾ͻᳬ��long long�������ܱ�ʾ�����������Χ���� 
 */
bool StringContainPrime(string &a, string &b)
{
    const int table[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                            47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
    int sum = 1;
    for (int i = 0; i < a.length(); ++i) 
    { 
        int temp = table[a[i] - 'A'];
        if (sum % temp)
        {
            sum *= temp;
        }
    }
    for (int i = 0; i < b.length(); ++i)
    {
        int temp = table[b[i] - 'A'];
        if (sum % temp)
        {
            return false;
        }
    }
    return true;
}


/**
 * �����ģ�λ���㷨 
 * 
 * ˼·�� 
 * 1.��λ���㣨26λ������ʾ��Ϊ���ַ���a�����һ��ǩ���� 
 * 2.���ν����ַ���b�е��ַ��ŵ�a�н��в��ҡ� 
 * 
 * ʱ�临�Ӷȣ�O(n+m)
 * 
 * ע��hash��move����ʹ��long long���͡���λ�����Ǹ���move���������ͽ����жϣ���
 * ��int���ͣ�'a'-'A'=32������32λ����int��Χ�����hash����ͬ�� 
 */
bool StringContainBit(string &a, string &b)
{
    long long hash = 0;
    long long move = 1;
    for (int i = 0; i < a.length(); ++i)
    {
        hash |= (move << (a[i] - 'A'));
    }
    for (int i = 0; i < b.length(); ++i)
    {
        if ((hash & (move << (b[i] - 'A'))) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a = "ABb19";
    string b = "Ab19";
    if (StringContainBit(a,b))
        cout << a << "����" << b; 
    else 
        cout << a << "������" << b; 
    return 0;
} 
