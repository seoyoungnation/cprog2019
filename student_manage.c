#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void file_manage(FILE*, node_t**);
void mode_select(int*);
void search(node_t*, node_t* (*func)(char*, node_t*));
node_t* search_node (char* name, node_t* list_head); 
void close(node_t**);

void main() {
	FILE* fp = NULL;
	node_t* new_node;
	node_t* list_head = NULL;
	int mode;

	file_manage(fp, &list_head);

	while (1) {
		mode_select(&mode);
		switch (mode) {
			case 1: //search
				search(list_head, search_node);
				break;
			case 2: //Check Attendance
					break;
			case 3: //Check Progress
					break;
			case 4: break;
		}

		if (mode == 4)
			break;
	}
	
	close(&list_head);
	fclose(fp);
}

void file_manage(FILE* fp, node_t** list_head){
	node_t* new_node;

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
		new_node->next = *list_head;
		*list_head = new_node;
	}
}

void mode_select(int* mode) {

	printf("=======================\n");
	printf("1. Search Student\n");
	printf("2. Check Attendance\n");
	printf("3. Check Progress\n");
	printf("4. Quit\n");  
	printf("=======================\n");
	printf("Select: ");
	scanf("%d", mode);
	printf("=======================\n");
	return;
}

void search(node_t* list_head, node_t* (*func) (char*, node_t*)){
	char name[20];
	char input = '0';
	node_t* tmp_node;

	printf("=======================\n");
	printf("Type Name: ");
	scanf("%s", name);
	printf("=======================\n");
		
	if (func(name, list_head) != NULL) {
		tmp_node = func(name, list_head);
		printf("Name: %s\n", tmp_node->name);
		printf("Age: %d\n", tmp_node->age);
		printf("School: %s\n", tmp_node->school);
		printf("Phone: %s\n", tmp_node->phone);			
		}	
	else {
		printf("No Result\n");
	}
	printf("=======================\n");
	return;
}

node_t* search_node (char* name, node_t* list_head) {
	node_t* tmp = list_head;
	while (tmp) {
		if (strcmp(tmp->name, name) == 0) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return tmp;
}

void close(node_t** list_head){
	node_t* tmp_node;
	while(*list_head) {
		tmp_node = *list_head;
		*list_head = (*list_head)->next;
		free(tmp_node);
	}
	return;
}
