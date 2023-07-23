#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>

using namespace std;
/*
to find the kth smallest element in the priority queue
get the elements of the vector from the user
in the function kthsmallestelement insert the elements of the vector in the ascending order
pop out the elements of size greater than k
return the top element of the priority Queue

*/

int kthsmallestElement(vector<int> &vec,int k)
{
    priority_queue<int, vector<int>> priorityQueue;

    for(int s:vec)
    {
        priorityQueue.push(s);
        if(priorityQueue.size() > k)  //pop out the items greater than k value
            priorityQueue.pop();
    }

    return priorityQueue.top(); //return the kth smallest element
}

int main()
{
    int sizeOfQueue,k,i;



    cout<<"Enter the size of the Queue: ";
    cin>>sizeOfQueue;

    vector<int> priorityQ(sizeOfQueue);
    cout<<"\nEnter the Queue elements: "<<endl;
    for(i = 0;i<sizeOfQueue;i++)
        cin>>priorityQ[i];

    cout<<"Enter the kth element to be found: ";
    cin>>k;

    int kthsmall = kthsmallestElement(priorityQ,k);

    cout<<"The "<<k<<"th smallest element is "<<kthsmall<<endl;

    return 0;
}
