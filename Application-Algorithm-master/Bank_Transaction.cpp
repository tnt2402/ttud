#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> listAcc;
    set<string> listAcc1;
    map<string, int> total_money_acc, count_transaction;
    string from_account, to_account, time, atm;
    int check_from = 0;
    int check_to = 0;
    int money;
    int total_transactions = 0;
    int total_money = 0;
    while (1)
    {
        cin >> from_account;
        if (from_account == "#")
        {
            break;
        }
        cin >> to_account >> money >> time >> atm;
        listAcc1.insert(from_account);
        listAcc1.insert(to_account);
        total_transactions++;
        total_money += money;
        total_money_acc[from_account] += money;
        count_transaction[from_account]++;
        for (string str : listAcc)
        {
            if (from_account == str)
                check_from = 1;
        }
        if (check_from == 0)
        {
            listAcc.push_back(from_account);
        }
        for (string str : listAcc)
        {
            if (to_account == str)
                check_to = 1;
        }

        if (check_to == 0)
        {
            listAcc.push_back(to_account);
        }
        check_from = 0;
        check_to = 0;
    }
    string call;

    do
    {
        cin >> call;
        if (call == "?number_transactions")
        {
            cout << total_transactions << endl;
        }
        else if (call == "?total_money_transaction")
        {
            cout << total_money << endl;
        }
        else if (call == "?list_sorted_accounts")
        {
            for (auto &str : listAcc1)
            {
                cout << str << " ";
            }
            cout << endl;
        }
        else if (call == "?total_money_transaction_from")
        {
            string acc;
            cin >> acc;
            cout << total_money_acc[acc] << endl;
        }
        else if (call == "?inspect_cycle")
        {
            int count;
            string acc;
            cin >> acc >> count;
            if (count_transaction[acc] == count)
            {
                cout << 1 << endl;
            }
            else
                cout << 0 << endl;
        }
    } while (call != "#");
    return 0;
}