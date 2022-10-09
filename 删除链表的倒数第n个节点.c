//from nowcoder
//运用快慢指针解决问题

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param head ListNode类 
 * @param n int整型 
 * @return ListNode类
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n ) {
    // write code here
    struct ListNode *left = head;
    struct ListNode *right = head;
    //快指针先和慢指针拉开n个距离
    for (int i = 0; i < n && right; i++) {
        right = right->next;
    }
    //考虑快指针如果是空指针，就说明n的距离是整个链表的距离，删除头节点
    if (right == NULL) {
        return head->next;
    }
    //快指针最多只能是最后一个节点与慢指针的距离,
    //这样慢指针的下个节点就是倒数第n个节点
    while (right->next != NULL) {
        left = left->next;
        right = right->next;
    }
    //重新构建链表
    left->next = left->next->next;
    return head;
}
