#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public:
        int noMhs;
        Node *next;
        Node *prev;
};

class DoubleLinkedList
{
    private:
        Node *START;

    public:
        DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEneter the roll number of the student: ";
        cin >> nim;

        //step 1: Allocate memory for new node
        Node *newNode = new Node();

        //step 2: Assign value to the data field
        newNode->noMhs = nim;

        //step 3: Insert at beginning if liist is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //step 4: newNode.next = start
            newNode->next = START;

            //step 5: START.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            //step 6: newNode.prev = NULL
            newNode->prev = NULL;

            //step 7: START = newNode
            START = newNode;
            return;
        }

        // insert in between node
        // step 8: locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            cout << "\nDuplicate roll numbers noy allowed" << endl;
            return;
        }

        // step 9: Insert between current and current->next
        newNode->next = current->next; // step 9a: newNode.next = current.next
        newNode->prev = current; // step 9b: newNode.prev = current

        // insert last node
        if (current->next != NULL)
            current->next->prev = newNode; // step 9c: current.next.prev = newNode
        current->next = newNode; // step 9d: current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        // step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs != rollNo)
        {
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        // step 2: if node is at the beginning
        if (current == START)
        {
            START = current->next; //step 2a: START = START.next
            if (START != NULL)
                START->prev = NULL; // step 2b: START.prev = NULL
        }
        else
        {
            //step 3: link previous node to next current
            current->prev->next = current->next;

            //step 4: if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        // step 5: Delete the node
        delete current;
        cout << "Record with roll number " << rollNo << " deleted " << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }
        // step 1: Mark first node as currentNode
        Node *currentNode = START;

        // step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of  roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            // step 3: move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void retraverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        // step 1: move to last node
        Node *currentNode = START;
        int i = 0;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            i++;
        }

        // step 2: Traverse baclward
        cout << "\nRecords in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << i + 1 << ". " << currentNode->noMhs << " " << endl;

            //step 3: move to previous node
            currentNode = currentNode->prev;
            i--;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        // step 1: Traverse to find matching roll number
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        // step 2: output result
        if (current != NULL)
        {
            cout << "Record not found\n";
        }
        else
        {
            cout << "Record found\n";
            cout << "Roll number: " << current->noMhs << endl;
        }
    }
};

int main()
{
    DoubleLinkedList list;
    char choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add record\n";
        cout << "2. Delete record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
                list.addNode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.retraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid option\n";
        }
        cout << "\nPress Enter to contiune...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
}