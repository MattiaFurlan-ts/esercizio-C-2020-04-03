#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct
{
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

// crea un oggetto di tipo contact_type e lo inizializza con name e phone
contact_type *create_contact (char *name, char *phone)
{
    contact_type *c = malloc (sizeof (contact_type));
    if (!c) perror ("malloc");

    static int counter = 0;
    c->id = counter++;
    strncpy (c->name, name, NAME_LEN + 1);
    strncpy (c->phone, phone, PHONE_LEN + 1);
    return c;
}

// scrive su stdout i contenuti dell'oggetto
void print_contact (contact_type *person)
{
    if (person == NULL)
    {
        fprintf (stderr, "contatto non valido (NULL pointer).\n");
        exit (EXIT_FAILURE);
    }
    printf ("person: id=%d, name='%s', phone='%s'\n", person->id, person->name, person->phone);
}


int main (int argc, char **argv)
{
	contact_type *pino = create_contact ("pino rossi", "+393331234567");

	if (pino == NULL)
    	{
		printf ("errore in create_contact!\n");
		exit (EXIT_FAILURE);
	}

	contact_type *gino = create_contact ("gino verdi", "+393487654321");

	if (gino == NULL)
    	{
		printf ("errore in create_contact!\n");
		exit (EXIT_FAILURE);
	}

	print_contact (pino);

	print_contact (gino);

	return 0;
}
