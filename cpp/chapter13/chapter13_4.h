#ifndef CHAPTER13_4_H
#define CHAPTER13_4_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

/**********************************************************/
/* 拷贝控制示例 */
// Message类
class Message {
    friend class Folder;
public:
    explicit Message(const string &str = "") :
        contents(str) { }
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFldr(Folder*);
private:
    string contents;
    set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
};
Message::Message(const Message &m) :
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}
Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}
Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}
void Message::addFldr(Folder *f) { folders.insert(f); }
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}
void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

// Folder类
class Folder {
public:
    Folder(const Folder &f) : msgs(f.msgs)
    {
        add_to_Messages(f);
    }
    Folder & operator=(const Folder &f)
    {
        remove_from_Msgs();
        msgs = f.msgs;
        add_to_Messages(f);
        return *this;
    }

    ~Folder()
    {
        remove_from_Msgs();
    }

    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
private:
    set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
};

void Folder::add_to_Messages(const Folder &f)
{
    for (auto msg : f.msgs)
        msg->addFldr(this);
}
void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}

/**********************************************************/
/* 动态内存管理类 */

#endif // CHAPTER13_4_H
