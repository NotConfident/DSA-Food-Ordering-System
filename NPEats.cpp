#include "NPEats.h"
#include <string>
#include <iostream>
#include <list>

NPEats :: NPEats()
{
    menuSize = 0;
}

int NPEats :: returnMenuSize()
{
    return menuSize;
}

bool NPEats :: displayMenu()
{
    int counter = 1;
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
        return false;
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

void NPEats :: retrieveSelectedMenu(int itemID)
{
    Menu *current = frontMenu;
    if(current == NULL)
    {
        cout << "Menu is empty!" << endl;
    }
    else
    {
        while (current != NULL && current->itemID != itemID)
        {
            current = current->next;
        }
        cout << current->itemName << "," << " SGD$" << current->price << endl;
    }
}

bool NPEats :: createMenuItem(int itemID, string cuisineType, string foodName, float price)
{
    Menu *newNode = new Menu;
    newNode->itemID = itemID;
    newNode->cuisineType = cuisineType;
    newNode->itemName = foodName;
    newNode->price = price;
    newNode->next = NULL;

    if(frontMenu == NULL || frontMenu->itemID == NULL)
    {
        frontMenu = newNode;
        frontMenu->next = NULL;
        menuSize+=1;
    }

    else
    {
        Menu *current = frontMenu;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        menuSize+=1;
    }
    backMenu = newNode;
}

void NPEats :: modifyMenu(int itemID, string cuisineType, string itemName, float price)
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

string NPEats :: returnItemName(int itemID)
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
//                cout << "Found! " << current->itemID << ": SGD$" << current->price << endl;
                return current->itemName;
            }
            current = current->next;
        }
    }
}

string NPEats :: returnCuisineType(int itemID)
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

float NPEats :: returnPrice(int itemID)
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

bool NPEats :: createFoodOrder(int queueID, int quantity, string cuisineType, string foodName, float price)
{
    Node *newNode = new Node;
    newNode->queueID = queueID;
    newNode->quantity = quantity;
    newNode->cuisineType = cuisineType;
    newNode->foodName = foodName;
    newNode->price = price;
    newNode->next = NULL;

    if(frontNode == NULL || frontNode->queueID == NULL)
    {
        frontNode = newNode;
        frontNode->next = NULL;
    }

    else
    {
        Node *current = frontNode;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    backNode = newNode;
}

void NPEats :: displayFoodOrders()
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

void NPEats :: retrieveFoodOrder(int queueID)
{
    Node *current = frontNode;
    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }
    else
    {
        while (current != NULL && current->queueID != queueID)
        {
            current = current->next;
        }
        cout << current->quantity << "x " << current->foodName  << ", SGD$" << current->price << endl;
    }
}
bool NPEats :: modifyFoodOrder(int queueID, int quantity, string cuisineType, string itemName, float price)
{
    Node *current = frontNode;
    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }
    else
    {
        while (current != NULL && current->queueID != queueID)
        {
            current = current->next;
        }
        current->quantity = quantity;
        current->cuisineType = cuisineType;
        current->foodName = itemName;
        current->price = price;
    }
}

bool NPEats :: deleteFoodOrder(int queueID) // 3 Test Case: Deleting the order in queue, Deleting the middle order , Deleting the last (bottom) order.
{ // Currently unable to delete from middle then last.
    Node *current = frontNode;
    Node *temp = NULL;

    if(current == NULL)
    {
        cout << "Order list is empty!" << endl;
    }
    else if (frontNode->next == NULL)
    {
        frontNode = NULL;
    }

    else
    {
        while (current != NULL && current->queueID != queueID)
        {
            temp = current;
            current = current->next;
        }
        if (current->next == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = current->next;
//            current->next = temp->next;

            while (current->queueID >= queueID or current->next->queueID >= queueID) // Traverse down from target queue onwards
            {
                if (current->next == NULL)
                {
//                    current->queueID = current->queueID - 1; // If next node is NULL, stop traverse and break.
                    break;

                }
                else
                {
                    current->next->queueID = current->next->queueID - 1; // Deduct queueID by 1
                    current->next = current->next->next;  // Traverse to next node
                }
            }
        }
    }
    delete current; // Free up memory
}


