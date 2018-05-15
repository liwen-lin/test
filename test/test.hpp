//
//  test.hpp
//  test
//
//  Created by Liwen Lin on 4/7/16.
//  Copyright © 2016 Liwen Lin. All rights reserved.
//

#ifndef test_hpp
#define test_hpp

#include <stdio.h>


using namespace std;

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;

static int aaa = 4;


#ifdef GLOBAL_A
int ga = 4;
#endif

template <typename T>
class Data {
    
public:
    T d;
    static int *p;
};

class Data1 {
    
public:
    static int *p;
};


class OperatorTest {
public:
    OperatorTest(string str_ = "") {
        str = str_;
    }
    virtual ~OperatorTest() {
        cout << "destructor" << endl;
    }
    OperatorTest(const OperatorTest& copyed) {
        str = copyed.str;
    }
    
    
    OperatorTest operator + (const OperatorTest& ot1) {
        OperatorTest res(this->str + ot1.str);
        return res;
    }
    
    const OperatorTest& operator = (const OperatorTest& ot1) {
        this->str = ot1.str;
        return *this;
    }
    
//    template <typename T>
//    OperatorTest& operator<<(T data) {
//        this->ss << data;
//        return *this;
//    }
    template <typename T>
    OperatorTest& operator<<(T data);
    
    string str;
    stringstream ss;
};


//#include "../test.cpp"

#endif /* test_hpp */
