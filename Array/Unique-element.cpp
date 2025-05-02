// Find the unique elememnts and print

#include <iostream>
#include <unordered_map>
using namespace std;

void findUnique(int *arr, int n)
{
    unordered_map<int, int> store;
    for (int i = 0; i < n; i++)
    {
        if (store.find(arr[i]) == store.end())
        {
            store[arr[i]] = 1;
        }
        else
        {
            store[arr[i]] += 1;
        }
    }
    // for(auto&pair:store){
    //     cout<<pair.first<<" occures "<<pair.second<<" times"<<endl;
    // }

    for (auto &pair : store)
    {
        if (pair.second == 1)
        {
            cout << pair.first << endl;
        }
    }
}

int main()
{
    int x;
    cout << "Enter no: ";
    cin >> x;
    cout << "Number: " << x << endl;

    int arr[] = {11, 22, 33, 44, 11, 22, 33, 11, 22, 33, 55};

    int n = sizeof(arr) / sizeof(arr[0]);

    findUnique(arr, n);
}
