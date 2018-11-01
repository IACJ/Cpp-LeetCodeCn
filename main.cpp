#include <iostream>
using namespace std;

int fun(int i) {
    int temp;
    while (i > 10) {
        temp = i % 10;
        if (temp == 7) {
            return 1;
        }
        i = i / 10;
    }
    if ( i != 7) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << fun(70);
    return 0;
}