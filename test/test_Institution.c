#include <stdio.h>
#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_Institution_reverse_given_TARC_MMU_should_reverse_become_MMU_TARC(void)
{
   Institution TARC= {   .name = "TARC" };

   Institution MMU= {    .name = "MMU"  };
				
  
	
  
    LinkedList inputList;
    LinkedList outputList;
    Stack stack;
	
	Stack_create_ExpectAndReturn(&stack);

	
	List_removeHead_ExpectAndReturn(&inputList,&TARC);
	Stack_push_Expect(&stack, &TARC);
	List_removeHead_ExpectAndReturn(&inputList,&MMU);
	Stack_push_Expect(&stack, &MMU);
	List_removeHead_ExpectAndReturn(&inputList, NULL);

	
	Stack_pop_ExpectAndReturn(&stack, &MMU);
	List_addTail_Expect(&outputList, &MMU);
	Stack_pop_ExpectAndReturn(&stack, &TARC);
	List_addTail_Expect(&outputList, &TARC);
	Stack_pop_ExpectAndReturn(&stack, NULL);
	
	
	Institution_reverse(&inputList, &outputList);

	}
		
		
void test_isUniversityCollege_given_TARUC_UARC_should_return_1_and_return_0(void){

   Institution TARUC= {   .name = "TARUC",
                          .type = 2       };
						  
   Institution UTAR= {   .name = "UTAR",
                          .type = 1      };

	
				 					  
		InstitutionType type= UniversityCollege;					  
		int result;
	
		result = isUniversityCollege (&TARUC, &type);
		TEST_ASSERT_EQUAL ( 1,result);
	
		result = isUniversityCollege (&UTAR, &type);
		TEST_ASSERT_EQUAL ( 0,result);
	
	
	
}

		
void test_Institution_select_that_can_slect_the_school_InstitutionTypr(void)
{
  
 Institution TARUC= {    .name = "TARUC",
                         .address ="abc",
						 .postcode=01000,
						 .telephone=001,
						 .type=3,
						 .yearEstablished=1940
					};

   Institution MMU= {    .name = "MMU",
                         .address ="abc",
						 .postcode=10000,
						 .telephone=000,
						 .type=3,
						 .yearEstablished=2013
					};
					
	
   Institution UTAR= {   .name = "UTAR",
                         .address ="abc",
						 .postcode=10000,
						 .telephone=000,
						 .type=2,
						 .yearEstablished=2002
					};
					
	LinkedList inputList;
    LinkedList outputList;
    Stack stack;
	

		
//Institution_select( &inputList, &outputList, &Institution.type , &compare(&MMU.type, &TARUC.type) );
				
}










	

