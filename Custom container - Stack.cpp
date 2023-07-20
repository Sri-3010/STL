#include <iostream>
#include <algorithm>
#include <vector>
/*
Creating a custom container that acts like a Stack using STL libraries
1) Declaring a class template with type T
2) Creating a vector of type T stack_like to perform operations
3) Functions implemented:
    1) size()
        * Return the size of the vector using the function size() as integer
    2) pop()
        * Removes the top element i.e the element added in the last
        * The top element is retrieved using back() function and it is removed using pop_back()
        * Returns the top element with the type T
    3) push(T )
        * This function is used to insert the value that is passed as an argument in the function
        * The argument will be of type T
        * The value is inserted using push_back()
    4) empty()
        * This function checks whether the vector i.e stack is empty or not
        * It returns either 0 or 1
        * It is checked using empty() of vector
*/
using namespace std;

template <class T>
class Stack
{
    vector<T> stack_like;
public:
    int size()
    {
        return stack_like.size();
    }

    T pop()
    {
        T top = stack_like.back();
        stack_like.pop_back();
        return top;
    }

    void push(T val)
    {
        stack_like.push_back(val);
    }

    bool empty()
    {
        return stack_like.empty();
    }
};
int main()
{
    Stack<int> stack_like;

    int i;
    int n,input; //n - stores the number of inputs , input- stores the input value

    //inserting values into the stack like
    cout<<"Enter the number of values needed to be inserted in the stack: "<<endl;
    cin>>n;

    cout<<"\nEnter the values needed to be inserted in the stack: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>input;
        stack_like.push(input);
    }

    //displaying the size of the stack like
    cout<<"\nThe size of the stack is "<<stack_like.size()<<endl;

    //checking whether the stack is empty
    if(stack_like.empty())
        cout<<"\nThe stack is empty!"<<endl;
    else
        cout<<"\nThe stack is not empty! It is filled with "<<stack_like.size()<<" elements."<<endl;

    //display the values of the stack like
    int size_of_stack = stack_like.size();
    cout<<"\nThe values in the stack are: "<<endl;
    for(i = 0; i< size_of_stack; i++)
    {
        cout<<stack_like.pop()<<endl;
    }


    //checking whether the stack is empty after popping out all the elements
    if(stack_like.empty())
        cout<<"\nThe stack is empty!"<<endl;
    else
        cout<<"\nThe stack is not empty! It is filled with "<<stack_like.size()<<" elements."<<endl;

    return 0;
}
