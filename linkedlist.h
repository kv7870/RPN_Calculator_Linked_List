struct Node {
    float data;
    Node * next;
};

class LinkedList {
    public:
        //constructor
        LinkedList();

        //add node to beginning of list
        int insertStart(float);

        //remove head
        void removeStart();

        //return the head pointer
        Node* getHead();

    private:
        Node * head;
};

