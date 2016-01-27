/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mehmet
 *
 * Created on January 26, 2016, 3:52 PM
 */
// C program for merge sort on doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
int list_size=0;
 
struct node *split(struct node *head);
 
// Function to merge two linked lists
struct node *merge(struct node *first, struct node *second)
{
    // If first linked list is empty
    if (!first)
        return second;
 
    // If second linked list is empty
    if (!second)
        return first;
 
    // Pick the smaller value
    if (first->data < second->data)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
 
// Function to do merge sort
struct node *mergeSort(struct node *head)
{
    if (!head || !head->next)
        return head;
    struct node *second = split(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
 
    // Merge the two sorted halves
    return merge(head,second);
}

  struct node *insertionSort(struct node *head){
     struct node *temp=NULL;
     int i;
     temp=head;
     head=head->next;
     printf("temp %d\n",temp->data);
     printf("head %d\n",head->data);
     head->prev=temp;
     head->next=temp->next;
     temp->next->prev=head;
     temp->next=head;
     temp->prev=NULL;
     return temp;
 }

// A utility function to insert a new node at the
// beginning of doubly linked list
struct node *insert(struct node **head, int data)
{
    struct node *temp =
        (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head)){
        (*head) = temp;
        return *head;}
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
        return *head;
    }
    list_size++;
}
 
// A utility function to print a doubly linked list in
// both forward and backward directions
void print(struct node *head)
{
    struct node *temp = head;
    printf("Forward Traversal using next poitner\n");
    while (head)
    {
        printf("%d ",head->data);
        temp = head;
        head = head->next;
    }
    printf("\nBackword Traversal using prev pointer\n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
 
// Utility function to swap two integers

 
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *split(struct node *head)
{
    struct node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct node *temp = slow->next;
    slow->next = NULL;
    return temp;
}
 
struct node* SortedInsert(struct node *head,int data)
 {
  struct node *temp;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data=data;
  new_node->next=NULL;
  new_node->prev=NULL;
  temp=head;

if(head==NULL)
 {
    head = new_node;      
 }

else
 {
    while(temp!=NULL)
    {
        if(temp->data<data&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        else
            {
            if(temp->next==NULL&&temp->data<data)
                {
                temp->next = new_node;
                new_node->prev = temp;
                break;
            }

           else if(temp->prev==NULL&&temp->data>data)
                {
                new_node->next=temp;
                temp->prev = new_node;
                head=new_node;
                break;
            }

           else
                {
                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev->next =new_node;
                temp->prev=new_node;
                break;
                }    
             }
         }
   }
  return head;
}
void append(struct node *root,int deger) {
    puts("hi");
    struct node *temp=root;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));  // Create a new Node
    new_node->data=deger;

    if(temp == NULL) {  //   If the list is empty 
            temp = new_node; //  Assign created Node as head 
            return;
    }

    while(temp->next) 
            temp = temp->next; // Go to the end of the list

    temp->next = new_node;		// Bind the new Node to the last Node of the list
    new_node->prev = temp;
    printf("\n%d -> %d\t", temp->data, new_node->data);
    printf("%d <- %d\n", new_node->data, temp->data);
	
}
void selectionsort(struct node *head){
    //en küçüğü bul başa getir
    struct node *temp=head;
    while(temp->next){
        temp=temp->next;
    }
}
// Driver program
int main(void)
{
    struct node *head = NULL;
    head=insert(&head,5);
    head=insert(&head,20);
    head=insert(&head,4);
    head=insert(&head,3);
    head=insert(&head,30);
    head=insert(&head,10);
    printf("HEAD-%d\n",head->data);
    print(head);
    
    
    
    return 0;
}
