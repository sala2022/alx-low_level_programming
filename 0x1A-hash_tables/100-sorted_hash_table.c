#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: the size of the array
 * Return: a pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *new_table;

if (!size)
return (NULL);

new_table = malloc(sizeof(shash_table_t));
if (!new_table)
return (NULL);

new_table->size = size;
new_table->array = malloc(sizeof(shash_node_t *) * size);
if (!new_table->array)
{
free(new_table);
return (NULL);
}

for (unsigned long int i = 0; i < size; i++)
new_table->array[i] = NULL;

new_table->shead = NULL;
new_table->stail = NULL;

return (new_table);
}

/**
 * shash_table_set - Adds or updates a key-value pair in a sorted hash table.
 * @ht: Pointer to the hash table.
 * @key: The key of the key-value pair.
 * @value: The value of the key-value pair.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
if (!ht || !key || !value)
return (0);

unsigned long int index = key_index((const unsigned char *)key, ht->size);
shash_node_t *new = ht->array[index];

while (new)
{
if (strcmp(new->key, key) == 0)
{
free(new->value);
new->value = strdup(value);
if (!new->value)
return (0);
return (1);
}
new = new->next;
}

new = malloc(sizeof(shash_node_t));
if (!new)
return (0);

new->key = strdup(key);
new->value = strdup(value);
if (!new->key || !new->value)
{
free(new->key);
free(new->value);
free(new);
return (0);
}

new->next = ht->array[index];
ht->array[index] = new;

return (sorted_linked_list(ht, new));
}

/**
 * shash_table_get - Retrieves the value associated
 * with a key in a sorted hash table.
 * @ht: Pointer to the hash table.
 * @key: The key to search for.
 *
 * Return: Pointer to the value associated with the key, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
if (!ht || !key)
return (NULL);

unsigned long int index = key_index((const unsigned char *)key, ht->size);
shash_node_t *node = ht->array[index];

while (node)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}

return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: Pointer to the hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
if (ht)
{
printf("{");
shash_node_t *node = ht->shead;
int isComma = 0;

while (node)
{
if (isComma)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
isComma = 1;
node = node->snext;
}

printf("}\n");
}
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: Pointer to the hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
if (ht)
{
for (unsigned long int i = 0; i < ht->size; i++)
{
shash_node_t *node = ht->array[i];
while (node)
{
shash_node_t *tmp = node;
node = node->next;
free(tmp->key);
free(tmp->value);
free(tmp);
}
}
free(ht->array);
free(ht);
}
}

