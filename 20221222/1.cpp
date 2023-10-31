#include "getFirstPublicNode.h"

ListNode *getFirstPublicNode(ListNode *headA, ListNode *headB)
{
    ListNode *tmp = headA;
    ListNode *tmpb = headB;
    while (tmpb != NULL)
    {
        for (ListNode *i = tmp; i != NULL; i = i->next)
        {
            if (tmpb == i)
                return i;
        }
        tmpb = tmpb->next;
    }
    return NULL;
}