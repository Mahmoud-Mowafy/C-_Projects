
#include "user.h"

void t_user::read()
{
    cout << "Enter user info: natioinal_id & user_name ";
    cin >> nationalId >> userName >> userName;
    // total_borrowed = 0;
}

void t_user::borrow(int book_id)
{
    borrowed_books_ids[len++] = book_id;
}

void t_user::return_copy(int book_id)
{
    bool removed = false;
    for (int i = 0; i < len; i++)
    {
        if (borrowed_books_ids[i] == book_id)
        {
            for (int j = i + 1; j < len; j++)
            {
                borrowed_books_ids[j - 1] = borrowed_books_ids[j];
            }
            removed = true;
            --len;
            break;
        }
    }
    if (removed == true)
    {
        cout << "User " << userName << " never borrowed book id " << book_id << endl;
    }
}

bool t_user::is_borrowed(int book_id)
{
    for (int i = 0; i < len; i++)
    {
        if (borrowed_books_ids[i] == book_id)
        {
            return true;
        }
    }
    return false;
}
void t_user::print()
{
    sort(borrowed_books_ids, borrowed_books_ids + len);
    cout << " user = " << userName << "id = " << nationalId << " borrowed books ids: ";
    for (int i = 0; i < len; i++)
    {
        cout << borrowed_books_ids[i] << " ";
    }
    cout << endl;
}
