#include "unity.h"
#include "mock_Stack.h"
#include "mock_LinkedList.h"
#include "Institution.h"
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

Institution UTAR = {

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







 Stack_create_CMockExpectAndReturn(57, &stack);



 List_removeHead_CMockExpectAndReturn(59, &inputList, &TARC);

 Stack_push_CMockExpect(60, &stack, &TARC);

 List_removeHead_CMockExpectAndReturn(61, &inputList, &UTAR);

 Stack_push_CMockExpect(62, &stack, &UTAR);

 List_removeHead_CMockExpectAndReturn(63, &inputList, ((void *)0));



 Stack_pop_CMockExpectAndReturn(65, &stack, &UTAR);

 List_addTail_CMockExpect(66, &outputList, &UTAR);

 Stack_pop_CMockExpectAndReturn(67, &stack, &TARC);

 List_addTail_CMockExpect(68, &outputList, &TARC);

 Stack_pop_CMockExpectAndReturn(69, &stack, ((void *)0));



 Institution_reverse(&inputList, &outputList);



}





void test_isUniversityCollege_given_TARUC_UTAR_should_return_1_and_return_0(void){



  int result;



  InstitutionType type= UniversityCollege;



  result = isUniversityCollege (&TARUC, &type);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);



  result = isUniversityCollege (&UTAR, &type);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);



}



void test_isUniversityCollege_given_TARUC_UTAR_request_college_should_return_0(void){



  int result;



  InstitutionType type= College;



  result = isUniversityCollege (&TARUC, &type);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);



  result = isUniversityCollege (&UTAR, &type);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);



}



void test_Institution_select_given_TARUC_and_select_type_as_UniversityCollege_should_return_1(void){



     int result;



 InstitutionType type= UniversityCollege;



 List_removeHead_CMockExpectAndReturn(110, &inputList, &TARUC);

 List_addTail_CMockExpect(111, &outputList, &TARUC);

 List_removeHead_CMockExpectAndReturn(112, &inputList, ((void *)0));



 result = Institution_select(&inputList,&outputList,&type,isUniversityCollege);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

}





void test_Institution_select_given_UTAR_MMU_USM_and_select_type_as_University_should_return_3(void){



     int result;





  Institution MMU = {.type = University };

 Institution USM = {.type = University };







 InstitutionType type= University;





 List_removeHead_CMockExpectAndReturn(132, &inputList, &UTAR);

 List_addTail_CMockExpect(133, &outputList, &UTAR);

 List_removeHead_CMockExpectAndReturn(134, &inputList, &MMU);

 List_addTail_CMockExpect(135, &outputList, &MMU);

 List_removeHead_CMockExpectAndReturn(136, &inputList, &USM);

 List_addTail_CMockExpect(137, &outputList, &USM);



 List_removeHead_CMockExpectAndReturn(139, &inputList, ((void *)0));







 result = Institution_select(&inputList,&outputList,&type,isUniversityCollege);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

}





void test_wasEstablishedBefore_given_TARUC_year_2013_should_return_1(void){



  int result=0 , year = 2013;



  result = wasEstablishedBefore(&TARUC , &year);



  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_INT);

 }







void test_wasEstablishedBefore_given_ABC_year_2020_should_throw_exception(void){





 Institution ABC= { .yearEstablished = 2020 };



 int result=0 , year = 1995;

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 { result = wasEstablishedBefore(&ABC , &year);

  UnityFail( ("Should throw Invalid_yearEstablished exception"), (_U_UINT)169);;

 }



 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 { UnityAssertEqualNumber((_U_SINT)((Invalid_yearEstablished)), (_U_SINT)((err)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

 }

}
