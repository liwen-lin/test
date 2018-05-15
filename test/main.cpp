//
//  main.m
//  test
//
//  Created by Liwen Lin on 11/16/15.
//  Copyright © 2015 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <iomanip>

#include "test.hpp"

using std::vector;
// using namespace std;
using std::stringstream;
using std::cout;

//#define MY_ASSERT(e) ((void) ((e) ? (void)0 : __MY_ASSERT(#e, __FILE__, __LINE__)))
//#define __MY_ASSERT(e, file, line) ((void)printf("%s %d\n", line, file), abort())

#define MY_ASSERT(e) ( ((e) ? ((void)0) : __MY_ASSERT(#e, __FILE__, __LINE__)) )
#define __MY_ASSERT(e, file, line) (printf("%s:%u: %s\n", file, line, e), abort())



struct TEST
{
public:
    string str;
    int t;
    
    void fun1(const vector<string>& strs = {})
    {
        int t = strs.size();
    }
    
private:
    static int id;
    
};
int TEST::id = 4;

class EnumClass{
public:
    enum EnumEntity{
        type1 = 104,
        type2 = 31,
        type3 = 42
    };
    
    EnumClass() {
        cout << "construction" << endl;
    }
    
    virtual ~EnumClass() {
        cout << "destruction" << endl;
    }
    
    void test() {
        cout << "test" << endl;
    }
    
};


template <typename T>
void test_template(T t) {
    int k  = 2;
    cout << t << endl;
}


int main(int argc, const char * argv[])
{    
    test_template("dfad");
    
    EnumClass().test();
    
    
    vector<float> ve_f;
    ve_f = {1.3, 2.4};
    
    EnumClass::EnumEntity e1 = EnumClass::EnumEntity::type1;
    cout << e1 << endl;
    
    stringstream ss1;
    ss1 << std::setfill('0') << std::setw(5) << 3 << " " << 5 << " " << 87;
    int i1, i2;
    while (ss1 >> i1) {
        cout << i1 << endl;
    }
    
    ostringstream oss1;
    oss1 << 325;
    string ssss = oss1.str();
    
    
    
    
    int tk = 3;
    MY_ASSERT(tk==4);
    assert(tk == 5);
    
    
    TEST tt1;
    tt1.fun1();
    
    vector<vector<string> > kw = {{"s1", "s2"}, {"13", "3dk"}};
    
    
    vector<int> ve1 = {1, 2, 3, 4, 5};
    
    for (auto &each : ve1)
        cout << &each << endl;

    cout << ve1.capacity() << endl << endl;
    ve1.reserve(10);
    cout << ve1.capacity() << endl << endl;

    for (auto &each : ve1)
        cout << &each << endl;
    
    
    float t1 = reinterpret_cast<int>(3);
    
    char t11[] = "daf";
    int x, y;
    x = 10;
    y = 20;
    swap(x, y);
    
    // eofbit
    // int t = eofbit;
    cout << "hello" << endl;
    
    ifstream ifs("/Users/liwen/Development/tests/test/test/log");
    string str;
    stringstream ss;
    getline(ifs, str);
    ss << str;
    int mc, dim_size, dim[3];
    char c;
    ss >> mc >> dim_size;
    ss >> c;
    for (int i = 0; i < dim_size; i++) {
        ss >> dim[i] >> c;
    }
    
//    TEST *t = (TEST*)malloc(sizeof(TEST)*100);
    TEST *t = new TEST[100];
    t[0].str = "asdfsasdfasdfasdfasdfasdfdf";
    free(t);
    
    
    if (str == "daf");
    
    ifs.close();
    
    
    printf("hello\n");
    return 0;
}
