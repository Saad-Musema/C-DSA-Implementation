#include<iostream>

using namespace std;

// Define your linked list structures and functions here if needed


void showMenu(){
                cout << "\t\t\t 1. Insert at the beginning\n";
                cout << "\t\t\t 2. Insert at the end\n";
                cout << "\t\t\t 3. Insert at the middle\n";
                cout << "\t\t\t 4. Delete the first node\n";
                cout << "\t\t\t 5. Delete the middle node\n";
                cout << "\t\t\t 6. Display from first to last\n";
                cout << "\t\t\t 7. Display from last to first\n";
                cout << "\t\t\t 8. Back to main menu\n";
                cout << "\n Enter Your Choice: ";
}

int main(){

    int choice;
    do {
        char x;
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
                cout << "\t\t\t----- Operations on Singly Linked List -----\n";
                int singlyChoice;
                showMenu();
                cin >> singlyChoice;

                switch (singlyChoice) {
                    // Implement cases for singly linked list operations here
                }
                break;
            }

            case 2: {
                cout << "\t\t\t----- Operations on Doubly Linked List -----\n";
                int doublyChoice;
                showMenu();
                cin >> doublyChoice;

                switch (doublyChoice) {
                    // Implement cases for doubly linked list operations here
                }
                break;
            }

            case 3: {
                cout << "\t\t\t----- Operations on Circular Linked List -----\n";
                int circularChoice;
                showMenu();
                cin >> circularChoice;

                switch (circularChoice) {
                    // Implement cases for circular linked list operations here
                }
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
