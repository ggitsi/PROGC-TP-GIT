#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "finproFunction.h"

#define MAX_RECIPES 7
#define MAX_NAME_LENGTH 50
#define MAX_DAYS 7
#define MAX_MENUS_PER_DAY 5
#define MAX_INGREDIENTS 20

//menyimpan nama, jumlah, dan harga bahan makanan
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;   
    int pricePerGram; 
} Ingredient;

//menyimpan bahan makanan yang diperlukan (resep) per menu
typedef struct {
    char name[MAX_NAME_LENGTH];
    Ingredient ingredients[5];
} Recipe;

//menyimpan meal plan : hari ke berapa, menu, dan porsi saji
typedef struct {
    int day;
    int recipeIndex;
    int servings;
} MealPlanEntry;

typedef struct {
    Ingredient storage[MAX_INGREDIENTS];
    int storageCount;
    int budget;
    MealPlanEntry mealPlan[MAX_DAYS * MAX_MENUS_PER_DAY];
    int mealPlanSize;
} Pantry;

int main() {
    Pantry pantry;
    Recipe recipes[MAX_RECIPES];

    initializePantry(&pantry);
    initializeRecipes(recipes);

    int choice;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Lihat Bahan Makanan\n");
        printf("2. Lihat Resep\n");
        printf("3. Add Budget\n");
        printf("4. Beli Bahan Makanan\n");
        printf("5. Buat Meal Plan\n");
        printf("6. Edit Meal Plan\n");
        printf("7. Lihat Meal Plan\n");
        printf("0. Exit\n");
        printf(">> ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                displayIngredients(&pantry);
                break;
            case 2:
                displayRecipes(recipes, MAX_RECIPES);
                break;
            case 3:
                addBudget(&pantry);
                break;
            case 4:
                buyIngredientsMenu(&pantry, recipes, MAX_RECIPES);
                break;
            case 5:
                createMealPlan(&pantry, recipes, MAX_RECIPES);
                break;
            case 6:
                editMealPlan(&pantry, recipes, MAX_RECIPES);
                break;
            case 7:
                displayMealPlan(&pantry, recipes, MAX_RECIPES);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}