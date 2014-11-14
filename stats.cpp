#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    int odds[500];
    int evens[500];
    int ordered[500];
    int graph[500][20] = {0};
    int graphOneD = 0;
    int graphTwoD = 0;
    int freq[500] = {0};
    int evenCounter = 0;
    int oddCounter = 0;
    int orderedCounter = 0;
    int maxFreq = 0;
    ifstream inFile;
    ofstream outFile;

    inFile.open("data.txt");
    outFile.open("output.txt");

    inFile>>number;
    for(int i = 0;!inFile.eof(); i++)
    {
        ordered[i] = number;
        orderedCounter++;
        if(number % 2 == 0)
        {
            evens[evenCounter] = number;
            evenCounter++;
        }
        else
        {
            odds[oddCounter] = number;
            oddCounter++;
        }

        inFile>>number;
    }
    std::sort(ordered, ordered + orderedCounter);
    graph[graphOneD][graphTwoD] = ordered[0];
    for (int i = 0; i < orderedCounter; i++)
    {
        if(ordered[i] == graph[graphOneD][graphTwoD])
        {
            graphTwoD++;
            graph[graphOneD][graphTwoD] = ordered[i];
            if ((graphTwoD + 1) > maxFreq) maxFreq = (graphTwoD + 1);
            freq[graphOneD] += 1;
        }
        else
        {
            graphTwoD = 0;
            graphOneD++;
            graph[graphOneD][graphTwoD] = ordered[i];
            freq[graphOneD] = 1;
        }
    }
    for (int i = maxFreq + 4; i > 0; i--)
    {   cout<<"|";
        for (int j = 0; j <= graphOneD; j++)
        {
            if(graph[j][0] == 0 && freq[j] < i)cout<<":";
            else if(freq[j] >= i) cout<<"*";
            else cout<<" ";
            cout<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0; i <= graphOneD; i++)
    {
        if(i == 0)cout<<graph[i][0];
        else if(graph[i][0] == 0)cout<<"0";
        else if(i == graphOneD / 2) cout<<graph[graphOneD][0]/2;
        else if(i == graphOneD -1) cout<<graph[graphOneD][0];
        else cout<<" ";
        cout<<" ";
    }
    inFile.close();
    outFile.close();
    return 0;
}
