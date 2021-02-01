#ifndef ASSIGNMENT_NPEATS_H
#define ASSIGNMENT_NPEATS_H
#pragma once
#include<string>
#include<iostream>
#include <list>

using namespace std;
//
class NPEats
{
private:
    struct Node
    {
        int queueID;
        int quantity;
        string cuisineType;
        string foodName;
        float price;

        Node *next;	// pointer pointing to next item
    };

    struct Menu
    {
        int itemID;
        string cuisineType;
        string itemName;
        float price;

        Menu *next;
    };

    Node *frontNode;	// point to the first item
    Node *backNode;	// point to the last item

    Menu *frontMenu;	// point to the first item
    Menu *backMenu;	// point to the last item

public:
    int menuSize;

    NPEats();

//    ~NPEats();

    bool displayMenu();
    int returnMenuSize();
    bool createMenuItem(int, string, string, float);
    void modifyMenu(int, string, string, float);
    void retrieveSelectedMenu(int);

    string returnItemName(int);
    string returnCuisineType(int);
    float returnPrice(int);

    void displayFoodOrders();
    void retrieveFoodOrder(int);
    bool createFoodOrder(int, int, string, string, float);
    bool modifyFoodOrder(int, int, string, string, float);
    bool deleteFoodOrder(int);
};


#endif //ASSIGNMENT_NPEATS_H
