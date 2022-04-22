#include "Book.h"

int main()
{
    cout << "Enter the number of books: ";
    int size;
    cin >> size;
    cin.ignore();
    Book* array = new Book[size];
    cout << "Enter information about the books in format [full authors name, title, year, number of pages]:" << endl;
    for (int i = 0; i < size; i++)
    {
        string str;
        getline(cin, str);
        array[i] = Book(str);
    }


    return 0;
}