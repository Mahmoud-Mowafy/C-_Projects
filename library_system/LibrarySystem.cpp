
#include "LibrarySystem.h"

using namespace std;

void t_library::run()
{
    while (true)
    {
        int choice = menu();
        switch (choice)
        {
        case 1:
            add_book();
            break;

        case 2:
            search_books_by_prefix();
            break;
        case 3:
            print_who_borrowed_book_by_name();
            break;

        case 4:
            list_library_by_ID();
            break;
        case 5:
            list_library_by_name();
            break;

        case 6:
            add_user();
            break;
        case 7:
            user_borrow_book();
            break;

        case 8:
            user_return_book();
            break;
        case 9:
            print_users();
            break;

        default:
            break;
        }
    }
}

int t_library::menu()
{
    int choice = -1;
    while (choice == -1)
    {
        if (false)
        {
            cout << "\nLibrary Menu\n";
            cout << "1) add_book\n";
            cout << "2) search_books_by_prefix\n";
            cout << "3) print_who_borrowed_book_by_name\n";
            cout << "4) print_library_by_id\n";
            cout << "5) print_library_by_name\n";
            cout << "6) add_user\n";
            cout << "7) user_borrow_book\n";
            cout << "8) user_return_book\n";
            cout << "9) print_users\n";
            cout << "10) Exit\n";
        }
        cout << "\n Enter your choice [ from 1 to 10 ]" << endl;
        cin >> choice;
        if (!(choice >= 1 && choice <= 110))
        {
            cout << "Invalid choice, please try again" << endl;
            choice = -1;
        }
    }
    return choice;
}

/* Adding a new book to the library, and get book info  */
void t_library::add_book()
{
    books[total_books++].read();
}

/* */
void t_library::add_user()
{
    users[total_users++].read();
}

/*  */
void t_library::search_books_by_prefix()
{
    cout << "Enter the book name: ";
    string prefix;
    cin >> prefix;
    bool exist = false;
    for (int i = 0; i < total_books; i++)
    {
        if (books[i].has_prefix(prefix))
        {
            cout << books[i].bookName << endl;
            exist = true;
        }
    }
    if (exist == false)
    {
        cout << " No books with such prefix";
    }
}

/* return the index of the dersired book */
int t_library::find_book_id_by_name(string name)
{
    for (int i = 0; i < total_books; i++)
    {
        if (books[i].bookName == name)
            return i;
    }
    return -1;
}

/* return the index of the dersired user */
int t_library::find_user_id_by_name(string name)
{
    for (int i = 0; i < total_users; i++)
    {
        if (users[i].userName == name)
            return i;
    }
    return -1;
}

/*  */
void t_library::print_who_borrowed_book_by_name()
{
    cout << " Enter the book name: ";
    string name;
    cin >> name;

    /* find the index of the dersired book by book_name */
    int bookIndex = find_book_id_by_name(name);

    if (bookIndex == -1)
        cout << "Invalid Book Name" << endl;

    /* find the book id via the book_index in the books array*/
    int bookId = books[bookIndex].id;

    for (int i = 0; i < total_users; i++)
    {
        if (users[i].is_borrowed(bookId))
        {
            cout << users[i].userName << endl;
        }
    }
}

/* Verify the user name and book name*/
int t_library::user_book_verification(int &user_index, int &book_index, int trials)
{
    while (trials--)
    {
        cout << "Enter user name and book name: ";
        string user_name, book_name;
        cin >> user_name >> book_name;

        user_index = find_user_id_by_name(user_name);

        if (user_index == -1)
        {
            cout << "Invalid User Name, try again" << endl;
            continue;
        }

        book_index = find_book_id_by_name(user_name);

        if (book_index == -1)
        {
            cout << "Invalid Book Name, try again" << endl;
            continue;
        }
        return true;
    }
    cout << " You did several trials with invalid data! Try later....." << endl;
    return false;
}

/* */
void t_library::user_borrow_book()
{
    int user_index, book_index;
    int verify = user_book_verification(user_index, book_index);

    if (!verify)
        return;
    int userID = users[user_index].nationalId;
    int bookID = books[book_index].id;

    /////////////////////////
    if (books[book_index].borrow(bookID))
        cout << " No more copies available right now!" << endl;
    else
        users[user_index].borrow(bookID);
}

/* */
void t_library::user_return_book()
{
    int user_index, book_index;
    if (!user_book_verification(user_index, book_index))
        return;
    int userID = users[user_index].nationalId;
    int bookId = books[book_index].id;

    books[book_index].return_copy();
    users[user_index].return_copy(bookId);
}

/*  */
void t_library::list_library_by_ID()
{
    sort(books, books + total_books);

    for (int i = 0; i < total_books; i++)
    {
        books[i].print();
    }
}

/*  */
void t_library::list_library_by_name()
{
    sort(books, books + total_books);

    for (int i = 0; i < total_books; i++)
    {
        books[i].print();
    }
}

/* */
void t_library::print_users()
{
    cout << endl;
    for (int i = 0; i < total_users; i++)
    {
        users[i].print();
    }
}

/*
bool t_library::cmp_book_by_name(Book &a, Book &b)
{
    return a.bookName < b.bookName;
}

bool t_library::cmp_book_by_id(Book &a, Book &b)
{
    return a.id < b.id;
}
*/
