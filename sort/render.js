var root = document.getElementById("root");
var arrBuffer = {};
var render = function (arr, flag) {
    if (flag) {
        var targetRoot_1;
        if (!root.firstElementChild) {
            targetRoot_1 = root;
        }
        else {
            var div = document.createElement("div");
            div.className = "root";
            document.body.appendChild(div);
            targetRoot_1 = div;
        }
        arr.forEach(function (x, i) {
            var element = document.createElement("div");
            element.className = "bar";
            element.textContent = "" + x;
            arrBuffer[x] = {
                index: i,
                width: x,
                y: (i + 1) * 45,
                element: element
            };
        });
        Object.keys(arrBuffer).forEach(function (val) {
            var elem = arrBuffer[val];
            elem.element.style.left = elem.y + "px";
            elem.element.style.height = elem.width + "px";
            targetRoot_1.appendChild(elem.element);
        });
    }
    else {
        arr.forEach(function (x, i) {
            arrBuffer[x].index = i;
            arrBuffer[x].y = (i + 1) * 45;
        });
        Object.keys(arrBuffer).forEach(function (val) {
            var elem = arrBuffer[val];
            elem.element.style.left = elem.y + "px";
        });
    }
};
