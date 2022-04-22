#include "Book.h"

int main()
{
    cout << "Enter the number of books: ";
    int size;
    cin >> size;
    cin.ignore();
    Book* array = new Book[size];
    cout << "Enter information about the books in format [full authors name, title, year, number of pages]:" << endl;
    for (int i = 0; i < size; i++) {
        string str;
        getline(cin, str);
        array[i] = Book(str);
    }

    cout << endl << "Enter the range of years in format [minYear-maxYear]: ";
    string stringRange;
    cin >> stringRange;
    vector<string> range = split(stringRange, '-');
    int minYear = stoi(range[0]);
    int maxYear = stoi(range[1]);

    cout << endl << "Books published in this range: " << endl;
    for (int i = 0; i < size; i++) {
        int year = array[i].getYear();
        if (year > minYear && year < maxYear) {
            cout << array[i].getInfo() << endl;
        }

    }

    delete[] array;
    return 0;
}