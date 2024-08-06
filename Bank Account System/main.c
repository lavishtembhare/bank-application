#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <windows.h>  
  
void CheckBankBalance(char*);  
void SendMoney(void);  
void display(char*);  
void person(char*);  
void login(void);  
void loginsu(void);  
void CreateBankAccount(void);  
void accountcreated(void);  
void afterlogin(void);  
void logout(void);  
  
  
void displayCoordinates(int a, int b)  
{  
    COORD curr;  
    curr.X = a;  
    curr.Y = b;  
  
    SetConsoleCursorPosition(  
        GetStdHandle(STD_OUTPUT_HANDLE), curr);  
}  
  
  
struct accountDetails {  
    char username[50];  
    int date, month, year;  
    char pnumber[15];  
    char adharnum[20];  
    char fname[20];  
    char lname[20];  
    char fathname[20];  
    char mothname[20];  
    char address[50];  
    char typeaccount[20];  
};  
  
  
struct money {  
    char usernameto[50];  
    char userpersonfrom[50];  
    long int money1;  
};  
  
struct userpass {  
    char password[50];  
};  
  
// Driver Code  
int main()  
{  
    int i, a, b, choice;  
    int passwordlength;  
  
    displayCoordinates(20, 3);  
  
    printf("WELCOME TO BANK ACCOUNT SYSTEM OF JAVATPOINT\n\n");  
    displayCoordinates(18, 5);  
  
    printf("**********************************");  
    displayCoordinates(25, 7);  
  
    displayCoordinates(20, 10);  
    printf("1.... CREATE A NEW BANK ACCOUNT");  
  
    displayCoordinates(20, 12);  
    printf("2.... HAVINg ALREADY AN ACCOUNT");  
    displayCoordinates(20, 14);  
    printf("3.... EXIT\n\n");  
  
    printf("\n\nENTER YOUR CHOICE..");  
  
    scanf("%d", &choice);  
  
    switch (choice) {  
    case 1:  
        system("cls");  
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");  
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");  
        CreateBankAccount();  
        break;  
  
    case 2:  
        login();  
        break;  
  
    case 3:  
        exit(0);  
        break;  
  
        getch();  
    }  
}  
  
  
  
void CreateBankAccount(void)  
{  
    char password[20];  
    int passwordlength, i, seek = 0;  
    char ch;  
    FILE *file1, *file2;  
    struct accountDetails u1;  
    struct userpass p1;  
  
    struct userpass u2;  
    file1 = fopen("username.txt", "ab");  
  
    system("cls");  
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");  
  
    printf("\n\nFIRST NAME..");  
    scanf("%s", &u1.fname);  
  
    printf("\n\n\nLAST NAME..");  
    scanf("%s", &u1.lname);  
  
    printf("\n\nFATHER's NAME..");  
    scanf("%s", &u1.fathname);  
  
    printf("\n\nMOTHER's NAME..");  
    scanf("%s", &u1.mothname);  
  
    printf("\n\nADDRESS..");  
    scanf("%s", &u1.address);  
  
    printf("\n\nACCOUNT TYPE");  
    scanf("%s", &u1.typeaccount);  
  
    printf("\n\nDATE OF BIRTH..");  
    printf("\nDATE-");  
    scanf("%d", &u1.date);  
    printf("\nMONTH-");  
    scanf("%d", &u1.month);  
    printf("\nYEAR-");  
    scanf("%d", &u1.year);  
  
    printf("\n\nADHAR NUMBER");  
    scanf("%s", u1.adharnum);  
  
    printf("\n\nPHONE NUMBER");  
    scanf("%s", u1.pnumber);  
  
    printf("\n\nUSERNAME.. ");  
    scanf("%s", &u1.username);  
  
    printf("\n\nPASSWORD..");  
  
  
    for (i = 0; i < 50; i++) {  
        ch = getch();  
        if (ch != 13) {  
            password[i] = ch;  
            ch = '*';  
            printf("%c", ch);  
        }  
        else  
            break;  
    }  
  
    fwrite(&u1, sizeof(u1),  
        1, file1);  
  
  
    fclose(file1);  
    accountcreated();  
}  
  
  
void accountcreated(void)  
{  
    int i;  
    char ch;  
    system("cls");  
    printf(  
        "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");  
    for (i = 0; i < 200000000; i++) {  
        i++;  
        i--;  
    }  
  
    displayCoordinates(30, 10);  
  
    printf("ACCOUNT CREATED SUCCESSFULLY....");  
    displayCoordinates(0, 20);  
  
    printf("Press enter to login");  
  
    getch();  
    login();  
}  
  
  
  
