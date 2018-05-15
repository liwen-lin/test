//
//  test_overloading_operator.cpp
//  test
//
//  Created by Liwen Lin on 6/9/16.
//  Copyright © 2016 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "test.hpp"

#if 0
using std::string;
using std::cout;
using std::endl;
using std::stringstream;

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
    
    template <typename T>
    OperatorTest& operator<<(T data) {
        this->ss << data;
        return *this;
    }
    
    string str;
    stringstream ss;
};

#endif

int main(int argc, char *argv[]) {    
    OperatorTest ot1("1"), ot2("2");
    cout << "hello world" << endl;
    ot1 << 3 << "dafda";
    cout << ot1.ss.str() << endl;
    
    OperatorTest ot3;
    ot3 = ot1 + ot2;
    OperatorTest o1, o2, o3, o4, o5;
    int t = 3;
    ot3.str = "dafds";
    //cout << ot3.str << endl;
    o3 = o1 + o2;
    int k = 4;
    
    return 0;
}




