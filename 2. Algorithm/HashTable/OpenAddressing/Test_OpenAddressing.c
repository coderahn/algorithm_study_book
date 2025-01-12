#include "OpenAddressing.h"

int main(void) {
    HashTable* HT = OAHT_CreateHashTable(11);

    OAHT_Set(&HT, "MSFT", "Microsoft Corporation");
    OAHT_Set(&HT, "REDH", "Red Hat Linux");
    OAHT_Set(&HT, "APAC", "Apache Org");
    OAHT_Set(&HT, "ZYMZZ", "Unisys Ops Check"); //APAC°ú Ãæµ¹

    printf("\n");
    printf("Key:%s, Value:%s\n", "MSFT", OAHT_Get(HT, "MSFT"));
    printf("Key:%s, Value:%s\n", "REDH", OAHT_Get(HT, "REDH"));
    printf("Key:%s, Value:%s\n", "APAC", OAHT_Get(HT, "APAC"));
    printf("Key:%s, Value:%s\n", "ZYMZZ", OAHT_Get(HT, "ZYMZZ"));

    OAHT_DestroyHashTable(HT);

    return 0;
}