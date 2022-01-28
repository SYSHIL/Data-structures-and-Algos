#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#define MAX_NAME 100
#define TABLE_SIZE 10 //number of table entries

typedef struct{
    char name[MAX_NAME];
    uint8_t age;
}person;

person* hash_table[TABLE_SIZE];

void init_hash_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        hash_table[i]=NULL;
    }
    //empty hash table
}
void print_table(){
    for(int i=0;i<TABLE_SIZE;i++){
        if(hash_table[i]==NULL){
            printf("\t%d\t----\n",i);
        }
        else{
            printf("\t%d\t%s\n",i,hash_table[i]->name);
        }
    }
}
unsigned int hash(char *name){
    //generate hash
    uint16_t name_length = strnlen(name,MAX_NAME); 
    uint16_t hash_generate=0;
    for(int i=0;i<name_length;i++){
        hash_generate+=name[i];
    }
    return hash_generate%TABLE_SIZE;
}
person* create_name(){
    person* node = (person*)malloc(sizeof(person));
    if(node==NULL){
        printf("\nInsufficient memory");
        exit(1);
    }
    printf("\nEnter name :");
    scanf("%s",node->name);
    printf("\nEnter %s's age :",node->name);
    scanf("%d",&node->age);
    return node;
}
bool hash_table_insert(person* new_entry){
    int index = hash(new_entry->name);
    if(hash_table[index]!=NULL){ //occupied by someone else
        return false; 
    }
    else{
        hash_table[index]=new_entry;
        return true;
    }
}
bool lookup_hash_table(char *name){
    int index = hash(name);
    if(strncmp((hash_table[index])->name,name,MAX_NAME)==0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    init_hash_table();
    print_table();
    int number_of_entries;
    printf("\nHow many entries (table size is %d) : ",TABLE_SIZE);
    scanf("%d",&number_of_entries);
    if(number_of_entries>10){
        printf("\nToo many names exceeds table size");
        exit(1);
    }
    while(number_of_entries--){
        hash_table_insert(create_name());//create name returns pointer
    }
    print_table();
    char name[30];
    printf("\nEnter name to lookup: ");
    scanf("%s",name);
    if(lookup_hash_table(name)){
        printf("\nFound");
    }
    else{
        printf("\nNot found");
    }
   
    return 0;
}
