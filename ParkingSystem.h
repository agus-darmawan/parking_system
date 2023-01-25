#include "stdio.h"
#include "stdlib.h"

#define LENGTH_PARKING_LOT 10
#define WIDTH_PARKING_LOT 100

enum vehicle_type {
    SCOOTER = 1,
    CAR = 2,
    BUS = 3,
    TRUCK = 4
} ;

struct vehicle_count{
    int scooter ; 
    int car ;
    int bus ;
    int truck ;
    int vehicle ;
} ;

struct vehicle{ 
    char *name;  
    int num ;
    int row ;
    int col ;
    int type ;
    struct vehicle_count vc;
} ;

struct vehicle add(struct vehicle v, char *name,int num, int row, int col, int type) {
    v.name = name;
    v.num = num ;
    v.row = row ;
    v.col = col ;
    v.type = type ;
        if (type == 1) {
            v.vc.scooter++;
        } else if (type == 2) {
            v.vc.car++ ;
        } else if (type == 3) {
            v.vc.bus++ ;
        } else if (type == 4) {
            v.vc.truck++ ;
        }
        v.vc.vehicle++ ;
    return v ;
}

void clear(){
    system("clear");
}

void search(struct vehicle v) {
    clear();
    printf("Search Vehicle \n");
    printf("Search by : \n");
    printf("1. Vehicle Name \n");
    printf("2. Vehicle Number \n");
    printf("3. Vehicle Row \n");
    printf("4. Vehicle Col \n");
    printf("5. Vehicle Type \n");
    printf("Select Search by : ");
    int search;
    scanf("%d", &search);
    switch (search) {
        case 1:
            printf("Vehicle Name : %s \n", v.name);
            break;
        case 2:
            printf("Vehicle Number : %d \n", v.num);
            break;
        case 3:
            printf("Vehicle Row : %d \n", v.row);
            break;
        case 4:
            printf("Vehicle Col : %d \n", v.col);
            break;
        case 5:
            printf("Vehicle Type : %d \n", v.type);
            break;
        default:
            printf("Error \n");
            break;
    }
}

void delete(struct vehicle *v) {
    clear();
    printf("Delete Vehicle \n");
    printf("Delate by : \n");
    printf("1. Vehicle Name \n");
    printf("2. Vehicle Number \n");
    printf("3. Vehicle Row and Col \n");
    printf("4. Vehicle Type \n");
    printf("Select Delete by : ");
    int del;
    scanf("%d", &del);
    switch (del) {
        case 1:
            printf("Vehicle Name : %s \n", v->name);
             printf("Enter the Name of Vehicle to Delete : ");
            char name[100];
            scanf("%s", name);
            if (v->name == name) {
                v->name = NULL;
                v->num = 0;
                v->row = 0;
                v->col = 0;
                v->type = 0;
                if (v->type == 1) {
                    v->vc.scooter--;
                } else if (v->type == 2) {
                    v->vc.car-- ;
                } else if (v->type == 3) {
                    v->vc.bus-- ;
                } else if (v->type == 4) {
                    v->vc.truck-- ;
                }
            }
            break;
        case 2:
            printf("Vehicle Number : %d \n", v->num);
            printf("Enter the Number of Vehicle to Delete : ");
            int num;
            scanf("%d", &num);
            if (v->num == num) {
                v->name = NULL;
                v->num = 0;
                v->row = 0;
                v->col = 0;
                v->type = 0;
                if (v->type == 1) {
                    v->vc.scooter--;
                } else if (v->type == 2) {
                    v->vc.car-- ;
                } else if (v->type == 3) {
                    v->vc.bus-- ;
                } else if (v->type == 4) {
                    v->vc.truck-- ;
                }
            }
            break;
        case 3:
            printf("Delete by Row and Col \n");
            printf("Enter the Row of Vehicle to Delete : ");
            int row;
            scanf("%d", &row);
            printf("Enter the Col of Vehicle to Delete : ");
            int col;
            scanf("%d", &col);
            if (v->row == row && v->col == col) {
                v->name = NULL;
                v->num = 0;
                v->row = 0;
                v->col = 0;
                v->type = 0;
                if (v->type == 1) {
                    v->vc.scooter--;
                } else if (v->type == 2) {
                    v->vc.car-- ;
                } else if (v->type == 3) {
                    v->vc.bus-- ;
                } else if (v->type == 4) {
                    v->vc.truck-- ;
                }
            break;
        case 4:
            printf("Vehicle Type : %d \n", v->type);
            printf("Enter the Type of Vehicle to Delete : ");
            int type;
            scanf("%d", &type);
            if (v->type == type) {
                v->name = NULL;
                v->num = 0;
                v->row = 0;
                v->col = 0;
                v->type = 0;
                if (v->type == 1) {
                    v->vc.scooter--;
                } else if (v->type == 2) {
                    v->vc.car-- ;
                } else if (v->type == 3) {
                    v->vc.bus-- ;
                } else if (v->type == 4) {
                    v->vc.truck-- ;
                }
            }
            break;
        default:
            printf("Error \n");
            break;
    }
    }
}

