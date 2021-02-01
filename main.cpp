#include <iostream>
#include "NPEats.h"
#include "list"

using namespace std;

NPEats eats;
int input;
int counter = 1;

int main()
{
    void printMenuSelection();
    void printFoodSelection();
    void printMainMenu();

    bool inputOne();
    bool inputTwo();

    // Default Menu
    eats.createMenuItem(1, "Western", "Chicken Chop", 5.5);
    eats.createMenuItem(2, "Chinese", "Xiao Long Bao (6pcs)", 3.5);
    eats.createMenuItem(3, "Italian", "Parmesan Aglio Olio", 5.0);

    printMainMenu();

    while(true)
    {
        cout << "Enter your option: ";
        cin >> input;

        if (input == 1)
        {
            inputOne();
        }

        if (input == 2)
        {
            inputTwo();
        }

        if (input == 0)
        {
            break;
        }
    }
}

void printMainMenu()
{
    cout << endl;
    cout << "********************************************" << endl;
    cout << "***                1. Menu               ***" << endl;
    cout << "***                2. Order              ***" << endl;
    cout << "***                0. Exit               ***" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void printMenuSelection()
{
    cout << endl;
    cout << "********************************************" << endl;
    cout << "***              1. View Menu            ***" << endl;
    cout << "***              2. Create Menu          ***" << endl;
    cout << "***              3. Modify Menu          ***" << endl;
    cout << "***              4. Delete Menu          ***" << endl;
    cout << "***              0. Exit                 ***" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void printFoodSelection()
{
    cout << endl;
    cout << "********************************************" << endl;
    cout << "***           1. Create Order            ***" << endl;
    cout << "***           2. View Orders             ***" << endl;
    cout << "***           3. Modify Orders           ***" << endl;
    cout << "***           4. Delete Orders           ***" << endl;
    cout << "***           0. Exit                    ***" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

bool inputOne()
{
    bool inputTwo();

    printMenuSelection();

    cout << "Enter your option: ";
    cin >> input;
    cout << endl;

    if (input == 1)
    {
        eats.displayMenu();
        cout << endl;
        cout << "0) Back to options";

        cout << endl;
        cout << endl;
        cout << "Enter your option: ";
        cin >> input;
        cout << endl;

        if(input == 0)
        {
            inputOne();
        }

    }

    if(input == 2)
    {
        string cuisineType;
        string ItemName;
        float price;

        cout << "Enter Cuisine Type: ";
        cin >> cuisineType;

        cout << "Enter Item Name: ";
        cin >> ItemName;

        cout << "Enter Price: ";
        cin >> price;

        eats.createMenuItem(eats.returnMenuSize() + 1,  cuisineType, ItemName, price);
        cout << endl;
        cout << "Food Item(s) added to Menu." << endl;
        inputOne();
    }

    if (input == 3)
    {
        string cuisineType;
        string ItemName;
        float price;

        eats.displayMenu();

        cout << endl;
        cout << "Item to Modify: ";
        cin >> input;
        cout << endl;

        cout << "Item Retrieved: ";
        eats.retrieveSelectedMenu(input);
        cout << endl;

        cout << "Enter Item Name: ";
        cin.ignore();
        getline(cin, ItemName, '\n');

        cout << "Enter Cuisine Type: ";
        getline(cin, cuisineType, '\n');

        cout << "Enter Price: ";
        cin >> price;

        eats.modifyMenu(input, cuisineType, ItemName, price);

        cout << endl;

        cout << "Item has been updated to: ";
        eats.retrieveSelectedMenu(input);
        cout << endl;

        inputOne();
    }

    if (input == 0)
    {
        printMainMenu();

        cout << endl;
        cout << "Enter your option: ";
        cin >> input;

        if (input == 1)
        {
            inputOne();
        }

        if(input == 2)
        {
            inputTwo();
        }
    }
}

bool inputTwo()
{
    int foodSelection;
    int quantity;
    string foodReturned;
    string typeReturned;
    float priceReturned;

    printFoodSelection();

    cout << "Enter your option: ";
    cin >> input;

    if(input == 1)
    {
        eats.displayMenu();
        cout << endl;
        cout << "0) Back to options";
        cout << endl;

        cout << endl;
        cout << "Choose the food desired: ";
        cin >> foodSelection;

        if (foodSelection == 0)
        {
            inputTwo();
        }

        foodReturned = eats.returnItemName(foodSelection);
        typeReturned = eats.returnCuisineType(foodSelection);
        priceReturned = eats.returnPrice(foodSelection);

        cout << "Quantity: ";
        cin >> quantity;

        eats.createFoodOrder(counter, quantity, typeReturned, foodReturned, priceReturned * quantity);
        counter++;

        cout << endl;
        cout << "Order Placed!" << endl;
        inputTwo();
    }

    if (input == 2)
    {
        cout << endl;
        eats.displayFoodOrders();
        inputTwo();
    }

    if (input == 3)
    {
        int newItem;
        int newQuantity;

        string itemReturned;
        string quantityReturned;
        float priceReturned;
        string typeReturned;

        eats.displayFoodOrders();

        cout << endl;
        cout << "Item to Modify: ";
        cin >> input;

        cout << "Order Chosen: ";
        eats.retrieveSelectedMenu(input);
        cout << endl;

        eats.displayMenu();
        cout << endl;

        cout << "Select the food desired: ";
        cin >> newItem;

        cout << "Enter Quantity: ";
        cout << endl;

        cin >> newQuantity;
        cout << endl;

        itemReturned = eats.returnItemName(newItem);
        typeReturned = eats.returnCuisineType(newItem);
        priceReturned = eats.returnPrice(newItem);

        eats.modifyFoodOrder(input, newQuantity, typeReturned, itemReturned, priceReturned * newQuantity);

        cout << "Your order has been updated to: ";
        eats.retrieveFoodOrder(input);
        cout << endl;

        inputTwo();
    }

    if (input == 4)
    {
            eats.displayFoodOrders();

            cout << endl;
            cout << "Select order to delete: ";
            cin >> input;

            eats.deleteFoodOrder(input);
            counter--;

            cout << endl;
            cout << "Order has been deleted" << endl;

            cout << endl;
            eats.displayFoodOrders();
            inputTwo();
    }

    if (input == 0)
    {
        printMainMenu();

        cout << endl;
        cout << "Enter your option: ";
        cin >> input;

        if (input == 1)
        {
            inputOne();
        }

        if (input == 2)
        {
            inputTwo();
        }
    }
}