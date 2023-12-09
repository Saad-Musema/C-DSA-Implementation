#include<iostream>
#include<string>

using namespace std;

struct Node {
    string studentName;
    Node* next = nullptr;
};

// Structure for Doubly Linked List
struct DNode{
    string studentName;
    DNode* next = nullptr;
    DNode* previous = nullptr;
};

void insertAtBeginning(Node*& head, string name) {
    Node* newNode = new Node;
    newNode->studentName = name;
    newNode->next = head;
    head = newNode;
}

void insertAtBeginningD(DNode*& head, string name){
    DNode* newNode = new DNode;
    newNode->studentName = name;                                                                               
    newNode->next = head;
    if(head == nullptr){
        head = newNode;
        return;
    }else{
        head->previous = newNode;
        head = newNode;
    }
}

void insertAtEnd(Node*& head, string name){
    Node* newNode = new Node;
    newNode->studentName = name;
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while(current->next!=nullptr){
        current = current->next;
    }

    current->next = newNode;
}


void insertAtEndD(DNode*& head, string name) {
    DNode* newNode = new DNode;
    newNode->studentName = name;

    if (head == nullptr) {
        head = newNode;
    } else {
        DNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->previous = current;
    }
}



void insertAtMiddle(Node*& head, string name, int place){
    Node* current = head;
    for(int i=1; i<place-1; i++){  
        if(current->next==nullptr){
            cout<<"End of node reached at index "<< i;
            cout<<" Node added at end";
            // insertAtEnd(head, name);
            Node* newNode = new Node;
            newNode->studentName = name;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    Node* newNode = new Node;
    newNode->studentName = name;
    newNode->next = current->next;
    current->next = newNode;
};

void insertAtMiddleD(DNode*& head, string name, int place){
    DNode* current = head;
    for(int i=1; i<place-1; i++){
        current = current->next;
    }
    DNode* newNode = new DNode;
    newNode->studentName = name;
    current->next->previous = newNode;
    newNode->next = current->next;
    newNode->previous = current;
    current->next = newNode;
};

void deleteFromFirst(Node*& head){
    Node* newNode = new Node;
    if(head == nullptr){
        cout<<"Can not delete from empty list!";
        return;
    }
    newNode = head;
    head = newNode->next;
    delete newNode;
}


void deleteFromFirstD(DNode*& head){
    DNode* newNode = new DNode;
    if(head == nullptr){
        cout<<"Can not delete from empty list!";
        return;
    }
    head->previous = newNode;
    newNode = head;
    head = newNode->next;
    delete newNode;
}

// void deleteFromMiddle(Node*& head, string name){
//     Node* current = new Node;
//     while (current != nullptr && current->studentName != name) {
//         current = current->next;
//     }

//     if (current == nullptr) {
//         cout << "Node with name " << name << " not found!\n";
//         return;
//     }

//     if(current->next != nullptr){

//     }

// }

void deleteFromMiddle(Node*& head,string name) {
    if (head == nullptr) {
        cout << "Empty list. Cannot delete.\n";
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->studentName != name) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node with name " << name << " not found!\n";
        return;
    }

    // If the node to be deleted is the head
    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
}

void deleteFromMiddleD(DNode*& head, string name){
    DNode* current = head;
    while (current != nullptr && current->studentName != name) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node with name " << name << " not found!\n";
        return;
    }

    if (current->previous != nullptr) {
        current->previous->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->previous = current->previous;
    }

    delete current;

    cout << "Node with name " << name << " deleted.\n";
}


void displayFromFirst(Node* head) {
    Node* current = head;
    if (head == nullptr) {
        cout << "Empty List!";
    } else {
        while (current != nullptr) {
            cout << current->studentName << " -> ";
            current = current->next;
        }
    }
}

void displayFromFirstD(DNode* head){
    DNode* current = head;
    if (head == nullptr) {
        cout << "Empty List!";
    } else {
        while (current != nullptr) {
            cout << current->studentName << " -> ";
            current = current->next;
        }
    }
}

void displayFromLast(Node* head){
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next != NULL) {
        displayFromLast(head->next);
    }
    cout << head->studentName << " -> ";

    // if (head == nullptr) {
    //     cout << "Empty List!";
    // } else {
    //     Node* current = head;
    //     Node* end = head;
        
    //     //To get to the end of the LL
    //     while(end->next!= nullptr){
    //         if(end->next->next == nullptr){
    //             current = end;
    //         }
    //         end = end->next;
    //     }


    //     while(current->studentName!= end->studentName){

    //     }
    // }
}

