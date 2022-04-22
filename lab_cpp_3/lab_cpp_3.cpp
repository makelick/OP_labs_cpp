#include "Book.h"

int main()
{
    cout << "Enter the number of books: ";
    int size;
    cin >> size;
    cin.ignore();

    Book* books = createArray(size);

    Book bookWithMaxPages = findBooksInRange(books, size);

    cout << endl << "Book with max number of pages in this range: " << endl << bookWithMaxPages.getInfo() << endl;

    delete[] books;
    return 0;
}