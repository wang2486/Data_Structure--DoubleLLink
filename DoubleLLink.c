/**
  * @file name:DoubleLLink.c
  * @brief    :functional tests
  * @author   :i33akq@163.com
  * @date     :2025/04/15
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#include "DLLink.h"

int main(int argc,char *argv[])
{
    DLNode_t *list=DLLink_Creat();
    /*DLLink_HeadInsert(list,5);
    DLLink_HeadInsert(list,4);
    DLLink_HeadInsert(list,3);
    DLLink_HeadInsert(list,2);
    DLLink_HeadInsert(list,1);*/

    DLLink_TailInsert(list,5);
    DLLink_TailInsert(list,4);
    DLLink_TailInsert(list,3);
    DLLink_TailInsert(list,2);
    DLLink_TailInsert(list,1);
    DLLink_Traverse(list);

    //DLLinkt_InDest_BeforeInsert(list,100,5);
    //DLLinkt_InDest_AfterInsert(list,100,1);
    //DLLinkt_InDest_Place(list,100,4);

    //DLLink_HeadDelete(list);
    //DLLink_TailDelete(list);
    //DLLink_DelDest_Place(list,5);
    DLLink_DelDest_Value(list,4);
    printf("%d\n",DLLink_Length(list));

    DLLink_Traverse(list);
    return 0;
}