class _List {
  value: number;
  next: _List | null;
  constructor(x) {
    this.value = x;
  }
}
class List {
  HEAD: _List | null = null;
  TAIL: _List | null = null;
  push(value: number) {
    if (!this.HEAD) {
      this.HEAD = new _List(value);
      this.HEAD.next = null;
      this.TAIL = this.HEAD;
    } else {
      let temp = new _List(value);
      temp.next = null;
      this.TAIL.next = temp;
      this.TAIL = temp;
    }
  }
  printList() {
    if (this.HEAD != null) {
      let current = this.HEAD;
      while (current) {
        console.log(current.value);
        current = current.next;
      }
    }
  }
}
const llist = new List();
llist.push(1);
llist.push(2);
llist.push(3);
llist.push(4);
llist.push(5);

llist.printList();
