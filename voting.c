#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct voter_information {
    char aadhar[20];
    char name[50];
    char birth_date[15];
    struct voter_information *next;
} node;

node *head;
node *start = NULL;
node *search(char x[], char y[], char z[], node *, int *);
node *voter_insert(node *);
node *main_logs(node *);
void admin();
void winner();
void exi();
void voting();
void not_again();
void stop();
void show();

int count = 0, R = 3;
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;
node *main_logs(node *start) {
    system("cls");
    printf("\n\n\n");
    printf("        \t\t\t1. FOR VOTE ENTRY     \n");
    Sleep(300);
    printf("        \t\t\t2. FOR ADMIN PANEL    \n");
    Sleep(300);
    printf("        \t\t\t3. FOR WINNER         \n");
    printf("    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT    \n\n\n");
    Sleep(500);
    printf("    \t ********So Plz Enter********\n\n\n");
    int T;
    if (scanf("%d", &T) != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    switch (T) {
        case 1:
            start = voter_insert(start);
            break;
        case 2:
            admin();
            break;
        case 3:
            winner();
            break;
        default:
            main_logs(start);
    }
    return start;
}

node *voter_insert(node *start) {
    int UNIVERSAL = 0;
    int *z = &UNIVERSAL;
    node *temp;
    char name[50], birth_date[15], aadhar[20];
    system("cls");
    printf("\n\n\n\n");
    printf("\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    Sleep(300);
    printf("\t\t\t IF YOU DO WRONG %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n", R);
    Sleep(300);
    printf("\t\tPlease \n");
    Sleep(300);
    printf("\t\t\tEnter your AADHAR ID number  ");
    getchar();  // to consume the newline character left by previous input
    fgets(aadhar, sizeof(aadhar), stdin);
    strtok(aadhar, "\n");  // remove the newline character
    printf("\t\t\tEnter Your NAME   ");
    fgets(name, sizeof(name), stdin);
    strtok(name, "\n");  // remove the newline character
    printf("\t\t\tEnter Your BIRTH DATE in dd-mm-yyyy format: ");
    fgets(birth_date, sizeof(birth_date), stdin);
    strtok(birth_date, "\n");  // remove the newline character

    temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(temp->aadhar, aadhar);
    strcpy(temp->name, name);
    strcpy(temp->birth_date, birth_date);
    temp->next = NULL;
    head = temp;

    while (temp != NULL) {
        if ((strcmp(temp->aadhar, "10001") == 0 && strcmp(temp->name, "Mohit Kumar") == 0 && strcmp(temp->birth_date, "31-03-1999") == 0) ||
            (strcmp(temp->aadhar, "10002") == 0 && strcmp(temp->name, "Ganesh Kumar") == 0 && strcmp(temp->birth_date, "01-01-1999") == 0) ||
            (strcmp(temp->aadhar, "10003") == 0 && strcmp(temp->name, "Kiran Kumar") == 0 && strcmp(temp->birth_date, "12-10-1999") == 0) ||
            (strcmp(temp->aadhar, "10004") == 0 && strcmp(temp->name, "Rohan Kumar") == 0 && strcmp(temp->birth_date, "08-12-1999") == 0) ||
            (strcmp(temp->aadhar, "10005") == 0 && strcmp(temp->name, "Krushna Kumar") == 0 && strcmp(temp->birth_date, "28-08-1999") == 0) ||
            (strcmp(temp->aadhar, "10006") == 0 && strcmp(temp->name, "Rohit Kumar") == 0 && strcmp(temp->birth_date, "20-10-2000") == 0) ||
            (strcmp(temp->aadhar, "10007") == 0 && strcmp(temp->name, "Pankaj Kumar") == 0 && strcmp(temp->birth_date, "02-03-1999") == 0) ||
            (strcmp(temp->aadhar, "10008") == 0 && strcmp(temp->name, "Rachin Kumar") == 0 && strcmp(temp->birth_date, "26-12-1999") == 0) ||
            (strcmp(temp->aadhar, "10009") == 0 && strcmp(temp->name, "Sanket Kumar") == 0 && strcmp(temp->birth_date, "02-01-1999") == 0) ||
            (strcmp(temp->aadhar, "10010") == 0 && strcmp(temp->name, "Satish Kumar") == 0 && strcmp(temp->birth_date, "03-01-1999") == 0)) {
            R = 3;
            start = search(temp->aadhar, temp->name, temp->birth_date, start, &UNIVERSAL);

            if (UNIVERSAL == 0) {
                voting();
            } else {
                not_again();
            }
        } else {
            R--;
            if (R == 0) {
                stop();
                break;
            }
            printf("\n\n\n\n");
            printf("\tYour AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n");
            Sleep(300);
            printf("\t\t\tPlease Re-Enter\n\n");
            Sleep(300);
            system("pause");
            start = main_logs(start);
        }
        temp = temp->next;
    }
    return start;
}

void voting() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    Sleep(300);
    printf("\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n");
    Sleep(300);
    printf("\t\t\t 1. Narendra Modi                  1. Lotus\n");
    Sleep(300);
    printf("\t\t\t 2. Rahul Gndhi                    2. Panja\n");
    Sleep(300);
    printf("\t\t\t 3. Nitish Kumar                   3. Ball\n");
    Sleep(300);
    printf("\t\t\t 4. Devandra Fadnavis              4. Cylinder\n");
    Sleep(300);
    printf("\t\t\t 5. Indira Gandhi                  5. Bat\n\n\n");

    int B, j;
    printf("\t\t\t Please, \n");
    printf("\t\t\t Enter Your Choice \n");
    for (j = 1; j <= 1; j++) {
        if (scanf("%d", &B) != 1) {
            fprintf(stderr, "Invalid input.\n");
            exit(EXIT_FAILURE);
        }

        switch (B) {
            case 1:
                vote1++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Narendra Modi\n");
                break;
            case 2:
                vote2++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Rahul Gndhi\n");
                break;
            case 3:
                vote3++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Nitish Kumar \n");
                break;
            case 4:
                vote4++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Devandra Fadnavis\n");
                break;
            case 5:
                vote5++;
                printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Indira Gandhi\n");
                break;
            default:
                printf("\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n");
                printf("\n\t\t\tENTER AGAIN\t\t\t\n");
                j--;  // retry the input
                break;
        }
    }
    printf("\n\n**************************THANK YOU***************************\n\n");
    printf("Press any key to continue.");
    getch();
}

void admin() {
    int B;
    printf("\n\n\n\n");
    printf("\t\t\t\t\tEnter Your Password To Unlock The Admin Panel\n\n");
    if (scanf("%d", &B) != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    if (B == 1234) {
        show();
    } else {
        printf("Wrong Password\n");
    }
}

void show() {
    int G;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\tPresent Vote Count :\n\n");
    Sleep(500);
    printf("\t\t\t  Narendra Modi is on     %d Votes\n", vote1);
    Sleep(500);
    printf("\t\t\t  Rahul Gndhi is on      %d Votes\n", vote2);
    Sleep(500);
    printf("\t\t\t  Nitish Kumar  is on       %d Votes\n", vote3);
    Sleep(500);
    printf("\t\t\t  Devandra Fadnavis  is on      %d Votes\n", vote4);
    Sleep(500);
    printf("\t\t\t  Indira Gandhi  is on     %d Votes\n\n\n\n", vote5);
    Sleep(500);

    printf("\t\t\t\t\tEnter Any Key For Main Logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE SPECIAL PASSWORD TO CLOSE THE VOTING PORTAL\n ");
    if (scanf("%d", &G) != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    if (G == 5678) {
        exi();
    } else {
        main_logs(start);
    }
}

void winner() {
    system("cls");
    printf("\n\n\n\n");
    if (vote2 < vote1 && vote3 < vote1 && vote4 < vote1 && vote5 < vote1)
        printf("\t\t\tThe present Winner is Narendra Modi and she has got %d votes\n\n\n\n", vote1);
    else if (vote1 < vote2 && vote3 < vote2 && vote4 < vote2 && vote5 < vote2)
        printf("\t\t\tThe present Winner is Rahul Gndhi and she has got %d votes\n\n\n\n", vote2);
    else if (vote1 < vote3 && vote2 < vote3 && vote4 < vote3 && vote5 < vote3)
        printf("\t\t\tThe present Winner is Nitish Kumar  and she has got %d votes\n\n\n\n", vote3);
    else if (vote1 < vote4 && vote2 < vote4 && vote3 < vote4 && vote5 < vote4)
        printf("\t\t\tThe present Winner is Devandra Fadnavis and he has got %d votes\n\n\n\n", vote4);
    else if (vote1 < vote5 && vote2 < vote5 && vote3 < vote5 && vote4 < vote5)
        printf("\t\t\tThe present Winner is Indira Gandhi and he has got %d votes\n\n\n\n", vote5);

    printf("\t\t\t\tEnter Any Key for Main Log\n\n");
    getch();
    main_logs(start);
}

void stop() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t (:-SORRY YOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW -:) \n\n\n");
    Sleep(500);
    printf("\t\t\t Please try again After A few Moments\n\n\n");
    Sleep(500);
    printf("\t\t\t * * *Thank You* * *  \n\n\n");
    Sleep(500);
    printf("Press any key to continue.");
    getch();
}

void not_again() {
    int A;
    system("cls");
    printf("\n\n\n\n");
    printf("\t\t\t        ***YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY***       \n\n\n");
    Sleep(300);
    printf("\t\t\t        ***YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE***     \n\n\n");
    Sleep(300);
    printf("\t\t\t If You want to see the present winner, Enter One(1) or Enter Any Other Key for Main Logs\n\n");
    Sleep(300);

    if (scanf("%d", &A) != 1) {
        fprintf(stderr, "Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    if (A == 1) {
        winner();
    } else {
        main_logs(start);
    }
}

void exi() {
    system("cls");
    printf("\n\n\n\n\n");
    Sleep(500);
    printf("\t\t\t        ***YOU ARE NOW EXITING THE PORTAL***       \n\n\n");
    Sleep(1000);
    printf("\t\t\t * * *Thank You For Using This ONLINE PLATFORM For VOTING* * *  \n\n\n");
    Sleep(1000);
    exit(0);
}

node *search(char x[], char y[], char z[], node *start, int *Y) {
    *Y = 0;
    node *t, *space;
    if (start == NULL) {
        space = (node *)malloc(sizeof(node));
        if (space == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(space->aadhar, x);
        strcpy(space->name, y);
        strcpy(space->birth_date, z);

        start = space;
        space->next = NULL;
    } else {
        t = start;
        while (t != NULL) {
            if (strcmp(t->aadhar, x) == 0 && strcmp(t->name, y) == 0 && strcmp(t->birth_date, z) == 0) {
                *Y = 1;
                break;
            }
            t = t->next;
        }

        if (*Y == 0) {
            space = (node *)malloc(sizeof(node));
            if (space == NULL) {
                fprintf(stderr, "Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }
            strcpy(space->aadhar, x);
            strcpy(space->name, y);
            strcpy(space->birth_date, z);
            space->next = start;
            start = space;
        }
    }
    return start;
}

int main() {
    while (1) {
        system("cls");
        printf("\n\n\n");
        printf("\t            ****** WELCOME TO THE ONLINE VOTING PORTAL ******        \n\n");
        printf("\t           ***************************************************        \n\n\n\n\n");
        printf("        \t\t *****Please Enter One(1) for logging vote main Logs*****    \n\n\n");
        int BB;
        if (scanf("%d", &BB) != 1) {
            fprintf(stderr, "Invalid input.\n");
            exit(EXIT_FAILURE);
        }
        if (BB == 1) {
            start = main_logs(start);
        }
    }
    return 0;
}


