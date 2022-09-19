//created by Thaw Zin Thant at sep 13 2022

//Main functions

// void insert()
// {

// }

// void research()
// {

// }

// void update()
// {

// }

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#define index_max 100
#define line_max 2048
#define True 1
#define False 0

//color func
//________________________________________

void red () 
{
  printf("\033[1;31m");
}

void yellow() 
{
  printf("\033[1;33m");
}

void blue()
{
    printf("\033[0;34m");
}

void magenta()
{
    printf("\x1b[35m");
}

void reset () 
{
  printf("\033[0m");
}

//________________________________________

struct Info{
    char name[index_max];
    char password[index_max];
    int id;
    int age;
    int amount;
    char location[index_max];
    struct Info* next;
};

struct Input{
    int input_id;
    char input_name[index_max];
    char input_password[index_max];
    int  input_age;
    int  input_amount;
    char input_location[index_max];
};

struct Input i1;

void insert_end(struct Info** head)
{
    struct Info* newNode = malloc(sizeof(struct Info));
    if(newNode == NULL)
    {
        exit(1);
    }

    newNode->id = i1.input_id;
    strcpy(newNode->name , i1.input_name);
    strcpy(newNode->password , i1.input_password);
    newNode->age = i1.input_age;
    newNode->amount = i1.input_amount;
    strcpy(newNode->location , i1.input_location);

    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Info* curr = *head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;

}

void deserialize(struct Info** head) {
    FILE* file = fopen("database.txt", "r");
    if (file == NULL)
    {
        exit(1);
    }

    while(fscanf(file, "%d %s %s %d %d %s\n",&i1.input_id,i1.input_name,i1.input_password,&i1.input_age,&i1.input_amount,i1.input_location) > 0)
    {
        insert_end(head);
    }
    fclose(file);
}

void func_1(FILE* data_file , int Integeral_input , char String_input[index_max])
{
    data_file = fopen("database.txt" , "a+");
    first:
    printf("Enter you ID: ");
    scanf("%d" , &Integeral_input);
    fprintf(data_file , "%d " , Integeral_input);

    second:
    printf("Enter your username: ");
    scanf("%s" , String_input);
    //input
    fprintf(data_file , "%s " , String_input);

    third:
    printf("Enter your password: ");
    scanf("%s" , String_input);
    //input
    fprintf(data_file , "%s " , String_input);

    fourth:
    printf("Enter your age: ");
    scanf("%d" , &Integeral_input);
    if (Integeral_input < 18)
    {
        printf("ppl who are under 18 are not allowed\n");
        goto fourth;
    }
    //input
    fprintf(data_file , "%d " , Integeral_input);

    fifth:
    printf("Enter amount: ");
    scanf("%d" , &Integeral_input);
    //input
    fprintf(data_file , "%d " , Integeral_input);

    sixth:
    printf("Enter Location: ");
    scanf("%s" , String_input);
    //input
    fprintf(data_file , "%s\n" , String_input);

    fclose(data_file);
}

void search(struct Info* head)
{
    char username[index_max];
    char pwd[index_max];
    printf("Enter your name: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", pwd);

    
    for(struct Info* temp = head;temp != NULL;temp = temp->next)
    {

        if(strcmp(username , temp->name) == 0)
        {
            if(strcmp(pwd , temp->password) == 0)
            {
                printf("Found your acc\n");
                printf("Username: %s\n", temp->name);
                printf("password: %s\n", temp->password);
            }
        }
    }
        

}

void del_line(int read_line)
{
    int lineNo = 0;
    int curr_lineNo = 0;
    FILE *data_file , *data_file_1 , *data_file_2;    
    char str[line_max] , temp[] = "temp.txt";
    char file_path[] = "database.txt";

    data_file_1 = fopen(file_path , "r");
    data_file_2 = fopen(temp , "w");
    if(data_file_1 == NULL || data_file_2 == NULL)
    {
        exit(1);
    }

    while(!feof(data_file_1))
    {
        strcpy(str , "\0");
        fgets(str , line_max , data_file_1);
        if(!feof(data_file_1))
        {
            curr_lineNo++;

            if(read_line != curr_lineNo)
            {
                fprintf(data_file_2 , "%s" , str);
            }
        }
    }
    fclose(data_file_1);
    fclose(data_file_2);
    remove(file_path);

    rename(temp , file_path);
}

void confrim_del(struct Info* head){
    deserialize(&head);
    char username[index_max];
    char pwd[index_max];
    int lineNo = 0;

    printf("Enter your name: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", pwd);

    for(struct Info* temp = head;temp != NULL;temp = temp->next)
    {
        lineNo++;
        if(strcmp(username , temp->name) == 0)
        {
            if(strcmp(pwd , temp->password) == 0)
            {
                break;
            }
        }
    }
    del_line(lineNo);
}

