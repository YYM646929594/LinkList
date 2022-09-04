#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/* https://cloud.tencent.com/developer/article/1474161 */

void List_Init(List_Typedef *List_Struct)
{
    /* init linkList */
    List_Struct->next = NULL;
}

int List_Insert(List_Typedef *List_Struct, int data, int offset)
{
    int i;
    List_Typedef* node = malloc(sizeof(List_Typedef));
    node->data = data;
    node->next=NULL;

    /* find position */
    for(i=0; i<offset; i++)
        List_Struct = List_Struct->next;

    /* insert data */
    if(i==offset)
    {
        node->next = List_Struct->next;
        List_Struct->next = node;
    }

    return 0;
}

int List_TailInsert(List_Typedef *List_Struct,int data)
{
    List_Typedef *node = malloc(sizeof(List_Typedef));
    node->data = data;
    node->next = NULL;
    
    while (List_Struct->next != NULL)
    {
        List_Struct = List_Struct->next;
    }
    if(List_Struct->next == NULL)
    {
        node->next = List_Struct->next;
        List_Struct->next = node;
    }
    return 0;
}

int List_HeadInsert(List_Typedef *List_Struct,int data)
{
    List_Typedef *node = malloc(sizeof(List_Typedef));
    node->data = data;
    node->next = NULL;

    node->next = List_Struct->next;
    List_Struct->next = node;

    return 0;
}

List_Typedef* Find_Middle(List_Typedef *List_Struct)
{
    /* fast & slow pointer find middle */
    List_Typedef *slow,*fast,*temp,*middle;
    slow = fast = List_Struct ;
    
    while (fast != NULL)  
    {
        if(fast->next != NULL)
            fast = fast->next->next;
        else break;
        slow = slow->next;
    }
    middle = slow;
    printf("[ %d ]\n",middle->data);
    return middle;
}

/* https://blog.csdn.net/h84121599/article/details/85012983 */
int List_Invert(List_Typedef *List_Struct)
{
    List_Typedef *temp,*p;
    temp = p = List_Struct->next;
    List_Struct->next = NULL;

    while (p!= NULL)
    {
        temp = temp->next;  /* disconnect node1 & node2, p pointer record node1*/
        p->next = List_Struct->next;    /* p record node1, List_HeadInsert insert into  List_Struct->next front */
        List_Struct->next = p;
        p=temp;     // next node
    }
    return 0;
}

int List_DeleteData(List_Typedef *List_Struct, int data)
{
    List_Typedef *temp;
    while(List_Struct->next != NULL)
    {
        if(List_Struct->next->data == data)
        {
            /* find data delete data */
            temp = List_Struct->next;
            List_Struct->next = List_Struct->next->next;
            free(temp);
        }
        List_Struct = List_Struct->next;
    }
    return 0;

}

int List_DeleteOffset(List_Typedef *List_Struct, int offset)
{
    int i;
    List_Typedef *temp;

    if(offset < 0)
        return -1;
    
    /* find position */
    for(i=0; i<offset; i++)
        List_Struct = List_Struct->next;
    if(List_Struct->next != NULL)
    {
        /* find delete */
        temp = List_Struct->next;
        List_Struct->next = List_Struct->next->next;
        free(temp);
    }
    return 0;
}

int List_Update(List_Typedef *List_Struct, int olddata, int newdata)
{
    while(List_Struct->next != NULL)
    {
        if(List_Struct->next->data == olddata)
            List_Struct->next->data = newdata;
        List_Struct = List_Struct->next;
    }
    return 0;
}

int List_Select(List_Typedef *List_Struct, int data)
{
    while(List_Struct->next != NULL)
    {
        if(List_Struct->next->data == data)
            return 0;
        List_Struct = List_Struct->next;
    }
    return -1;
}

int List_Show(List_Typedef *List_Struct)
{
    while (List_Struct->next != NULL)
    {
        printf("%d, ",List_Struct->next->data);
        List_Struct = List_Struct->next;
    }
    printf("\n");
    return 0;
}

