#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
    int data;
    LNode *next;
}LNode;

//初始化头节点(1)
bool InitList(LNode *L)
{
    L->next=NULL;  
    return true; 
}
//初始化头节点(2)
LNode *InitListHead()
{
    LNode *L = (LNode *)malloc(sizeof(LNode));
    if(L != NULL)
        L->next=NULL;  
    return L; 
}


//删除整条链表
bool DeleteList(LNode *L)
{
    if (L == NULL)
        return false;
    LNode *p = L;
    while (p != NULL)
    {
        LNode *temp = p->next;  //保存下一节点指针
        free(p);                //释放当前节点
        p = temp;               //移动到下一节点
    }
    
    
    return true;
}

//获取目标节点位置
LNode *GetListNode(LNode *L,int index)
{
    if (index < 0)
        return NULL;
    LNode *p=L;
    int i=0;
    while (p != NULL && i<index)
    {
        p=p->next;
        i++;
    } 
    return p;
}

//在目标位置向后插入新的节点
bool InsertNextNode(LNode *L,int index,int val)
{
    if(index < 1)
        return false;
    LNode *p=GetListNode(L,index);
    if(p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s ==NULL)
        return false;   //判断节点是否成功分配内存
    s->data = val;
    s->next = p->next;
    p->next = s;
    return true;
}

//删除目标节点
bool DeletetNode(LNode *L,int index)
{
    if(index < 1)
        return false;
    LNode *p = GetListNode(L,index-1);  //获取待删除节点前一节点位置
    if(p->next == NULL || p == NULL)    //判断目标节点或前一节点是否存在
        return false;
    LNode *p1 = p->next;    //p1为目标节点
    p->next = p1->next;     
    free(p1);   //删除目标节点
    return true;
}

//查找目标节点的值
bool GetListValue(LNode *L,int index,int *returnValue)
{
    if(index < 1)
        return false;
    LNode *p = GetListNode(L,index);
    if(p == NULL)   //判断目标节点是否存在
        return false;
    returnValue = p->data;
    return true;
}

//从头部插入新的链表
bool InsertHead(LNode *L,int val)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL)
        return false;
    p->data = val;
    p->next = L->next;
    L->next = p;
    return true;
}

//从尾部插入新的链表
bool InsertTail(LNode *L,int val)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL)
        return false;
    p->data = val; 
    p->next = NULL;
    LNode *p1 = L;
    while (p1->next != NULL)    //寻找表尾
    {
        p1 = p1->next;
    }
    p1->next = p;
    return true;
}