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

void delete(struct vehicle v) {
    dela
    if (v.type == 1) {
        v.vc.scooter--;
    } else if (v.type == 2) {
        v.vc.car-- ;
    } else if (v.type == 3) {
        v.vc.bus-- ;
    } else if (v.type == 4) {
        v.vc.truck-- ;
    }
    v.vc.vehicle-- ;
}

int main() {
    while (true) {
        printf("Parking System ITTS");
    struct vehicle v;
    printf("Menu : \n");
    printf("1. Add Vehicle \n");
    printf("2. Delete Vehicle \n");
    printf("3. Show Vehicle \n");
    printf("4.Search Vehicle \n");
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
            delete(v);
            break;
        case 3:
            printf("Show Vehicle \n");
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
            break;
        case 5:
            printf("Exit \n");
            exit(0);
            break;
        default:
            printf("Error \n");
            break;
        }
    } 
    return 0;
}


