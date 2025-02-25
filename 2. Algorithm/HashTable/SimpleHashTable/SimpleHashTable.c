#include "SimpleHashTable.h"

HashTable* SHT_CreateHashTable(int TableSize) {
    HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
    HT->Table = (Node*)malloc(sizeof(Node) * TableSize);
    HT->TableSize = TableSize;

    return HT;
}

//해시함수값 세팅
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value) {
    int Address = SHT_Hash(Key, HT->TableSize);

    HT->Table[Address].Key = Key;
    HT->Table[Address].Value = Value;
    
}

//해시함수값 가져오기
ValueType SHT_Get(HashTable* HT, KeyType Key) {
    int Address = SHT_Hash(Key, HT->TableSize);

    return HT->Table[Address].Value;   
}

//해시함수 destroy
void SHT_DestroyHashTable(HashTable* HT) {
    free(HT->Table);
    free(HT);
}

//해시알고리즘(나눗셈법)으로 해시 생성
int SHT_Hash(KeyType Key, int TableSize) {
    return Key % TableSize;
}