#include <stdio.h>
#include "list.h"

int main(void)
{
    List_Typedef List_Struct;

    List_Init(&List_Struct);

    int i = 10,j=0;
	while(i--)
	{
		List_Insert(&List_Struct, i, j);
		j++;
	}

    List_Show(&List_Struct);

    List_Insert(&List_Struct,80,10);
    List_Insert(&List_Struct,60,8);
    List_Show(&List_Struct);
    List_TailInsert(&List_Struct,88);
    List_Show(&List_Struct);
    List_HeadInsert(&List_Struct,45);
    List_Show(&List_Struct);

    List_DeleteData(&List_Struct,2);
    List_Show(&List_Struct);

    List_DeleteOffset(&List_Struct,6);
    List_Show(&List_Struct);

    List_Update(&List_Struct,4,6);
    List_Show(&List_Struct);

    List_DeleteData(&List_Struct,6);
    List_Show(&List_Struct);

    printf("\n[ %d ] \n",List_Select(&List_Struct,99));

    Find_Middle(&List_Struct);

    List_Invert(&List_Struct);
    List_Show(&List_Struct);

    printf("*********************************************\n");
    return 0;
}