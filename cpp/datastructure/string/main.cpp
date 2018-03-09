#include <iostream>
#include <string>

using namespace std;

// 求子串位置的定位函数
// 返回子串T在主串S中第pos个字符之后的位置，若不存在，则返回0
int Index(string S, string T, int pos)
{
    int i = pos;
    int j = 0; // 从0开始的。。。

    while (i < S.length() && j < T.length())
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {   // 匹配失败，i回到原来的地方+1的地方，j回到0
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= T.length())
        return i - T.length();
    else
        return 0;

}

// KMP算法
// 和模式串长度相等的next数组，用来确定当匹配失败时j退回的"位置"
// 正常取值为0 - (T.length()-1)，-1表示不存在相同的最大前缀和最大后缀

// next函数找到模式串T的相同的最大前缀和最大后缀相匹配的位置
// 和KMP算法相似
void cal_next(string T, int next[])
{
    next[0] = -1;   // 第一个字符不存在相同的最大前缀和后缀
    int i = 0;
    int j = -1;
    while (i < T.length())
    {
        if (j == -1 || T[i] == T[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int KMP(string S, string T, int pos)
{
    int i = pos;
    int j = 0;
    int next[T.length()];

    cal_next(T, next);

    while (i < S.length() && j < int(T.length()))
    {
        if (j == -1 || S[i] == T[j])
        {   // 继续匹配后面的字符：
            // j = -1表示匹配失败后，j从0开始和i+1字符来进行匹配
            // S[i] == T[j]表示继续进行下个字符的匹配
            ++i;
            ++j;
        }
        else
        {   //  匹配失败，i不变，j回到next[j]的位置
            j = next[j];
        }
    }
    if (j >= T.length())
        return i - T.length();
    else
        return 0;
}

int main(int argc, char *argv[])
{
    string S = "a string searching example consisting of simple text";
    string T = "sting";
    int pos = 0;

    cout << "pos = " << Index(S, T, pos) << endl;

    cout << "using KMP :" << endl;
    string T2 = "abaabcac";

//    int next[T2.length()];
//    cal_next(T2, next);
//    for (int i = 0; i < T2.length(); ++i)
//        cout << next[i] << " ";
    cout << "pos = " << KMP(S, T, 0) << endl;
//    if ( -1 < int(T2.length())) // int < unsigned ?
//        cout << "111" << endl;
//    else
//        cout << "222" << endl;

    return 0;
}
