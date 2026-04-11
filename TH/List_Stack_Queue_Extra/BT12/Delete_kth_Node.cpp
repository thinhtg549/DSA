
#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
        void printLinkedList();

};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* removeNthFromEnd(SinglyLinkedListNode* head, int n);

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    
    int llist_count;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    int n; cin >> n;
    llist->head = removeNthFromEnd(llist->head, n);
    llist->printLinkedList();
    free_singly_linked_list(llist->head);

    return 0;
}

void SinglyLinkedList::printLinkedList() {
    SinglyLinkedListNode* cur = head;
    while (cur) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << '\n';
}

//
SinglyLinkedListNode* removeNthFromEnd(SinglyLinkedListNode* head, int n){
    int len=-1;
    for(SinglyLinkedListNode *it=head;it!=NULL;it=it->next){
        len++;
    }
    len=max(0,len-n);
    SinglyLinkedListNode *temp=head,*prev=NULL;
    while(len){
        prev=temp;
        temp=temp->next;
        len--;
    }
    if(prev) prev->next=temp->next;
    else head=temp->next;
    delete temp;
    return head;
}