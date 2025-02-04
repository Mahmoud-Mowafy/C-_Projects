#ifndef USER_H
#define USER_H

#define MAX_BOOKS 10
#define MAX_USERS 10

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct User
{

    string userName;
    int nationalId;
    int len;
    int borrowed_books_ids[MAX_BOOKS];

    User()
    {
        len = 0;
        nationalId - -1;
        userName = " ";
    }

    void read();

    void borrow(int book_id);

    void return_copy(int book_id);

    bool is_borrowed(int book_id);
    void print();
} t_user;

#endif