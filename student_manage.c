#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum ATTNENDANCE { NONE, ATTEND, TARDY, ABSENCE };
enum MODE { ADD, LIST, SEARCH, ATTENDANCE, PROGRESS, BACKUP, QUIT };

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

void new_student(node_t**);
node_t* file_manage(FILE*, node_t*);
void mode_select(int*, char*);
void show_list(node_t*);
void print_res(char*, node_t*, node_t* (*func)(char*, node_t*));
void print_att(node_t *);
void check_attendance(char*, node_t*, node_t* (*func) (char*, node_t*));
node_t* search_node (char*, node_t*); 
void progress_mode(char*, node_t*, node_t* (*func) (char*, node_t*));
void backup(FILE*, node_t**);
void close(node_t**);
void quit(FILE*, int*, node_t**);
void myflush();

void main() {
	FILE* fp = NULL;
	node_t* list_head = NULL;

	int mode;
	char name[20];
	int chk = 0;
	char save;

	list_head = file_manage(fp, list_head);

	while (1) {
		mode_select(&mode, name);
		switch (mode) {
			case ADD:
				new_student(&list_head);
				break;
			case LIST: 
				show_list(list_head);
				break;
			case SEARCH: //SEARCH
				print_res(name, list_head, search_node);
				break;
			case ATTENDANCE: //ATTENDANCE
				check_attendance(name, list_head, search_node);
				break;
			case PROGRESS: //PROGRESS
				progress_mode(name, list_head, search_node);
					break;
			case BACKUP: //BACKUP
				backup(fp, &list_head);
					break;
			case QUIT:
				myflush();
				scanf("%c", &save);
				if (save == 'y')
					backup(fp, &list_head);
				chk = QUIT;
				//quit(fp, &chk, &list_head);
				printf("Quit\n\n");
				//exit(0);
				break;
			default:
				printf("Unvalid Mode\n\n");
				break;
		}
		if (chk == QUIT)
			break;
	}
	close(&list_head);
}

node_t* file_manage(FILE* fp, node_t* list_head){
	node_t* new_node;

	//opening file
	fp = fopen ("data.dat", "r+");
	if (fp == NULL) {
		printf("File Opening Error\n");
		return NULL;
	}

	//read the file
	while(1) {
		new_node = (node_t*) malloc (sizeof(node_t));
		fscanf(fp, "%s %s %d %s %d %s %d", new_node->name, new_node->school, &new_node->age, new_node->phone, &new_node->attendance, new_node->book, &new_node->page); 
		if(feof(fp)!=0)
			break;
		//adding nodes
		new_node->next = list_head;
		list_head = new_node;
	}

	fclose(fp);
	return list_head;
}

void new_student(node_t** list_head ){
	node_t* new_node;

	new_node = (node_t*) malloc (sizeof(node_t));

	printf("Name: ");
	scanf("%s", new_node->name);
	printf("School: ");
	scanf("%s", new_node->school);
	printf("Age: ");
	scanf("%d", &new_node->age);
	printf("Phone: "); 
	scanf("%s", new_node->phone);	

	strcpy(new_node->book, "NULL");
	new_node->attendance = NONE;
	new_node->page = 1;	
	new_node->next = *list_head;

	*list_head = new_node;	
	return;	
}

void show_list(node_t* list_head){
	node_t* tmp = list_head;
	while(tmp) {
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	return;
}

void backup(FILE* fp, node_t** list_head){
	node_t* tmp_node;
	
	fp = fopen ("data.dat", "w+");
	if (fp == NULL) {
		printf("File Opening Error\n");
		return;
	}
	while(*list_head) {
		tmp_node = *list_head;
		fprintf(fp, "%s %s %d %s %d %s %d\n", tmp_node->name, tmp_node->school, tmp_node->age, tmp_node->phone, tmp_node->attendance, tmp_node->book, tmp_node->page); 
		*list_head = (*list_head)->next;	
	}

	fclose(fp);
	printf("\nFile Saved!\n");
}

void mode_select(int* mode, char* name) {

	printf("\n");

	printf("0. Add New Student\n");
	printf("1. Student List\n");
	printf("2. Search Student\n");
	printf("3. Check Attendance\n");
	printf("4. Check Progress\n");
	printf("5. Back Up\n");  
	printf("6. Quit\n");  
	printf("\n");
	printf("Select: ");
	scanf("%d", mode);
	switch(*mode) {
	case 2:
	case 3:
	case 4:
		printf("Type Name: ");
		scanf("%s",name);
		printf("\n");
		break;
	default: break;
	}
	return;
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
		printf("\n");
		printf("1: ATTEND, 2: TARDY, 3: ABSENCE, 0: NONE\n");
		printf("Type status: ");
		scanf("%d", &stat);
		printf("\n");
		tmp_node->attendance = stat;
		print_att(tmp_node);
	}
	else {
		printf("No Result\n");
	}
}

void progress_mode(char* name, node_t* list_head, node_t* (*func) (char*, node_t*)){
	int mode;
	char book[20];
	int page;
	node_t* tmp_node;

	printf("1. Change Book Name\n");
	printf("2. Modify Page\n");
	printf("\n");
	printf("Type mode: ");
	scanf("%d", &mode);
	printf("\n");

	if (func(name, list_head) != NULL) {
		tmp_node = func(name, list_head);
		switch (mode) {
			case 1: 
				printf("Type New Book Name: ");
				scanf("%s", book);
				strcpy(tmp_node->book, book);
				myflush();
				printf("\n");
			case 2:
				printf("Current Book Page: %d\n", tmp_node->page);
				printf("Type Last Page: ");
				scanf("%d", &page);
				tmp_node->page = page;
				printf("\n");
				break;
			default:
				printf("Invalid Mode\n");
				break;
			}
		printf("Book: %s\n", tmp_node->book);
		printf("Page: %d\n", tmp_node->page);
		printf("\n");
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

void quit(FILE* fp, int* chk, node_t** list_head){
	char save;
	printf("Do you want to save before closing? [y/n] ");
	scanf("%c", &save);
	if (save != 'y' && save != 'n')
		return;
	else if (save == 'y')
		backup(fp, list_head);
	*chk = QUIT;
	return;
}
