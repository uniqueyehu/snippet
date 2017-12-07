#include <iostream>
#include <memory>
#include <list>
#include <vector>

using namespace std;

// ��̬�ڴ�
// ���˾�̬�ڴ��ջ�ڴ棬ÿ������ӵ��һ���ڴ��
// ��Ϊ���ɿռ��ѣ������ö����洢��̬����Ķ���
// ��̬�ڴ�Ĺ���ͨ��new��delete�����
// new�ڶ�̬�ڴ���Ϊ�������ռ䣬������ָ��ö����ָ��
// delete���ٸö��󣬲��ͷ���֮�������ڴ棨����+�ͷţ�
//
// ����
// new֮�������ͷ��ڴ棬������ڴ�й©
// ָ��������ʱ���ͷ��ˣ������Ӧ�÷Ƿ��ڴ��ָ��

// ����ָ�룬������memoryͷ�ļ���
// shared_ptr
// ������ָ��ָ��ͬһ������
// shared_ptr<T> sp;    ������ָ�룬����ָ������ΪT�Ķ���
// p                        ��p����һ�������жϣ���pָ��һ��������Ϊtrue
// *p                       ������p�������ָ��Ķ���
// p->mem / (*p).mem        ����p��ָ�����ĳ�Ա
// p.get()                  ����p�б����ָ�룬����һ������ָ��
// swap(p, q) / p.swap(q)   ����p��q��ָ��

// make_shared<T>(args)     ����һ��shared_ptr��ָ��һ����̬���������ΪT�Ķ���ʹ��args��ʼ��
// shared_ptr<T>p(q)        p��shared_ptr q�Ŀ������˲��������q�ļ�������q�е�ָ�������ת����T*
// p = q                    p��q����shared_ptr���������ָ��������໥ת����
//                          �˲�����ݼ�p�����ü���������q�е����ü�������p�����ü�����Ϊ0����������ԭ�ڴ��ͷ�
// p.unique()               ��p.use_count()Ϊ1������true�����򷵻�false
// p.use_count()            ������p���������ָ�����������ܺ�������Ҫ���ڵ���


void test_share_ptr()
{
    // ��������ָ��
    // shared_ptr<T> sp;
    shared_ptr<string> p1;      // ����ָ��string
    shared_ptr<list<int>> p2;   // ����ָ��int��list

    // ��p1��Ϊ�գ�������Ƿ�ָ��һ����string
    if (p1 && p1->empty())
        *p1 = "hi"; // ��p1ָ��һ����string��������p1����һ����ֵ����string

    // ָ��һ��ֵΪ42��int��shared_ptr
    shared_ptr<int> p3 = make_shared<int>(42);
    // ָ��һ��ֵΪ��9999999999����string
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    // ָ��һ��ֵ��ʼ����int������ֵΪ0
    shared_ptr<int> p5 = make_shared<int>();

    cout << *p3 << endl;
    cout << *p4 << endl;
    cout << *p5 << endl;

    // shared_ptr�Ŀ����͸�ֵ
    auto p = make_shared<int>(42); // pָ��Ķ���ֻ��pһ��������
    auto q(p); // p��qָ����ͬ����

    // ����
    // ��һ��shared_ptr��ʼ����һ��shared_ptrʱ
    // ������Ϊ�������ݸ�һ������
    // ��Ϊ�����ĵķ���ֵ
    // �ݼ�
    // ��shared_ptr������ֵ
    // shared_ptr������

    auto r = make_shared<int>(33);
    r = q; // ����qָ��Ķ�������ü���
           // �ݼ�rԭ��ָ��Ķ�������ü���
           // rԭ��ָ��Ķ����Ѿ�û�������ߣ����Զ��ͷ�

    // ��������������shared_ptr��ָ��Ķ����ͷ�������ռ�õ��ڴ�

    // ����shared_ptr�����һ�������У���������Ҫȫ��Ԫ�أ�ֻʹ��
    // ����һ���֣�Ҫ�ǵ���eraseɾ��������Ҫ��Ԫ��

    // new
    // �����ڴ棻��ָ��ö���
    // ��new������ڴ���������
    int *pi = new int; // piָ��һ����̬����ġ�δ��ʼ������������
    int *pi2 = new int(); // ֵ��ʼ��Ϊ0
    string *ps1 = new string(); // Ĭ�ϳ�ʼ��Ϊ��string
    // Ĭ������£���̬����Ķ�����Ĭ�ϳ�ʼ����
    // �������ͻ���������͵Ķ����ֵ��δ�����
    // �����Ͷ�����Ĭ�Ϲ��캯������ֵ��ʼ��

    // ���ṩ���Ű�Χ�ĳ�ʼ����������ʹ��auto
    int obj = 42;
    auto p6 = new auto(obj); // pָ��һ����obj������ͬ�Ķ���
    //int a, b, c;
    //auto p7 = new auto{a, b, c}; // ����������ֻ���е�����ʼ����

    // ��̬����const����
    const int *pci = new const int(1024);

    // ʹ�ö�λnew���������ʧ�ܣ�new����һ����ָ��
    int *p8 = new (nothrow) int;

    // delete
    // ���ٸ�����ָ����ָ��Ķ����ͷŶ�Ӧ���ڴ�
    // ���ݸ�delete��ָ�����ָ��̬������ڴ棬������һ����ָ��
    // �ͷ�һ��const����
    delete pci;

    // ������ָ�루����������ָ�룩����Ķ�̬�ڴ��ڱ���ʽ�ͷ�ǰһֱ�������

    // ���ܽ�һ������ָ����ʽת��Ϊһ������ָ�룬����ʹ��ֱ�ӳ�ʼ����ʽ
    //shared_ptr<int> p9 = new int(1024); // ����
    shared_ptr<int> p10(new int(1024)); // ��ȷ
    /*
    // ����
    shared_ptr<int> clone(int p) {
        return new int(p);
    }

    // ��ȷ
    shared_ptr<int> clone(int p) {
        return shared_ptr<int>(new int(p));
    }
    */

    // get��������һ������ָ�룬ָ������ָ�����Ķ���
    // ��������Ҫ����ʹ������ָ��Ĵ����д���һ������ָ��ʱ��ʹ��get
    // ʹ��get���ص�ָ��Ĵ��벻��delete��ָ��
    // ��Ҫʹ��get��ʼ����һ������ָ���Ϊ����ָ�븳ֵ

    // reset
    shared_ptr<int> p11;
    //p = new int(1024); // ���󣺲��ܽ�һ��ָ�븳��shared_ptr
    p11.reset(new int(1024)); // ��ȷ��pָ��һ���¶���

    // ����Դ������ͷ�֮�䷢�����쳣������Ҳ�ᷢ���ڴ�й©
    // ����һ��shared_ptrʱ�����Դ���һ��ָ��ɾ���������Ĳ���
    // p��ʹ�ÿɵ��ö���d������delete
    // shared_ptr<T> p(q, d);

    // ʹ�ù淶
    // ��ʹ����ͬ������ָ�� ֵ��ʼ������reset���������ָ��
    // ��delete get()���ص�ָ��
    // ��ʹ��get()��ʼ����reset��һ������ָ��
    // ��ʹ��get()���ص�ָ�룬��ס�����һ����Ӧ������ָ�����ٺ�ָ��ͱ�Ϊ��Ч��
    // ���ʹ������ָ��������Դ����new������ڴ棬��ס���ݸ���һ��ɾ����
}


