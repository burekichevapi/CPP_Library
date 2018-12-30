#ifndef AMER_DELIC_ARRAYSTACK_H
#define AMER_DELIC_ARRAYSTACK_H

#include <iostream>

template <class T>
class ArrayStack {
private:
    unsigned int _capacity = 0;
    T *_items = new T[0];

public:
    bool is_empty();

    void print_all();

    void push(T item);

    void pop();

    void clear();

    T get_top_value();

    T get_bottom_value();
};



#endif //AMER_DELIC_ARRAYSTACK_H
