#include "Tree.h"

int main()
{
    Tree tree;
    int size;
    double element;
    cout << "Enter the number of elements in tree: ";
    cin >> size;
    cout << "Enter tree elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        tree.addElement(element);
    }
    tree.printTree();
    
    tree.swapMaxAndMin();
    cout << "Tree with swaped elements: " << endl;
    tree.printTree();
    return 0;
}
