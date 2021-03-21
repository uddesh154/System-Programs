#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int nos,noi,nof,trans[MAX][MAX],final[MAX];
char input_str[MAX],input_symb[MAX];

void read()
{
	int i,j;
	printf("Enter no of states:");
	scanf("%d",&nos);
	printf("NO of final sates");
	scanf("%d",&nof);
	printf("Enter final sates");
	for(i=0;i<nof;i++)
	scanf("%d",&final[i]);
	printf("Enter no of input symbols:");
	scanf("%d",&noi);
	printf("Enter input symbols:");
	scanf("%s",input_symb);
	printf("Enter transition table");
	for(i=0;i<nos;i++)
	{
		for(j=0;j<noi;j++)
		{
			printf("d(q%d,%c)",i,input_symb[j]);
			scanf("%d",&trans[i][j]);
		}
	}
}

void show()
{
	int i,j;
 for(i=0;i<noi;i++)
  printf("%c\t",input_symb[i]);

 printf("\n");

 for(i=0;i<nos;i++)
 {
  printf("q%d\t",i);
  for(j=0;j<noi;j++)
   printf("q%d\t",trans[i][j]);
  printf("\n");
 }
}

void check()
{
 int i,j,curr;

 printf("Enter input string:");
 scanf("%s",input_str);

 curr = 0;
 for(i=0;input_str[i]!='\0';i++)
 {
  curr = trans[curr][input_str[i]-input_symb[0]];
 }

 for(i=0;i<nof;i++)
 {
  if(final[i]==curr)
  {
   printf("Accept\n");
   return;
  }
 }

 printf("Reject\n");
}

int main()
{
 int ch;
 while(1)
 {
  printf("1.Read DFA\n2.Show Transition Table\n3.Check acceptance of given string\n4.Exit\n");
  printf("Enter choice (1-4):");
  scanf("%d",&ch);

  switch(ch)
  {
  case 1:
   read();
   break;
  case 2:
   show();
   break;
  case 3:
   check();
   break;
  case 4:
   exit(0);
  }
 }
}
