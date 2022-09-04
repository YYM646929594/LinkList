#ifndef __List_H_
#define __List_H_

typedef struct list_t
{
    int data;
    struct list_t *next;
}List_Typedef;

/**************************************************
	初始化顺序表数据结构
	arg: 	List顺序表对象的指针（顺序表对象句柄）
	return: 0/-1
***************************************************/
void List_Init(List_Typedef *List_Struct);

/**************************************************
	向顺序表数据结构插入新元素
	arg: 	List顺序表对象的指针（顺序表对象句柄）
			data待插入的新数据
			offset插入位置
	return: 0/-1
***************************************************/
int List_Insert(List_Typedef *List_Struct, int data, int offset);

int List_TailInsert(List_Typedef *List_Struct,int data);

int List_HeadInsert(List_Typedef *List_Struct,int data);

List_Typedef* Find_Middle(List_Typedef *List_Struct);

int List_Invert(List_Typedef *List_Struct);

/**************************************************
	删除顺序表数据结构中的一个数据
	arg: 	List顺序表对象的指针（顺序表对象句柄）
			data待删除的数据
	return: 0/-1
***************************************************/
int List_DeleteData(List_Typedef *List_Struct, int data);

/**************************************************
	删除顺序表数据结构中的一个数据（按位置）
	arg: 	List顺序表对象的指针（顺序表对象句柄）
			offset待删除的数据的位置
	return: 0/-1
***************************************************/
int List_DeleteOffset(List_Typedef *List_Struct, int offset);

/**************************************************
	更新顺序表数据结构中的一个数据
	arg: 	List顺序表对象的指针（顺序表对象句柄）
			olddata待更新的数据。newdata新数据
	return: 0/-1
***************************************************/
int List_Update(List_Typedef *List_Struct, int olddata, int newdata);

/**************************************************
	查找顺序表数据结构中的一个数据
	arg: 	List顺序表对象的指针（顺序表对象句柄）
			data待查询的数据
	return: 0/-1
***************************************************/
int List_Select(List_Typedef *List_Struct, int data);

/**************************************************
	调试顺序表数据结构
	arg: 	List顺序表对象的指针（顺序表对象句柄）
			olddata待更新的数据。newdata新数据
	return: 0/-1
***************************************************/
int List_Show(List_Typedef *List_Struct);

#endif 
