

#include "book.h"
using namespace std;


void t_book::read()
{
    cout << "Enter book info: id & name & total quantity: ";
    cin >> id >> bookName >> total_quantity;
    // total_borrowed = 0;
}

bool t_book::has_prefix(string prefix)
{
    string str = bookName.substr(0, prefix.size());
    if (str == prefix)
        return true;
    else
        return false;
}

bool t_book::borrow(int id)
{
    if (total_quantity - total_borrowed == 0)
        return false;
    ++total_borrowed;
    return true;
}

void t_book::return_copy()
{
    assert(total_borrowed > 0);
    --total_borrowed;
}

void t_book::print()
{
    cout << endl
         << "id = " << id << " name = " << bookName << " total_quantity = "
         << total_quantity << "total_borrowed " << total_borrowed << endl;
}
