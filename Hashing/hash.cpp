#include <iostream>
using namespace std;
const int TABLE_SIZE = 10;
class hashtable
{
    int table[TABLE_SIZE];

public:
    hashtable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = -1;
        }
    }
    int hashFunc(int key)
    {
        return key % TABLE_SIZE;
    }
    void insert(int key)
    {
        int index = hashFunc(key);
        int start = index;
        while (table[index] != -1)
        {
            index = (index + 1) % TABLE_SIZE;
            if (index == start)
            {
                cout << "Error: Hash table is full. Cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
    }
    void display()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << " --> " << table[i] << endl;
        }
    }
};
int main()
{
    hashtable h;
    h.insert(10);
    h.insert(22);
    h.insert(30);
    h.insert(44);
    h.insert(55);
    h.insert(70);
    h.insert(90);
    h.insert(100);
    h.insert(110);
    h.insert(120);
    h.insert(130);
    h.display();
    return 0;
}