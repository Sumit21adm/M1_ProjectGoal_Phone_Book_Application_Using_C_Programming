#include "phonebook.h" //Including user defined library

//main function
int main()
{
    system("color 5f");
    selectmenu();
}

void selectmenu()
{
    printf("\t\t----------WELCOME TO PHONEBOOK Apploication----------");

    printf("\n\n\t\t\t    HOME    \t\t\n\n");
    printf("\t1.Add Contact\n\t2.List Contact\n\t3.Search Contact\n\t4.Update Contact\n\t5.Delete Contact\n\t");

    switch(getch())
    {
        case '1':
        addcontact();
        break;
        case '2':
        listcontact();
        break;
        case '3':
        searchcontact();
        break;
        case '4':
        updatecontact();
        break;
        case '5':
        deletecontact();
        break;
        default:
        printf("\nEnter 1 to 6 only");
        printf("\n Enter any key");
        getch();
        selectmenu();
    }
}