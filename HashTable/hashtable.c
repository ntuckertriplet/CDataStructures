#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>


#define TABLE_SIZE 100000

typedef struct entry_t {
  char *key;
  char *value;
  struct entry_t *next;
} entry_t;

typedef struct {
  entry_t **entries;
} ht_t;

entry_t *ht_pair(const char *key, const char *value);
ht_t *ht_create(void);
void ht_set(ht_t *hashtable, const char *key, const char *value);
char *ht_get(ht_t *hashtable, const char *key);
unsigned int hash(const char *key);
void ht_dump(ht_t *hashtable);

ht_t *ht_create(void) {
  ht_t *hashtable = malloc(sizeof(ht_t) * 1);
  
  hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

  int i = 0;
  for(; i < TABLE_SIZE; ++i) {
    hashtable->entries[i] = NULL;
  }

  return hashtable;
}

void ht_set(ht_t *hashtable, const char *key, const char *value) {
  unsigned int slot = hash(key);

  entry_t *entry = hashtable->entries[slot];

  if (entry == NULL) {
    hashtable->entries[slot] = ht_pair(key, value);
    return;
  }

  entry_t *prev;

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      free(entry->value);
      entry->value = malloc(strlen(value) + 1);
      strcpy(entry->value, value);
      return;
    }

    prev = entry;
    entry = prev->next;
  }

  prev->next = ht_pair(key,value);
}

char *ht_get(ht_t *hashtable, const char *key) {
  unsigned int slot = hash(key);

  entry_t *entry = hashtable->entries[slot];

  if (entry == NULL) {
    return NULL;
  }

  while (entry != NULL) {
    if (strcmp(entry->key, key) == 0) {
      return entry->value;
    }

    entry = entry->next;
  }

  return NULL;
}

entry_t *ht_pair(const char *key, const char *value) {
  entry_t *entry = malloc(sizeof(entry) * 1);
  entry->key = malloc(strlen(key) + 1);
  entry->value = malloc(strlen(value) + 1);

  strcpy(entry->key, key);
  strcpy(entry->value, value);

  entry->next = NULL;

  return entry;
}

void ht_dump(ht_t *hashtable) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    entry_t *entry = hashtable->entries[i];

    if (entry == NULL) {
      continue;
    }

    printf("slot[%4d]: ", i);

    for(;;) {
      printf("%s=%s ", entry->key, entry->value);
      if (entry->next == NULL) {
        break;
      }
      entry = entry->next;
    }
    printf("\n");
  }
}

unsigned int hash(const char *key) {
  unsigned long int value = 0;
  unsigned int i = 0;
  unsigned int key_len = strlen(key);

  for(; i < key_len; ++i) {
    value = value * 37 + key[i];
  }

  value = value % TABLE_SIZE;

  return value;
}


int main(int argc, char *argv[]) {
  ht_t *ht = ht_create();
  
  ht_set(ht, "name1", "adam");
  ht_set(ht, "name2", "russia");
  ht_set(ht, "name3", "nate");

  ht_dump(ht);
  
  return 0;
}
