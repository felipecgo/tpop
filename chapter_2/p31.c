#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* Lookup: binary seach for name in tab; return index */
int lookup(char *name, Nameval tab[], int ntab)
{
	int low, high, mid, cmp;
	
	low = 0;
	high = ntab - 1;
	while(low <= high)
	{
		mid = (low+high) / 2;
		cmp = strcmp(name, tab[mid].name);
		if (cmp < 0)
			high = mid - 1;
		else if (cmp > 0)
			low = mid + 1;
		else	/* Found match */
			return mid;
	}
	
	return -1; /* No match */
}

int main()
{
	printf("Posição %d\n", lookup("Aciarc", htmlchars, 4));
	
	return 0;
}