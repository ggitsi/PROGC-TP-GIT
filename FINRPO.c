#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPES 7
#define MAX_NAME_LENGTH 50
#define MAX_DAYS 7
#define MAX_MENUS_PER_DAY 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int ingredientsCount;
    char ingredients[5][MAX_NAME_LENGTH];
    int quantities[5];
} Recipe;

typedef struct {
    int day;
    int recipeIndex;
    int servings;
} MealPlanEntry;

typedef struct {
    MealPlanEntry mealPlan[MAX_DAYS * MAX_MENUS_PER_DAY];
    int mealPlanSize;
} MealPlan;

void initializeRecipes(Recipe recipes[]);
void createMealPlan(MealPlan *plan, Recipe recipes[], int recipeCount);
void displayMealPlan(MealPlan *plan, Recipe recipes[], int recipeCount);
void displayRecipes(Recipe recipes[], int recipeCount);

int main() {
    Recipe recipes[MAX_RECIPES];
    MealPlan plan;
    plan.mealPlanSize = 0;

    initializeRecipes(recipes);

    int choice;
    do {
        printf("\n=== Menu ===\n");
        printf("1. Buat Meal Plan\n");
        printf("2. Lihat Meal Plan\n");
        printf("3. Lihat Daftar Resep\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        } else {
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1:
                createMealPlan(&plan, recipes, MAX_RECIPES);
                break;
            case 2:
                displayMealPlan(&plan, recipes, MAX_RECIPES);
                break;
            case 3:
                displayRecipes(recipes, MAX_RECIPES);
                break;
            case 0:
                printf("Terima kasih telah menggunakan program ini.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 0);

    return 0;
}

//display menu + resep
void displayRecipes(Recipe recipes[], int recipeCount) {
    printf("\nDaftar Resep:\n");
    for (int i = 0; i < recipeCount; i++) {
        printf("%d. %s\n", i + 1, recipes[i].name);
        for (int j = 0; j < recipes[i].ingredientsCount; j++) {
            printf("    - %s: %d gram\n", recipes[i].ingredients[j], recipes[i].quantities[j]);
        }
    }
}

//simpan resep
void initializeRecipes(Recipe recipes[]) {
    strcpy(recipes[0].name, "Ayam Rica-Rica");
    recipes[0].ingredientsCount = 5;
    strcpy(recipes[0].ingredients[0], "Daging Ayam"); recipes[0].quantities[0] = 150;
    strcpy(recipes[0].ingredients[1], "Cabai Merah Keriting"); recipes[0].quantities[1] = 20;
    strcpy(recipes[0].ingredients[2], "Bawang Merah"); recipes[0].quantities[2] = 15;
    strcpy(recipes[0].ingredients[3], "Bawang Putih"); recipes[0].quantities[3] = 10;
    strcpy(recipes[0].ingredients[4], "Tomat"); recipes[0].quantities[4] = 25;

    strcpy(recipes[1].name, "Ayam Bumbu Kuning");
    recipes[1].ingredientsCount = 5;
    strcpy(recipes[1].ingredients[0], "Daging Ayam"); recipes[1].quantities[0] = 150;
    strcpy(recipes[1].ingredients[1], "Kunyit"); recipes[1].quantities[1] = 5;
    strcpy(recipes[1].ingredients[2], "Bawang Merah"); recipes[1].quantities[2] = 15;
    strcpy(recipes[1].ingredients[3], "Bawang Putih"); recipes[1].quantities[3] = 10;
    strcpy(recipes[1].ingredients[4], "Serai"); recipes[1].quantities[4] = 5;

    strcpy(recipes[2].name, "Ayam Suwir Balado");
    recipes[2].ingredientsCount = 5;
    strcpy(recipes[2].ingredients[0], "Ayam Suwir"); recipes[2].quantities[0] = 150;
    strcpy(recipes[2].ingredients[1], "Cabai Merah"); recipes[2].quantities[1] = 25;
    strcpy(recipes[2].ingredients[2], "Bawang Merah"); recipes[2].quantities[2] = 15;
    strcpy(recipes[2].ingredients[3], "Bawang Putih"); recipes[2].quantities[3] = 10;
    strcpy(recipes[2].ingredients[4], "Tomat"); recipes[2].quantities[4] = 20;

    strcpy(recipes[3].name, "Ayam Kecap Pedas");
    recipes[3].ingredientsCount = 5;
    strcpy(recipes[3].ingredients[0], "Daging Ayam"); recipes[3].quantities[0] = 150;
    strcpy(recipes[3].ingredients[1], "Kecap Manis"); recipes[3].quantities[1] = 15;
    strcpy(recipes[3].ingredients[2], "Cabai Merah Keriting"); recipes[3].quantities[2] = 15;
    strcpy(recipes[3].ingredients[3], "Bawang Merah"); recipes[3].quantities[3] = 15;
    strcpy(recipes[3].ingredients[4], "Bawang Putih"); recipes[3].quantities[4] = 10;

    strcpy(recipes[4].name, "Ayam Cabe Ijo");
    recipes[4].ingredientsCount = 5;
    strcpy(recipes[4].ingredients[0], "Daging Ayam"); recipes[4].quantities[0] = 150;
    strcpy(recipes[4].ingredients[1], "Cabai Hijau Besar"); recipes[4].quantities[1] = 20;
    strcpy(recipes[4].ingredients[2], "Bawang Merah"); recipes[4].quantities[2] = 15;
    strcpy(recipes[4].ingredients[3], "Bawang Putih"); recipes[4].quantities[3] = 10;
    strcpy(recipes[4].ingredients[4], "Tomat Hijau"); recipes[4].quantities[4] = 20;

    strcpy(recipes[5].name, "Semur Ayam");
    recipes[5].ingredientsCount = 5;
    strcpy(recipes[5].ingredients[0], "Daging Ayam"); recipes[5].quantities[0] = 150;
    strcpy(recipes[5].ingredients[1], "Kecap Manis"); recipes[5].quantities[1] = 20;
    strcpy(recipes[5].ingredients[2], "Bawang Merah"); recipes[5].quantities[2] = 15;
    strcpy(recipes[5].ingredients[3], "Bawang Putih"); recipes[5].quantities[3] = 10;
    strcpy(recipes[5].ingredients[4], "Tomat"); recipes[5].quantities[4] = 20;

    strcpy(recipes[6].name, "Ayam Goreng Lengkuas");
    recipes[6].ingredientsCount = 5;
    strcpy(recipes[6].ingredients[0], "Daging Ayam"); recipes[6].quantities[0] = 150;
    strcpy(recipes[6].ingredients[1], "Lengkuas (Parut)"); recipes[6].quantities[1] = 15;
    strcpy(recipes[6].ingredients[2], "Bawang Putih"); recipes[6].quantities[2] = 10;
    strcpy(recipes[6].ingredients[3], "Bawang Merah"); recipes[6].quantities[3] = 10;
    strcpy(recipes[6].ingredients[4], "Minyak Goreng"); recipes[6].quantities[4] = 300;
}

void createMealPlan(MealPlan *plan, Recipe recipes[], int recipeCount) {
    int days;
    printf("Masukkan jumlah hari untuk meal plan (maks %d): ", MAX_DAYS);
    scanf("%d", &days);
   
    if (days < 1 || days > MAX_DAYS) {
        printf("Jumlah hari tidak valid!\n");
        return;
    }
    int totalEntries = 0;
    for (int d = 0; d < days; d++) {
        int menus, selRecipe, porsi;
        printf("Hari %d\n", d+1);
        printf("Berapa menu yang ingin dimasak? (maks %d): ", MAX_MENUS_PER_DAY);
        scanf("%d", &menus);
        
        if (menus < 1 || menus > MAX_MENUS_PER_DAY) {
            printf("Jumlah menu tidak valid!\n");
            return;
        }
        for (int m = 0; m < menus; m++) {
            printf("Daftar resep:\n");
            for (int i = 0; i < recipeCount; i++) {
                printf("%d. %s\n", i + 1, recipes[i].name);
            }
            printf("Pilih resep untuk menu ke-%d: ", m + 1);
            scanf("%d", &selRecipe);
            
            if (selRecipe < 1 || selRecipe > recipeCount) {
                printf("Resep tidak valid!\n");
                return;
            }
            printf("Berapa porsi?: ");
            scanf("%d", &porsi);
           
            if (porsi < 1) {
                printf("Porsi tidak valid!\n");
                return;
            }
            if (totalEntries >= MAX_DAYS * MAX_MENUS_PER_DAY) {
                printf("Meal plan sudah penuh!\n");
                return;
            }
            plan->mealPlan[totalEntries].day = d + 1;
            plan->mealPlan[totalEntries].recipeIndex = selRecipe - 1;
            plan->mealPlan[totalEntries].servings = porsi;
            totalEntries++;
        }
    }
    plan->mealPlanSize = totalEntries;
    printf("Meal plan berhasil dibuat.\n");
}

void displayMealPlan(MealPlan *plan, Recipe recipes[], int recipeCount) {
    if (plan->mealPlanSize == 0) {
        printf("Meal plan belum dibuat.\n");
        return;
    }
    printf("\nMeal Plan:\n");
    int currentDay = -1;
    for (int i = 0; i < plan->mealPlanSize; i++) {
        if (plan->mealPlan[i].day != currentDay) {
            currentDay = plan->mealPlan[i].day;
            printf("Hari %d:\n", currentDay);
        }
        printf("  - %s: %d porsi\n", recipes[plan->mealPlan[i].recipeIndex].name, plan->mealPlan[i].servings);
    }
}
