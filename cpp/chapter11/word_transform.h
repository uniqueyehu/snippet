#ifndef WORD_TRANSFORM_H
#define WORD_TRANSFORM_H

#include <istream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string & transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);    // 保存转换规则
    string text;
    while (getline(input, text)) {  // 读取每一行输入
        istringstream stream(text); // 读取每个单词
        string word;
        bool firstword = true;  // 是否打印空格
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map); // 打印输出
        }
        cout << endl;
    }
}

void run_transform()
{
    string rule_file = "e:\\mygit\\snippet\\cpp\\chapter11\\rule.txt";
    string text_file = "e:\\mygit\\snippet\\cpp\\chapter11\\text.txt";
    ifstream map_file(rule_file), input(text_file);

    if (map_file && input)
        word_transform(map_file, input);
    else
        cout << "open files error!" << endl;
}

#endif // WORD_TRANSFORM_H
