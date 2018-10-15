#include <iostream>
#include <array>

using namespace std;

class foo {
    public:
        int x, y;
};

class bar {
    public:
        int x, y;
        char c;
};

int main() {
    // int array[5];
    // for(int i = 0; i < 5; ++i) {
    //     array[i] = i;
    // }
    // // for(int x: array) {
    // //     cout << x << endl;
    // // }
    
    // int* p = array;
    // for(int i = 0; i < 5; ++i) {
    //     cout << p[i] << endl;
    // }
    // // cout << array << endl;
    // // cout << p << endl << endl;
    
    // // cout << sizeof(array) << endl;
    // // cout << sizeof(int) << endl;
    // // cout << sizeof(p) << endl;
    
    // for(int i = 0; i < 5; ++i) array[i] = i;
    // for(int i = 0; i < 5; ++i) p[i] = i;
    // for(int i = 0; i < 5; ++i) *(p + i) = i;
    
    // p = array;
    // p++;
    // cout << array << endl;
    // cout << p << endl;
    // cout << (p - array) << endl << endl;
    
    // cout << sizeof(p) << endl;
    
    
    // size_t n;
    // cout << "How many gigabytes do you want? ";
    // cin >> n;
    
    
    // size_t n = 0;
    // while(true) {
    //     ++n;
    //     char* p = new(std::nothrow) char[n * 1024L * 1024L * 1024L];
    //     if(p != NULL) {
    //         cout << "Success at " << n << " gigabytes!" << endl;
    //         delete[] p;
    //     } else {
    //         cout << "Failed at " << n << " gigabytes!" << endl;
    //         break;
    //     }
    // }
    
    cout << sizeof(foo) << endl;
    foo array[10];
    cout << sizeof(array) << endl << endl;
    
    cout << sizeof(bar) << endl;
    bar array1[10];
    cout << sizeof(array1) << endl;
    
    return 0;
}