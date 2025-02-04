#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <string>
#include <cassert>

#include "book.h"
#include "user.h"

typedef struct LibrarySystem
{
    int total_books;
    int total_users;
    Book books[MAX_BOOKS];
    User users[MAX_USERS];

    /* Constructor */
    LibrarySystem()
    {
        total_books = total_users = 0;
    }
    void run();

    int menu();
    /* Adding a new book to the library, and get book info  */
    void add_book();

    /* */
    void add_user();
    /*  */
    void search_books_by_prefix();

    /* return the index of the dersired book */
    int find_book_id_by_name(string name);

    /* return the index of the dersired user */
    int find_user_id_by_name(string name);
    /*  */
    void print_who_borrowed_book_by_name();
    /* Verify the user name and book name*/
    int user_book_verification(int &user_index, int &book_index, int trials = 3);

    /* */
    void user_borrow_book();
    /* */
    void user_return_book();

    /*  */
    void list_library_by_ID();

    /*  */
    void list_library_by_name();
    /* */
    void print_users();

    /*
    bool cmp_book_by_name(Book &a, Book &b);
    bool cmp_book_by_id(Book &a, Book &b);
    */
} t_library;

#endif