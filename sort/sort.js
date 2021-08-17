var __spreadArray = (this && this.__spreadArray) || function (to, from) {
    for (var i = 0, il = from.length, j = to.length; i < il; i++, j++)
        to[j] = from[i];
    return to;
};
var Sort = /** @class */ (function () {
    function Sort(arr) {
        this.animArr = [];
        this.arr = arr;
    }
    /**
     * @returns mutated array reference
     */
    Sort.prototype.selectionSort = function () {
        var _a;
        this.animArr = [];
        for (var i = 0; i < this.arr.length; i++) {
            var min = i;
            for (var j = i; j < this.arr.length; j++) {
                if (this.arr[min] < this.arr[j])
                    min = j;
            }
            _a = [this.arr[min], this.arr[i]], this.arr[i] = _a[0], this.arr[min] = _a[1];
            this.animArr.push(__spreadArray([], this.arr));
        }
        this.drawStuff(0, __spreadArray([], this.animArr));
        return this.arr;
    };
    Sort.prototype.drawStuff = function (n, anim) {
        var _this = this;
        var x = n + 1;
        if (x <= this.animArr.length) {
            setTimeout(function () {
                render(_this.animArr[n], false);
                _this.drawStuff(x, anim);
            }, 500);
        }
        else {
            return;
        }
    };
    /**
     * @returns sorted array reference. (mutates original array)
     */
    Sort.prototype.bubbleSort = function () {
        var _a;
        this.animArr = [];
        for (var i = 0; i < this.arr.length - 1; i++) {
            var flag = false;
            for (var j = 0; j < this.arr.length - i - 1; j++) {
                if (this.arr[j] > this.arr[j + 1]) {
                    _a = [this.arr[j + 1], this.arr[j]], this.arr[j] = _a[0], this.arr[j + 1] = _a[1];
                    flag = true;
                    this.animArr.push(__spreadArray([], this.arr));
                }
            }
            if (!flag)
                break;
        }
        this.drawStuff(0, __spreadArray([], this.animArr));
        return this.arr;
    };
    /**
     * @returns sorted array reference. (mutates original array)
     */
    Sort.prototype.insertionSort = function () {
        this.animArr = [];
        for (var i = 1; i < this.arr.length; i++) {
            var hole = i;
            var value = this.arr[i];
            while (hole > 0 && this.arr[hole - 1] > value) {
                this.arr[hole] = this.arr[hole - 1];
                hole -= 1;
            }
            this.arr[hole] = value;
            this.animArr.push(__spreadArray([], this.arr));
        }
        // console.log(this.animArr);
        this.drawStuff(0, __spreadArray([], this.animArr));
        return this.arr;
    };
    return Sort;
}());
// const arr = new Sort([5, 10, 98, 12, 46, 0, -8]);
// console.log(arr.selectionSort());
// console.log(arr.bubbleSort());
// console.log(arr.insertionSort());
