
    #include <iostream>
    #include <limits>
    #include <tuple>
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


    void SinglyLinkedList::printLinkedList() {
        SinglyLinkedListNode* cur = head;
        while (cur) {
            cout << cur -> data << " ";
            cur = cur -> next;
        }
        cout << '\n';
    }


    //
    void Turning(SinglyLinkedList *&A,int k, string s, int n){
        if(s.length()==1){
            SinglyLinkedListNode *it=A->head;
            k%=n;
            int len=n-k-1;
            while(len){
                it=it->next;
                len--;
            }
            A->tail->next=A->head;
            A->tail=it;
            A->head=it->next;
            A->tail->next=NULL;
        }
        else{
            k%=n;
            for(int i=0;i<k;i++){
                A->tail->next=A->head;
                A->tail=A->head;
                A->head=A->head->next;
                A->tail->next=NULL;
            }   
        }
    }

    int main(){
        SinglyLinkedList *L= new SinglyLinkedList();
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            L->insert_node(x);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int k;
            string s;
            cin>>k>>s;
            Turning(L,k,s,n);
            L->printLinkedList();
        }
        return 0;
    }