class Stack<T> {
  private arr: Array<T> = [];

  push(value: T) {
    this.arr.push(value);
  }

  pop() {
    this.arr.pop();
  }

  size(): number {
    return this.arr.length;
  }

  isEmpty(): boolean {
    return this.arr.length === 0;
  }

  top(): T {
    return this.arr[this.arr.length - 1];
  }
}

const S: Stack<number> = new Stack();

const expr = "45 50+690 123-+";

function operate(x: number, y: number, z: string): number {
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
function isOperator(c: string): boolean {
  return c == "+" || c == "*" || c == "-" || c == "/";
}
for (let i = 0; i < expr.length; i++) {
  if (isOperator(expr[i])) {
    let sec = S.top();
    S.pop();
    let first = S.top();
    S.pop();

    const res = operate(first, sec, expr[i]);

    S.push(res);
  } else if (expr[i] == " ") {
    continue;
  } else {
    let num = "";

    while (expr[i] !== " " && !isOperator(expr[i])) {
      num += expr[i++];
    }

    i--;

    S.push(+num);
  }
}
console.log(S);
