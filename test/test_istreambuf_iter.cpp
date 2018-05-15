#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>


int main()
{
    std::vector<int> a = {1, 3, 34, 5};
    int *t = &(a[0]);
    int *t1 = &(a[1]);
    int *t2 = &(a[2]);
    int *t3 = &(a[3]);
    
    std::string image[] = {"dafds", "dfasdfaiaewr", "dasdaeld"};
    std::cout << sizeof(image)/sizeof(std::string) << std::endl;
    std::vector<std::string> image1 = {"dafds", "dfasdfaiaewr", "dasdaeld"};
    
    std::ifstream ifs("/Users/liwen/Development/df_face/lfwraw/Aaron_Eckhart/Aaron_Eckhart_0001.jpg");
    //std::string str(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
    std::string str((std::istreambuf_iterator<char>(ifs)),
                    std::istreambuf_iterator<char>());
    std::cout << str << std::endl;
    
    // typical use case: an input stream represented as a pair of iterators
    std::istringstream in("Hello, world");
    std::vector<char> v( (std::istreambuf_iterator<char>(in)),
                        std::istreambuf_iterator<char>() );
    std::cout << "v has " << v.size() << " bytes. ";
    v.push_back('\0');
    std::cout << "it holds \"" << &v[0] << "\"\n";
    
    
    // demonstration of the single-pass nature
    std::istringstream s("abc");
    std::istreambuf_iterator<char> i1(s), i2(s);
    std::cout << "i1 returns " << *i1 << '\n'
              << "i2 returns " << *i2 << '\n';
    ++i1;
    std::cout << "after incrementing i1, but not i2\n"
              << "i1 returns " << *i1 << '\n'
              << "i2 returns " << *i2 << '\n';
    ++i2; // this makes the apparent value of *i2 to jump from 'a' to 'c'
    std::cout << "after incrementing i2, but not i1\n"
              << "i1 returns " << *i1 << '\n'
              << "i2 returns " << *i2 << '\n';
    
    return 0;
}