#include "windows.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "phonebookstruct.h"

void selectmenu();
//Add new contacts
void addcontact()
{
    system("cls");
    FILE *f;
    f=fopen("project","ab+");
    printf("\n Enter name: ");
    scanf("%s",p.name);
    printf("\nEnter the address: ");
    scanf("%s",p.address);
    printf("\nEnter phone no.:");
    scanf("%ld",&p.mble_no);
    printf("\nEnter e-mail:");
    scanf("%s",p.mail);
    fwrite(&p,sizeof(p),1,f);

    fflush(stdin);

    printf("\ncontact saved");
    fclose(f);
    printf("\n\nEnter any key");
	getch();
    system("cls");
    selectmenu();
}
//List saved contacts
void listcontact()
{
    FILE *f;
    f=fopen("project","rb");
    if(f==NULL)
    {
        printf("\nfile opening error in listing :");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,f)==1)
    {
        printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAdress=%s\nMobile no=%ld\nE-mail=%s",p.name,p.address,p.mble_no,p.mail);
        getch();
        system("cls");
    }
    fclose(f);
    printf("\n Enter any key");
    getch();
    system("cls");
    selectmenu();
}

//Search Contact
void searchcontact()
{
    FILE *f;
    char name[100];
    f=fopen("project","rb");
    if(f==NULL)
    {
        printf("\n error in opening\a\a\a\a");
        exit(1);
    }
    printf("\nEnter name of person to search\n");
    scanf("%s",name);
    while(fread(&p,sizeof(p),1,f)==1)
    {
        if(strcmp(p.name,name)==0)
        {
            printf("\n\tDetail Information About %s",name);
            printf("\nName:%s\naddress:%s\nMobile no:%ld\nE-mail:%s",p.name,p.address,p.mble_no,p.mail);
            break;
        }
        else
        {
            printf("file not found");
        }
    }
    fclose(f);
    printf("\n Enter any key");
	getch();
    system("cls");
    selectmenu();
}

//Update Contact
void updatecontact()
{
    int c;
    FILE *f;
    int flag=0;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("CONTACT'S DATA NOT ADDED YET.");
			exit(1);
		}
	else
	{
	    system("cls");
		printf("\nEnter CONTACT'S NAME TO MODIFY:\n");
        scanf("%s",name);
        while(fread(&p,sizeof(p),1,f)==1)
        {
            if(strcmp(name,p.name)==0)
            {
                printf("\n Enter name:");
                scanf("%s",s.name);
                printf("\nEnter the address:");
                scanf("%s",s.address);
                printf("\nEnter phone no:");
                scanf("%ld",&s.mble_no);
                printf("\nEnter e-mail:");
                scanf("%s",s.mail);
                fseek(f,-sizeof(p),SEEK_CUR);
                fwrite(&s,sizeof(p),1,f);
                flag=1;
                break;
            }
        fflush(stdin);
        }

        if(flag==1)
        {
            printf("\n your data id modified");

        }
        else
        {
                printf(" \n data is not found");

        }
    fclose(f);
    }

	printf("\n Enter any key");
	getch();
    system("cls");
	selectmenu();
}


//Delete Contact
void deletecontact()
{
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{
			printf("CONTACT'S DATA NOT ADDED YET.");
		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)
        {
            printf("file opaning error");
        }
		else
        {
		printf("Enter CONTACT'S NAME:");
		scanf("%s",name);
		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
            {
				fwrite(&p,sizeof(p),1,ft);
			}
            if(strcmp(p.name,name)==0)
            {
                flag=1;
            }
        }
        fclose(f);
        fclose(ft);
        if(flag!=1)
        {
            printf("NO CONACT'S RECORD TO DELETE.");
            remove("temp.txt");
        }
        else
        {
            remove("project");
            rename("temp.txt","project");
            printf("RECORD DELETED SUCCESSFULLY.");

        }
        }
        }

printf("\n Enter any key");
getch();
system("cls");
selectmenu();
}
