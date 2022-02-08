#include "Header.h"

int main()
{
	string first_file_name = "first file.txt";
	string second_file_name = "second file.txt";
	input_file(first_file_name);

	cout << "First file:\n";
	output_file(first_file_name);

	create_second_file(first_file_name, second_file_name);

	cout << "Second file:\n";
	output_file(second_file_name);

	return 0;
}
