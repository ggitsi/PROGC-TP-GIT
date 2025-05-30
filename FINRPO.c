//library untuk seluruh fungsi yang ada di program meal plan
#include "finproFunction.h"

int main() {
    Pantry pantry;
    Recipe recipes[MAX_RECIPES];

    initializePantry(&pantry);
    initializeRecipes(recipes);

    int choice;

    printf("Selamat datang di program WEEKLY MEALPLAN\n");

    //menu untuk program meal plan
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