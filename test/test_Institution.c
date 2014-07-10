#include <stdio.h>
#include "unity.h"
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include "CException.h"



Institution TARC = {
						.name = "TARC",
						.address = "malaysia",
						.postcode = 10001,
						.telephone = 888,
						.type = College,
						.yearEstablished = 1959
					};

Institution TARUC = {
						.name = "TARUC",
						.address = "malaysia",
						.postcode = 10002,
						.telephone = 777,
						.type = UniversityCollege,
						.yearEstablished = 2013
					
					

					};
Institution UTAR = 	{	
						.name = "UTAR",
						.address = "malaysia",
						.postcode = 10000,
						.telephone = 999,
						.type = University,
						.yearEstablished = 2003
					};

LinkedList inputList;
LinkedList outputList;
Stack stack;



void setUp(void)
{
}

void tearDown(void)
{
}

void test_Institution_reverse_given_TARC_MMU_should_reverse_become_MMU_TARC(void){

				
  
	Stack_create_ExpectAndReturn(&stack);

	List_removeHead_ExpectAndReturn(&inputList,&TARC);
	Stack_push_Expect(&stack, &TARC);
	List_removeHead_ExpectAndReturn(&inputList,&UTAR);
	Stack_push_Expect(&stack, &UTAR);
	List_removeHead_ExpectAndReturn(&inputList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &UTAR);
	List_addTail_Expect(&outputList, &UTAR);
	Stack_pop_ExpectAndReturn(&stack, &TARC);
	List_addTail_Expect(&outputList, &TARC);
	Stack_pop_ExpectAndReturn(&stack, NULL);
		
	Institution_reverse(&inputList, &outputList);

}
		
		
void test_isUniversityCollege_given_TARUC_UTAR_should_return_1_and_return_0(void){

		int result;
		
		InstitutionType type= UniversityCollege;					  

		result = isUniversityCollege (&TARUC, &type);
		TEST_ASSERT_EQUAL ( 1,result);
	
		result = isUniversityCollege (&UTAR, &type);
		TEST_ASSERT_EQUAL ( 0,result);
	
}
		
void test_isUniversityCollege_given_TARUC_UTAR_request_college_should_return_0(void){

		int result;
		
		InstitutionType type= College;					  

		result = isUniversityCollege (&TARUC, &type);
		TEST_ASSERT_EQUAL ( 0,result);
	
		result = isUniversityCollege (&UTAR, &type);
		TEST_ASSERT_EQUAL ( 0,result);
	
}

void test_Institution_select_given_TARUC_and_select_type_as_UniversityCollege_should_return_1(void){

     int result;
  
	InstitutionType type= UniversityCollege;	
		
	List_removeHead_ExpectAndReturn(&inputList , &TARUC);
	List_addTail_Expect(&outputList , &TARUC);
	List_removeHead_ExpectAndReturn(&inputList , NULL);

	result = Institution_select(&inputList,&outputList,&type,isUniversityCollege);
	TEST_ASSERT_EQUAL(1 , result);
}


void test_Institution_select_given_UTAR_MMU_USM_and_select_type_as_University_should_return_3(void){

     int result;
  
 
 	Institution MMU = 	{.type = University };
	Institution USM = 	{.type = University };
	
  
  
	InstitutionType type= University;	
	
	
	List_removeHead_ExpectAndReturn(&inputList , &UTAR);
	List_addTail_Expect(&outputList , &UTAR);
	List_removeHead_ExpectAndReturn(&inputList , &MMU);
	List_addTail_Expect(&outputList , &MMU);
	List_removeHead_ExpectAndReturn(&inputList , &USM);
	List_addTail_Expect(&outputList , &USM);

	List_removeHead_ExpectAndReturn(&inputList , NULL);
	
	

	result = Institution_select(&inputList,&outputList,&type,isUniversityCollege);
	TEST_ASSERT_EQUAL(3 , result);
}


void test_wasEstablishedBefore_given_TARUC_year_2013_should_return_1(void){
	
    int result=0 , year = 2013;
	
	result = wasEstablishedBefore(&TARUC , &year);
	
	TEST_ASSERT_EQUAL(1 , result);
}



void test_wasEstablishedBefore_given_ABC_year_2020_should_throw_exception(void){
	

	Institution ABC= 	{		.yearEstablished = 2020  };
	
	int result=0 , year = 1995;
	CEXCEPTION_T err;

	Try
	{   result = wasEstablishedBefore(&ABC , &year);
		TEST_FAIL_MESSAGE("Should throw Invalid_yearEstablished exception");
	}
	
	Catch(err)
	{   TEST_ASSERT_EQUAL (Invalid_yearEstablished , err );
		TEST_ASSERT_EQUAL(0 , result);
	}
}








	

