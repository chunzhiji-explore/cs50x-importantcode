typedef struct node
{
    int number;
           //指向node的名为next的指针
    struct node *next;
}node

node *list = NULL;
node *n = malloc(sizeof(node));
n->number = 1;
n->next = NULL;
list = n;
node *n = malloc(sizeof(node));
n->number = 2;
//将next指针赋值为list（非指向list！！）
n->next = list;
list = n;

//指针储存地址，地址代表存储数据的内存位置。
