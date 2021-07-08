var _List = /** @class */ (function () {
    function _List(x) {
        this.value = x;
    }
    return _List;
}());
var List = /** @class */ (function () {
    function List() {
        this.HEAD = null;
        this.TAIL = null;
    }
    List.prototype.push = function (value) {
        if (!this.HEAD) {
            this.HEAD = new _List(value);
            this.HEAD.next = null;
            this.TAIL = this.HEAD;
        }
        else {
            var temp = new _List(value);
            temp.next = null;
            this.TAIL.next = temp;
            this.TAIL = temp;
        }
    };
    List.prototype.printList = function () {
        if (this.HEAD != null) {
            var current = this.HEAD;
            while (current) {
                console.log(current.value);
                current = current.next;
            }
        }
    };
    return List;
}());
var llist = new List();
llist.push(1);
llist.push(2);
llist.push(3);
llist.push(4);
llist.push(5);
llist.printList();
