#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addpar(vector<string> &v, string str, int n, int m)
{
    if (n == 0 && m == 0)
    {
        v.push_back(str);
        return;
    }
    // 每次生成括号时，可以分别判断生成左还是右括号，满足条件就递归调用
    if (m > 0)
        addpar(v, str+")", n, m-1);     // 每生成一个右括号，m-1，n不变
    if (n > 0)
        addpar(v, str+"(", n-1, m+1);   // 每生成一个左括号，n-1，m+1
}

int main(int argc, char *argv[])
{
    vector<string> res;
    int n = 3;
    addpar(res, "", n, 0);

    for (auto it = res.cbegin(); it != res.cend(); ++it)
        cout << *it << endl;
    return 0;
}