// unique_ptr
// ��ռ��ָ�Ķ���
// ĳ��ʱ��ֻ����һ��unique_ptrָ��һ�������Ķ���
void test_unique_ptr()
{
    // û������make_shared�Ĳ���
    // ��Ҫ����󶨵�һ��new���ص�ָ����
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));

    //unique_ptr<int> p3(p2); // ����unique_ptr��֧�ֿ���
    unique_ptr<int> p4;
    //p4 = p2; // ����unique_ptr��֧�ָ�ֵ

    // ֧�ֵĲ���
    // ��unique_ptr������ָ������ΪT�Ķ���ʹ��delete
    // unique_ptr<T> u1
    // ʹ��D�Ŀɵ��ö������ͷ�����ָ��
    // unique_ptr<T, D> u2
    // u������ָ��Ŀ���Ȩ������ָ�룬����u��Ϊ��
    // u.release()
    // �ͷ�uָ��Ķ������ṩ������ָ��q����uָ��������󣻷���u��Ϊ��
    // u.reset()
    // u.reset(q)

    // ������Ȩ��p2ת�Ƹ�p5��release��p2��Ϊ��
    unique_ptr<int> p5(p2.release());
    cout << "p5 = " << *p5 << endl;
    unique_ptr<int> p6(new int(24));
    // ������Ȩ��p6ת�Ƹ�p5��reset�ͷ���p5ԭ��ָ����ڴ�
    p5.reset(p6.release());
    cout << "p5' = " << *p5 << endl;
    // release���ж�unique_ptr����ԭ������Ķ�������ϵ
    // release���ص�ָ��ͨ����������ʼ����һ������ָ��
    // ���߸���һ������ָ�븳ֵ
    //p5.release(); // ����p2�����ͷ��ڴ棬�������Ƕ�ʧ��ָ��
    auto p = p5.release(); // ��ȷ�������Ǳ���ǵ�delete(p)
}

// weak_ptr
// ָ����һ��shared_ptr����Ķ���
// ��weak_ptr�󶨵�һ��shared_ptr����ı�shared_ptr�����ü���
// �����һ��ָ������shared_ptr�����٣�����ͻᱻ�ͷţ���ʹ��weak_ptrָ�����

