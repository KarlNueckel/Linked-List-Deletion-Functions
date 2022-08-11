//This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node {
public:
    Node* next;
    int val;

    Node() {
        next = NULL;
        val = 0;
    }
};

class Linked {
private:
    Node* head;
public:
    Linked() {
        head = NULL;
    }
    void Insert(int num);
    void Delete_Node(int pos);
    void Delete_Occurance(int num, int occurance);
    void Delete_Last(int num);
    void Remove_All_but_First(int num);
    void Print_List();
};

void Linked::Insert(int num) {
    //Create new Node
    Node* newNode = new Node; 
    
    //Insert Value
    newNode->val = num;

    //Inserting at the front
    newNode->next = head;

    //newNode becomes the new head
    head = newNode;
}
void Linked::Delete_Node(int pos) {
    Node* ptrWalk = head;

    if (pos == 1) {
        head = ptrWalk->next;
        delete (ptrWalk);
        return;
    }
    //get to the correct position
    while (pos > 2) {
        ptrWalk = ptrWalk->next;
        pos--;
    }

    //delete the node
    Node* temp = ptrWalk->next;
    ptrWalk->next = ptrWalk->next->next;
    //cout << ptrWalk->val << endl;
    delete (temp);//temp holds the node to be deleted but ptrWalk has to stay or else the next for the previous node will be NULL

}
void Linked::Delete_Occurance(int num, int occurance) {
    Node* ptrWalk = head;
    int count = 1;

    while (ptrWalk != NULL) {
        if (ptrWalk->val == num && occurance == 1) {
            //cout << count << endl;
            Delete_Node(count);
            return;
        }
        else if (ptrWalk->val == num) {
            occurance--;
        }
        count++;
        ptrWalk = ptrWalk->next;
    }
}
void Linked::Delete_Last(int num) {
    Node* ptrWalk = head;
    int pos = 0;
    int del = 0;//delete

    while (ptrWalk != NULL) {
        pos++;
        if (ptrWalk->val == num) {
            del = pos;
        }
        ptrWalk = ptrWalk->next;
    }
    if (del == 0)
        return;
    Delete_Node(del);//delete the node
}
void Linked::Remove_All_but_First(int num) {
    Node* ptrWalk = head;
    int remove = -1;
    int pos = 0;

    while (ptrWalk != NULL) {
        pos++;
        if (ptrWalk->val == num && remove == -1) {
            remove = 0;
        }
        else if (ptrWalk->val == num && remove >= 0){
            //cout << pos << endl;
            //cout << ptrWalk->val << endl;
            //Print_List();
            //cout << endl;
            Delete_Node(pos+remove);
            remove++;
            //Print_List();
            //cout << endl;

            ptrWalk = head;
            //cout << endl << head->val << endl;

            int temp = pos;
            while (temp > 1) {
                //cout << ptrWalk->val << endl;
                ptrWalk = ptrWalk->next;
                temp--;
            }
            pos--;
        }
        ptrWalk = ptrWalk->next;
    }


}
void Linked::Print_List(){
    Node* ptrWalk = head;
    while (ptrWalk != NULL) {
        cout << ptrWalk->val << "\t";
        ptrWalk = ptrWalk->next;
    }
}

int main()
{
    std::cout << "Linked List Deletions\n";

    Linked run;
    
    run.Insert(3);
    run.Insert(1);
    run.Insert(2);
    run.Insert(3);
    run.Insert(3);

    //run.Delete_Node(5);
    
    //run.Delete_Occurance(3, 3);

    //run.Remove_All_but_First(3);

    run.Delete_Last(2);

    
    run.Print_List();


    cout << endl;
    system("pause");
    return 0;
}
