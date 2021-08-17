type printObject = {
  index: number;
  width: number;
  y: number;
  element: HTMLDivElement;
};
interface Hash {
  [key: string]: printObject;
}
const root = document.getElementById("root") as HTMLDivElement;
const arrBuffer: Hash = {};
const render = (arr: Array<number>, flag: boolean): void => {
  if (flag) {
    let targetRoot: HTMLDivElement;
    if (!root!.firstElementChild) {
      targetRoot = root;
    } else {
      const div = document.createElement("div");
      div.className = "root";
      document.body.appendChild(div);
      targetRoot = div;
    }
    arr.forEach((x, i) => {
      const element = document.createElement("div");
      element.className = "bar";
      element.textContent = "" + x;
      arrBuffer[x] = {
        index: i,
        width: x,
        y: (i + 1) * 45,
        element,
      };
    });

    Object.keys(arrBuffer).forEach((val) => {
      const elem = arrBuffer[val];
      elem.element.style.left = `${elem.y}px`;
      elem.element.style.height = `${elem.width}px`;
      targetRoot.appendChild(elem.element);
    });
  } else {
    arr.forEach((x, i) => {
      arrBuffer[x].index = i;
      arrBuffer[x].y = (i + 1) * 45;
    });
    Object.keys(arrBuffer).forEach((val) => {
      const elem = arrBuffer[val];
      elem.element.style.left = `${elem.y}px`;
    });
  }
};
