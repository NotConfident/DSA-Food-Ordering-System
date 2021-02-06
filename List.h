#ifndef ASSIGNMENT_LIST_H
#define ASSIGNMENT_LIST_H
#pragma once
#include<string>
#include<iostream>
#include <list>

// Everything is done by Student - TEE YONG TENG S10198102

using namespace std;

class List
{
private:
    struct Node // Order
    {   // Information
        int queueID;
        int quantity;
        string cuisineType;
        string foodName;
        float price;

        Node *next;	// Pointer pointing to next item
        Node *prevNode; // Pointer pointing to previous item
    };

    struct Menu
    {   // Information
        int itemID;
        string cuisineType;
        string itemName;
        float price;

        Menu *next; // Pointer pointing to next item
        Menu *prevMenu;	// Pointer pointing to previous item
    };

    Menu *frontMenu;	// Points to the previous item in Menu
    Menu *backMenu;

    Node *frontNode;	// Points to the first item in Order
    Node *backNode;	// Points to the first item in Order

public:
    int menuSize;
    int orderSize;

    List(); // Constructor

//    ~List();

    void displayMenu(); // Display Menu from the Linked List from the front to the back
    int returnMenuSize(); // Return the amount of items in the Menu.
    bool createMenuItem(int, string, string, float); // Adds an Menu item to the back of the List
    void modifyMenu(int, string, string, float); // Modifies and Update an Menu item in the List
    void retrieveSelectedMenu(int); // Returns a more detailed information on the selected Menu
    bool deleteMenu(int); // Remove and Delete an Menu item in the List

    string returnItemName(int); // Returns the name of the item in the Menu List
    string returnCuisineType(int); // Returns the cuisine type of the item in the Menu List
    float returnPrice(int); // Returns the price of the item in the Menu List

    int returnOrderSize(); // Return the amount of Order.
    void displayFoodOrders(); // Display Orders from the Linked List from the front to the back
    void retrieveFoodOrder(int); // Returns a more detailed information on the selected order
    bool createFoodOrder(int, int, string, string, float); // Adds an Order to the back of the List
    bool modifyFoodOrder(int, int, string, string, float); // Modifies and Update an Order in the List
    bool deleteFoodOrder(int); // Remove and Delete an Order in the List

    void reverseOrder();
};


#endif //ASSIGNMENT_LIST_H
