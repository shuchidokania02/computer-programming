// SHUCHI DOKANIA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member{
    char name[50];
    char author[35];
    char date[35];
    char person[35];
    
}input1;

FILE *ptr, *ptr_copy;

void add_book(){
    ptr= fopen("library.txt", "ab");

    printf("Enter name: ");
    fflush(stdin);
    gets(input1.name);
    printf("Enter author: ");
    fflush(stdin);
    gets(input1.name);
    printf("Enter date: ");
    fflush(stdin);
    gets(input1.date);

    fprintf(ptr, "%s\n%s\n%s", input1.name, input1.author, input1.date);

    fclose(ptr);
}

void loan_book(){
    ptr= fopen("loan_books.txt", "ab");

    printf("Enter name: ");
    fflush(stdin);
    gets(input1.name);
    printf("Enter person: ");
    fflush(stdin);
    gets(input1.person);

    fprintf(ptr, "%s\n%s", input1.name, input1.person);

    fclose(ptr);
}

void display_all(){
    ptr= fopen("loan_books.txt", "rb");
    char str[100];

    printf("<== LOAN DETAILS ==>\n\n");

    int a=0; //line number inside file for a struct
    while(fgets(str, 100, ptr)!=NULL)
    {
        if(a==0)
        {
            printf("--------------------\n");
            printf("Name : %s\n",str);
            a++;
        }
        else if(a==1)
        {
            printf("Author : %s",str);
            a++;
        }
        else if(a==2)
        {
            printf("Person on loan to : %s",str);
            a=0;
            printf("\n--------------------\n");
            printf("\n--------------------\n");
        }
    }

    fclose(ptr);
}

void delete(){
    ptr = fopen("loan_books.txt", "r+");
    ptr_copy = fopen("loan_books_copy.txt", "w+");

    char str[100];
    char name[100];
    printf("Enter the book name to be returned: ");
    scanf("%s",&name);

    while(fgets(str, 100, ptr)!=NULL)
    {
        if(strcmp(name, str)==0)
        {
            fgets(str, 100, ptr);
            fgets(str, 100, ptr);
        }

        fputs(str, ptr_copy);
    }
    fclose(ptr);
    fclose(ptr_copy);
    remove("loan_books.txt");
    rename("loan_books_copy.txt", "loan_books.txt");
    printf("Data Successfully deleted!");

}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\n<== LIBRARY MANAGEMENT SYSTEM ==>\n\n");
        printf("1. ADD A BOOK\n");
        printf("2. LOAN A BOOK\n");
        printf("3. DISPLAY BOOKS LOANED\n");
        printf("4. RETURN A BOOK\n");
        printf("5. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice==1)
        {
            add_book();
        }
        else if(choice==2)
        {
            loan_book();
        }
        else if(choice==3)
        {
            display_all();
        }
        else if(choice==4)
        {
            delete();
        }
        else if(choice==5)
        {
            exit(1);
        }
    }

    return 0;
}