#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_Institution_reverse_given_TARC_MMU_should_reverse_become_MMU_TARC(void)

{

   Institution TARC= { .name = "TARC" };



   Institution MMU= { .name = "MMU" };









    LinkedList inputList;

    LinkedList outputList;

    Stack stack;



 Stack_create_CMockExpectAndReturn(29, &stack);





 List_removeHead_CMockExpectAndReturn(32, &inputList, &TARC);

 Stack_push_CMockExpect(33, &stack, &TARC);

 List_removeHead_CMockExpectAndReturn(34, &inputList, &MMU);

 Stack_push_CMockExpect(35, &stack, &MMU);

 List_removeHead_CMockExpectAndReturn(36, &inputList, ((void *)0));





 Stack_pop_CMockExpectAndReturn(39, &stack, &MMU);

 List_addTail_CMockExpect(40, &outputList, &MMU);

 Stack_pop_CMockExpectAndReturn(41, &stack, &TARC);

 List_addTail_CMockExpect(42, &outputList, &TARC);

 Stack_pop_CMockExpectAndReturn(43, &stack, ((void *)0));





 Institution_reverse(&inputList, &outputList);



 }





void test_isUniversityCollege_given_TARUC_UARC_should_return_1_and_return_0(void){



   Institution TARUC= { .name = "TARUC",

                          .type = 2 };



   Institution UTAR= { .name = "UTAR",

                          .type = 1 };







  InstitutionType type= UniversityCollege;

  int result;



  result = isUniversityCollege (&TARUC, &type);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);



  result = isUniversityCollege (&UTAR, &type);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);







}





void test_Institution_select_that_can_slect_the_school_InstitutionTypr(void)

{



   Institution TARUC= { .name = "TARUC",

                          .type = 2 };



   Institution UTAR= { .name = "UTAR",

                          .type = 1 };





    InstitutionType type= UniversityCollege;

 int result;





 LinkedList inputList;

    LinkedList outputList;

    Stack stack;



 inputList.head = &TARUC;

 inputList.tail = &UTAR;





 Stack_create_CMockExpectAndReturn(97, &stack);



 List_removeHead_CMockExpectAndReturn(99, &inputList, &TARUC);

    Stack_push_CMockExpect(100, &stack, &TARUC);

 List_removeHead_CMockExpectAndReturn(101, &inputList, &UTAR);

    Stack_push_CMockExpect(102, &stack, &UTAR);







 List_removeHead_CMockExpectAndReturn(106, &inputList, ((void *)0));







 Stack_pop_CMockExpectAndReturn(110, &stack, &UTAR);

 List_addTail_CMockExpect(111, &outputList, &UTAR);

 Stack_pop_CMockExpectAndReturn(112, &stack, &TARUC);

 List_addTail_CMockExpect(113, &outputList, &TARUC);





 List_removeHead_CMockExpectAndReturn(116, &inputList, ((void *)0));





 result = Institution_select(&inputList, &outputList, &type, isUniversityCollege);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);









}
