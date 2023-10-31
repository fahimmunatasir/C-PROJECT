#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int indx=0;
int indx2=0;

struct place{
    char name[50];
    float dist;
}place[1000];

void addplace(){
    system("cls");
    printf("\t\t\t    ADD PLACES");
    printf("\n\n\t--------------------------------------------------\n");
    char c;
    while((c = getchar()) != '\n' && c != EOF);
    printf("\n\tAdd the name of the place: ");
    gets(place[indx].name);
    strlwr(place[indx].name);

    printf("\tDistance from Daffofil Smart City: ");
    scanf("%f",&place[indx].dist);
    printf("\n\tAdding...\n\tSuccessfull!! Place added.");

    indx++;

    printf("\n\n\tDo you want to continue?(y/n)");
    char ch;
    while((c = getchar()) != '\n' && c!=EOF);
    scanf("%c",&ch);
    printf("\n\tChanging!");
    if(ch == 'y'){
        addplace();
    }
}

void showalph(float km){
    system("cls");
    int a,b,c,d;

    printf("\t      Showing the name Alpahabetically");
    printf("\n\n\t-------------------------------------------\n");
    printf("\n\tName     \t-> Price  \t-> Distance\n\n");

    for(int i=0;i<indx;i++){
        struct place temp;

        for(int j=i;j<indx;j++){

            a=place[i].name[0];
            b=place[j].name[0];

            if(a >= b){
                temp=place[i];
                place[i]=place[j];
                place[j]=temp;
                c=place[i].name[1];
                d=place[j].name[2];
                if(c < d){
                    temp=place[i];
                    place[i]=place[j];
                    place[j]=temp;
                }
            }        
        }
    }

    for(int i=0;i<indx;i++){
        printf("\t%-15s  ",place[i].name);
        printf("  %-13.2f  ",place[i].dist*km);
        printf(" %.2f\n",place[i].dist);
    }
    printf("\n\n\tPress any key to continue...");
    
    getch();
}

void showbypr(float km){
    system("cls");
    printf("\t         Showing the list by Price");
    printf("\n\n\t-------------------------------------------\n");
    printf("\n\tName     \t-> Price  \t-> Distance\n\n");

    for(int i=0;i<indx;i++){

        struct place temp2;

        for(int j=0;j<indx;j++){
            if(place[i].dist > place[j].dist){
                temp2=place[i];
                place[i]=place[j];
                place[j]=temp2;
            }
        }
    }

    for(int i=0;i<indx;i++){
        printf("\t%-15s  ",place[i].name);
        printf("  %-13.2f  ",place[i].dist*km);
        printf(" %.2f\n",place[i].dist);
    }

    printf("\n\n\tPress any key to continue...");
    getch();
}

void changedist(){
    system("cls");
    float dist2;
    char cng[50],c;

    printf("\t\t   Change the distance of a place");
    printf("\n\n\t--------------------------------------------------\n");

    while((c = getchar()) != '\n' && c != EOF);
    printf("\n\tEnter the name of the place: ");
    gets(cng);
    strlwr(cng);

    for(int i=0;i<indx;i++){
        if(strcmp(cng,place[i].name)==0){
            indx2++;
        }
    }

    if(indx2==0){
        indx2=0;

        printf("\n\n\tWrong input, Please try again.");
        printf("\n\n\tPress any key to continue...");

        getch();
    }

    else if(indx2>0){
        indx2=0;
        printf("\tEnter the changed distance: ");
        scanf("%f",&dist2);

        for(int i=0;i<indx;i++){
            if(strcmp(place[i].name,cng)==0){
                place[i].dist=dist2;
                break;
            }
        }
    }
}

void changename(){
    system("cls");
    char cng[50];
    char cng2[50],c;

    while((c = getchar()) != '\n' && c != EOF);

    printf("\t\t    Change the name of a place");
    printf("\n\n\t--------------------------------------------------\n");

    printf("\n\tEnter the name of the place: ");
    gets(cng);
    strlwr(cng);

    for(int i=0;i<indx;i++){
        if(strcmp(cng,place[i].name)==0){
            indx2++;
        }
    }

    if(indx2==0){
        indx2=0;
        printf("\n\n\tWrong input, Please try again.");
        printf("\n\n\tPress any key to continue...");
        getch();
    }


    if(indx2>0){
        indx2=0;
        printf("\tEnter the name what it should be: ");
        gets(cng2);
        strlwr(cng2);

        for(int i=0;i<indx;i++){
            if(strcmp(place[i].name,cng)==0){
                strcpy(place[i].name,cng2);
                break;
            }
        }
    }
}

void display(){
    printf("Add place, type 1\n");    
    printf("Show the name Alphabatically, type 2\n");
    printf("Show the name by Price, type 3\n");
    printf("Change the price for per KM, type 4\n");
    printf("Change the name of a place, type 5\n");
    printf("Chnage the distance of a place, type 6\n");
    printf("to Show the place individually, type 7\n");
    printf("TO close the program, press 0\n");
    printf("Enter you choice: ");
}

void showprbyplc(float km){
    system("cls");

    char c,cng[50];

    indx2=0;
    
    printf("\t         Showing the name of place");
    printf("\n\n\t-------------------------------------------\n");

    while((c = getchar()) != '\n' && c != EOF);
    printf("\n\tEnter the name of the place: ");
    gets(cng);
    strlwr(cng);

    for(int i=0;i<indx;i++){
        if(strcmp(cng,place[i].name)==0){
            indx2=i+1;
            break;
        }
    }


    if(indx2>0){
        printf("\n\tName     \t-> Price  \t-> Distance");
        printf("\n\t%-15s  ",place[indx2-1].name);
        printf("  %-13.2f  ",place[indx2-1].dist*km);
        printf(" %.2f\n",place[indx2-1].dist);
    }

    else if(indx2==0){
        printf("\n\tWrong input, Try again!!");
    }
    

    printf("\n\n\tPress any key 