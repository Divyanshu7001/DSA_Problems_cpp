#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    cout << "Size of V: " << v.size() << endl;
    cout << "Capacity of v:" << v.capacity() << endl;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    cout << "Size of V: " << v.size() << endl;
    cout << "Capacity of v:" << v.capacity() << endl;
    v[1]=5;


    vector<int>v1(5,1);
    cout << "Size of V: " << v1.size() << endl;
    cout << "Capacity of v:" << v1.capacity() << endl;
    v.begin();
    v.end();

    
    v1.push_back(8);
    cout << "Size of V: " << v1.size() << endl;
    cout << "Capacity of v:" << v1.capacity() << endl;


    vector<int>v3={1,2,5,6,7};
    cout << "Size of V: " << v3.size() << endl;
    cout << "Capacity of v:" << v3.capacity() << endl;
    
    int x;
    cout<<"Enter number: ";
    cin>>x;
    cout<<"Number: "<<x<<endl;
    v3.push_back(x);
    cout << "Size of V: " << v3.size() << endl;
    cout << "Capacity of v:" << v3.capacity() << endl;
}