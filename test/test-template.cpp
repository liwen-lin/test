//
//  template-test.cpp
//  test
//
//  Created by Liwen Lin on 9/1/17.
//  Copyright © 2017 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <memory>
#include <thread>
#include <unordered_map>
#include "test.hpp"

using namespace std;

template <typename T>
T add_t(T a, T b) {
    return a+b;
}

template <typename Dst, typename Src>
Dst cast(Src s) {
    return Dst(s);
}

template <typename T>
class OpClass {
    
};

template <> class OpClass<int> {
public:
    static int op(int a, int b) {
        return a+b;
    }
    
};

template <> class OpClass<float> {
public:
    static float op(float a, float b) {
        return a*b;
    }
    
};

template <typename T> struct X {};

template <typename T> struct Y
{
    typedef X<T> ReboundType;				// 类型定义1
    typedef typename X<T>::MemberType MemberType;	// 类型定义2
    //typedef UnknownType MemberType3;			// 类型定义3
    
    void foo()
    {
        X<T> instance0;
        typename X<T>::MemberType instance1;
        //WTF instance2;
        //大王叫我来巡山 - + &
    }
};

template <typename T = void>
class Base {
public:
    void func() {
        cout << "base" << endl;
    }
};

template <>
class Base<int> {
public:
    void func() {
        cout << "base int" << endl;
    }
};

template <>
class Base<int*> {
public:
    void func() {
        cout << "base int*" << endl;
    }
};

template <typename T>
class Base<T*> {
public:
    void func() {
        cout << "base pointer" << endl;
    }
};

class A1 {
public:
    int a1;
    virtual void print() {
        cout << "A1" << endl;
    }
};

class A2 : public A1 {
public:
    virtual void print() {
        cout << "A2" << endl;
    }
    
};


void fun3(shared_ptr<A1> a1) {
    a1->print();
}


struct TestOp {
    
     virtual bool operator()(const int a) {
         cout << "testop" << endl;
         return false;
     }
    
};

struct TestOp1 : public TestOp {
    
    virtual bool operator()(const int a) {
        cout << "testop1" << endl;
        return false;
    }
    
};

struct TestOp2 : public TestOp {
    
    virtual bool operator()(const int a) {
        cout << "testop2" << endl;
        return false;
    }
    
};

template <int M, int N>
class SMatrix {
public:
    SMatrix() {
        m_col = M;
        m_row = N;
        m_data = new float[m_col*m_row];
    }
public:
    int m_col, m_row;
    float *m_data;
};

struct NewTest {
    NewTest(int m) {
        cout << "construct: " << this << ", " << m << endl;
    }
    
    NewTest(const NewTest &nt) {
        cout << "assign: " << this << ", " << &nt << endl;
        *this = nt;
    }
};

template<typename T>
struct small_any_policy
{
    virtual void static_delete(void**) { }
    virtual void copy_from_value(void const* src, void** dest)
    {
        cout << dest << ", " << (T*)*dest << ", " << **((T**)(dest)) << endl;
        new (dest) T(* reinterpret_cast<T const*>(src));
        cout << dest << ", " << (T*)*dest << ", " << **((T**)(dest)) << endl;
    }
};

#include <typeinfo>

struct Struct1 {
    int a;
    virtual int fun() = 0;
};

struct Struct12 : public Struct1 {
    int fun() {
        return 0;
    }
};

struct Struct13 : public Struct12 {

};

struct Struct2 {
    int b;
    
    Struct2() {
        b = 12;
    }    
};

template <const char* T>
struct Struct3 {
    string b;
    
    Struct3() {
        b = string(T);
    }
};

template <typename T>
struct BigStruct : T {
    BigStruct() {
        b = T::b-2;
    }
    int b;
};

template <typename T = float, int a = 5>
struct TempType1 {
    int k;
    TempType1() {
        k = (T)a;
    }
};

template <typename ... Ts>
struct TempType2 {
    TempType2() {
        cout << "TempType2" << endl;
    }
};

template <typename T1, typename T2, typename T3>
struct TempType2 <T1, T2, T3> {
    T1 k1;
    T2 k2;
    T3 k3;
    TempType2() {
        
    }
};

template <typename T1 = int>
T1 add(T1 a, T1 b) {
    return a+b;
}

template <typename T1>
class TempClass1 {
public:
    TempClass1() {};
};

template<> class TempClass1<float> {
private:
    TempClass1() {};
};

template<> class TempClass1<double>;



template <typename T>
string default_name();
//{
//    return "";
//}

template <>
string default_name<int>() {
    return "int";
}

template <typename T>
T func1(const string &name = default_name<T>());

template <>
int func1<int>(const string &name) {
    cout << "func1<int>" << name << __FUNCTION__ << endl;
    return 3;
}

template <>
vector<string> func1<vector<string> >(const string &name) {
    vector<string> strs;
    return strs;
}

template <typename T>
int func2(T &val, const string &name = "daf");

template <>
int func2<int>(int &val, const string &name) {
    cout << "func2<int>" << name << __FUNCTION__ << endl;
    return 3;
}

