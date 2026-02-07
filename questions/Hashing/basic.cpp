#include <iostream>
using namespace std;
#define SIZE 10

int hashTable[SIZE];
// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

void insertKey() 
{
    int key;
    cout << "Enter key to insert: ";
    cin >> key;
    int index = hashFunction(key);
    for (int i = 0; i < SIZE; i++) 
    {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == -1 || hashTable[newIndex] == -2) 
        {
            hashTable[newIndex] = key;
            cout << "Key inserted at index " << newIndex << endl;
            return;
        }
    }
    cout << "Hash table is full!\n";
}

void searchKey() 
{
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    int index = hashFunction(key);
    for (int i = 0; i < SIZE; i++) 
    {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == key) 
        {
            cout << "Key found at index " << newIndex << endl;
            return;
        }
        if (hashTable[newIndex] == -1)
            break;
    }
    cout << "Key not found!\n";
}

void deleteKey() 
{
    int key;
    cout << "Enter key to delete: ";
    cin >> key;
    int index = hashFunction(key);
    for (int i = 0; i < SIZE; i++) 
    {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == key) 
        {
            hashTable[newIndex] = -2;   // marking deleted element as -2
            cout << "Key deleted from index " << newIndex << endl;
            return;
        }
        if (hashTable[newIndex] == -1)
            break;
    }
    cout << "Key not found!\n";
}

void display() 
{
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) 
    {
        if (hashTable[i] == -1)
            cout << "Index " << i << " : EMPTY\n";
        else if (hashTable[i] == -2)
            cout << "Index " << i << " : DELETED\n";
        else
            cout << "Index " << i << " : " << hashTable[i] << endl;
    }
}

int main() 
{
    int choice;
    // Initializing hash table with -1 as a default value indicating empty slot
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    do 
    {
        cout << "\n--- HASHING MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1: 
                insertKey(); break;
            case 2: 
                searchKey(); break;
            case 3: 
                deleteKey(); break;
            case 4: 
                display(); break;
            case 5: 
                cout << "Exiting...\n"; break;
            default: 
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
