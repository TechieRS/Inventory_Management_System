#include <stdio.h>
#include <string.h>

struct Item
{
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[100];
int itemCount = 0;

void addItem();
void updateQuantity();
void displayInventory();
void deleteItem();

int main()
{
    int choice;

    do
    {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Quantity\n");
        printf("3. Display Inventory\n");
        printf("4. Delete Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            updateQuantity();
            break;
        case 3:
            displayInventory();
            break;
        case 4:
            deleteItem();
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addItem()
{
    if (itemCount < 100)
    {
        printf("Enter item name: ");
        scanf(" %[^\n]%*c", inventory[itemCount].name);
        printf("Enter item quantity: ");
        scanf("%d", &inventory[itemCount].quantity);
        printf("Enter item price: ");
        scanf("%f", &inventory[itemCount].price);
        itemCount++;
        printf("Item added successfully!\n");
    }
    else
    {
        printf("Inventory is full!\n");
    }
}
void updateQuantity()
{
    char name[50];
    int quantity;
    printf("Enter item name to update quantity : ");
    scanf(" %[^\n]%*c", name);
    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            printf("Enter new quantity : ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            printf("Quantity updated suscessfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void displayInventory()
{
    if(itemCount == 0){
        printf("Inventory is empty!\n");
    } else
    {
        printf("\nInventory:\n");
        printf("%-20s %-15s %-10s\n","Name", "Quantity", "Price");
        for (int i = 0; i < itemCount; i++)
        {
            printf("%-20s %-15d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}


void deleteItem()
{
    char name[50];
    printf("Enter the item name to delete : ");
    scanf(" %[^\n]%*c", name);
    for (int i = 0; i < itemCount; i++)
    {
        if (strcmp(inventory[i].name, name) == 0)
        {
            for (int j = i; j < itemCount - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            return;
        }
    }
    printf("Item not found!\n");
}
