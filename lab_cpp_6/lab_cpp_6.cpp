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
        tree.addElement(tree.getRoot(), element);
    }
    tree.printTree(tree.getRoot(), 0);
    
    tree.swapMaxAndMin(tree.getRoot());
    cout << "Tree with swaped elements: " << endl;
    tree.printTree(tree.getRoot(), 0);
    return 0;
}
