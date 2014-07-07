#include <stdio.h>
#include "Institution.h"
#include "LinkedList.h"
#include "Stack.h"


int Institution_reverse(LinkedList *inputList, LinkedList *outputList){

   Institution  *ptrdata, *popStack;
   Stack *stack =Stack_create();


   
   do {
		  ptrdata= List_removeHead(inputList);       		 //Move the data to from list head 
		  if  ( ptrdata!=NULL)
				{ 
					printf("Name:  %s\n", ptrdata->name);	//if that is data print out the name
					Stack_push( stack   ,ptrdata);		    //push data to stack
				} 
		  else	
	      printf("Address:  %p\n", ptrdata);  			   //if data is empty then print out address
      
	  } while (ptrdata!=NULL);
	  
	  
	  
	do{
		popStack = Stack_pop(stack);    			  // pop data from stack
		if(popStack!= NULL)
		   {
			  printf("Name : %s\n", popStack->name);   //if that is data print out the name
			  List_addTail( outputList , popStack );   // add the data to list tail
		   }
		else
			printf("Address : %p\n", popStack);        //if data is empty then print out address

	}while(popStack!= NULL);


}


int isUniversityCollege (void *elem1, void *type){


      Institution  *ptrdata= ( Institution *) elem1 ;
	  InstitutionType *SchoolType = ( InstitutionType *)type;
	  printf("Name:  %s\n", ptrdata->name);
	  
	  if (ptrdata->type == *SchoolType)
	  return 1;
	  
	  return 0;
	  
	 
}





int Institution_select( LinkedList *inputList, LinkedList *outputList, void *criterion, int(*compare)( void *, void *) ){

int element = 0;
	Stack *stack = Stack_create();
	Institution *dataRemove, *dataOutput;

	if((Institution *)List_removeHead(inputList) == NULL)
		return element;

	//printf("type: %d\n", *type);
	do{
		dataRemove = (Institution *)List_removeHead(inputList);
	//printf("dataRemove->type: %d\n", dataRemove->type);
		if(compare(dataRemove, criterion))
		{
			Stack_push(stack, dataRemove);
			dataOutput = (Institution *)Stack_pop(stack);
			List_addTail(outputList, dataOutput);
			element++;
		}
	}while((Institution *)List_removeHead(inputList) != NULL);

	return element;


}