void update(struct Info* head)
{

    char buffer[line_max];
    char username[index_max];
    char pwd[index_max];

    int read_line = 0;
    
    printf("Enter your name: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", pwd);

    for(struct Info* temp = head;temp != NULL;temp = temp->next)
    {
        read_line++;
        if(strcmp(username , temp->name) == 0)
        {
            if(strcmp(pwd , temp->password) == 0)
            {
                strcpy(i1.input_name , temp->name);
                strcpy(i1.input_password , temp->password);
                strcpy(i1.input_location , temp->location);
                i1.input_id = temp->id;
                i1.input_age = temp->age;
                i1.input_amount = temp->amount;
                break;
            }
        }
    }

    del_line(read_line);

    int edit;
    loop:
    printf("1 = edit your name\n2 = edit your password\n3 = edit your age\n4 = edit your amount\n5 = edit your location\n");
    printf("Enter your choice: ");
    scanf("%d", &edit);

    switch(edit)
    {
        case 1:
        printf("Enter your new name: ");
        scanf("%s", i1.input_name);
        break;

        case 2:
        printf("Enter your new password: ");
        scanf("%s", i1.input_name);
        break;

        case 3:
        printf("Enter your new age: ");
        scanf("%d", &i1.input_age);
        break;

        case 4:
        printf("Enter your new amount: ");
        scanf("%d", &i1.input_amount);
        break;

        case 5:
        printf("Enter your new location: ");
        scanf("%s" , i1.input_location);
        break;

        default:
        printf("Invaild comamnd");
        goto loop;
        break;
    }

   FILE *dataFile;
   dataFile = fopen("database.txt" , "a+");
    fprintf(dataFile , "%d " , i1.input_id);
    fprintf(dataFile , "%s " , i1.input_name);
    fprintf(dataFile , "%s " , i1.input_password);
    fprintf(dataFile , "%d " , i1.input_age);
    fprintf(dataFile , "%d " , i1.input_amount);
    fprintf(dataFile , "%s\n" , i1.input_location);
   fclose(dataFile);
    
}

void length(struct Info* head)
{
    int count_line = 0;
    deserialize(&head);
    for(struct Info* curr = head;curr != NULL;curr = curr->next)
    {
        count_line++;
    }
    count_line = count_line / 2;
    red();
    printf("\n\nnumber of ppl who signed in: %d\n\n", count_line);
    reset();
    
}

void admin_printList(struct Info* head)
{
        yellow();
        for (struct Info* curr = head; curr != NULL; curr = curr->next) 
        {
            yellow();
            printf("\n____________________________________________________\n\n");
            printf("%d | " , curr->id);
            printf("%s | ", curr->name);
            printf("%s | ", curr->password);
            printf("%d | ", curr->age);
            printf("%d | ", curr->amount);
            printf("%s\n ", curr->location);
            printf("_____________________________________________________\n");
        }
        reset();
}

void admin(struct Info* head)
{
    int admin_choice;
    char confirm[index_max];
    char adminPwd[] = "ThawZinThant";
    printf("Enter admin password: ");
    scanf("%s" , confirm);

    if(strcmp(confirm , adminPwd) == 0)
    {
        deserialize(&head);
        loop:
        printf("1 = printList\n2 = print out how many users are there in database\n");
        printf("Enter choice: ");
        scanf("%d" , &admin_choice);
        switch(admin_choice){

            case 1:
            admin_printList(head);
            break;
        
            case 2:
            length(head);
            break;

            default:
            printf("Invaild command\n");
            goto loop;
            break;
            
        }
    }
}

int main()
{

    struct Info* head = NULL;
    int choice;

    //for inputting to file
    int Integeral_input;
    char String_input[index_max];

    FILE* data_file;

    blue();
    main:
    printf("Enter 0 to quit\n");
    printf("Enter 1 to store a new user's data\n");
    printf("Enter 2 to login(research)\n");
    printf("Enter 3 to update a info from a user\n");
    printf("Enter 4 to delete one of ur acc\n");
    printf("Your choice: ");
    scanf("%d" , &choice);
    switch(choice)
    {
        case 0:
        exit(0);
        break;

        case 1:
        func_1(data_file , Integeral_input , String_input);
        break;

        case 2:
        deserialize(&head);
        search(head);
        break;
        
        case 3:
        deserialize(&head);
        update(head);
        break;

        case 4:
        confrim_del(head);
        break;

        case 1000:
        admin(head);
        break;

        default:
        printf("Invaild command\n");
        goto main;
        break;
    }

}