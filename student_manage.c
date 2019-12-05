#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum ATTNENDANCE { NONE, ATTEND, TARDY, ABSENCE };
enum MODE { SEARCH=1, ATTENDANCE, PROGRESS, BACKUP, QUIT };

typedef struct student {
	char name[20];
	char school[20];
	int age;
	char phone[12];

	int attendance; 

	char book[20];
	int page;

	struct student* next;
}node_t;

void file_manage(FILE*, node_t**);
void mode_select(int*);
void search_name(char*);
void print_res(char*, node_t*, node_t* (*func)(char*, node_t*));
void print_att(node_t *);
void check_attendance(char*, node_t*, node_t* (*func) (char*, node_t*));
node_t* search_node (char*, node_t*); 
void progress_mode(node_t*, node_t* (*func) (char*, node_t*));
void close(node_t**);
void myflush();

void main() {
	FILE* fp = NULL;
	node_t* list_head = NULL;

	int mode;
	char name[20];

	file_manage(fp, &list_head);

	while (1) {
		mode_select(&mode);
		switch (mode) {
			case SEARCH: //SEARCH
				search_name(name);
				print_res(name, list_head, search_node);
				break;
			case ATTENDANCE: //ATTENDANCE
				search_name(name);
				check_attendance(name, list_head, search_node);
				break;
			case PROGRESS: //PROGRESS
				progress_mode(list_head, search_node);
					break;
			case BACKUP: //BACKUP
					break;
			case QUIT:
				printf("Quit\n"); 
				printf("=======================\n");
				break;
			default:
				printf("Unvalid Mode\n");
				printf("=======================\n");
				break;
		}

		if (mode == QUIT)
			break;
	}
	close(&list_head);
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

		strcpy(new_node->book, "NULL");
		new_node->attendance = NONE;
		new_node->page = 0;

		//adding nodes
		new_node->next = *list_head;
		*list_head = new_node;
	}

	fclose(fp);
	return;
}

void mode_select(int* mode) {

	printf("=======================\n");
	printf("1. Search Student\n");
	printf("2. Check Attendance\n");
	printf("3. Check Progress\n");
	printf("4. Back Up\n");  
	printf("5. Quit\n");  
	printf("=======================\n");
	printf("Select: ");
	scanf("%d", mode);
	printf("=======================\n");
	return;
}

void search_name(char* name){
	printf("Type Name: ");
	scanf("%s", name);
	printf("=======================\n");
}

void print_res(char* name, node_t* list_head, node_t* (*func) (char*, node_t*)){
	node_t* tmp_node;

	if (func(name, list_head) != NULL) {
		tmp_node = func(name, list_head);
		printf("Name: %s\n", tmp_node->name);
		printf("Age: %d\n", tmp_node->age);
		printf("School: %s\n", tmp_node->school);
		printf("Phone: %s\n", tmp_node->phone);			
		printf("Book: %s\n", tmp_node->book);
		printf("Last Page: %d\n", tmp_node->page);

		print_att(tmp_node);
		}	
	else {
		printf("No Result\n");
	}
	return;
}

void print_att(node_t * tmp_node) {
		printf("Today's attendance: ");
		switch(tmp_node->attendance){
			case NONE: printf("NONE\n"); break;
			case ATTEND: printf("ATTEND\n"); break;
			case TARDY: printf("TARDY\n"); break;
			case ABSENCE: printf("ABSENCE\n");break;
			default: printf("NULL\n"); break;
		}
}

void check_attendance(char* name, node_t* list_head, node_t* (*func) (char*, node_t*)){
	int stat;
	node_t* tmp_node;
	
	if (func(name, list_head) != NULL) {
		tmp_node = func(name, list_head);
		printf("Name: %s\n", tmp_node->name);
		print_att(tmp_node);
		printf("=======================\n");
		printf("1: ATTEND, 2: TARDY, 3: ABSENCE, 0: NONE\n");
		printf("Type status: ");
		scanf("%d", &stat);
		printf("=======================\n");
		tmp_node->attendance = stat;
		print_att(tmp_node);
	}
	else {
		printf("No Result\n");
	}
}

void progress_mode(node_t* list_head, node_t* (*func) (char*, node_t*)){
	int mode;
	char book[20];
	int page;
	char name[20];
	node_t* tmp_node;

	printf("1. Change Book Name\n");
	printf("2. Modify Page\n");
	printf("=======================\n");
	printf("Type mode: ");
	scanf("%d", &mode);
	printf("=======================\n");
	search_name(name);

	if (func(name, list_head) != NULL) {
		tmp_node = func(name, list_head);
		switch (mode) {
			case 1: 
				printf("Type New Book Name: ");
				scanf("%s", book);
				strcpy(tmp_node->book, book);
				myflush();
				printf("=======================\n");
			case 2:
				printf("Current Book Page: %d\n", tmp_node->page);
				printf("Type Last Page: ");
				scanf("%d", &page);
				tmp_node->page = page;
				printf("=======================\n");
				break;
			default:
				printf("Invalid Mode\n");
				break;
			}
		printf("Book: %s\n", tmp_node->book);
		printf("Page: %d\n", tmp_node->page);
		printf("=======================\n");
		}
	else {
		printf("No Result\n");
	}
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

void myflush(){
	char ch;
	while ((ch = getchar()) != '\n') {;}
	return;
}
