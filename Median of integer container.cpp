#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
To find the median of the container of integers
Storing the array values in a vector and finding the median using nth_element function
*/
template <class A>
class Custom
{
private:
    vector<A> container;
public:
    A median()
    {
        size_t n = container.size() / 2; //giving the middle value where the median resides
        nth_element(container.begin(),container.begin()+n,container.end());
        return container.at(n);
    }
    void insert_val(A val)
    {
        container.push_back(val);
    }

};

int main()
{
    Custom<int> container;

    int n,input; //n - stores the number of inputs , input- stores the input value

    //inserting values into the custom container
    cout<<"Enter the number of values needed to be inserted in the vector: "<<endl;
    cin>>n;

    cout<<"\nEnter the values needed to be inserted in the vector: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        container.insert_val(input);
    }


    //To get the median of the integer call the median function
    cout<<"The median of the integer array is "<<container.median()<<endl;

    return 0;
}
