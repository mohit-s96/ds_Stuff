var Stack = /** @class */ (function () {
    function Stack() {
        this.arr = [];
    }
    Stack.prototype.push = function (value) {
        this.arr.push(value);
    };
    Stack.prototype.pop = function () {
        this.arr.pop();
    };
    Stack.prototype.size = function () {
        return this.arr.length;
    };
    Stack.prototype.isEmpty = function () {
        return this.arr.length === 0;
    };
    Stack.prototype.top = function () {
        return this.arr[this.arr.length - 1];
    };
    return Stack;
}());
var S = new Stack();
var expr = "45 50+690 123-+";
function operate(x, y, z) {
    switch (z) {
        case "+":
            return x + y;
        case "-":
            return x - y;
        case "*":
            return x * y;
        case "/":
            return x / y;
        default:
            return 0;
    }
}
function isOperator(c) {
    return c == "+" || c == "*" || c == "-" || c == "/";
}
for (var i = 0; i < expr.length; i++) {
    if (isOperator(expr[i])) {
        var sec = S.top();
        S.pop();
        var first = S.top();
        S.pop();
        var res = operate(first, sec, expr[i]);
        S.push(res);
    }
    else if (expr[i] == " ") {
        continue;
    }
    else {
        var num = "";
        while (expr[i] !== " " && !isOperator(expr[i])) {
            num += expr[i++];
        }
        i--;
        S.push(+num);
    }
}
console.log(S);
