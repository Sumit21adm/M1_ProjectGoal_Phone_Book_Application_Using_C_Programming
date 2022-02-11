#include "phone_book.h"
#include "file_read_write.h"

int main()
{
    int i = 0;
    while (i != 2)
    {
        printf("\n\nPress 1 : To Continue...\nPress 2 : To Exit\n");
        scanf("%d", &i);
        if (i == 1)
        {
            i = 0;
            contact_options();
        }
        if (i == 2)
        {
            i = 2;
            EXIT_SUCCESS;
        }
    }
    return 0;
}

int contact_options()
{
    // writing file
    filepointer = fopen("contacts.txt", "w");

    // declaring Variable For Choosing an Option
    int option = 0;

    // Printing All The Options User Can Perform In This Program
    printf("\nEnter One Of The Choices Mentioned Below:\n");
    printf("Press: 1  To Add New Contact.\n");
    printf("Press: 2  To List All Contact.\n");
    // Getting Input from user
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\nCreating New Contact:-\nEnter Name: ");
        scanf("%s", input1.fullname);
        printf("\nEnter Contact Number: ");
        scanf("%d", &input1.mobno);

        // writing structure to file
        if (filepointer != NULL)
        {
            fprintf(filepointer, "Name: %s", input1.fullname);
            fprintf(filepointer, "Mob No: %d", input1.mobno);
            printf("New Contact is added successfully.\n");
        }
        else
        {
            printf("Something gone wrong, can't save this contact, Try Again!");
        }
        fclose(filepointer);
        break;
    case 2:
        // open contacts.txt for reading
        filepointer = fopen("contacts.txt", "r");
        if (filepointer == NULL)
        {
            fprintf(stderr, "\nSomething Went Wrong, error opening file!\n");
            exit(1);
        }
        // Read file contents
        while (fread(&output1, sizeof(struct contact), 1, filepointer))
        {
            printf("Full Name = %s", output1.fullname);
            printf("Mob No = %d \n", output1.mobno);
        }
        // close file
        fclose(filepointer);
        break;
    default:
        printf("please choose between given options only!");
        break;
    }
    return 0;
}
