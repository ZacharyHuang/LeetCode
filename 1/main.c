#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DT1;
typedef int DT2;

typedef struct HashNode HashNode;
typedef struct HashTable HashTable;
typedef int(*HashFunc)(DT1);

struct HashNode
{
	DT1 _key;
	DT2 _value;
	HashNode* _next;
	HashNode* _prior;
};

struct HashTable
{
	HashNode* _table;
	int _size;
	HashFunc _func;
};

HashTable* HashTableCreate(int size, HashFunc func)
{
	// alloc struct
	HashTable* t = (HashTable*)calloc(1, sizeof(HashTable));
	if (!t) return NULL;

	// alloc table
	t->_table = (HashNode*)calloc(size, sizeof(HashNode));
	if (!t->_table) { free(t); return NULL; }

	// set member
	t->_size = size;
	t->_func = func;

	return t;
}

HashTable* HashTableDestroy(HashTable* table)
{
	if (!table) return NULL;
	int i;
	for (i = 0; i < table->_size; ++i)
	{
		HashNode* node;
		while (node = table->_table[i]._next)
		{
			table->_table[i]._next = node->_next;
			free(node);
		}
	}
	free(table->_table);
	free(table);
	return NULL;
}

HashNode* _HashTableFind(HashTable* table, int index, DT1 key)
{
	// get node list of the index
	HashNode* node = &table->_table[index];

	// find in list
	while (node = node->_next)
	{
		// found and return
		if (node->_key == key) return node;
	}

	// not found, return NULL
	return NULL;
}

bool HashTableFind(HashTable* table, DT1 key, DT2* value)
{
	// calculate index
	int index = table->_func(key);

	// find node
	HashNode* node = _HashTableFind(table, index, key);

	// found, set value and return true
	if (node)
	{
		*value = node->_value;
		return true;
	}

	// not found, return false
	return false;
}

bool HashTableInsert(HashTable* table, DT1 key, DT2 value)
{
	// calculate index
	int index = table->_func(key);

	// find if it exists
	HashNode* node = _HashTableFind(table, index, key);

	// exists, return false
	if (node)
	{
		return false;
	}
	// not exists, add node and return true
	else
	{
		node = (HashNode*)calloc(1, sizeof(HashNode));
		node->_key = key;
		node->_value = value;
		node->_next = table->_table[index]._next;
		node->_prior = &table->_table[index];
		node->_prior->_next = node;
		if (node->_next) node->_next->_prior = node;
		return true;
	}
}

bool HashTableModify(HashTable* table, DT1 key, DT2 value)
{
	// calculate index
	int index = table->_func(key);

	// find if it exists
	HashNode* node = _HashTableFind(table, index, key);

	// exists, modify and return true;
	if (node)
	{
		node->_value = value;
		return true;
	}
	// not exists, return false
	else
	{
		return false;
	}
}

bool HashTableDelete(HashTable* table, DT1 key)
{
	// calculate index
	int index = table->_func(key);

	// find if it exists
	HashNode* node = _HashTableFind(table, index, key);

	// exists, delete, free and return true;
	if (node)
	{
		node->_prior->_next = node->_next;
		if (node->_next) node->_next->_prior = node->_prior;
		free(node);
		return true;
	}
	// not exists, return false
	else
	{
		return false;
	}
}

int GetIndex(int x)
{
	return x & 1023;
}

int* twoSum(int* nums, int numsSize, int target)
{
	int i;
	HashTable* table = HashTableCreate(1024, GetIndex);
	for (i = 0; i < numsSize; ++i)
	{
		int j;
		if (HashTableFind(table, target - nums[i], &j))
		{
			int *res = malloc(8);
			res[0] = j + 1;
			res[1] = i + 1;
			HashTableDestroy(table);
			return res;
		}
		HashTableInsert(table, nums[i], i);
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *res = twoSum(a, 9, 17);
	printf("%d %d\n", res[0], res[1]);
	free(res);
	return 0;
}