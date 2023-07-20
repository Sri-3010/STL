#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
To find the longest increasing subsequence of an array using STL algorithms and container
1) Getting the array and calculating its size
2) Passing the array(arr) and the size of the array(n) to the function which calculates the LIS
3) LIS function:
    1) Creates a vector named lis and initialize with 1 of size of the array
    2) Traverse through the array and find if the next element of the current element is in increasing order
    3) If it is in creasing order increase the value of the current element in the corresponding index in the list
        with the value of the next element in the list + 1
    4) To find the longest increasing subsequence length find the maximum value in the list using maximum_element()
    5) To find which elements corresponds to that longest increasing subsequence find the indexes of the element
    6) Store the indexes in the vector named indeses
    7) Display the longest increasing subsequence length and the values in that LIS
*/

void LIS( int *arr, int n )
{
    int  i, j, max = 0;
    vector<int> lis(n);
    fill(lis.begin(),lis.end(),1);
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis.at(i) < lis.at(j) + 1)
                lis.at(i) = lis.at(j) + 1;
    max = *max_element(lis.begin(),lis.end());

    int tmp = max;
    vector<int> indexes;
    for( i = n - 1; i >= 0; --i )
    if( lis.at(i) == tmp )
    {
        indexes.push_back( i );
        --tmp;
    }
    reverse( indexes.begin(), indexes.end());
    cout<<"\nLength of the Longest Increasing Subsequence: "<<max<<endl;
    cout<<"\nThe values of the longest Increasing Subsequence is: "<<endl;
    for(auto s:indexes)
    {
        cout<<arr[s]<<endl;
    }
   /* Free memory to avoid memory leak */
   lis.clear();
   //return max;
}

int main()
{
    int arr[]={7 ,6 ,2 ,3 ,4 ,1 ,8 ,5 ,9 ,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    LIS(arr,n);

    return 0;
}
