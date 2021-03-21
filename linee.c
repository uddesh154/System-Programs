#include<stdio.h>
#include<stdlib.h>
#define newnode (struct node *)malloc(sizeof(struct node))

struct node
{
	char line[100];
	struct node* next;
};

struct node *create(struct node *head)
{
	struct node *temp,*p;
	int i,n;
	temp=head;
	printf("How many lines: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=newnode;
		printf("%d$ ",i+1);
		scanf("%s",&p->line);
		p->next=NULL;
		temp->next=p;
		temp=p;
	}
	return(head);
}

int save(struct node *head,char *fn)
{
	FILE *fp;
	struct node *temp;
	fp=fopen(fn,"w");
	temp=head;
	while(temp!=NULL)
	{
		fputs(temp->line,fp);
		temp=temp->next;
	}
	fclose(fp);
}

void display(struct node *head)
{
	struct node *temp;
	int i=0;
	for(temp=head->next,i=0;temp!=NULL;temp=temp->next,i++)
	{
		printf("%d:%s ",i+1,temp->line);
	}
}

struct node *insert(struct node *head)
{
	struct node *temp,*p;
	temp=head;
	int i,pos;
	printf("Enter the line no:");
	scanf("%d",&pos);
	for(i=0;i<pos && temp!=NULL;i++)
	{
		temp=temp->next;
	}
	if(temp!=NULL)
	{
		p=newnode;
		printf("%d$",pos);
		scanf("%s",p->line);
		p->next=temp->next;
		temp->next=p;
	}
	else
	{
		printf("line not found");
	}
	return(head);
}

struct node *delete(struct node *head)
{
	struct node *temp,*p;
	temp=head;
	int i,pos;
	printf("Enter the line no to delete");
	scanf("%d",&pos);
	for(i=1;i<pos && temp->next!=NULL;i++)
	{
		temp=temp->next;
	}
	if(temp->next!=NULL)
	{
		p=temp->next;
		temp->next=p->next;
		printf("Deleted line is %s",p->line);
		free(p);
	}
	else
	{
		printf("line is not found");
	}
	return(head);
}

void main()
{
struct node *head=NULL;
struct node *create();
struct node *insert();
struct node *delete();
int i,key,q=0;
char ch,d[20];
int save();
void display();
head=newnode;
head->next=NULL;
while(1)
{
printf("\n c.create \n i.insert \n d.delete \n s.save");
printf("\n se.search \n d.display \n e.exit");
printf("\n Enter your choice");
scanf("%c",&ch);
switch(ch)
{
case 'C':head=create(head);
       break;
case 'I':head=insert(head);
       break;
case 'S':printf("Enter the file name");
         scanf("%s",d);
         i=save(head,d);
         if(i==1)
         {
         printf("File saving Error\n");
         }
         else
         {
         printf("File saved succesfully");
         }
         break;
case 'D':head=delete(head);
       display(head);
       break;
case 'P':display(head);
       break;
case 'E':exit(0);
}
}
}
