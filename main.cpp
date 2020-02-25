#include <iostream>

using namespace std;

struct Node{
    Node(Node *nx, Node *pr, int n){
        next = nx;
        prew = pr;
        number = n;
    }
    Node(){}
    Node *next = nullptr;
    Node *prew = nullptr;
    int number = 0;
};

struct MyQueue{
private:
    Node *nullNode = new Node();
    Node *head = nullNode;
    Node *tail = nullNode;
    int size = 0;

public:
    void pushFirst(int n){
        if(size == 0) head->number = n;
        else {
            head = new Node(head, nullptr, n);
            head->next->prew = head;
        }
        size++;
    }
    void pushLast(int n){
        if(size == 0) tail->number = n;
        else {
            tail = new Node(nullptr, tail, n);
            tail->prew->next = tail;
        }
        size++;
    }

    int peekFirst(){
        return head->number;
    }
    int peekLast(){
        return tail->number;
    }


    int popFirst(){
        int n = head->number;
        head = head->next;
        delete(head->prew);
        head->prew = nullptr;
        size--;
        return n;
    }
    int popLast(){
        int n = tail->number;
        tail = tail->prew;
        delete(tail->next);
        tail->next = nullptr;
        size--;
        return n;
    }

    int getSize(){
        return size;
    }
    bool empty(){
        return size == 0;
    }

    void print(){
        Node *link = head;
        for(int i = 0; i < size; i++){
            cout << link->number << " ";
            link = link->next;
        }
        cout << endl;
    }
};

int main() {



    return 0;
}
