newnode->next = tail->next;
      newnode->prev = tail;
      tail->next->prev = newnode;
      tail->next = newnode;
      tail = newnode;