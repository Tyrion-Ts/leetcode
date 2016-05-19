/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *temp1 = l1, *temp2 = l2;
    struct ListNode *res = (struct ListNode*)malloc(sizeof(struct ListNode)), *tempRes = res;
    res->val = 0;
    res->next = NULL;
    bool increment = false;
    while(temp1 != NULL && temp2 != NULL)
    {
        struct ListNode *tt = (struct ListNode*)malloc(sizeof(struct ListNode));
        tt->val = 0;
        tempRes->next = tt;
        tempRes = tt;
        tempRes->val = temp1->val + temp2->val;
        if(increment) tempRes->val ++;
        if(tempRes->val > 9)
        {
            tempRes->val %= 10;
            increment = true;
        }
        else
            increment = false;
        
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1 != NULL)
    {
        struct ListNode *tt = (struct ListNode*)malloc(sizeof(struct ListNode));
        tt->val = 0;
        tt->next = NULL;
        tempRes->next = tt;
        tempRes = tt;
        tempRes->val = temp1->val;
        if(increment)
        {
            tempRes->val ++;
            increment = false;
        }
         if(tempRes->val > 9)
        {
            tempRes->val %= 10;
            increment = true;
        }
        else
            increment = false;
       
        temp1 = temp1->next;
    }
     while(temp2 != NULL)
    {
        struct ListNode *tt = (struct ListNode*)malloc(sizeof(struct ListNode));
        tt->val = 0;
        tt->next = NULL;
        tempRes->next = tt;
        tempRes = tt;
        tempRes->val = temp2->val;
        if(increment)
        {
            tempRes->val ++;
            increment = false;
        }
         if(tempRes->val > 9)
        {
            tempRes->val %= 10;
            increment = true;
        }
        else
            increment = false;
       
        temp2 = temp2->next;
    }
    if(increment)
    {
        struct ListNode *tt = (struct ListNode*)malloc(sizeof(struct ListNode));
        tt->val = 1;
        tt->next = NULL;
        tempRes->next = tt;
        tempRes = tt;
    }
    
    tempRes = res->next;
    free(res);
    res = tempRes;
    return res;
}