#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int wert;
	int limit;
	struct node* next;
} Node;


Node* addFirst(int w, int l, Node* head){
	Node* newHead=(Node*)malloc(sizeof(Node));
	newHead->wert=w;
	newHead->limit=l;
	newHead->next=head;
	
	Node* hilfsnode=newHead;
	for(Node* tmp=head; tmp!=NULL; tmp=tmp->next){
		tmp->wert=tmp->wert+newHead->wert;
		if(tmp->wert>tmp->limit){
			hilfsnode->next=tmp->next;
		}
		hilfsnode=tmp;
	}
	return newHead;
}

void printNode(Node* myNode){
    for(Node* tmp=myNode; tmp != NULL; tmp=tmp->next){
        printf("%d/%d ", myNode->wert, myNode->limit);
    }
}

Node* deleteNode(Node* node){

    if(node != NULL){
        free(node);
    }
    
    return NULL;
}
/*
Node* deleteList(Node* node){

    if(start != NULL){
        deleteList(node->next);
    }
    return deleteNode(start);
}
*/
int size(Node* head){
	int size=0;
	Node* tmp=head;
	while(tmp!=NULL){
		size++;
		tmp=tmp->next;
	}
	return size;
}




/*void removeAfter(Node* n){
	Node* tmp=n->next;
	
	n->next=n->next->next;
	free(tmp);
}
*/


int main(){

	
	Node* head=NULL;
	int l;
	int w;
	
	while(1){
		
		printf("Enter value and limit X/Y:\n");
		scanf("%d/%d", w, l);
		
		if((w) < (l)){
			if(w==0){
			}
			else{
				head=addfirst(w,l,head);
				printNode;
			}
		}
	}
	return 0;
}
		