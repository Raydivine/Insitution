#ifndef Institution_H
#define Institution_H
#include "LinkedList.h"

typedef enum {Unknown, University, UniversityCollege,
							College} InstitutionType;

typedef struct Institution_t {
	char *name;
	char *address;
	unsigned long postcode;
	unsigned long int telephone;
	InstitutionType type;
	int yearEstablished;
			
}Institution;
	
int Institution_reverse(LinkedList *inputList, LinkedList *outputList);	
int Institution_select( LinkedList *inputList, LinkedList *outputList, void *criterion, int(*compare)( void *, void *) );


   
		
	

#endif // Institution_H