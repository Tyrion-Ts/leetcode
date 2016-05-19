#define prime 97

typedef struct hashEle{
    int index;
    struct hashEle *next;
}hashEle;


void addEle(hashEle **hashTable,int i,int index){
    hashEle *newEle = (hashEle*)malloc(sizeof(hashEle));
    newEle->index = index;
    newEle->next = NULL;
	while(i < 0)
	{
		i += prime;
	}
    hashEle *temp = hashTable[i%prime];
    if(!temp){
        hashTable[i%prime] = newEle;
		return ;
    }
    while(temp->next)
    {
        temp = temp->next;
    }
    newEle->next = temp->next;
    temp->next = newEle;
}

void deleteHashTable(hashEle **hashTable){
    int i = 0;
    for(i = 0; i<prime; i++)
    {
        hashEle *temp = hashTable[i];
        hashEle *delEle = NULL;
        while(temp)
        {
            delEle = temp;
            temp = temp->next;
            free(delEle);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
	hashEle *hashTable[prime];
    for(;i < prime; ++i)
    {
        hashTable[i] = NULL;
    }
    for(i = 0; i < numsSize; ++i)
    {
        addEle(hashTable,nums[i],i);
    }
    for(i = 0; i < numsSize; ++i)
    {
        int test = target - nums[i];
		while(test < 0)
		{
			test += prime;
		}
		test %= prime;
        if(!hashTable[test])
        {
            continue;
        }
        else
        {
            hashEle *temp = hashTable[test];
            int *res = (int*)malloc(sizeof(int)*2);
            while(temp)
            {
                if(nums[temp->index] == target - nums[i] && i != temp->index)
                {
                    res[0] = i+1;
                    res[1] = temp->index+1;
                    deleteHashTable(hashTable);
                    return res;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }
	deleteHashTable(hashTable);
    return NULL;
    
}