template <>
int func2<string>(string &val, const string &name) {
    return 1;
}

class CT1 {
public:
    CT1() {
        a = 10;
    }
    int a;
};

template <typename T, typename T1 = void>
class CT2 {
    
    
};

template <typename T>
//class CT2<T, typename std::enable_if<std::is_base_of<T, CT1>::value>::type> : public T {
class CT2<T, typename std::enable_if<std::is_base_of<T, CT1>::value||true>::type> : public T {
public:
    CT2() {
        //cout << T::a << endl;
    }
};


class Searcher {
    Searcher() {
        //s = "daga";
    }
public:
    static const string s;
};

class ReSearcher : public Searcher {
public:
    void func() {
        cout << "researcher" << endl;
    }
};


template <typename T, typename T1, typename enable=void>
class TC1;

template <typename T, typename T1>
//class TC1<T, T1, typename std::enable_if<std::is_base_of<Searcher, T1>::value>::type> : public T1 {
class TC1<T, T1, typename std::enable_if<std::is_base_of<Searcher, T1>::value>::type> {
public:
    TC1() {
        
    }
    
    //template <typename T1>
    
    void func();
    //{ cout << "func\n";}
    
    
    void func1() {
        cout << "func1\n";
    }
};





template <typename T, typename T1>
void TC1<T, T1, typename std::enable_if<std::is_base_of<Searcher, T1>::value>::type>::func() {
    cout << "func1\n";
}

template <typename T>
class Container {
    
};

template <typename T>
class TC3 : public shared_ptr<Container<T> > {
public:
    TC3() {
        cout << "TC3::" << typeid(data).name() << ", " << typeid(T).name() << endl;
    }
    
private:
    //static const string str;
    T data;
};



#include <map>
using std::unique_ptr;

struct Node {
    Node() {
        static int idc = 0;
        id = idc++;
    }
    virtual ~Node() {
        cout << "destruct: " << id << ", " << this << endl;
    }
    
    shared_ptr<Node> pre, next;
    int id;
};

void slave_thread(shared_ptr<Node> *n) {
    shared_ptr<Node> &n1 = *n;
    shared_ptr<Node> n2 = n1;
    return;
}

const class my_nullptr_t
{
public:
    
    /* Return 0 for any class pointer */
    template<typename T>
    operator T*() const
    {
        cout << "efg" << endl;
        return 0;
    }
    
    /* Return 0 for any member pointer */
    template<typename T, typename U>
    operator T U::*() const
    {
        cout << "abc" << endl;
        return 0;
    }
    
    /* Safe boolean conversion */
    operator void*() const
    {
        return 0;
    }
    
private:
    
    /* Not allowed to get the address */
    void operator&() const;
    
} my_nullptr = {};

template <typename T>
void g(T t) {
    //cout << "g::" << t << endl;
}
        
class ABC {
public:
    ABC() {
        ABC::k = my_nullptr;
    }
    
    void f(int) {};
    
    typedef int* ABC_int;
    int *k;
    ABC *next;
    
};

int kk = 0;
        
template <typename Dtype>
static int get_opencv_mat_type(int channel_num = 3) {
    cout << "1" << endl;
    return 0;
}

template <>
static int get_opencv_mat_type<float>(int channel_num) {
        cout << "2" << endl;
    if (channel_num == 3)
        return 1;
    if (channel_num == 1)
        return 2;
    
    return 0;
}

template <>
static int get_opencv_mat_type<double>(int channel_num) {
        cout << "3" << endl;
    if (channel_num == 3)
        return 3;
    if (channel_num == 1)
        return 4;
    return 0;
}

        void fun1() {
            return;
        }
        
        
