#include <iostream>
using namespace std;

// ����� �����'������ ������
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// ������ ������� � ����� ������
void append(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node{ value, nullptr, nullptr };
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// ������� ������
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// �������� ��������, ����� �����
void removeMultiplesOfThree(Node*& head, Node*& tail) {
    Node* current = head;
    while (current) {
        if (current->data % 3 == 0) {
            Node* temp = current;
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next; // ���� �� ������ �������
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev; // ���� �� ������� �������
            }
            current = current->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

// ������ ����� 88 ���� ����� ���� ����� �����
void addAfterEqualPairs(Node*& head, Node*& tail) {
    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* newNode = new Node{ 88, current, current->next };
            current->next->prev = newNode;
            current->next = newNode;
            current = newNode->next; // ������� �� ���������� ����� ���� �������
        }
        else {
            current = current->next;
        }
    }
}

// �������� ���'��� ������
void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ������� �������
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // ���������� ������
    append(head, tail, 9);
    append(head, tail, 3);
    append(head, tail, 7);
    append(head, tail, 7);
    append(head, tail, 15);
    append(head, tail, 5);
    append(head, tail, 5);

    cout << "List: ";
    printList(head);

    // ��������� ��������, ������� �����
    removeMultiplesOfThree(head, tail);
    cout << "List after delete num that can be /3: ";
    printList(head);

    // ��������� ����� 88 ���� ����� ���� ����� �����
    addAfterEqualPairs(head, tail);
    cout << "List after add, to every pair of some num 88: ";
    printList(head);

    // ��������� ���'��
    freeList(head);

    return 0;
}
