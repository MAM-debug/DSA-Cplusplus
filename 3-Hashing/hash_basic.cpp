#include <iostream>
using namespace std;


int hashfunction (int key,int tablesize)
{
    return key % tablesize;
}

int main()
{
    int key[]={8,15,22,29,36};
    int tablesize=7;
    for(int i=0;i<5;i++)
    {
        cout<<key[i]<<" -> "<<hashfunction(key[i],tablesize)<<endl;
    }
    return 0;
}