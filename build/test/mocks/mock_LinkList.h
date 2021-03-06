/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_LINKLIST_H
#define _MOCK_LINKLIST_H

#include "LinkList.h"
#include "CException.h"

void mock_LinkList_Init(void);
void mock_LinkList_Destroy(void);
void mock_LinkList_Verify(void);




#define List_addTail_Ignore() List_addTail_CMockIgnore()
void List_addTail_CMockIgnore(void);
#define List_addTail_Expect(list, element) List_addTail_CMockExpect(__LINE__, list, element)
void List_addTail_CMockExpect(UNITY_LINE_TYPE cmock_line, LinkedList* list, void* element);
typedef void (* CMOCK_List_addTail_CALLBACK)(LinkedList* list, void* element, int cmock_num_calls);
void List_addTail_StubWithCallback(CMOCK_List_addTail_CALLBACK Callback);
#define List_addTail_ExpectAndThrow(list, element, cmock_to_throw) List_addTail_CMockExpectAndThrow(__LINE__, list, element, cmock_to_throw)
void List_addTail_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, LinkedList* list, void* element, CEXCEPTION_T cmock_to_throw);
#define List_removeHead_IgnoreAndReturn(cmock_retval) List_removeHead_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void List_removeHead_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, void* cmock_to_return);
#define List_removeHead_ExpectAndReturn(list, cmock_retval) List_removeHead_CMockExpectAndReturn(__LINE__, list, cmock_retval)
void List_removeHead_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, LinkedList* list, void* cmock_to_return);
typedef void* (* CMOCK_List_removeHead_CALLBACK)(LinkedList* list, int cmock_num_calls);
void List_removeHead_StubWithCallback(CMOCK_List_removeHead_CALLBACK Callback);
#define List_removeHead_ExpectAndThrow(list, cmock_to_throw) List_removeHead_CMockExpectAndThrow(__LINE__, list, cmock_to_throw)
void List_removeHead_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, LinkedList* list, CEXCEPTION_T cmock_to_throw);
#define List_create_Ignore() List_create_CMockIgnore()
void List_create_CMockIgnore(void);
#define List_create_Expect() List_create_CMockExpect(__LINE__)
void List_create_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_List_create_CALLBACK)(int cmock_num_calls);
void List_create_StubWithCallback(CMOCK_List_create_CALLBACK Callback);
#define List_create_ExpectAndThrow(cmock_to_throw) List_create_CMockExpectAndThrow(__LINE__, cmock_to_throw)
void List_create_CMockExpectAndThrow(UNITY_LINE_TYPE cmock_line, CEXCEPTION_T cmock_to_throw);

#endif
