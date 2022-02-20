#include "Header.h"

int main()
{
    string first_file_path = "first file.txt";
    string second_file_path = "second file.txt";
    input_file(first_file_path);

    cout << "First file:" << endl;
    output_file(first_file_path);

    return 0;
}
