#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
/*
To count the unique elements in an array using set container
1) Get the array from the user
2) Define a set 'unique_ele'
3) Insert the elements of the array to the unique_ele using insert()
4) Print the size of the set using set() to display the count of unique elements in an array
     Since set is of ordered data structure and it does not allow duplicate values to enter we can display the sziz of the set
     to count the unique elements in the array
*/

int main()
{
    int n,i;
    cout<<"Enter the number of elements in an array: ";
    cin>>n;
    cout<<endl;

    int arr[n];
    cout<<"Enter the elements of array: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //initialize the set container to store the elements of the array
    set<int> unique_ele;

    //push the elements of array into the stack
    for(i = 0;i<n;i++)
    {
        int val = arr[i];
        unique_ele.insert(val);
    }

    cout<<"The number of unique elements in the array is "<<unique_ele.size()<<endl;
    cout<<"The unique elements of array are: "<<endl;
    for(auto &s:unique_ele)
        cout<<s<<endl;

    return 0;

}
