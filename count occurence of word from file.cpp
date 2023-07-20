#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;
/*
To find the count of occurrences of word and display
Storing the words and their counts in map container 'occurence'
Opening a file where the texts are stored and the lines are fetched from the line using getline function
Storing the sentence and avoiding space using stringstream
After changing the words into lower case the occurence map is called and increased the count of occurence[word]
Display the word and count using display()
*/
void display(map<string,int> &occur)
{
    cout<<"Word -> Occurrence count"<<endl;
    for(auto &s:occur)
    {
        cout<<s.first<<" -> "<<s.second<<endl;
    }
}
int main()
{
    ifstream file("occurence.txt");
    if(!file.is_open())
        cout<<"Error in File opening!"<<endl;

    map<string,int> occurence;

    string line;

    while(getline(file,line))
    {
        stringstream string_input(line);

        string word;

        while(string_input >> word)
        {
            for(char &s: word)
            {
                s = tolower(s);
            }

            //incrementing the count of word by 1
            ++occurence[word];
        }
    }
    display(occurence);

    return 0;
}
