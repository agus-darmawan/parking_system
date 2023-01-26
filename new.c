#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char name[20];
    int num;
    int row;
    int col;
    int type;
    struct vehicle_count vc;
} ;

void clear(){
    system("clear") || system ("cls") ||  printf("\e[1;1H\e[2J");

}

int main(){
    struct vehicle *v;
    v = (struct vehicle *)malloc(sizeof(struct vehicle));
    v->vc.scooter = 0;
    v->vc.car = 0;
    v->vc.bus = 0;
    v->vc.truck = 0;
    int noOfRecords = 0;
    while (1){
        clear();
        printf("Parking System \n");
        printf("MENU \n");
        printf("1. Add Vehicle \n");
        printf("2. Show Vehicle \n");
        printf("3. Remove Vehicle \n");
        printf("4. Display Parking Lot\n");
        printf("5. Search Vehicle \n");
        printf("6. Save \n");
        printf("7. Load \n");
        printf("8. Exit \n");
        printf("Enter your choice : ");
        int choice;
        scanf("%d", &choice);
        if(noOfRecords > WIDTH_PARKING_LOT * LENGTH_PARKING_LOT){
            printf("Parking Lot is full");
            break;
        }
        switch (choice){
        case 1:
            printf("Add Vehicle \n");
            printf("Enter Vehicle Name : ");
            scanf("%s", (v+noOfRecords)->name);
            printf("Enter Vehicle Type : ");
            int type;
            scanf("%d", &type);
            (v+noOfRecords)->type = type;
            switch (type)
            {   
            case 1:
                v->vc.scooter++;
                break;
            case 2:
                v->vc.car++;
                break; 
            case 3:
                v->vc.bus++;
                break;
            case 4:
                v->vc.truck++;
                break;
            case 5:
                v->vc.vehicle++;
                break;
            default:
                break;
            }
            (v+noOfRecords)->num = noOfRecords;
            noOfRecords++;
            break;
        case 2:
            printf("Show Vehicle \n");
            printf("Vehicle Name \n");
            for (int i = 0; i < noOfRecords; ++i) {
                printf("%s \n", (v+i)->name);
            }
            printf("\nNumber of Viechle : %d", noOfRecords);
            printf("\nNumber of Scooter : %d", v->vc.scooter);
            printf("\nNumber of Car : %d", v->vc.car);
            printf("\nNumber of Bus : %d", v->vc.bus);
            printf("\nNumber of Truck : %d", v->vc.truck);

            printf("\nPlese Enter any key to continue");
            getchar();
            break;
        case 3:
            printf("Remove Vehicle \n");
            printf("Enter Vehicle Name : ");
            char name[20];
            scanf("%s", name);
            for (int i = 0; i < noOfRecords; ++i) {
                if (strcmp(name, (v+i)->name) == 0) {
                    for (int j = i; j < noOfRecords; ++j) {
                        *(v+j)->name = *(v+j+1)->name;
                        (v+j)->num = (v+j+1)->num;
                        (v+j)->row = (v+j+1)->row;
                        (v+j)->col = (v+j+1)->col;
                        (v+j)->type = (v+j+1)->type;
                    }
                    noOfRecords--;
                    break;
                }
            }
            break;
        case 4:
            printf("Display Parking Lot \n");
            printf("Vehicle Name \t Vehicle Number \t Vehicle Row \t Vehicle Column \n");
            for (int i = 0; i < noOfRecords; ++i) {
                printf("%s \t\t", (v+i)->name);
                printf("%d \t\t", i+1);
                printf("%d \t\t",(noOfRecords- noOfRecords-i) / WIDTH_PARKING_LOT );
                printf("%d \t\t",-(noOfRecords- noOfRecords-i) % WIDTH_PARKING_LOT);
            }
            printf("\nPlese Enter any key to continue");
            getchar();
            break;
        case 5:
            printf("Search Vehicle \n");
            printf("Enter Vehicle Number : ");
            int num_search;
            scanf("%d", &num_search);
            for (int i = 0; i < noOfRecords; ++i) {
                if (num_search < noOfRecords) {
                    printf("Vehicle Name   : %s \n", (v+num_search)->name);
                    printf("Vehicle Number : %d \n", num_search);
                    printf("Vehicle Row    : %d \n",(noOfRecords- noOfRecords-num_search) / WIDTH_PARKING_LOT );
                    printf("Vehicle Col    : %d \n",-(noOfRecords- noOfRecords-num_search) % WIDTH_PARKING_LOT);
                }
            }
            printf("\nPlese Enter any key to continue");
            getchar();
            break;
        case 6:
            printf("Save \n");
            FILE *fp;
            fp = fopen("data.txt", "w");
            for (int i = 0; i < noOfRecords; ++i) {
                fprintf(fp, "%s \n", (v+i)->name);
                fprintf(fp, "%d \n", i+1);
                fprintf(fp, "%d \n", (noOfRecords- noOfRecords-i) / WIDTH_PARKING_LOT );
                fprintf(fp, "%d \n", (-(noOfRecords- noOfRecords-i) % WIDTH_PARKING_LOT));
                fprintf(fp, "%d \n", (v+i)->type);
            }
            fclose(fp);
            printf("Save Complete");
            printf("\nPlese Enter any key to continue");
            getchar();
            break;
        case 7:
            printf("Load \n");
            FILE *fp1;
            fp1 = fopen("data.txt", "r");
            for (int i = 0; i < noOfRecords; ++i) {
                fscanf(fp1, "%s", (v+i)->name);
                fscanf(fp1, "%d", &(v+i)->num);
                fscanf(fp1, "%d", &(v+i)->row);
                fscanf(fp1, "%d", &(v+i)->col);
                fscanf(fp1, "%d", &(v+i)->type);
            }
            fclose(fp1);
            printf("Load Complete");
            printf("\nPlese Enter any key to continue");
            getchar();
            break;
        
        }


    }
    free(v);
    return 0;
}

