# Object 对象名词解释  
## Object对象自身的方法和实例方法 
* ### 自身的方法（又称为“静态方法”）  
定义一个方法： 
~~~js
Object.print = function (o) { console.log(o) };
~~~

* ### 实例方法   
继承自Object.`prototype`的方法
~~~js
Object.prototype.print = function () {
  console.log(this);
};
var obj = new Object();
obj.print() // Object
~~~

## Object  
* ### Object本身是一个函数  
可以当作工具方法使用，将任意值转为对象。这个方法常用于保证某个值一定是对象。
```js
var obj = Object();
// 等同于
var obj = Object(undefined);
var obj = Object(null);

obj instanceof Object // true
```
* ### instanceof  
instanceof运算符用来验证，一个对象`是否为指定的构造函数的实例`。obj instanceof Object返回true，就表示obj对象是Object的实例。
```js
var obj = Object(1);
obj instanceof Object // true
obj instanceof Number // true

var obj = Object('foo');
obj instanceof Object // true
obj instanceof String // true

var obj = Object(true);
obj instanceof Object // true
obj instanceof Boolean // true
```

* ### Object函数的参数
1.  参数是各种原始类型的值，转换成对象就是原始类型值对应的包装对象。
2.  参数是一个对象，它总是返回该对象，即不用转换。
~~~js
var arr = [];
var obj = Object(arr); // 返回原数组
obj === arr // true

var value = {};
var obj = Object(value) // 返回原对象
obj === value // true

var fn = function () {};
var obj = Object(fn); // 返回原函数
obj === fn // true
~~~