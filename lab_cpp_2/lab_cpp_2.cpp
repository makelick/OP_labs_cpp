#include "Header.h"

int main()
{
    string first_file_path = "first file.txt";
    string second_file_path = "second file.txt";
    input_file(first_file_path);

    cout << "Birthday in this month and career >= 5 years: " << endl;
    birthday_in_this_month(first_file_path);

    return 0;
}
