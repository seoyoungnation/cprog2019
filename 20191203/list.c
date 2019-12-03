#include<stdio.h>
#include<stdlib.h>

struct node{
	int score;
	struct node* next;
};

void print_list(struct node* list_head);

void main() {
	int count = 0;
	int tmp_score = 0;
	struct node* new_node;
	struct node* list_head = NULL;

	while (count < MAX_COUNT) {
		printf("score %d: ", count);
		scanf("%d", &tmp_score);
	
		new_node = (struct node*) malloc (sizeof(struct node));
		new_node -> score = tmp_score;

		new_node -> next = list_head;
		list_head = new_node;
		print_list(list_head);
		count++;
	}
}

void print_list(struct node* list_head) {
	while(list_head != NULL) {
		printf("%d => ", list_head -> score);
		list_head = list_head -> next;
	}
	printf("\n");
}
