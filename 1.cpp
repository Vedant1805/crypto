
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *low_head = NULL;
        ListNode *low = NULL;
        ListNode *high_head = NULL;
        ListNode *high = NULL;

        int cnt1 = 0, cnt2 = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (temp->val < x && cnt1 == 0)
            {
                low_head = temp;
                low = low_head;
                low->next = NULL;
            }
            else if (head->val >= x && cnt2 == 0)
            {
                high_head = temp;
                high = high_head;
                high->next = NULL;
            }
            else if (head->val < x && cnt1 > 0)
            {
                low->next = temp;
                low = temp;
                low->next = NULL;
            }
            else if (temp->val >= x && cnt2 > 0)
            {
                high->next = temp;
                high = temp;
                high->next = NULL;
            }
            temp = temp->next;
        }
        // low->next=high_head;

        return low_head;
    }
};