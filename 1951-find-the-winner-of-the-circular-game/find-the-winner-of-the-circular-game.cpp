class Solution {
public:
    struct Node {
        int data;
        Node *next;

        Node(int x) {
            data=x;
            next=NULL;
        }
    };

    Node* makeList(int n) {
      Node *head = new Node(1);
      Node *curr = head;
      for (int i=1;i<n;i++) {
        curr->next= new Node(i+1);
        curr=curr->next;
      }
      curr->next=head;
      return head;
    }

    int findTheWinner(int n, int k) {
        Node* head = makeList(n);
      
        if (k==1) {
            return n;
        }
    
        Node* curr = head;
        while (curr->next != curr) {
            for (int i=1;i<k-1;i++) {
                curr = curr->next;
            }
            
            Node* del = curr->next;
            curr->next = curr->next->next;
            delete del;
            curr=curr->next;
        }

        int winner = curr->data;
        delete curr;  
        return winner;
    }
};