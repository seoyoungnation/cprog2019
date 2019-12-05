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

void file_manage(FILE*, node_t*, node_t*);
int select();
void close(node_t*);

void main() {
	FILE* fp = NULL;
	node_t* new_node;
	node_t* list_head = NULL;
	file_manage(fp, new_node, list_head);

	int mode;

	while (1) {
		if (mode == 4) break;
		mode = select();
		switch (mode) {
			case 1: //search
					break;
			case 2: //Check Attendance
					break;
			case 3: //Check Progress
					break;
			case 4: break;
		}
	}
	
	fclose(fp);
}

void file_manage(FILE* fp, node_t* new_node, node_t* list_head){
	
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

void select(int* mode) {
	printf("=======================\n");
	printf("1. Search Student\n");
	printf("2. Check Attendance\n");
	printf("3. Check Progress\n");
	printf("4. Quit\n");  
	printf("=======================\n");
	printf("Select: \n");
	scanf("%d", mode);
	return;
}

void close(node_t* list_head){
	node_t* tmp_node;
	while(list_head) {
		tmp_node = list_head;
		list_head = list_head->next;
		free(tmp_node);
	}
	return;
}
