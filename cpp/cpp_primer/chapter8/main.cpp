#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void test_8_4()
{
    string file_path = "e:\\workspace\\yehu\\algorithm\\cpp\\cprimer_8\\data.txt";
    vector<string> file_data;

    ifstream fstrm(file_path);

    //�ж��ļ��Ƿ�򿪳ɹ�
    if(fstrm)
        cout << "open success !" << endl;
    else
        cout << "open error!" << endl;

    //�ж��ļ��Ƿ���������������ļ�β
    while(fstrm)
    {
        string temps;
        getline(fstrm, temps);//��ȡһ����
        file_data.push_back(temps);
    }

    for(auto i = 0; i < file_data.size(); ++i)
        cout << file_data[i] << "\n" << endl;
}

//------------------------------------------------
//8.3.1��
struct PersonInfo {
    string name;
    vector<string> phones;
};

void test_8_3_1()
{
    string line, word;
    vector<PersonInfo> people;

    while (getline(cin, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (auto i = 0; i < people.size(); ++i)
    {
        cout << people[i].name << endl;
        for (auto j = 0; j < people[i].phones.size(); ++j)
            cout << people[i].phones[j] << endl;
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    test_8_3_1();
    return 0;
}
