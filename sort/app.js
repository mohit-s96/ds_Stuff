var string =
  "84, 78, 82, 119, 60, 102, 78, 58, 71, 97, 19, 113, 69, 102, 33, 30, 36, 39, 44, 113, 56, 42, 34, 31, 50, 75, 65, 84, 84, 45";
var testArr = string.split(", ").map(function (x) {
  return +x;
});
//@ts-ignore
testArr = [...new Set(testArr)];
// console.log(testArr);
render(testArr, true);
var sortArr = new Sort(testArr);
sortArr.selectionSort();
// render(testArr, true);
// sortArr.bubbleSort();
// render(testArr, true);
// sortArr.insertionSort();
