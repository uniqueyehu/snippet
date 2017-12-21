#ifndef CHAPTER13_4_H
#define CHAPTER13_4_H

#include <iostream>
#include <string>
#include <set>
#include <memory>
#include <utility>

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
/* StrVec类 */
class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    // 移动构造函数
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(StrVec &&rhs) noexcept;

    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
private:
    static allocator<string> alloc;

    void chk_n_alloc()
    {
        if (size() ==  capacity())
            reallocate();
    }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();

    string *elements;
    string *first_free;
    string *cap;
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec& StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

#endif // CHAPTER13_4_H
