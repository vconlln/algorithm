#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 100 // 假设散列表的大小为100，根据实际情况调整

// 散列表的节点结构
typedef struct HashNode {
    int key;
    struct HashNode* next;
} HashNode;

// 散列表结构
typedef struct HashTable {
    HashNode* table[TABLE_SIZE];
} HashTable;

// 创建散列表
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        exit(-1);
    }
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// 散列函数
unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

// 向散列表中插入元素
void insertHashTable(HashTable* hashTable, int key) {
    unsigned int index = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (newNode == NULL) {
        exit(-1);
    }
    newNode->key = key;
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

// 检查元素是否在散列表中
bool isKeyInHashTable(HashTable* hashTable, int key) {
    unsigned int index = hash(key);
    HashNode* node = hashTable->table[index];
    while (node != NULL) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

// 删除散列表
void deleteHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* node = hashTable->table[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(hashTable);
}

// 删除数组中的重复元素
void removeDuplicates(int* arr, int* size) {
    HashTable* hashTable = createHashTable();
    int j = 0; // 新数组的索引
    for (int i = 0; i < *size; ++i) {
        if (!isKeyInHashTable(hashTable, arr[i])) {
            insertHashTable(hashTable, arr[i]);
            arr[j++] = arr[i]; // 保留不重复的元素
        }
    }
    *size = j; // 更新数组大小
    deleteHashTable(hashTable); // 删除散列表
}

int main() {
    int arr[] = {4, 2, 5, 2, 8, 4, 1 , 2 ,  5, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    removeDuplicates(arr, &size);
    
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