void savedata(struct vehicle v) {
    FILE *fptr;
    fptr = fopen("data.txt", "w");
    fprintf(fptr, "Vehicle Name : %s \n", v.name);
    fprintf(fptr, "Vehicle Number : %d \n", v.num);
    fprintf(fptr, "Vehicle Row : %d \n", v.row);
    fprintf(fptr, "Vehicle Col : %d \n", v.col);
    fprintf(fptr, "Vehicle Type : %d \n", v.type);
    fprintf(fptr, "Vehicle Count : %d \n", v.vc.vehicle);
    fprintf(fptr, "Scooter Count : %d \n", v.vc.scooter);
    fprintf(fptr, "Car Count : %d \n", v.vc.car);
    fprintf(fptr, "Bus Count : %d \n", v.vc.bus);
    fprintf(fptr, "Truck Count : %d \n", v.vc.truck);
    fclose(fptr);
}

void loaddata(struct vehicle v) {
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    fscanf(fptr, "Vehicle Name : %s \n", v.name);
    fscanf(fptr, "Vehicle Number : %d \n", v.num);
    fscanf(fptr, "Vehicle Row : %d \n", v.row);
    fscanf(fptr, "Vehicle Col : %d \n", v.col);
    fscanf(fptr, "Vehicle Type : %d \n", v.type);
    fscanf(fptr, "Vehicle Count : %d \n", v.vc.vehicle);
    fscanf(fptr, "Scooter Count : %d \n", v.vc.scooter);
    fscanf(fptr, "Car Count : %d \n", v.vc.car);
    fscanf(fptr, "Bus Count : %d \n", v.vc.bus);
    fscanf(fptr, "Truck Count : %d \n", v.vc.truck);
    fclose(fptr);
}

int main() {
    while (1) {
        clear();
        printf("Parking System ITTS\n");
        struct vehicle v;
        printf("Menu : \n");
        printf("1. Add Vehicle \n");
        printf("2. Delete Vehicle \n");
        printf("3. Show Vehicle \n");
        printf("4. Search Vehicle \n");
        printf("5. Save Data \n");
        printf("6. Load Data \n");
        printf("5. Exit \n");
        printf("Select Menu : ");
        int menu;
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Add Vehicle \n");
                printf("Vehicle Name : ");
                char name[100];
                scanf("%s", name);
                printf("Vehicle Number : ");
                int num;
                scanf("%d", &num);
                printf("Vehicle Row : ");
                int row;
                scanf("%d", &row);
                printf("Vehicle Col : ");
                int col;
                scanf("%d", &col);
                printf("Vehicle Type : ");
                int type;
                scanf("%d", &type);
                v = add(v, name, num, row, col, type);
                break;
            case 2:
                printf("Delete Vehicle \n");
                delete(&v);
                break;
            case 3:
                printf("Show Vehicle \n");
                // show vehicle using iomanip table

                printf("Vehicle Name : %s \n", v.name);
                printf("Vehicle Number : %d \n", v.num);
                printf("Vehicle Row : %d \n", v.row);
                printf("Vehicle Col : %d \n", v.col);
                printf("Vehicle Type : %d \n", v.type);
                printf("Vehicle Count : %d \n", v.vc.vehicle);
                printf("Scooter Count : %d \n", v.vc.scooter);
                printf("Car Count : %d \n", v.vc.car);
                printf("Bus Count : %d \n", v.vc.bus);
                printf("Truck Count : %d \n", v.vc.truck);
                break;
            case 4:
                printf("Search Vehicle \n");
                search(v);
                break;
            case 5:
                printf("Save Data \n");
                savedata(v);
                break;
            case 6:
                printf("Load Data \n");
                loaddata(v);
                break;
            default:
                printf("Error \n");
                break;
            }
    } 
    return 0;
}