#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#define MAX_BOOKS 10
typedef struct Book
{

    string bookName;
    int id;
    int total_quantity;
    int total_borrowed;

    Book()
    {
        total_quantity = total_quantity = 0;
        id - -1;
        bookName = " ";
    }

    void read();
    bool has_prefix(string prefix);
    bool borrow(int id);
    void return_copy();
    void print();
} t_book;

#endif