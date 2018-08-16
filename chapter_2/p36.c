#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval
{
	char *name;
	int value;
};

struct Nameval htmlchars[] =
{
	"AElig", 0x00c6,
	"Aacute", 0x00c1,
	"Acirc", 0x00c2,
	/* ... */
	"zeta", 0x03b6,
};

/* nvmp: compare two Nameval names */
int nvcmp(const void *va, const void *vb)
{
    const Nameval *a, *b;

    a = (Nameval *) va;
    b = (Nameval *) vb;
    return strcmp(a->name, b->name); 
}

int lookup(char *name, Nameval tab[], int ntab)
{
    Nameval key, *np;

    key.name = name;
    key.name = 0; /* Unused; anything will do */
    np = (Nameval *) bsearch(&key, tab, ntab, sizeof(tab[0]), nvcmp);

    if(np == NULL)
    {
        return -1;
    }
    else
    {
        return np-tab;
    }
}

int main()
{
    printf("%d", lookup("AElig", htmlchars, 4));
    return 0;
}