#include "item.h"

int main(int argc, char *argv[]) {
    int size = 5;
    Item *item_list = create_item_list(size);

    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1);
    add_item(item_list, 10.25, "31542", "snacks", "chips", 2);
    add_item(item_list, 7.40, "62345", "meat", "lb steak", 3);
    add_item(item_list, 4.00, "14512", "produce", "apples", 4);

    print_items(item_list, size);
    printf("Average price of items = %lf\n", average_price(item_list, size));

    if (argc > 1) {
        char *search_sku = argv[1];
        Item *found_item = find_item_by_sku(item_list, size, search_sku);
        if (found_item) {
            printf("Item found:\n");
            printf("Name: %s\nSKU: %s\nCategory: %s\nPrice: %lf\n",
                   found_item->name, found_item->sku, found_item->category, found_item->price);
        } else {
            printf("Item not found\n");
        }
    }

    free_items(item_list, size);
    return 0;
}

