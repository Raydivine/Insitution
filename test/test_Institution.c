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
  
   Institution TARUC= {   .name = "TARUC",
                          .type = 2       };
						  
   Institution UTAR= {   .name = "UTAR",
                          .type = 1      };
		

    InstitutionType type= UniversityCollege;					  
	int result;
	
		
	LinkedList inputList;
    LinkedList outputList;
    Stack stack;
	
	inputList.head = &TARUC;
	inputList.tail = &UTAR;

	
	Stack_create_ExpectAndReturn(&stack);
	
	List_removeHead_ExpectAndReturn(&inputList, &TARUC);
    Stack_push_Expect(&stack, &TARUC);
	List_removeHead_ExpectAndReturn(&inputList, &UTAR);
    Stack_push_Expect(&stack, &UTAR);
	
	
	
	List_removeHead_ExpectAndReturn(&inputList, NULL);

	
	
	Stack_pop_ExpectAndReturn(&stack, &UTAR);
	List_addTail_Expect(&outputList, &UTAR);
	Stack_pop_ExpectAndReturn(&stack, &TARUC);
	List_addTail_Expect(&outputList, &TARUC);
	
	
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	
	result = Institution_select(&inputList, &outputList, &type, isUniversityCollege);
	TEST_ASSERT_EQUAL(2, result);
	

	
				
}










	

