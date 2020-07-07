#include <iostream>

// 自顶向下，递归过多会存在很多重复计算，耗时较久
long long fabonacci(unsigned int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fabonacci(n - 1) + fabonacci(n - 2);
}

// 自下向上，循环累加
long long fabonacci2(unsigned int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    long long fb1 = 1;
    long long fb2 = 0;
    long long fbn = 0;
    for (unsigned int i = 2; i < n; i++) {
        fbn = fb1 + fb2;
        fb2 = fb1;
        fb1 = fbn;
    }
    return fbn;
}

int main() {
    return 0;
}