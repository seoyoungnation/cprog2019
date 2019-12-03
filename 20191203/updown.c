#include<stdio.h>
#include<stdlib.h>

void main() {
	int count = 0;
	int tmp_score = 0;
	node_t* new_node;
	node_t* list_head = NULL;
	node_t* next_p;
	node_t* prev_p;

	whlie (count < MAX_COUNT) {
		printf("score %d: ", count);
		scanf("%d", &tmp_score);
		
		new_node = (node_t*) malloc (sizeof(node_t));
		new_node -> score = tmp_score;

		next_p = list_head;
		prev_p = NULL;

		while (next_p) {
			if (next_p->score < new_node->score)
				break;
			prev_p = next_p;
			next_p = next_p->next;
		}
		
		new_node.next = next_p;
		
		if (prev_p) {
			prev_p->next = new_node;
		}
		else {
			list_head = new_node;
		}
		print_list(list_head);
		count++;
	}
}
