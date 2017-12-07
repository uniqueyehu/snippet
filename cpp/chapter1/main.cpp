#include <iostream>
#include <string>
#include <vector>

using namespace std;

void chapter_2_17()
{
    int i, &ri = i;
    i = 5;
    ri = 10;
    cout << i << " " << ri << endl;
}

void test_ptr_size()
{
    int *ptr_i = nullptr;
    cout << sizeof(ptr_i) << endl;
}

void chapter_2_36()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

void chapter_2_37()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

void test_str()
{
//    string s1, s2;
//    cin >> s1 >> s2;
//    cout << s1 << s2 << endl;

//    string s = "hello";
//    cout << s.size() << endl;

//    string st1(10, 'c');
//    cout << st1 << endl;

//    string str("some string");
//    for(auto c : str)
//        cout << c << endl;

    string s("Hello World!!!");
    for(auto &c : s)
        c = toupper(c);
    cout << s << endl;
}

void test_vec()
{
//    int a;
//    vector<int> va;
//    while(cin>>a) //input end of 'ctrl + z'
//    {
//        va.push_back(a);
//    }
//    for(int i = 0; i < va.size(); i++)
//    {
//        cout << va[i] << endl;
//    }

    string s;
    vector<string> vs;
    while (cin >> s) {
        vs.push_back(s);
    }
    for(int i = 0; i < vs.size(); i++)
        cout << vs[i] << endl;
}

void test_iterator()
{
    string s("some string");
//    if(s.begin() != s.end())
//    {
//        auto it =  s.begin();
//        *it = toupper(*it);
//    }
//    cout << s << endl;
    for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << s << endl;

}

int main(int argc, char *argv[])
{
//    chapter_2_17();
//    test_ptr_size();
//    chapter_2_36();
//    chapter_2_37();
//    test_str();
//    test_vec();
    test_iterator();
    return 0;
}
