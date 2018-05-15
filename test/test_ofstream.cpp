//
//  test_ofstream.cpp
//  test
//
//  Created by Liwen Lin on 6/10/16.
//  Copyright © 2016 Liwen Lin. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

#define MACRO(x) MACRO1(x)
#define MACRO1(x) #x
#define MACRO2 3

int main(void) {
    cout << MACRO1(MACRO2) << endl;
    //cout << MACRO1 << endl;
    
    ofstream ofs1, ofs2;
    ofs1.open("test1.log");
    ofs2.open("test2.log");
    bool b = ofs1.is_open();
    
    ofs1 << "test1" << endl;
    ofs2 << "test2" << endl;
    
    ofs1.close();
    ofs2.close();
    
    return 0;
}


