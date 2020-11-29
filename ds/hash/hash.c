/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

#define HASH_SIZE 911
struct  HashNode {
    int key;
    int val;
    struct HashNode* next;
};

struct Hash {
    int size;
    struct HashNode* hash;
};

void hash_init(       struct Hash* self);
void hash_insert(     struct Hash* self, int key, int val);
int  hash_find( const struct Hash* self, int key);
void hash_free(       struct Hash* self);

int* twoSum(int* nums, int numsSize, int target) {
    struct Hash hash;
    hash_init(&hash);
    int i;
    for (i = 0; i < numsSize; ++i) {
        int index = hash_find(&hash, target - nums[i]);
        if (index != -1) {
            int* result = (int*)malloc(sizeof(int)*2);
            result[0] = index;
            result[1] = i;
            hash_free(&hash);
            return result;
        }
        hash_insert(&hash, nums[i], i);
    }
    hash_free(&hash);
    return NULL;
}

void hash_init(struct Hash* self) {
    self->size = HASH_SIZE;
    self->hash = (struct HashNode*)malloc(sizeof(struct HashNode)*self->size);
    int i;
    for (i = 0; i < self->size; ++i)
        self->hash[i].next = NULL;
}

int hash_get_key_index(struct Hash* self, int key) {
    return abs(key)%self->size;
}

void hash_insert(struct Hash* self, int key, int val) {
    struct HashNode* p        = self->hash + hash_get_key_index(self, key);
    struct HashNode* new_node = (struct HashNode*)malloc(sizeof(struct HashNode));
    new_node->key  = key;
    new_node->val  = val;
    new_node->next = p->next;
    p->next        = new_node;
}

int  hash_find(const struct Hash* self, int key) {
    struct HashNode* p = self->hash + hash_get_key_index(self, key);
    while (p->next != NULL) {
        p = p->next;
        if (p->key == key)
            return p->val;
    }
    return -1;
}

void hash_free(struct Hash* self) {
    int i;
    // todo 这里没有考虑seperate chain的free，只free了一个节点。对本题来说没问题，但实际上不应该这样
    for (i = 0; i < self->size; ++i) 
        if (self->hash[i].next != NULL) {
            struct HashNode* p = self->hash[i].next;
            self->hash[i].next = p->next;
            free(p);
        }
}

int main()
{
    int nums[4] = {2,7,11,15};
    int numsSize =4;
    int* res = twoSum(nums, numsSize, 9);
    printf("%d %d\n", res[0], res[1]);
}


