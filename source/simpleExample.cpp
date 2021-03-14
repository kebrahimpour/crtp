//
// Created by keyvan on 3/13/21.
//

#include <iostream>
#include "simpleExample.h"

template <typename T>
void doSomething(T& base){
    base.doSomething();
}

int main() {
    D1 d;
    doSomething(d);
    return 0;
}
