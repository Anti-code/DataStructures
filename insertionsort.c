/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mehmet
 *
 * Created on January 27, 2016, 1:15 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
struct Node{
    int data;
    struct Node *next;
    
};
struct Node *newNode(int data){
    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
}
struct Node * SortList1(struct Node * pList) {
    // zero or one element in list
    
    if(pList == NULL || pList->next == NULL)
        return pList;
    // head is the first element of resulting sorted list
    struct Node * head = NULL;
    while(pList != NULL) {
        struct Node * current = pList;
        pList = pList->next;
        if(head == NULL || current->data < head->data) {
            // insert into the head of the sorted list
            // or as the first element into an empty sorted list
            current->next = head;
            head = current;
        } else {
            // insert current element into proper position in non-empty sorted list
            struct Node * p = head;
            while(p != NULL) {
                if(p->next == NULL || // last element of the sorted list
                   current->data < p->next->data) // middle of the list
                {
                    // insert into middle of the sorted list or as the last element
                    current->next = p->next;
                    p->next = current;
                    break; // done
                }
                p = p->next;
            }
        }
    }
    return head;
}
int main(int argc, char** argv) {
    int i;
    int l[]={2,41,26,24,34,1,23,12,4};
    struct Node *head=NULL;
    for(i=0;i<9;i++){
        if(head==NULL){
            head=newNode(l[i]);
            continue;
        }
        struct Node *temp=head;
        while(temp->next)
            temp=temp->next;
        struct Node *new_node=newNode(l[i]);
        temp->next=new_node;
    }
    struct Node *head2=head;
    while(head->next){
    printf("%d ",head->data);
    head=head->next;}
    head2=SortList1(head2);
    puts("");
    while(head2->next){
    printf("%d ",head2->data);
    head2=head2->next;}
    return (EXIT_SUCCESS);
}