void login(void)  
{  
    system("cls");  
  
    char username[50];  
    char password[50];  
  
    int i, j, k;  
    char ch;  
    FILE *file1, *file2;  
    struct accountDetails u1;  
    struct userpass u2;  
  
  
    file1 = fopen("username.txt",  
            "rb");  
  
    if (file1 == NULL) {  
        printf("THERE IS AN ERROR IN OPENING FILE");  
    }  
    displayCoordinates(34, 2);  
    printf(" ACCOUNT LOGIN ");  
    displayCoordinates(7, 5);  
    printf("***********************************************"  
        "********************************");  
  
    displayCoordinates(35, 10);  
    printf("==== LOG IN ====");  
  
    displayCoordinates(35, 12);  
    printf("USERNAME.. ");  
    scanf("%s", &username);  
  
    displayCoordinates(35, 14);  
    printf("PASSWORD..");  
  
    for (i = 0; i < 50; i++) {  
        ch = getch();  
        if (ch != 13) {  
            password[i] = ch;  
            ch = '*';  
            printf("%c", ch);  
        }  
  
        else  
            break;  
    }  
  
  
    while (fread(&u1, sizeof(u1),  
                1, file1)) {  
        if (strcmp(username,  
                u1.username)  
            == 0) {  
            loginsu();  
            display(username);  
        }  
    }  
  
    fclose(file1);  
}  
  
  
void loginsu(void)  
{  
    int i;  
    FILE* file1;  
    struct accountDetails u1;  
    system("cls");  
    printf("Fetching account details based on yur input.....\n");  
    for (i = 0; i < 20000; i++) {  
        i++;  
        i--;  
    }  
  
    displayCoordinates(30, 10);  
    printf("LOGIN SUCCESSFULLY INTO YOUR ACCOUNT....");  
    displayCoordinates(0, 20);  
    printf("Press enter to continue");  
  
    getch();  
}  
  
  
void display(char user1[])  
{  
    system("cls");  
    FILE* file1;  
    int choice, i;  
    file1 = fopen("username.txt", "rb");  
    struct accountDetails u1;  
  
    if (file1 == NULL) {  
        printf("error in opening file");  
    }  
  
    while (fread(&u1, sizeof(u1),  
                1, file1)) {  
        if (strcmp(user1,  
                u1.username)  
            == 0) {  
            displayCoordinates(30, 1);  
            printf("WELCOME, %s %s",  
                u1.fname, u1.lname);  
            displayCoordinates(28, 2);  
            printf("..........................");  
            displayCoordinates(55, 6);  
            printf("==== YOUR ACCOUNT INFO ====");  
            displayCoordinates(55, 8);  
            printf("***************************");  
            displayCoordinates(55, 10);  
            printf("NAME..%s %s", u1.fname,  
                u1.lname);  
  
            displayCoordinates(55, 12);  
            printf("FATHER's NAME..%s %s",  
                u1.fathname,  
                u1.lname);  
  
            displayCoordinates(55, 14);  
            printf("MOTHER's NAME..%s",  
                u1.mothname);  
  
            displayCoordinates(55, 16);  
            printf("ADHAR CARD NUMBER..%s",  
                u1.adharnum);  
  
            displayCoordinates(55, 18);  
            printf("MOBILE NUMBER..%s",  
                u1.pnumber);  
  
            displayCoordinates(55, 20);  
            printf("DATE OF BIRTH.. %d-%d-%d",  
                u1.date, u1.month, u1.year);  
  
            displayCoordinates(55, 22);  
            printf("ADDRESS..%s", u1.address);  
  
            displayCoordinates(55, 24);  
            printf("ACCOUNT TYPE..%s",  
                u1.typeaccount);  
        }  
    }  
  
    fclose(file1);  
  
    displayCoordinates(0, 6);  
    printf(" HOME ");  
    displayCoordinates(0, 7);  
    printf("******");  
    displayCoordinates(0, 9);  
    printf(" 1....CHECK YOUR ACCOUNT BALANCE");  
    displayCoordinates(0, 11);  
    printf(" 2....SEND MONEY");  
    displayCoordinates(0, 13);  
    printf(" 3....LOG OUT FROM ACCOUNT\n\n");  
    displayCoordinates(0, 15);  
    printf(" 4....EXIT\n\n");  
  
    printf(" ENTER YOUR CHOICES..");  
    scanf("%d", &choice);  
  
    switch (choice) {  
    case 1:  
        CheckBankBalance(user1);  
        break;  
  
    case 2:  
        SendMoney();  
        break;  
  
    case 3:  
        logout();  
        login();  
        break;  
  
    case 4:  
        exit(0);  
        break;  
    }  
}  
  
  
void SendMoney(void)  
{  
      
    int i, j;  
    FILE *file1, *file2;  
    struct accountDetails u1;  
    struct money m1;  
    char sender[20];  
    char receiver[20];  
    system("cls");  
  
  
    file2 = fopen("username.txt", "rb");  
  
  
    file1 = fopen("mon.txt", "ab");  
  
    displayCoordinates(33, 4);  
    printf("---- SEND MONEY ----");  
    displayCoordinates(33, 5);  
    printf("========================");  
  
    displayCoordinates(33, 11);  
    printf("FROM (your username).. ");  
    scanf("%s", &sender);  
  
    displayCoordinates(33, 13);  
    printf(" TO (username of person)..");  
    scanf("%s", &receiver);  
  
  
    while (fread(&u1, sizeof(u1),  
                1, file2))  
  
    {  
        if (strcmp(receiver,  
                u1.username)  
            == 0) {  
            strcpy(m1.usernameto,  
                u1.username);  
            strcpy(m1.userpersonfrom,  
                sender);  
        }  
    }  
    displayCoordinates(33, 16);  
  
    printf("ENTER THE AMOUNT TO BE TRANSFERRED..");  
    scanf("%d", &m1.money1);  
  
    fwrite(&m1, sizeof(m1),  
        1, file1);  
  
    displayCoordinates(0, 26);  
    printf(  
        "--------------------------------------------------"  
        "--------------------------------------------");  
  
    displayCoordinates(0, 28);  
    printf(  
        "--------------------------------------------------"  
        "--------------------------------------------");  
  
    displayCoordinates(0, 29);  
    printf("transfering amount, Please wait..");  
  
    displayCoordinates(10, 27);  
    for (i = 0; i < 70; i++) {  
        for (j = 0; j < 1200000; j++) {  
            j++;  
            j--;  
        }  
        printf("*");  
    }  
  
    displayCoordinates(33, 40);  
    printf("YOUR MONEY IS SUCCESSFULLY TRANSFERRED....");  
    getch();  
  
  
    fclose(file2);  
    fclose(file1);  
  
    display(sender);  
}  
  
  
void CheckBankBalance(char user2[])  
{  
      
    system("cls");  
    FILE* file1;  
    struct money m1;  
    char ch;  
    int i = 1, summoney = 0;  
  
    file1 = fopen("mon.txt", "rb");  
  
    int k = 5, l = 10;  
    int m = 30, n = 10;  
    int u = 60, v = 10;  
  
    displayCoordinates(30, 2);  
    printf("==== BANK ACCOUNT MONEY  ====");  
    displayCoordinates(30, 3);  
    printf("***************************");  
    displayCoordinates(k, l);  
    printf("S no.");  
    displayCoordinates(m, n);  
    printf("TRANSACTION ID");  
    displayCoordinates(u, v);  
    printf("AMOUNT");  
  
    while (fread(&m1, sizeof(m1),  
                1, file1)) {  
        if (strcmp(user2,  
                m1.usernameto)  
            == 0) {  
            displayCoordinates(k, ++l);  
            printf("%d", i);  
            i++;  
            displayCoordinates(m, ++n);  
            printf("%s", m1.userpersonfrom);  
  
            displayCoordinates(u, ++v);  
            printf("%d", m1.money1);  
          
            summoney = summoney + m1.money1;  
        }  
    }  
  
    displayCoordinates(80, 10);  
    printf("TOTAL AMOUNT");  
  
    displayCoordinates(80, 12);  
    printf("%d", summoney);  
  
    getch();  
    fclose(file1);  
    display(user2);  
}  
  
  
  
void logout(void)  
{  
    int i, j;  
    system("cls");  
    printf("please wait, logging out");  
  
    for (i = 0; i < 10; i++) {  
        for (j = 0; j < 25000000; j++) {  
            i++;  
            i--;  
        }  
        printf(".");  
    }  
  
    displayCoordinates(30, 10);  
    printf("logged  out successfully..\n");  
  
    displayCoordinates(0, 20);  
    printf("press any key to continue..");  
  
    getch();  
}  
