#include "List.h"
#include <string>
#include <iostream>
#include <list>

// Everything is done by Student - TEE YONG TENG S10198102

// Initialise constructor and set the size of Menu to 0 (Empty)
List :: List()
{
    menuSize = 0;
    orderSize = 0;
}

// Returns the size (number of items in the List) of Menu
int List :: returnMenuSize()
{
    return menuSize;
}

// Display all the items in the Linked List (Menu) by traversing down each Node (Menu) if applicable
void List :: displayMenu()
{
    int counter = 1;
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << counter << ") " << current->itemName  << ": SGD$" << current->price << endl;
            current = current->next;
            counter++;
        }
    }
}

// Traverse down each Node in the Linked List (Menu) to look for a matching itemID and display the selected item if matched
// Sequential Search as it is able to display the items clearer
void List :: retrieveSelectedMenu(int itemID)
{
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }
    else
    {
//        while (current != NULL && current->itemID != itemID)
//        {
//            current = current->next;
//        }
//        cout << current->itemName << "," << " SGD$" << current->price << endl;
        cout << current[itemID - 1].itemName << "," << " SGD$" << current[itemID - 1].price << endl;
    }
}

// Creates and add a new Menu item to the back of the Linked List (Menu)
bool List :: createMenuItem(int itemID, string cuisineType, string foodName, float price)
{
    Menu *newNode = new Menu;
    newNode->itemID = itemID;
    newNode->cuisineType = cuisineType;
    newNode->itemName = foodName;
    newNode->price = price;
    newNode->next = NULL;
    newNode->prevMenu = NULL;

    if(frontMenu == NULL || frontMenu->itemID == NULL)
    {
        frontMenu = newNode;
        menuSize+=1;
    }

    else
    {
        Menu *current = frontMenu;
        while(current->next != NULL)
        {
            current = current->next;
        }
        newNode->prevMenu = current;
        current->next = newNode;
        menuSize+=1;
    }
//    frontMenu = newNode;
}

// Traverse down the Node(Menu) and updates the Menu based on the inputs provided.
void List :: modifyMenu(int itemID, string cuisineType, string itemName, float price)
{
    Menu *current = frontMenu;

    while (current != NULL && current->itemID != itemID)
    {
        current = current->next;
    }
    current->cuisineType = cuisineType;
    current->itemName = itemName;
    current->price = price;

}

// Traverse down each Node in the Linked List (Menu) to look for a matching itemID and deletes the selected item if matched
// 3 Test Case: Deleting the first Menu item, Deleting the middle (random) Menu item , Deleting the last (bottom) Menu item
 bool List :: deleteMenu(int itemID)
{
    Menu *current = frontMenu;
    Menu *temp = NULL;

    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }

    else if (frontMenu->next == NULL) // If Menu have one Item
    {
        frontMenu = NULL;
    }

    else if (frontMenu->itemID == itemID)
    {
        temp = current;
        frontMenu = current->next;
        current->next->prevMenu = NULL;
    }

    else // If Menu have more than one Item
    {
        while (current != NULL && current->itemID != itemID)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            temp = current;
            current = current->prevMenu;
            current->next = NULL;
        }
        else // If Item is in the middle of first and last
        {
            temp = current;
            current = current->prevMenu;
            current->next = current->next->next;

//            while (current->itemID >= itemID or current->next->itemID >= itemID) // Traverse down from target item onwards to minus itemID by 1
//            {
//                if (current->next == NULL)
//                {
//                    break;
//                }
//                else
//                {
//                    current->next->itemID = current->next->itemID - 1; // Deduct itemID by 1
//                    current->next = current->next->next;  // Traverse to next node
//                }
//            }
        }
    }
    delete temp; // Deletes the target Menu item
    menuSize--;
}

// Returns the name of the Item based on the Item ID
string List :: returnItemName(int itemID)
{
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }
    else
    {
        while(current != NULL)
        {
            if(current->itemID == itemID)
            {
                return current->itemName;
            }
            current = current->next;
        }
    }
}

