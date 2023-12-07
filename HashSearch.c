#include<stdio.h>
#include<stdlib.h>
#define tableSize 10
struct Node{
    int key;
    int value;
    struct Node *next;
};
struct HashTable{
    struct Node *table[tableSize];
};
int hash(int key){
    return key % tableSize;
}
void insert(struct HashTable *ht, int key, int value){
    int index = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}
int search(struct HashTable *ht, int key){
    int index = hash(key);
    struct Node *current = ht->table[index];
    while(current != NULL){
        if(current->key == key){
            return current->value;
        }
        current = current->next;
    }
    return -1;
}
void display(struct HashTable *ht){
    printf("Hash Table:\n");
    for(int i = 0; i < tableSize; i++){
        printf("Index %d: ", i);
        struct Node *current = ht->table[i];
        while(current != NULL){
            printf("%d ", current->value);
            current = current->next;
        }                                   
        printf("\n");
    }
}
int main(){
    struct HashTable ht;
    for(int i = 0; i < tableSize; i++){
        ht.table[i] = NULL;                      
    }
    int numEntries;
    printf("Enter number of entries: ");        
    scanf("%d", &numEntries);
    for(int i = 0; i < numEntries; i++){
        int key, value;
        printf("Enter key and value for entry %d: ",i);
        scanf("%d %d", &key, &value);
        insert(&ht, key, value);
    }
    display(&ht);
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    int result = search(&ht, key);
    if(result == -1){
        printf("Key not found\n");
    }else{                             
        printf("Value: %d\n", result);
    }
return 0;
}