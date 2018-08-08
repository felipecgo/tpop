#include <stdio.h>

typedef struct Nameval Nameval;

struct Nameval
{
	char *name;
	int value;
};

Nameval htmlchars[] =
{
	"AElig", 0x00c6,
	"Aacute", 0x00c1,
	"Acirc", 0x00c2,
	/* ... */
	"zeta", 0x03b6,
};

void print_Nameval(const Nameval *nameval)
{
	printf("Name: %s\t\t\tValue: 0x%04x\n", nameval->name, nameval->value);
}

int main()
{
	
	for (int i=0; i < sizeof(htmlchars)/sizeof(htmlchars[0]); i++)
	{
		print_Nameval(&htmlchars[i]);
	}
							 
	return 0;
}