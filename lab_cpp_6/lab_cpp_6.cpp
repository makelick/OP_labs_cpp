#include "Tree.h"

int main()
{
    Branch* root = NULL;
    int size;
    double element;
    cout << "Enter the number of elements in tree: ";
    cin >> size;
    cout << "Enter tree elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        addElement(root, element);
    }
    
    printTree(root, 0);
    return 0;
}