// Returns the cuisine type of the Item based on the Item ID
string List :: returnCuisineType(int itemID)
{
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }
    else
    {
        while(current != NULL)
        {
            if(current->itemID == itemID)
            {
                return current->cuisineType;
            }
            current = current->next;
        }
    }
}

// Returns the price of the Item based on the Item ID
float List :: returnPrice(int itemID)
{
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }
    else
    {
        while(current != NULL)
        {
            if(current->itemID == itemID)
            {
                return current->price;
            }
            current = current->next;
        }
    }
}

// Returns the size (number of items in the List) of Menu
int List ::returnOrderSize()
{
    return orderSize;
}

// Creates and add a new Order to the back of the Linked List (Order)
bool List :: createFoodOrder(int queueID, int quantity, string cuisineType, string foodName, float price)
{
    Node *newNode = new Node;
    newNode->queueID = queueID;
    newNode->quantity = quantity;
    newNode->cuisineType = cuisineType;
    newNode->foodName = foodName;
    newNode->price = price;
    newNode->next = NULL;
    newNode->prevNode = NULL;

    if(frontNode == NULL || frontNode->queueID == NULL)
    {
        frontNode = newNode;
        orderSize++;
    }

    else
    {
        Node *current = frontNode;
        while(current->next != NULL)
        {
            current = current->next;
        }
        newNode->prevNode = current;
        current->next = newNode;
        orderSize++;
    }
}

// Display all the items in the Linked List (Order) by traversing down each Node (Order) if applicable
void List :: displayFoodOrders()
{
    Node *current = frontNode;
    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << current->queueID << ": " << current->quantity << "x " << current->foodName  << ", SGD$" << current->price << endl;
            current = current->next;
        }
    }
}

// Traverse down each Node in the Linked List (Order) to look for a matching queueID and display the selected order if matched
void List :: retrieveFoodOrder(int queueID)
{
    Node *current = frontNode;
    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }
    else
    {
//        while (current != NULL && current->queueID != queueID)
//        {
//            current = current->next;
//        }
//        cout << current->quantity << "x " << current->foodName  << ", SGD$" << current->price << endl;
        cout << current[queueID - 1].quantity << "x " <<  current[queueID - 1].foodName  << ", SGD$" <<  current[queueID - 1].price << endl;
    }
}

// Traverse down the Node(Order) and update the Order based on the inputs provided.
bool List :: modifyFoodOrder(int queueID, int quantity, string cuisineType, string itemName, float price)
{
    Node *current = frontNode;
    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }
    else
    {
        while(current != NULL && current->queueID != queueID)
        {
            current = current->next;
        }
        current->quantity = quantity;
        current->cuisineType = cuisineType;
        current->foodName = itemName;
        current->price = price;
    }
}

// Traverse down each Node in the Linked List (Order) to look for a matching queueID and deletes the selected Order if matched
// 3 Test Case: Deleting the first Order, Deleting the middle (random) Order, Deleting the last (bottom) Order
bool List :: deleteFoodOrder(int queueID)
{
    Node *current = frontNode;
    Node *temp = NULL;

    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }

    else if(frontNode->next == NULL) // If Order List have one Item
    {
        frontNode = NULL;
    }

    else if(frontNode->queueID == queueID)
    {
        temp = current;
        frontNode = current->next;
        current->next->prevNode = NULL;
    }

    else // If Order have more than one Item
    {
        while(current != NULL && current->queueID != queueID)
        {
            current = current->next;
        }

        if(current->next == NULL)
        {
            temp = current;
            current = current->prevNode;
            current->next = NULL;
        }

        else
        {
            temp = current;
            current = current->prevNode;
            current->next = current->next->next;

            while (current->queueID != NULL) // Traverse down from target Order onwards to minus queueID by 1
            {
                if(current->next == NULL)
                {
                    current->queueID = current->queueID - 1; // Deduct queueID by 1
                    break;
                }

                current->next->queueID = current->next->queueID - 1; // Deduct queueID by 1
                current = current->next;  // Traverse to next node
            }
            current->queueID = current->queueID + 1; // Last index will always be the same as the second last index. Manual Addition.
        }
    }
    delete temp; // Deletes the target Order
    orderSize--;
}


