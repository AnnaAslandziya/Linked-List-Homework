#include <stdio.h>
#include <stdlib.h>

struct words {
	char words[30];
	int size;
	struct words *pnext;
};

struct words* listCreate(void); //1-i element spiska 
struct words* listAdd (struct words *memory);//dobavlyat
void freelist(struct words *memory);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *fptr = NULL;
	char filestring[] = "AA BB CC DDDD EE FF";
	puts(filestring);
	fptr = fopen ("filespisok.txt", "rt");
	fputs(filestring, fptr);
	fclose (fptr); 
	return 0;
}

struct words* listCreate(void)
{
    struct words *memory;
    memory =(struct words*)malloc(sizeof(struct words));
	if (memory == 0)
	{
		printf ("Memory has not been added\n");
		exit(1);
	}
}

struct words* listAdd (struct words *memory)
{
	struct words *add;

	for (add = memory; add->pnext != NULL; add = add->pnext);

    add->pnext = (struct words*)malloc(sizeof(struct words)); 
	if (add->pnext == 0)
	{
		printf ("Memory has not been added\n");
		exit(1);
	}
	add->pnext->pnext=0;
	return add->pnext;
}

void freelist(struct words *memory)
{
	struct words *freem;
	while (memory != 0)
	{
		freem = memory;
		memory = memory -> pnext;
		if (freem)
	 	free (freem);
	}
	printf ("\nList deleted\n");	 
}
