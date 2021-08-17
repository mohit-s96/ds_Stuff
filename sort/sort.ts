class Sort {
  arr: Array<number>;
  animArr: Array<any> = [];
  constructor(arr: number[]) {
    this.arr = arr;
  }
  /**
   * @returns mutated array reference
   */
  selectionSort() {
    this.animArr = [];
    for (let i = 0; i < this.arr.length; i++) {
      let min: number = i;
      for (let j = i; j < this.arr.length; j++) {
        if (this.arr[min] < this.arr[j]) min = j;
      }
      [this.arr[i], this.arr[min]] = [this.arr[min], this.arr[i]];
      this.animArr.push([...this.arr]);
    }
    this.drawStuff(0, [...this.animArr]);
    return this.arr;
  }

  drawStuff(n: number, anim: Array<any>) {
    let x = n + 1;
    if (x <= this.animArr.length) {
      setTimeout(() => {
        render(this.animArr[n], false);
        this.drawStuff(x, anim);
      }, 500);
    } else {
      return;
    }
  }

  /**
   * @returns sorted array reference. (mutates original array)
   */
  bubbleSort() {
    this.animArr = [];
    for (let i = 0; i < this.arr.length - 1; i++) {
      let flag: boolean = false;
      for (let j = 0; j < this.arr.length - i - 1; j++) {
        if (this.arr[j] > this.arr[j + 1]) {
          [this.arr[j], this.arr[j + 1]] = [this.arr[j + 1], this.arr[j]];
          flag = true;
          this.animArr.push([...this.arr]);
        }
      }
      if (!flag) break;
    }
    this.drawStuff(0, [...this.animArr]);
    return this.arr;
  }

  /**
   * @returns sorted array reference. (mutates original array)
   */
  insertionSort() {
    this.animArr = [];
    for (let i = 1; i < this.arr.length; i++) {
      let hole: number = i;
      let value: number = this.arr[i];
      while (hole > 0 && this.arr[hole - 1] > value) {
        this.arr[hole] = this.arr[hole - 1];
        hole -= 1;
      }
      this.arr[hole] = value;
      this.animArr.push([...this.arr]);
    }
    // console.log(this.animArr);

    this.drawStuff(0, [...this.animArr]);
    return this.arr;
  }
}

// const arr = new Sort([5, 10, 98, 12, 46, 0, -8]);
// console.log(arr.selectionSort());
// console.log(arr.bubbleSort());
// console.log(arr.insertionSort());
