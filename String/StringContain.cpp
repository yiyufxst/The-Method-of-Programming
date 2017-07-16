#include <iostream>
#include <string>

using namespace std;

/**
 * 方法一：蛮力轮询 
 * 
 * 思路：轮询短字符串b中每个字符，依次与长字符串a中的每个字符进行比较。 
 *
 * 时间复杂度：O(mn) 
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
 * 方法二：排序后轮询 
 * 
 * 思路：对两个字符串先进行排序，然后对两个字符串依次轮询。 
 *
 * 时间复杂度：O(mlogm)+O(nlogn)+O(m+n) 
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
 * 方法三：素数相乘 
 * 
 * 思路： 
 * 1.按照从小到大的顺序，用26个素数分别代替长字符串a中的所有字母。 
 * 2.遍历长字符串a，求得a中所有字母对应的素数的乘积。 
 * 3.遍历短字符串b，判断第二步得到的乘积是否能被b中字母对应的素数整除。 
 * 
 * 时间复杂度：O(m+n) 
 *
 * 注：仅供拓展思路，且仅适用于全部为大写字母。素数相乘结果会逐渐增大导致整数
 * 溢出（前16个字母对应的素数相乘就会超出long long类型所能表示的最大整数范围）。 
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
 * 方法四：位运算法 
 * 
 * 思路： 
 * 1.用位运算（26位整数表示）为长字符串a计算出一个签名。 
 * 2.依次将短字符串b中的字符放到a中进行查找。 
 * 
 * 时间复杂度：O(n+m)
 * 
 * 注：hash和move变量使用long long类型。移位操作是根据move变量的类型进行判断，若
 * 用int类型，'a'-'A'=32，左移32位超出int范围会出错，hash变量同理。 
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
        cout << a << "包含" << b; 
    else 
        cout << a << "不包含" << b; 
    return 0;
} 
