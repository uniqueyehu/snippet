#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s)
{
   stack<char> sch;
   for (int i = 0; i < s.size(); ++i)
   {
       if (s[i] == '(' || s[i] == '[' || s[i] == '{')
           sch.push(s[i]);
       else if (s[i] == ')' && !sch.empty() && sch.top() == '(')
           sch.pop();
       else if (s[i] == ']' && !sch.empty() && sch.top() == '[')
           sch.pop();
       else if (s[i] == '}' && !sch.empty() && sch.top() == '{')
           sch.pop();
       else
           return false;
   }
   return sch.empty();
}

int main(int argc, char *argv[])
{
//    string s = "()[]{}";
    string s = "]";
    cout << isValid(s) << endl;
    return 0;
}
