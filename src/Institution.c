#include <stdio.h>
#include "Institution.h"
#include "LinkedList.h"
#include "Stack.h"
#include "CException.h"


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

/* compare function
   input: school, type request
   output : if types are same return 1
            if type different return 0
*/

int isUniversityCollege (void *elem, void *type){


      Institution  *ptrdata= ( Institution *) elem ;       //type cas
	  InstitutionType *SchoolType = ( InstitutionType *)type;  //type cas

	  if (ptrdata->type == *SchoolType)
	  return 1;
	  
	  return 0;
	  
	 
}

/* To select the requested type from the school list, 
if the list is null then do nothing */


int Institution_select( LinkedList *inputList, LinkedList *outputList, void *criterion, int(*compare)( void *, void *) ){

    int result , No_school =0;  //No_school is the number.no of the school in the list
	Institution  *ptrdata;
 
	 do{
            ptrdata = List_removeHead (inputList) ; 
			
			 if( ptrdata != NULL)
		     result  =  compare ( ptrdata , criterion );   // compare wheter are they same type
			
			 if( result == 1 &&  ptrdata != NULL)    // if their types are same
			 {
					List_addTail(outputList ,ptrdata );  // add the school to the list
					No_school++;     // increment to the no. of school in the list
			 }
		} while( ptrdata != NULL);
		
	return No_school ;
		
}


/* To test the establish school year, if after 2014 throw exception */
int wasEstablishedBefore(void *elem , void *year)
{
	Institution *ptrdata = (Institution *) elem;
	int *Establisedyear = (int *)year;
	

    if( ptrdata->yearEstablished > 2014)
		Throw(Invalid_yearEstablished);	
		
	if( ptrdata->yearEstablished <= *Establisedyear)
		return 1;
    else
	 return 0;
}