int main(void) {
    get_opencv_mat_type<float*>();
    get_opencv_mat_type<float>();
    get_opencv_mat_type<double>();
    
    
    
    int kk = 5;
    cout << ::kk << ", " << kk << endl;
    
    
    g((float*)my_nullptr);
    g(my_nullptr);
    
    ABC abc, *abc1;
    abc1 = &abc;
    abc1->k = my_nullptr;
    abc1->next = my_nullptr;
    
    abc1 = my_nullptr;
    Data1::p = my_nullptr;
    ABC::ABC_int aii = my_nullptr;
    
    void (ABC::* p)(int) = &ABC::f;
    void (ABC::* p1)(int) = my_nullptr;
    
    stringstream ss;
    //ss << "1 3 4 5";
    //ss << "";
    while (!ss.eof()) {

        int num;
        cout <<ss.tellp() << endl;
        ss >> num;
        cout << num << ", " << ss.tellp() << endl;
    }
    
    Container<int> cc;
    cc.~Container();
    
    atomic<int> ai;
    ai = 3;
    cout << ai << endl;
    
    unordered_map<string, int> test_map;
    test_map.insert(make_pair<string, int>("dag", 3));
    auto f = test_map.find("dag1");
    cout << f->second << endl;
    
    
    std::allocator<TC3<int> > all;
    shared_ptr<TC3<int> > sp_tc3 = std::make_shared<TC3<int> >();
    shared_ptr<TC3<int> > sp_tc31 = std::allocate_shared<TC3<int> >(all);
    
    unique_ptr<int> up_int(new int(3));
    unique_ptr<int> up_int1(std::move(up_int));
    
    Node *n = new Node();
    unique_ptr<Node> nn(n);
    shared_ptr<Node> root(new Node);
    /*
    shared_ptr<Node> n1(new Node), n2(new Node);
    root->pre = n2;
    root->next = n1;
    n1->next = n2;
    n1->pre = root;
    n2->next = root;
    n2->pre = n1;
    shared_ptr<Node> &root_ref = root;
    */
    
    std::thread t1(slave_thread, &root);
    std::thread t2(slave_thread, &root);
    t1.join();
    t2.join();
    
    /*
    
    std::map<char,int> mymap;
    
    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    cout << mymap.find('a')->second << endl;
    stringstream ss1;
    ss1 << "ab;ds;df;kf; aaa";
    string s1, s2;
    ss1 >> s1 >> s2;
    
    size_t pos = s1.find_first_of("123fg;f", 0, 5);
    
    
    TC3<int> tc3;
    cout << typeid(tc3).name() << endl;
    
    
    TC1<int, ReSearcher> tc1;
    tc1.func();
    TC1<int, Searcher> tc2;
    tc2.func();
    
    
    CT2<CT1> ct2;
    CT2<A1> ct1;
    
    
    shared_ptr<A2> a21(new A2);
    shared_ptr<A1> a111(new A1);
    fun3(a21);
    fun3(a111);
    
    func1<int>();
    func1<int>("dag");
    func1<vector<string> >("dag");

    int km = 5;
    string str111;
    func2(km);
    func2<string>(str111);

    
    //const char sss[] = "dasgas";
    //Struct3<sss> s3;
    
    char str1[9];
    sprintf(str1, "%p", str1);
    string label = string(str1);
    
    
    BigStruct<Struct2> tt;
    tt.b = 11;
    tt.Struct2::b = 3;
    
    cout << typeid(tt).name() << endl;
    
    int int_tmp;
    int const* int_ptr = &int_tmp;
    //*int_ptr = 10;
    int_ptr = new int(100);
    
    vector<int> a2 = {1, 3, 3};
    vector<int> b2 = {1, 3, 3, 5};
    if (a2==b2) {
        int k = 5;
    }
    
    TempType1<float, 4> m;
    TempType1<> m2;
    TempType2<int, int, float> m1;
    cout << add(1.3, 3.3) << endl;
    
    typedef TempType2<int, float> TempType2_int_float;
    TempType2_int_float ttt;
    
    list<int> li;
    li = {1,3,4,6,7};
    
    unsigned att = 10;
    char buff[100];
    sprintf(buff, "%.8x", att);
    
    
    small_any_policy<int> sap;
    int *an = new int(3135);
    int *bn = new int(5);
    sap.copy_from_value((void*)an, (void**)&bn);
    int *cn = new int;
    int *cnn = new (cn) int(*an);
    
    
    
    NewTest *nt1, *nt2;
    nt1 = new NewTest(NewTest(10));
    nt2 = new NewTest(100);
    new (nt1) NewTest(*nt2);
    new (nt1) NewTest(12);

    
    int bb[3][4];
    cout << bb << ", " << bb[0] << ", " << bb[1] << ", " << bb[2] << endl;
    int *bbp = (int*)bb;
    for (int i = 0; i < 12; i++)
        bbp[i] = i;
    
    
    SMatrix<3, 6> sm;
    cout << sm.m_col << ", " << sm.m_row << endl;
    cout << typeid(sm.m_data).name() << endl;
    
    list<int> l1 = {1, 2, 3, 4};
    list<int> l2 = {10, 20, 30, 40, 50};
    l1.splice(l1.begin(), l2);
    
    int k1 = 42;
    k1 = (k1++)%5;
    
    
    shared_ptr<A1> aaa1(new A2);
    shared_ptr<A2> t1 = std::dynamic_pointer_cast<A2>(aaa1);
    aaa1->print();

    stringstream ss;
    string str[10];
    ss << "asdasgas;asdgasdfasd;e14";
    getline(ss, str[0], ';');

    TestOp *op1 = new TestOp1;
    TestOp *op2 = new TestOp2;
    (*op1)(1);
    (*op2)(2);
    
    vector<shared_ptr<int> >::iterator d;
    
    X<vector<string> > a11;
    list<int> aaa;
    
    bool (*func[3])(int);
    
    int k = (int)(long)op1;
    
    int a1[4];
    cout << (1 << 2) << "dafa:" << sizeof(a1) << endl;
    
    Base<int> bi;
    Base<int*> bp;
    Base<float> bf;
    Base<> bf1;
    bi.func();
    bf.func();
    bp.func();
    bf1.func();
    
    int a = 1;
    float b = 3;
    int c = add_t(float(a), b);
    
    b = cast<int>(b);
    cout << OpClass<int>::op(3, 4) << endl;
    */
    
    return 0;
}


