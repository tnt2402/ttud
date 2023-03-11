#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

set<string> list_accounts;
map<string, set<string>> account_transactions;
map<string, int> total_money_transactions_from_account;

void inspect_cycle(string start_account, int steps, set<string>& visited_accounts, bool& cycle_found)
{
    if (steps == 0)
    {
        if (account_transactions[start_account].count(start_account) > 0)
        {
            cycle_found = true;
            visited_accounts.insert(start_account);
        }
        return;
    }

    visited_accounts.insert(start_account);

    for (string account : account_transactions[start_account])
    {
        if (!visited_accounts.count(account))
        {
            inspect_cycle(account, steps - 1, visited_accounts, cycle_found);
        }
        else if (account == start_account && steps == 1)
        {
            cycle_found = true;
            visited_accounts.insert(account);
            return;
        }
        if (cycle_found)
        {
            visited_accounts.insert(start_account);
            return;
        }
    }

    visited_accounts.erase(start_account);
}

int main()
{
    string from_account, to_account, time_point, atm;
    int money, N;
    int count_data = 0;
    int total_money_transactions = 0;

    while (true)
    {
        cin >> from_account;

        if (from_account == "#")
        {
            break;
        }

        cin >> to_account >> money >> time_point >> atm;

        count_data++;
        total_money_transactions += money;
        list_accounts.insert(from_account);
        list_accounts.insert(to_account);

        if (from_account != to_account)
        {
            account_transactions[from_account].insert(to_account);
        }

        total_money_transactions_from_account[from_account] += money;
    }

    string query, account_last_query;

    while (true)
    {
        cin >> query;

        if (query == "#")
        {
            break;
        }

        if (query == "?number_transactions")
        {
            cout << count_data << endl;
        }
        else if (query == "?total_money_transaction")
        {
            cout << total_money_transactions << endl;
        }
        else if (query == "?list_sorted_accounts")
        {
            for (string account : list_accounts)
            {
                cout << account << " ";
            }
            cout << endl;
        }
        else if (query == "?total_money_transaction_from")
        {
            cin >> from_account;
            cout << total_money_transactions_from_account[from_account] << endl;
        }
        else if (query == "?inspect_cycle")
        {
            bool cycle_found = false;
            set<string> visited_accounts;
            cin >> account_last_query >> N;

            inspect_cycle(account_last_query, N, visited_accounts, cycle_found);

            if (cycle_found)
            {
                cout << 1 << endl;

                for (string account : visited_accounts)
                {
                    cout << account << " ";
                }
                cout << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
