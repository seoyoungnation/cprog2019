#include<stdio.h>
#include<stdlib.h>

enum ATTNENDANCE { NONE, ATTEND, TARDY, ABSENCE };

typedef struct student {
	char name[20];
	char school[20];
	int age;
	char phone[12];
	struct student* next;
}node_t;

typedef struct learning {
	char name[20];
	int attendance; 
	char book[20];
	int page;
	struct learning* next;
}node_f;

void file_manage(FILE* fp, node_t* list_head);

void main() {
	FILE* fp = NULL;
	node_t* list_head = NULL;
	file_manage(fp, list_head);


	
	fclose(fp);
}

void file_manage(FILE* fp, node_t* list_head){
	node_t* new_node;
	
	char name[20];
	char school[20];
	int age;
	char phone[12];

	//opening file
	fp = fopen ("data.dat", "r+");
	if (fp == NULL) {
		printf("File Opening Error\n");
		return;
	}

	//read the file
	while(!feof(fp)) {
		new_node = (node_t*) malloc (sizeof(node_t));
		fscanf(fp, "%s %s %d %s\n", new_node->name, new_node->school, &new_node->age, new_node->phone);

		//adding nodes
		new_node->next = list_head;
		list_head = new_node;
	}
}
