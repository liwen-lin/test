//
//  test_shared_mutex.cpp
//  test
//
//  Created by Liwen Lin on 10/19/16.
//  Copyright © 2016 Liwen Lin. All rights reserved.
//

#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <iomanip>

#define GLOBAL_A
#include "test.hpp"

using std::shared_ptr;
using std::unordered_map;
using std::string;

struct SharedData {
    int k = 0;
};

void fun1(shared_ptr<SharedData> sp) {
    sp.reset(new SharedData);
    sp->k = 3234;
    std::cout << sp->k << std::endl;
}

union UTest {
    int a;
    float b;
    char c[4];
};

struct STest {
    int a, bc, c;
    STest() : a(1), bc(1), c(1) {}
    
};

class A {
public:
    A() {
        a = 100;
    }
    int fun1() {
        static int k = 0;
        return ++k;
    }
protected:
    int a;
};

class B : public A {
public:
    B() {
        b = a;
    }
public:
    int b;
};


STest st1;
string kkk;
#define PRINT(TT) pr##TT##f("dfsf;a\n")
//#define PRINT(A) printf("1"#A"2\n")
#define Can(TT) s##TT##.bc
#define str(a) #a

enum ENUM_EXAMPLE {
    T1 = 0,
};

string sss[] = {"daf", "dadg", "asegaet"};

int main()
{
    cout << std::fixed << std::setprecision(3) << 0.0000523 << std::defaultfloat << endl;
    cout << 0.00523 << endl;
    
    cout << sizeof(sss) << ", " << sizeof(string) << ", " << sizeof(string*) << endl;
    int sn = sizeof(sss)/sizeof(string);
    
    unordered_map<string, int> map{{"asd", 1}, {"asdasd", 2}, {"a", 4}};
    
    A a1, a2;
    cout << a1.fun1() << endl;
    cout << a1.fun1() << endl;
    cout << a2.fun1() << endl;
    
    B b11;
    cout << b11.b << endl;
    
    cout << ga << endl;
    
    int i1, i2, i3;
    i1 = 3; i2 = 4;
    i3 = i1^i2;
    
    size_t ss = sizeof(ENUM_EXAMPLE);
    size_t ss1 = sizeof(bool);
    
    std::stringstream *oss = new std::stringstream;
    (*oss) << "dafdsa";
    delete oss;
    
    float a = 1.f;
    if (a == 1) {
        int k = 4;
    }
    UTest ut;
    ut.b = 1.35;
    STest st;
    string str = "dfasdf";
    std::size_t found = str.find("dfa");
    
    std::size_t k = string::npos;
    shared_ptr<SharedData> sp;
    if (sp == nullptr) {
        std::cout << "43235" << std::endl;
    }
    
    int k1 = 35;
    int mk1 = 515215;
    PRINT(int);
    std::cout << "asdf" "1244" "safsaf" << endl;
    fun1(sp);
    string s = str(asdfjiwqpe);
    //Can(t1) = 3;
    
    int b = aaa-4;
    if (b) {
        std::cout << "kao" << std::endl;
    }

    
    return 0;
}
