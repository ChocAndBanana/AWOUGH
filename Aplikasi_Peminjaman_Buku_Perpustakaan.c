#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100;

FILE *listbuku;
FILE *userlog;
FILE *userData;
FILE *replace;
int i;
char ch[100];
bool acc;
bool limit = false;

typedef struct{

    char name[50];
    char place[50];
    char logTime[50];
}studentdata;

typedef struct{
    char judul[50];
    int harga;
}buku;

buku buku1;

void reading(){
    replace = fopen("replace.txt", "r");
    i = 0;
    char singleline[50];
    printf("Judul Buku :\n");
    while(!feof(replace)){
        fgets(singleline, 50, replace);

        if (strcmp(singleline, "\n") == 0)
        {
            i--;
            continue;
        }

        printf("%d. %s\n", i + 1, singleline);
        i++;
    }
    char choice;
    fclose(replace);
    printf("Do u want to continue?(Y/N)\n");
      scanf(" %c", &choice);
      switch (choice) {
      case 'Y':
        printf("Press enter to continue...\n");
        getchar();
        system("CLS");
        
        break;
      case 'y':
        printf("Press enter to continue...\n");
        getchar();
        system("CLS");
        
        break;
      case 'N':
        system("CLS");
            printf("Zao shang hao zhong gu�!\n");
            printf("  Xi�n z�i wo you\n");
            printf("   bing chilling\n");
            exit(0);;
      case 'n':
        system("CLS");
            printf("Alongside courage and perserverance\n");
            printf("  we shape and define our future\n");
            printf("             ~ 22-1 ~\n");
            exit(0);
      default:
        printf("Error.\n");
        exit(1);
      }

}

void insertion()
{
    studentdata fivestudents;
    // int i;

    userlog = fopen("Userlog.txt", "a");
        puts("Insert name: ");
        getchar();
        scanf("%[^\n]", fivestudents.name);
        getchar();
        puts("Insert your address: ");
        scanf("%[^\n]", fivestudents.place);
        puts("Insert your log time(hh:mm, dd/mm/yyyy): ");
        scanf("%[^\n]", fivestudents.logTime);
    fprintf(userlog, "%s#%s#%s\n", fivestudents.name, fivestudents.place);
    fclose(userlog);
}


// void borrow(){

//     listbuku = fopen("listbuku.txt", "r"); //Open file 1
//     replace = fopen("replace.txt", "w+"); // Open file 2
//     i = 0;
//     char singleline[100];
//     char baru[100];
//     printf("Judul Buku :\n");

//     if(replace == NULL || listbuku == NULL){
//         printf("Can't open File.");
//         exit(0);
//     }

//     //File Reading
//     while(fscanf(listbuku, " %[^\n]", buku1.judul) != EOF){
//         printf("%d. %s\n", i + 1, buku1.judul);
//         i++;
//     }
//     printf("\nPlease Choose a book :\n\t>> ");
//     char borrow[100];
//     scanf(" %[^\n]", borrow);
    
//     int cmp;
//     int days;
//     char empty[10] = "";
//     // char read[100];
//     // int size = sizeof(borrow);
//     // printf("%s\n", borrow);
//     cmp = strcmp(borrow, buku1.judul);
//     printf("Please enter the days you want to borrow this book\n>>");
//     scanf("%d", &days);

//     rewind(listbuku);
//     if(days >= 1 && days <= 14){
//         while (!feof(listbuku)) {
//         if (strcmp(singleline, borrow) == 0) {
//         fscanf(listbuku, " %[^\n]\n", singleline);
 
//             strcpy(singleline, empty);
//         }
//         fprintf(replace, "%s\n", singleline);
            
//     }
//     printf("Thanks for borrowing the book!\n");       
//         }
    
//     fclose(listbuku);
//     fclose(replace);
//     }

void borrow(){

    listbuku = fopen("listbuku.txt", "r"); //Open file 1
    replace = fopen("replace.txt", "w+"); // Open file 2
    i = 0;
    char singleline[100];
    char baru[100];
    printf("Judul Buku :\n");

    if(replace == NULL || listbuku == NULL){
        printf("Can't open File.");
        exit(0);
    }

    //File Reading
    while(fscanf(listbuku, " %[^\n]", buku1.judul) != EOF){
        printf("%d. %s\n", i + 1, buku1.judul);
        i++;
    }
    printf("\nPlease Choose a book :\n\t>> ");
    char borrow[100];
    scanf(" %[^\n]", borrow);
    
    int cmp;
    int days;
    char empty[100] = "";
    char read[100];
    int size = sizeof(borrow);
    printf("%s\n", borrow);
    cmp = strcmp(borrow, buku1.judul);
    printf("Please enter the days you want to borrow this book\n>>");
    scanf("%d", &days);

    rewind(listbuku);
    if(days >= 1 && days <= 14){
        while (!feof(listbuku)) {
        fscanf(listbuku, " %[^\n]", singleline);
        if (strcmp(singleline, borrow) == 0) {
 
            strcpy(singleline, empty);
        }
        fprintf(replace, "%s\n", singleline);
            
    }
            
        }
    
    fclose(listbuku);
    fclose(replace);
    }