// w.use_count()    ������w��������shared_ptr������
// w.expired()      ��use_countΪ0������true�����򷵻�false
// w.lock()         ��expiredΪtrue������һ����shared_ptr�����򷵻�һ��ָ��w�Ķ����shared_ptr
// ���ڶ�����ܲ����ڣ����ǲ�����weak_ptrֱ�ӷ��ʶ��󣬱������lock
void test_weak_ptr()
{
    // weak_ptr����shared_ptr�����֣�û������operator *��->
    // ���������������Э��shared_ptr��������һ���۲���
    auto p = make_shared<int>(42);
    weak_ptr<int> wp(p);
//    cout << "wp = " << *wp << endl; // ����������

    if (shared_ptr<int> np = wp.lock())
    {
        // ��if�У�np��p�������
        cout << "np = " << *np << endl;
        cout << "p = " << *p << endl;
    }
}

// ��̬����
void test_array()
{
    int n = 10;
    int *pia = new int[n]; // 10��δ��ʼ����int
    int *pia2 = new int[10](); // 10��ֵ��ʼ��Ϊ0��int
    cout << "pia2 : " <<pia2[0] << endl;
    delete [] pia;
    delete [] pia2;

    string *psa = new string[10]; // 10����string
    string *psa2 = new string[10](); // 10����string
    cout << "psa2 : " << psa2[0] << endl;
    delete [] psa;
    delete [] psa2;

    // 10��int�������б��ж�Ӧ�ĳ�ʼ������ʼ��
    int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
    // 10��string��ǰ4���ø����ĳ�ʼ������ʼ����ʣ��Ľ���ֵ��ʼ��
    string *psa3 = new string[10]{"a", "an", "the", string(3, 'x')};
    cout << "pia3 : " << pia3[5] << endl;
    cout << "psa3 : " << psa3[0] << ", "
         << psa3[3] << ", " << psa3[5] << "." << endl;
    delete [] pia3;
    delete [] psa3;

    // ��̬����һ���������ǺϷ���
    // ���ڳ���Ϊ0��������˵����ʱp�൱��β��ָ��
    size_t n1 = 0;
    int *p = new int[n1];
    for (int *q = p; q != p + n; ++q)
        *q = 1;
    cout << "p : " << p << endl;
    delete [] p;

    // upָ��һ������10��δ��ʼ��int������
    unique_ptr<int[]> up(new int[10]);
    up.release(); // �Զ���delete[]������ָ��

    // Ϊ��ʹ��shared_ptr�������ṩһ��ɾ����
    shared_ptr<int> sp(new int[10], [](int *p) { delete [] p; });
    sp.reset(); //ʹ�������ṩ��lambda�ͷ����飬��ʹ��delete[]
}

// allocator��
// ���ڴ����Ͷ�������뿪
void test_allocator()
{
    int n = 5;
    // ����һ����ڴ棬Ϊ�ɷ���string��allocator����
    allocator<string> alloc;
    // ������n��δ��ʼ����string
    auto const p = alloc.allocate(n);

    // a.construct(p, args)
    // ��pָ����ڴ��й���һ������
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");

    cout << p[3] << endl;

    // a.destroy(p)
    // ��pָ��Ķ���ִ����������
    while (q != p)
        alloc.destroy(--q);

    // a.deallocate(p, n)
    // �ͷŴ�p��ʼ���ڴ棬n��allocate����ʱ��С��ͬ
    alloc.deallocate(p, n);

    // ���������δ��ʼ���ڴ���㷨
    //
    // ��b��e��Χ�п���Ԫ�ص�b2��ʼ���ڴ��У�����һ��ָ��ָ����һ���ڴ��ַ
    // uninitialized_copy(b, e, b2)
    // ��bָ���Ԫ�ؿ�ʼ������n��Ԫ�ص�b2��ʼ���ڴ��У�����һ��ָ��ָ����һ���ڴ��ַ
    // uninitialized_copy_n(b, n, b2)
    // ��b��e��Χ��Ԫ�أ��������󣬶����ֵ��Ϊt�Ŀ���
    // uninitialized_fill(b, e, t)
    // ��bָ���Ԫ�ؿ�ʼ������n��ֵΪt�Ķ���δ������ڴ���
    // uninitialized_file_n(b, n, t)
    vector<int> v;
    for (size_t i = 0; i != 10; ++i)
        v.push_back(i);
    allocator<int> alloc2;

    // �����v��Ԫ����ռ�ÿռ��һ���Ķ�̬�ڴ�
    auto pv = alloc2.allocate(v.size() * 2);
    // ͨ������v�е�Ԫ���������pv��ʼ��Ԫ��
    auto qv = uninitialized_copy(v.begin(), v.end(), pv);
    // ��ʣ��Ԫ�س�ʼ��Ϊ42
    auto endp = uninitialized_fill_n(qv, v.size(), 42);

    for (auto it = pv; it != (pv + v.size() * 2); ++it)
        cout << *it << " " << endl;

    while (endp != pv)
        alloc2.destroy(--endp);
//    for (auto it = pv; it != (pv + v.size() * 2); ++it)
//        alloc2.destroy(it);
    alloc2.deallocate(pv, v.size() * 2);
}


int main(int argc, char *argv[])
{
//    test_share_ptr();
//    test_unique_ptr();
//    test_weak_ptr();
//    test_array();
    test_allocator();
    return 0;
}
