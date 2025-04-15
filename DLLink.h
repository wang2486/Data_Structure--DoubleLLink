#ifndef DLLINK_H
#define DLLINK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Elemtype_t;
typedef struct  DLNode
{
    Elemtype_t data;
    struct DLNode *prev;
    struct DLNode *next;
}DLNode_t;

/**
  * @function name: DLLink_Creat
  * @brief        : Create a new empty node (Head or data node)
  * @param        : None
  * @retval       : Return pointer to newly created node
  * @version      : 1.0
  * @note         : Memory is allocated dynamically
*/
DLNode_t *DLLink_Creat();

/**
  * @function name: DLLink_NewNode
  * @brief        : Create a new data node with given value
  * @param        : @data: value for the new node
  * @retval       : Return pointer to new node
  * @version      : 1.0
  * @note         : None
*/
DLNode_t *DLLink_NewNode(Elemtype_t data);

/**
  * @function name: DLLink_HeadInsert
  * @brief        : Insert a new node at the beginning
  * @param        : @Head: list head pointer
  *                @data: data to insert
  * @retval       : true on success, false on failure
  * @version      : 1.0
  * @note         : None
*/
bool DLLink_HeadInsert(DLNode_t *Head, Elemtype_t data);

/**
  * @function name: DLLink_TailInsert
  * @brief        : Insert a new node at the end
  * @param        : @Head: list head pointer
  *                @data: data to insert
  * @retval       : true on success, false on failure
  * @version      : 1.0
  * @note         : None
*/
bool DLLink_TailInsert(DLNode_t *Head, Elemtype_t data);

/**
  * @function name: DLLink_HeadDelete
  * @brief        : Delete the node at the head (first element)
  * @param        : @Head: list head pointer
  * @retval       : true on success, false if list is empty
  * @version      : 1.0
  * @note         : None
*/
bool DLLink_HeadDelete(DLNode_t *Head);

/**
  * @function name: DLLink_TailDelete
  * @brief        : Delete the last node of the list
  * @param        : @Head: list head pointer
  * @retval       : true on success, false if list is empty
  * @version      : 1.0
  * @note         : None
*/
bool DLLink_TailDelete(DLNode_t *Head);

/**
  * @function name: DLLink_Length
  * @brief        : Get length of the list
  * @param        : @Head: list head pointer
  * @retval       : Integer length of list
  * @version      : 1.0
  * @note         : None
*/
int DLLink_Length(DLNode_t *Head);

/**
  * @function name: DLLink_Traverse
  * @brief        : Print all nodes in the list
  * @param        : @Head: list head pointer
  * @retval       : None
  * @version      : 1.0
  * @note         : Print format: value <-> value -> (NULL)
*/
void DLLink_Traverse(DLNode_t *Head);

/**
  * @function name: DLLinkt_InDest_Place
  * @brief        : Insert a node with given data at the specified position
  * @param        : @Head: the list head pointer
  *               : @data: the data to insert
  *               : @dest: the position (1-based) to insert the new node
  * @retval       : true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : Position starts from 1 (first node after head)
*/
bool DLLinkt_InDest_Place(DLNode_t *Head, Elemtype_t data, int dest);

/**
  * @function name: DLLinkt_InDest_AfterInsert
  * @brief        : Insert a node with given data after the first node with matching value
  * @param        : @Head: the list head pointer
  *               : @data: the data to insert
  *               : @dest: the target value after which to insert
  * @retval       : true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : Will insert after the first node with value equal to @dest
*/
bool DLLinkt_InDest_AfterInsert(DLNode_t *Head, Elemtype_t data, int dest);

/**
  * @function name: DLLinkt_InDest_BeforeInsert
  * @brief        : Insert a node with given data before the first node with matching value
  * @param        : @Head: the list head pointer
  *               : @data: the data to insert
  *               : @dest: the target value before which to insert
  * @retval       : true if insertion is successful, false otherwise
  * @version      : 1.0
  * @note         : Will insert before the first node with value equal to @dest
*/
bool DLLinkt_InDest_BeforeInsert(DLNode_t *Head, Elemtype_t data, int dest);

/**
  * @function name: DLLink_DelDest_Place
  * @brief        : Delete the node at the specified position
  * @param        : @Head: the list head pointer
  *               : @dest: the position (1-based) of the node to delete
  * @retval       : true if deletion is successful, false otherwise
  * @version      : 1.0
  * @note         : Position starts from 1 (first node after head)
*/
bool DLLink_DelDest_Place(DLNode_t *Head, int dest);

/**
  * @function name: DLLink_DelDest_Value
  * @brief        : Delete the first node with the specified value
  * @param        : @Head: the list head pointer
  *               : @dest: the value of the node to delete
  * @retval       : true if deletion is successful, false otherwise
  * @version      : 1.0
  * @note         : Will delete the first node that matches the value
*/
bool DLLink_DelDest_Value(DLNode_t *Head, int dest);

#endif