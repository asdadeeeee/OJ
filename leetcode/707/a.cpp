struct LinkNode {
  int val;
  LinkNode *next;
  LinkNode(int v, LinkNode *n) {
    val = v;
    next = n;
  }
  LinkNode() {
    val = 0;
    next = nullptr;
  }
};
class MyLinkedList {
public:
  MyLinkedList() { dum = new LinkNode(); }

  int get(int index) {
    int n = 0;
    LinkNode *ptr = dum->next;
    while (n <= index && ptr != nullptr) {
      if (n == index) {
        return ptr->val;
      }
      n++;
      ptr = ptr->next;
    }
    return -1;
  }

  void addAtHead(int val) {
    LinkNode *old_head = dum->next;
    LinkNode *new_head = new LinkNode(val, old_head);
    dum->next = new_head;
  }

  void addAtTail(int val) {
    LinkNode *tail = dum;
    while (tail->next != nullptr) {
      tail = tail->next;
    }
    LinkNode *new_tail = new LinkNode(val, nullptr);
    tail->next = new_tail;
  }

  void addAtIndex(int index, int val) {
    int n = 0;
    LinkNode *ptr = dum;
    while (n <= index && ptr != nullptr) {
      if (n == index) {
        LinkNode *new_node = new LinkNode(val, ptr->next);
        ptr->next = new_node;
        return;
      }
      n++;
      ptr = ptr->next;
    }
  }

  void deleteAtIndex(int index) {
    int n = 0;
    LinkNode *ptr = dum;
    while (n <= index && ptr != nullptr) {
      if (n == index) {
        if (ptr->next != nullptr) {
          LinkNode *temp = ptr->next;
          ptr->next = temp->next;
          delete temp;
        }
      }
      n++;
      ptr = ptr->next;
    }
  }

private:
  LinkNode *dum = nullptr;
};