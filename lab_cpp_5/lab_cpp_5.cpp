#include "Header.h"

int main()
{
    cout << "Enter the number of bank accounts: ";
    int n;
    cin >> n;
    cin.ignore();

    vector<CurrentAccount> currents;
    vector<DepositAccount> deposits;
    initVectors(n, currents, deposits);
    checkDeposits(n, currents, deposits);
    printAccounts(n, currents, deposits);

    return 0;
}