void returning() {
    listbuku = fopen("listbuku.txt", "r");
    replace = fopen("replace.txt", "a");

    printf("Please input the title of the book you wanted to return\n\t>> ");
    
    char returning[20];
    char judul[50];
    int cmp;
    bool isFound = false;
    scanf("%[^\n]", returning);

    
    while(!feof(listbuku)) {
        // rewind(listbuku);
        fscanf(listbuku, "%[^\n]\n", judul);
        // printf("%s", judul);
        cmp = strcmp(returning, judul);
        // printf("%d", cmp);

        if(cmp==0) {
            printf("Thank you for returning the book!\n");
            isFound = true;
            break;
        }
    }
    
         if (cmp != 0)
         {
             printf("Book not found in database!");
             isFound = false;
         }
        
    if (isFound == true)
    {
        // printf("1");
        fprintf(replace, "\n%s", returning);
    }
//    } else {
//        printf("Book not found in database!");
//        printf("2");
//    }
    
    fclose(listbuku);
    fclose(replace);
    // printf("Are you sure this is the book? (Y/N)");
    // char choice;
    // scanf(" %c", &choice);
    // switch(choice){
    //     case 'Y':
    //         printf("Thanks for returning the book!\n");
    //         break;
    //     case 'N':
    //         break;
    //     default:
    //         printf("Error.\n");
    //         exit(1);
    // } 

}

// void returning(){
//     listbuku = fopen("listbuku.txt", "r"); //Open file 1
//     replace = fopen("replace.txt", "a"); // Open file 2
//     if(replace == NULL || listbuku == NULL){
//         printf("Can't open File.");
//         exit(0);
//     }

//     char singleline[100];
//     printf("Judul Buku yang ingin dikembalikan :\n");
//     scanf("%[^\n]", singleline);
//     while(!feof(listbuku)) {
//         fscanf(listbuku, " %[^\n]", buku1.judul);
//         if (strcmp(buku1.judul, singleline) == 0) {
//             fprintf(replace, "%s\n", buku1.judul);
//             printf("Buku '%s' sudah dikembalikan\n", singleline);
//         }
//     }
//     fclose(listbuku);
//     fclose(replace);
// }



void stylemenu(){
    int option;
    printf("|===============================|\n");
    printf("|    Today a reader..,          |\n");
    printf("|        Tomorrow a leader~     |\n");
    printf("|                               |\n");
    printf("|                               |\n");
    printf("|          Welcome to           |\n");
    printf("|         The  Library          |\n");
    printf("|                               |\n");
    printf("|         Press ENTER           |\n");
    printf("|===============================|\n");

    if (getchar()){
    do{
    printf("|===============================|\n");
    printf("|                               |\n");
    printf("|  How would you like to        |\n");
    printf("|  upgrade yourself today:      |\n");
    printf("|                               |\n");
    printf("|    Don't forget to insert     |\n");
    printf("|        your userdata!         |\n");
    printf("|                               |\n");
    printf("|    1. Insert Userdata         |\n");
    printf("|    2. Check Available Books   |\n");
    printf("|    3. Borrow a Book           |\n");
    printf("|    4. Return a Book           |\n");
    printf("|    5. Exit the program.       |\n");
    printf("|-------------------------------|\n");
    
    scanf(" %d", &option);
    switch(option){
        case 1:
        insertion();
        break;
        case 2:
        reading();
        break;
        case 3:
        borrow();
        break;
        case 4:
        getchar();
        returning();
        break;
        case 5:
        printf("Alongside courage and perserverance\n");
        printf("  we shape and define our future\n");
        printf("             ~ 22-1 ~\n");
        printf("Press enter to exit the program...\n");
        getchar();getchar();
        system("CLS");
        acc = false;
        exit(0);
        default:    
        break;
    }

    }while(option != 5);
    }
}

void registration (){
    // variables
    char userName[20];
    char password[20];

    userData = fopen("userData.txt", "a");

    // user name
    printf("Insert Username (max 20 characters): ");
    scanf("%s", &userName);
    fprintf(userData, "%s", userName);

    // password
    printf("Insert Password (max 20 characters): ");
    scanf("%s", &password);
    fprintf(userData, "#%s\n", password);

    fclose(userData);

    printf("Access granted\n");
    acc = true;
}

void login(){
    char dbUserName[20];
    char dbPassword[20];
    char inputUserName[20];
    char inputPassword[20];

    int userNameCmp; // strcmp for username
    int passwordCmp; // strcmp for password

    userData = fopen("userData.txt", "r");

    // input username
    printf("Enter your username: ");
    scanf("%s", &inputUserName);
    // input password
    printf("Enter your password: ");
    scanf("%s", inputPassword);

    printf("Loading..\n\n");

    while (!feof(userData))
    {
    // User Name compare
    fscanf(userData, "%[^#]#", &dbUserName); // data base username
    userNameCmp = strcmp(dbUserName, inputUserName);
    // printf("%d\n", userNameCmp); // test strcmp value

    // Password compare
    fscanf(userData, "%[^\n]\n", &dbPassword); // data base password
    passwordCmp = strcmp(dbPassword, inputPassword);
    // printf("%d\n", passwordCmp); // test strcmp value

        if (userNameCmp == 0 && passwordCmp == 0)
        {
            printf("Access granted\n");
            acc = true;
            break;
        }
    }

    if (userNameCmp != 0 || passwordCmp != 0) {
        printf("Access denied\n");
        acc = false;
    }
}

void main(){
    char accChoice;

    while (true)
    {
    printf("|================================|\n");
    printf("|  1. Login                      |\n");
    printf("|  2. Register                   |\n");
    printf("|  Choose your option (1 or 2)   |\n");
    printf("|                                |\n");
    printf("|  Press other key to exit       |\n");
    printf("|================================|\n");
    scanf("%c", &accChoice);

    switch (accChoice)
    {
    case '1':
        login();
        getchar();
        break;
    case '2':
        registration();
        getchar();
        break;
    default:
        printf("Ni ai wo wo ai ni\n");
        printf("bye~\n");
        exit(0);
        break;
    }

    if (acc == true)
    {
        stylemenu();
    }
    }
    
        
    // stylemenu();
    // login();
    // returning();
    // borrow();
}

void booking(){

}