void displayFromLastD(DNode* head){
    DNode* current = head;
    if (head == nullptr) {
        cout << "Empty List!";
    }else{
        while(current->next!= nullptr){
            current = current->next;
        }

        while(current!=nullptr){
            cout<< current->studentName << " -> ";
            current = current->previous;
        }
    }
}


void searchSingle(Node*& head, string name){
    int position = 0;
    Node* current = head;
    while(current->next!= nullptr){
        
        if(current->studentName ==  name){
            cout<<name<< " found at index "<< position;
            return;
        }
        current = current->next;
        position++;
    }

    cout << name <<" not found!";
}


void showMenu() {
    cout << "\t\t\t 1. Insert at the beginning\n";
    cout << "\t\t\t 2. Insert at the end\n";
    cout << "\t\t\t 3. Insert at the middle\n";
    cout << "\t\t\t 4. Delete the first node\n";
    cout << "\t\t\t 5. Delete the middle node\n";
    cout << "\t\t\t 6. Display from first to last\n";
    cout << "\t\t\t 7. Display from last to first\n";
    cout << "\t\t\t 8. Search for Student's name\n";
    cout << "\t\t\t 9. Back to the main menu\n";
    cout << "\n Enter Your Choice: ";
}

string inputName() {
    string name;
    cout << "Input name of student: ";
    cin >> name;
    return name;
}

int inputPlace() {
    int place;
    cout<< "Input position you want to add Node at: ";
    cin>>place;
    return place;
}

int main() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t----- Linked List Implementation -----\n";
        cout << "\t\t\t-----1. Use Singly Linked List\n";
        cout << "\t\t\t-----2. Use Doubly Linked List\n";
        cout << "\t\t\t-----3. Use Circular Linked List\n";
        cout << "\t\t\t 4. Exit\n";
        cout << "\t\t\t-------------------------------------------\n";
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Node* head = nullptr;
                int singlyChoice;
                do {
                    system("cls");
                    cout << "\t\t\t----- Operations on Singly Linked List -----\n";
                    showMenu();
                    cin >> singlyChoice;

                    switch (singlyChoice) {
                        case 1:
                            insertAtBeginning(head, inputName());
                            break;
                        case 2:
                            insertAtEnd(head, inputName());
                            break;
                        case 3:
                            insertAtMiddle(head, inputName(), inputPlace());
                            break;
                        case 4:
                            deleteFromFirst(head);
                            break;
                        case 5:
                            deleteFromMiddle(head, inputName());
                            break;
                        case 6:
                            displayFromFirst(head);
                            break;
                        case 7:
                            displayFromLast(head);
                            break;
                        case 8:
                            searchSingle(head, inputName());
                            break;
                        // Add other cases for singly linked list operations here
                    }

                    if (singlyChoice != 9) {
                        cout << "\nPress Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }

                } while (singlyChoice != 9);
                break;
            }

            case 2: {
                DNode* head = nullptr;
                int doublyChoice;
                do {
                    system("cls");
                    cout << "\t\t\t----- Operations on Doubly Linked List -----\n";
                    showMenu();
                    cin >> doublyChoice;

                    switch (doublyChoice)
                    {
                    case 1:
                        insertAtBeginningD(head, inputName());
                        break;
                    case 2:
                        insertAtEndD(head, inputName());
                        break;
                    case 3:
                        insertAtMiddleD(head, inputName(), inputPlace());
                        break;
                    case 4:
                        deleteFromFirstD(head);
                        break;
                    case 5:
                        deleteFromMiddleD(head, inputName());
                        break;
                    case 6:
                        displayFromFirstD(head);
                        break;
                    case 7:
                        displayFromLastD(head);
                        break;
                    default:
                        break;
                    }

                    if (doublyChoice != 8) {
                        cout << "\nPress Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }

                } while (doublyChoice != 8);
                break;
            }

            case 3: {
                int circularChoice;
                do {
                    system("cls");
                    cout << "\t\t\t----- Operations on Circular Linked List -----\n";
                    showMenu();
                    cin >> circularChoice;

                    // Add cases for circular linked list operations here

                    if (circularChoice != 8) {
                        cout << "\nPress Enter to continue...";
                        cin.ignore();
                        cin.get();
                    }

                } while (circularChoice != 8);
                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
