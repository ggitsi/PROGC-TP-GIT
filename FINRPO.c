#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECIPES 7
#define MAX_NAME_LENGTH 50
#define MAX_DAYS 7
#define MAX_MENUS_PER_DAY 5
#define MAX_INGREDIENTS 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;   
    int pricePerGram; 
} Ingredient;

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

typedef struct {
    Ingredient storage[MAX_INGREDIENTS];
    int storageCount;
    int budget;
    MealPlanEntry mealPlan[MAX_DAYS * MAX_MENUS_PER_DAY];
    int mealPlanSize;
} Pantry;


void initializeRecipes(Recipe recipes[]);
void createMealPlan(MealPlan *plan, Recipe recipes[], int recipeCount);
void displayMealPlan(MealPlan *plan, Recipe recipes[], int recipeCount);
void displayRecipes(Recipe recipes[], int recipeCount);
int findIngredientIndex(Pantry *pantry, const char *name);
void buySingleIngredient(Pantry *pantry, int ingredientIndex);
void buyPackageIngredients(Pantry *pantry, Recipe recipes[], int recipeCount);

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

void displayIngredients(Pantry *pantry) {
    printf("\nIngredients in storage:\n");
    for (int i = 0; i < pantry->storageCount; i++) {
        printf("%d. %s: %d gr\n", i + 1, pantry->storage[i].name, pantry->storage[i].quantity);
    }
}

int findIngredientIndex(Pantry *pantry, const char *name) {
    for (int i = 0; i < pantry->storageCount; i++) {
        if (strcmp(pantry->storage[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int checkMealPlanCreated(Pantry *pantry) {
    return pantry->mealPlanSize > 0;
}

//membeli bahan
void buyIngredientsMenu(Pantry *pantry, Recipe recipes[], int recipeCount) {
    int choice;
    printf("\nMenu Beli Bahan:\n");
    printf("1. Beli bahan satuan\n");
    printf("2. Beli paket (berdasarkan meal plan terakhir)\n");
    printf("0. Kembali\n");
    printf("Pilih opsi: ");
    scanf("%d", &choice);
    

    if (choice == 1) {
        printf("\nBeli Bahan Satuan:\n");
        for (int i = 0; i < pantry->storageCount; i++) {
            printf("%d. %s (Harga Rp %d per gram)\n", i+1, pantry->storage[i].name, pantry->storage[i].pricePerGram);
        }
        int ingChoice;
        printf("Pilih bahan yang ingin dibeli: ");
        scanf("%d", &ingChoice);
      
        if (ingChoice < 1 || ingChoice > pantry->storageCount) {
            printf("Pilihan tidak valid!\n");
            return;
        }
        buySingleIngredient(pantry, ingChoice - 1);
    } else if (choice == 2) {
        if (!checkMealPlanCreated(pantry)) {
            printf("Meal plan belum dibuat. Silakan buat meal plan dulu sebelum beli paket bahan.\n");
            return;
        }
        buyPackageIngredients(pantry, recipes, recipeCount);
    } else if (choice == 0) {
        return;
    } else {
        printf("Pilihan tidak valid!\n");
    }
}

// fungsi beli bahan satuan
void buySingleIngredient(Pantry *pantry, int ingredientIndex) {
    printf("Masukkan jumlah gram yang ingin dibeli untuk %s: ", pantry->storage[ingredientIndex].name);
    int qty;
    scanf("%d", &qty);
    
    if (qty <= 0) {
        printf("Jumlah tidak valid!\n");
        return;
    }
    int cost = qty * pantry->storage[ingredientIndex].pricePerGram;
    if (cost > pantry->budget) {
        printf("Budget tidak cukup! Total biaya: Rp %d, Budget anda: Rp %d\n", cost, pantry->budget);
        return;
    }
    pantry->storage[ingredientIndex].quantity += qty;
    pantry->budget -= cost;
    printf("Pembelian sukses! %d gr %s ditambahkan. Sisa budget: Rp %d\n",
           qty, pantry->storage[ingredientIndex].name, pantry->budget);
}

//fungsi beli bahan yang kurang (Paketan)
void buyPackageIngredients(Pantry *pantry, Recipe recipes[], int recipeCount) {
    int needed[MAX_INGREDIENTS] = {0};
    int have[MAX_INGREDIENTS] = {0};
    int missing[MAX_INGREDIENTS] = {0};
    int totalCost = 0;

    for (int i = 0; i < pantry->storageCount; i++) {
        have[i] = pantry->storage[i].quantity;
    }

    for (int i = 0; i < pantry->mealPlanSize; i++) {
        MealPlanEntry *entry = &pantry->mealPlan[i];
        Recipe *rec = &recipes[entry->recipeIndex];
        for (int ing = 0; ing < rec->ingredientsCount; ing++) {
    int idx = findIngredientIndex(pantry, rec->ingredients[ing]);
    if (idx == -1) {
        strcpy(pantry->storage[pantry->storageCount].name, rec->ingredients[ing]);
        pantry->storage[pantry->storageCount].quantity = 0;
        pantry->storage[pantry->storageCount].pricePerGram = 100;
        idx = pantry->storageCount;
        pantry->storageCount++;
    }
    needed[idx] += rec->quantities[ing] * entry->servings;
}
    }

    for (int i = 0; i < pantry->storageCount; i++) {
        missing[i] = (needed[i] > have[i]) ? (needed[i] - have[i]) : 0;
    }

    printf("\nPembelian paket bahan diperlukan:\n");
    for (int i = 0; i < pantry->storageCount; i++) {
        if (missing[i] > 0) {
            printf("- %s: %d gr (Rp %d)\n", pantry->storage[i].name, missing[i], missing[i] * pantry->storage[i].pricePerGram);
            totalCost += missing[i] * pantry->storage[i].pricePerGram;
        }
    }
    printf("Total biaya pembelian paket: Rp %d\n", totalCost);

    if (totalCost == 0) {
        printf("Tidak ada bahan yang perlu dibeli, semua bahan cukup untuk meal plan.\n");
        return;
    }
    if (totalCost > pantry->budget) {
        printf("Budget Anda kurang untuk pembelian paket.\n");
        printf("Silakan tambah budget dulu.\n");
        return;
    }

    for (int i = 0; i < pantry->storageCount; i++) {
        if (missing[i] > 0) {
            pantry->storage[i].quantity += missing[i];
        }
    }
    pantry->budget -= totalCost;
    printf("Pembelian paket bahan berhasil!\nSisa budget: Rp %d\n", pantry->budget);
}