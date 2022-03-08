#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#define MAX_TABLE_SIZE 10
#define NAME_SIZE 256

typedef struct person {
	char name[NAME_SIZE];
	int value;
	struct person *next;
}person;

person *hash_table[MAX_TABLE_SIZE];

void hash_init()
{
	int index;
	for(index = 0; index<MAX_TABLE_SIZE; index++)
		hash_table[index] = NULL;
}

unsigned int hash(char *name)
{
	int length = strlen(name);
	unsigned int hash_value = 0;
	int i = 0;

	for(i=0; i<length; i++) {
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % MAX_TABLE_SIZE;
	}

	return hash_value;
}

int hash_insert(person *p)
{
	if(p==NULL)
		return false;

	int index = hash(p->name);
	p->next = (struct person *)hash_table[index];
	hash_table[index] = p;	

	return true;
}

person *hash_table_lookup(char *name)
{
	int index = hash(name);
	person *tmp = hash_table[index];
	while(tmp!=NULL && strncmp(tmp->name, name, NAME_SIZE)!=0)
		tmp = (person *)tmp->next;
	return tmp;
}

void print_hash()
{
	int i;
	printf("\nStart: \n");
	for(i = 0; i<MAX_TABLE_SIZE; i++) {
		if(hash_table[i] == NULL)
			printf("\t%i: ------\n", i);
		else {
			printf("\t%i\t", i);
			person *tmp = hash_table[i];
			while(tmp!=NULL) {
				printf("%s - ", tmp->name);
				tmp = (person *)tmp->next;
			}
			printf("\n");
		}
	}	
	printf("End: \n");
}

person *hash_table_delete(char *name)
{
	int index = hash(name);
	person *tmp = hash_table[index];
	person *prev = NULL;
	while(tmp!=NULL && strncmp(tmp->name, name, NAME_SIZE)!=0) {
		prev = tmp;
		tmp = (person *)tmp->next;
	}

	if(tmp == NULL) return NULL;

	if(prev == NULL)
		hash_table[index] = (person *)tmp->next;
	else
		prev->next = tmp->next;

	return tmp;
}

int main()
{
	bool check;

	hash_init();
	print_hash();

	person praveen = {.name = "praveen", .value = 12};
	person prem = {.name = "prem", .value = 29};;

	check = hash_insert(&praveen);
	check = hash_insert(&prem);

	person praveen1 = {.name = "praveen", .value = 12};
	check = hash_insert(&praveen1);
	person *tmp = hash_table_lookup("praveen");
	if(tmp == NULL) {
		printf("Lookup: Not Found\n");
	} else
		printf("Lookup: Found..\n");

	print_hash();

	//hash_table_delete("praveen");
	hash_table_delete("praveen");
	hash_table_delete("prem");

	print_hash();

	return 0;
}
