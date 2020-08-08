#include<stdio.h>
#include<stdlib.h>


typedef struct node Node;
struct node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;


void display(Node *head);
void insert_back();
Node* copy_list(Node *copy);
Node* delete_value( int key);
Node* delete_at( int pos);
Node* merge_list(Node *list1, Node *list2);

int back(Node *temp);




int main()
{
    Node *head = NULL;
    Node *list = NULL;

    Node *list1 = NULL;

     int op,num,pos,key;
    do{
        printf("\n \n ");
        printf("Options\n");
        printf("-------------- \n");
        printf("\n");
        printf("1.Insert Back  \n");
        printf("2.Delete value \n");
        printf("3.Delete At \n");
        printf("4.back \n");
        printf("5.Merge two list\n");
        printf("6.Display \n");
        printf("7.Close  \n");

        printf("\n");
        printf("Enter your option : \n");
        scanf("%d",&op);
        system("cls");


        if(op<=0 || op >7 ){
        printf("Invalid input.Please Insert Between 1 to 7\n");
        }
        else if(op ==1){


            insert_back();


        }


        else if (op ==2){
                printf("Enter the value : \n");
                scanf("%d ",&key);
                delete_value(key);
        }
        else if(op == 3){
        printf("Enter the position :");
        scanf("%d",&pos);
            delete_at( pos);
        }


        else if (op == 4){
             back(head);
        }
        else if(op == 5){
            list = copy_list(head);
            display(list);

            list1 = merge_list(head, list);
            display(list1);
        }
        else if (op == 6 ){
             display(head);
            }



    }while(op!=7);


}

void display(Node *head)
{
    Node *temp;
    temp = head;

    if(temp == NULL)
        {
           printf("list is Empty.\n");

        }
    else
        {
            printf("The list is : ");
            while(temp != NULL)
                {
                    printf("%d ",temp->data);
                    temp = temp->next;
                }

            printf("\n");
        }
}



void insert_back()
{
    Node *new_Node,*temp;
    int item;
    new_Node = (Node *) malloc(sizeof(Node));
    if(new_Node == NULL)
    {
        printf("OVERFLOW");

    }
    else
    {
        printf("Input Value to insert Back: ");
        scanf("%d",&item);
        new_Node->data=item;
        if(head == NULL)
        {
            new_Node->next = NULL;
            new_Node->prev = NULL;
            head = new_Node;
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = new_Node;
            new_Node ->prev=temp;
            new_Node->next = NULL;
        }

    }

}




int back(Node *temp)
{
    if(temp!=NULL)
    {
        while(temp->next)
        {
            temp=temp->next;
        }
        return temp->data;
    }
}
Node* delete_value( int key)
{
    if (head)
    {
        Node *temp = head, *prev;
        while(temp)
        {
            if(head->data == key)
            {
                if(temp == head)
                {
                    temp = head->next;
                    free(head);
                    return temp;
                }
                else
                {
                    prev->next = head->next;
                    free(head) ;
                    return temp;
                }
            }
            prev = head;
            head = head->next;
        }
        printf("Not Found\n");
        return temp;
    }
    else
        printf("Underflow Linked List\n");
    return head;
}
Node* delete_at( int pos)
{
    while(head)
    {
        if(pos>4 || pos<1)
        {
            printf("Index out of range");
            return NULL;
        }
        else
        {
            if(pos==1)
            {
                Node *new_head = NULL;
                new_head = head->next;
                free(head);
                return new_head;
            }
            else
            {
                Node *head2 = head;
                Node *prev, *next;
                int i=1;
                while(i<pos)
                {
                    prev = head;
                    head = head->next;
                    i++;
                }
                prev->next = head->next;
                free(head) ;
                return head2;
            }
        }
    }
    printf("Underflow Linked List\n");
    return NULL;
}
Node* copy_list(Node *copy)
{
    if(copy == NULL)
        return NULL;
    Node *temp = (Node*) malloc(sizeof (Node));
    temp->data = copy->data;
    temp->next = copy_list(copy->next) ;

    return temp;
}
Node* merge_list(Node *list1, Node *list2)
{
    Node *head, *temp;
    head = list1;
    while(list1->next)
    {
        list1 = list1->next;
    }
    list1->next = list2;
    return head;
}
