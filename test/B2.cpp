#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000;
string from_account, to_account, time_point, atm;
int money, N, res = 0;
set<string> list_accounts;
map<string, int> total_money_transaction_from_account;
string query, account_last_query;
map<string, set<string>> test;
set<string> list_inspect_cycle;

void printfCycle()
{
    cout << endl;
    for (set<string>::iterator it = list_inspect_cycle.begin(); it != list_inspect_cycle.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int TRY(int step, string account)
{
    list_inspect_cycle.insert(account);
    set<string> tmp(test[account]);
    if (step == N)
    {
        if (*tmp.find(account_last_query) == account_last_query)
        {
            // list_inspect_cycle.erase(*it);
            printfCycle();
            return 1;
        }
        else
        {
            // list_inspect_cycle.erase(*it);
            // printfCycle();
            return 0;
        }
    }
    for (set<string>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        // if (step == 1)
        // {
        //     cout << account_last_query << " ";
        // }
        // cout << *it << " ";
        if (*list_inspect_cycle.find(*it) != *it)
            res += TRY(step + 1, *it);
        else
            continue;
        if (res != 0)
        {
            return res;
        }
    }
    return 0;
}

int main()
{
    // ios_base::sync_with_stdio(0); // insert
    // cin.tie(0);
    int count_data = 0;
    int total_money_trans = 0;
    do
    {
        cin >> from_account;
        if (from_account == "#")
        {
            break;
        }
        cin >> to_account >> money >> time_point >> atm;
        count_data++;
        total_money_trans += money;
        list_accounts.insert(from_account);
        list_accounts.insert(to_account);
        if (to_account != from_account)
            test[from_account].insert(to_account);
        total_money_transaction_from_account[from_account] += money;
    } while (true);

    do
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
            cout << total_money_trans << endl;
        }
        else if (query == "?list_sorted_accounts")
        {
            set<string, greater<string>>::iterator it = list_accounts.begin();
            for (; it != list_accounts.end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
        else if (query == "?total_money_transaction_from")
        {
            cin >> from_account;
            cout << total_money_transaction_from_account[from_account] << endl;
        }
        else if (query == "?inspect_cycle")
        {
            res = 0;
            list_inspect_cycle.clear();
            cin >> account_last_query >> N;
            // cout << account_last_query << " ";
            res += TRY(1, account_last_query);
            if (res == 0)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    } while (true);

    return 0;
}