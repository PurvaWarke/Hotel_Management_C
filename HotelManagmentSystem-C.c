#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct MenuItem {
    char name[50];
    char category[20];
    float price;
}MenuItem;

typedef struct Order {
    MenuItem item;
    int quantity;
}Order;

int ctr;

void displayMenu(MenuItem*);
void hardcodedMenu(MenuItem*);
double calculateTotalBill(Order* , int);

void main()
{
    MenuItem menu[200];
    hardcodedMenu(menu);
    // sleep(10);
    displayMenu(menu);
    
    int orderSize;
    printf("\nEnter the number of items you want to order: ");
    scanf("%d", &orderSize);

    Order userOrder[orderSize];

    for (int i = 0; i < orderSize; i++)
    {
        int selectedItem;
		printf("\nEnter the item number you want to order from list(1 to %d): ", ctr);
        scanf("%d", &selectedItem);
//        selectedItem--; // Adjust for array indexing starting from 0

        userOrder[i].item = menu[selectedItem]; // Assign the selected menu item

        printf("\nEnter the quantity for item %d: ", i + 1);
        scanf("%d", &userOrder[i].quantity);
    }

    // Calculate and display the total bill
    double totalBill = calculateTotalBill(userOrder, orderSize);
    printf("|                               Total Bill                                      |        %.2lf        |\n",totalBill);
    printf("|------------------------------------------------------------------------------------------------------|\n");

//    printf("\nTotal Bill: %.2lf\n", totalBill);   
}

void hardcodedMenu(MenuItem* menu)
{
//    strcpy(menu[0].category, "South Indian");
//    strcpy(menu[0].name, "Idli Wada");
//    menu[0].price = 60;
//    ctr++;
//
//    strcpy(menu[1].category, "South Indian");
//    strcpy(menu[1].name, "Wada");
//    menu[1].price = 60;
//    ctr++;
//
//    strcpy(menu[2].category, "Panjabi");
//    strcpy(menu[2].name, "Paneer Butter");
//    menu[2].price = 60;
//    ctr++;
//
//    strcpy(menu[3].category, "Starter");
//    strcpy(menu[3].name, "Manchurian");
//    menu[3].price = 60;
//	ctr++;

    char* categories[] = {"South Indian", "South Indian", "South Indian", "South Indian", "South Indian", 
	"Starter", "Starter", "Starter", "Starter", "Starter", 
	"Chinese", "Chinese", "Chinese", "Chinese", "Chinese",
	"Soup", "Soup", "Soup", "Soup", "Soup",
	"Continental", "Continental", "Continental", "Continental", "Continental",
	"Panjabi Dishes", "Panjabi Dishes", "Panjabi Dishes", "Panjabi Dishes", "Panjabi Dishes",
	"Bhartiya Roti", "Bhartiya Roti", "Bhartiya Roti", "Bhartiya Roti", "Bhartiya Roti",
	"Rice", "Rice", "Rice", "Rice", "Rice"};
	
    char* names[] = {"Idli Wada", "Dosa", "Dahi Wada", "Puri Bhaji", "Pohe",
	"Rosted Papad", "Panner Manchurian", "Thai Paneer", "Crispy Paneer Thread", "Veg Crispy",
	"Manchow Soup", "Hot & Sour Soup", "Sweet Corn Soup", "Cream of Tomato Soup", "Lemon Coriender Soup",
	"Cheese Balls", "Spagetti Arbita", "Macroni Chesse Sauce", "Honey Chilli Potato", "Pesto Pasta",
	"Paneer Butter Masala", "Dal Fry", "Paneer Makhanwala", "Bhendi Fry", "Aloo Methi",
	"Javari Roti", "Tandoori Roti", "Naan", "Kulcha", "Shenga Poli",
	"Plain Rice", "Curd Rice", "Veg Pulav", "Dal Chawal Khichdi", "Kashmiri Pulav"};
	
    float prices[] = {60, 80, 60, 70, 35,
    30, 180, 180, 190, 170,
    70, 80, 70, 80, 80,
    140, 150, 150, 130, 150,
    170, 110, 150, 120, 140,
    20, 35, 55, 70, 60,
    100, 120, 160, 140, 150};

    for (int i = 0; i < 35; i++) 
	{
        strcpy(menu[i].category, categories[i]);
        strcpy(menu[i].name, names[i]);
        menu[i].price = prices[i];
        ctr++;
	}
}

void displayMenu(MenuItem* menu)
{
	printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu Category ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n|----------------------------------------------------------------|");
   	printf("\n|     Number   |             Item            |       Price       |\n");
	printf("|----------------------------------------------------------------|");
    for (int i = 0; i < ctr; i++)
	{
        printf("\n|       %-6d |    %-22s   |     %7.2f       |", i + 1, menu[i].name, menu[i].price);
    }
	printf("\n|----------------------------------------------------------------|\n");

}

double calculateTotalBill(Order* userOrder, int orderSize)
{
    double totalBill = 0;

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Order Details ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n|------------------------------------------------------------------------------------------------------|\n");
    printf("|              Item                 |   Quantity   |       Price Per Item       |       Subtotal       |\n");
    printf("|------------------------------------------------------------------------------------------------------|\n");

    for (int i = 0; i < orderSize; i++) 
	{
        double subtotal = userOrder[i].item.price * userOrder[i].quantity;

        printf("|      %-28s |      %-2d      |         %7.2f            |       %7.2f        |\n",
               userOrder[i].item.name, userOrder[i].quantity, userOrder[i].item.price, subtotal);

        totalBill = totalBill + subtotal;
    }

    printf("|------------------------------------------------------------------------------------------------------|\n");
    
    return totalBill;
}



