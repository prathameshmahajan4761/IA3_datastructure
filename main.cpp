#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <string>
using namespace std;

// PRN: 202501100189
// Seed: 189
// Scenario: Mango varieties
// Hashing: Mid-square method
// Collision handling: Separate chaining

const int SIZE = 17;

int midSquareHash(int key)
{
    int square = key * key;

    string s = to_string(square);

    while (s.length() < 4)
        s = "0" + s;

    int middle = stoi(s.substr(1, 2));

    return middle % SIZE;
}

void insertKey(vector<list<int>>& table, int key)
{
    int index = midSquareHash(key);

    if (!table[index].empty())
    {
        cout << "Collision detected at index "
             << index << endl;
    }
    else
    {
        cout << "No collision at index "
             << index << endl;
    }

    table[index].push_back(key);
}

void display(vector<list<int>>& table)
{
    cout << "\nIndex\tValues\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "\t";

        if (table[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (int key : table[i])
            {
                cout << key << " -> ";
            }
            cout << "NULL";
            cout << " | Total nodes: "
     << table[i].size();
        }

        cout << endl;
    }
}
void testHashFunction()
{
    int keys[] = {89, 2, 15};

    cout << "\nHash Function Testing\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "Key: " << keys[i]
             << " Hash Index: "
             << midSquareHash(keys[i]) << endl;
    }
}
void displayTableStructure()
{
    cout << "\nHash Table Structure\n";
    cout << "Total Buckets: " << SIZE << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Bucket " << i << endl;
    }
}
int main()
{
    int values[20] = {
        89, 2, 15, 28, 41,
        54, 67, 80, 93, 6,
        19, 32, 45, 58, 71,
        84, 97, 10, 23, 36
    };

    vector<list<int>> table(SIZE);
    testHashFunction();
    displayTableStructure();

    cout << "PRN: 202501100189\n";
    cout << "Mango Varieties Hash Table\n";

    for (int i = 0; i < 20; i++)
    {
        insertKey(table, values[i]);

        cout << "\nAfter inserting "
             << values[i] << ":\n";

        display(table);
    }

    cout << "\nFinal Hash Table:";
    display(table);

    return 0;
}