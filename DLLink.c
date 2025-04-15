/**
  * @file name:DLLink.c
  * @brief    :Basic functions of Double linked list
  * @author   :i33akq@163.com
  * @date     :2025/04/15
  * @version  :1.0
  * @note     :none
  * @CopyRight (C)   2024-2025   i33akq@163.com   ALL Right Reseverd
*/

#include "DLLink.h"

DLNode_t *DLLink_Creat(){
    DLNode_t *Head=(DLNode_t *)calloc(1,sizeof(DLNode_t));
    if(!Head){
        printf("calloc false");
        return false;
    }
    Head->prev=NULL;
    Head->next=NULL;
    return Head;
}

DLNode_t *DLLink_NewNode(Elemtype_t data){
    DLNode_t *New=DLLink_Creat();
    if(!New){
        printf("Failed creat a new node");
        return false;
    }

    New->data=data;
    New->prev=NULL;
    New->next=NULL;
    return New;
}

bool DLLink_HeadInsert(DLNode_t *Head,Elemtype_t data){
    DLNode_t *New=DLLink_NewNode(data);
    if(!New){
        printf("Failed creat a new node");
        return false;
    }
    if(Head->next==NULL){
        Head->next=New;
        return true;
    }

    New->next=Head->next;
    New->prev=Head;
    Head->next=New;
    return true;
}

bool DLLink_TailInsert(DLNode_t *Head,Elemtype_t data){
    DLNode_t *New=DLLink_NewNode(data);
    if(!New){
        printf("Failed creat a new node");
        return false;
    }
    if(Head->next==NULL){
        Head->next=New;
        return true;
    }

    DLNode_t *current=Head->next;
    while (current->next!=NULL)  current=current->next;
    New->prev=current;
    current->next=New;
    return true;
}

bool DLLink_HeadDelete(DLNode_t *Head){
    if(Head->next==NULL){
        printf("DoubleLinkedlist is empty");
        return false;
    }

    DLNode_t *currrent=Head->next;
    Head->next=currrent->next;
    if (currrent->next != NULL) {
        currrent->next->prev = NULL;
    }
    currrent->next = NULL;
    
    free(currrent);
    return true;

}

bool DLLink_TailDelete(DLNode_t *Head){
    if(Head->next==NULL){
        printf("DoubleLinkedlist is emtpy");
        return false;
    }
    
    DLNode_t *current=Head->next;
    if(NULL==current->next){
        Head->next=NULL;
        free(current);
        return true;
    }

    DLNode_t *previous=Head;
    while(current->next!=NULL){
        previous=previous->next;
        current=current->next;
    }
    previous->next=NULL;
    current->prev=NULL;

    free(current);
    return true;
}

int DLLink_Length(DLNode_t *Head){
    if(Head->next==NULL){
        printf("DoubleLinkedlist is empty");
        return 0;
    }

    DLNode_t *current=Head->next;
    int Len=1;
    while(current->next!=NULL){
        Len++;
        current=current->next;
    }
    return Len;
}

void DLLink_Traverse(DLNode_t *Head)
{   
    DLNode_t *current =Head->next; 
    while(current != NULL)
    {
        if(current->next==NULL)  printf("%d ->",current->data);
        else                     printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("(NULL)\n");
}

bool DLLinkt_InDest_Place(DLNode_t *Head,Elemtype_t data,int dest){
    if(dest<0 || !Head)  return false;
    if(DLLink_Length(Head)<dest)  return false;

    DLNode_t *New=DLLink_NewNode(data);
    if(!New)  return false;

    DLNode_t *prev=Head;
    DLNode_t *current=Head->next;
    
    int cnt=1;
    while(cnt<dest){
        cnt++;
        prev=prev->next;
        current=current->next;
    }
    New->next=current;
    current->prev=New;
    New->prev=prev;
    prev->next=New;
    return true;
}

bool DLLinkt_InDest_AfterInsert(DLNode_t *Head,Elemtype_t data,int dest){
    if(!Head || Head->next==NULL)  return false;
    DLNode_t *New=DLLink_NewNode(data);
    if(!New)  return false;

    DLNode_t *current=Head;
    DLNode_t *latter=Head->next;

    /*if(latter->data==dest){
        DLLink_HeadInsert(Head,data);
        return true;
    }*/

    while(latter->next!=NULL){
        if(current->data==dest)  break;
        latter=latter->next;
        current=current->next;
    }
    if(latter->next==NULL && current->data!=dest){
        if(latter->data==dest){
            DLLink_HeadInsert(latter,data);
            return true;
        }
        return false;
    }
    New->next=latter;
    latter->prev=New;
    New->prev=current;
    current->next=New;
    return true;
}
bool DLLinkt_InDest_BeforeInsert(DLNode_t *Head,Elemtype_t data,int dest){
    if(!Head || Head->next==NULL)  return false;
    DLNode_t *New=DLLink_NewNode(data);
    if(!New)  return false;

    DLNode_t *previous=Head;
    DLNode_t *current=Head->next;

    if(current->data==dest){
        DLLink_HeadInsert(Head,data);
        return true;
    }

    while(current->next!=NULL){
        if(current->data==dest)  break;
        previous=previous->next;
        current=current->next;
    }

    if(current->next==NULL && current->data!=dest)  return false;

    New->next=current;
    current->prev=New;
    New->prev=previous;
    previous->next=New;
    return true;
}

bool DLLink_DelDest_Place(DLNode_t *Head,int dest){
    if(!Head || Head->next==NULL)  return false;
    if(DLLink_Length(Head)<dest)  return false;

    DLNode_t *previous=Head;
    DLNode_t *current=Head->next;
    int cnt=1;
    while(cnt<dest){
        cnt++;
        previous=previous->next;
        current=current->next;
    }
    if(current->next==NULL){
        previous->next=NULL;
        current->prev=NULL;
        free(current);
        return true;
    }

    previous->next=current->next;
    current->next->prev=previous;
    current->prev=NULL;
    current->next=NULL;
    free(current);
    return true;
}

bool DLLink_DelDest_Value(DLNode_t *Head,int dest){
    if(!Head || Head->next==NULL)  return false;

    DLNode_t *previous=Head;
    DLNode_t *current=Head->next;
    while(current->next!=NULL){
        if(current->data == dest)  break;
        previous=previous->next;
        current=current->next;
    }
    if(current->next==NULL){
        if(current->data==dest){
            previous->next=NULL;
            current->prev=NULL;
            free(current);
            return true;
        }
        return false;
    }
    previous->next=current->next;
    current->next->prev=previous;
    current->prev=NULL;
    current->next=NULL;
    free(current);
    return true;
}
