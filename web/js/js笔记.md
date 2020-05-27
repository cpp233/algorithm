# console对象的静态方法   
* ## 占位符  
%s 字符串  
%d 整数  
%i 整数  
%f 浮点数  
%o 对象的链接  
%c CSS 格式字符串  
~~~javascript
console.log(
  '%cThis text is styled!',
  'color: red; background: yellow; font-size: 24px;'
)
~~~
* ## console.log(),`console.info()`,console.debug()  
> * `console.info`是`console.log`方法的别名，用法完全一样。只不过`console.info`方法会在输出信息的前面，加上一个`蓝色图标`。
> * `console.debug`方法与`console.log`方法类似，会在控制台输出调试信息。但是，默认情况下，`console.debug`输出的信息不会显示，只有在打开显示级别在`verbose`的情况下，才会显示。
* ## console.warn(),console.error()  
> * `warn`方法输出信息时，在最前面加一个黄色三角，表示警告
> * `error`方法输出信息时，在最前面加一个红色的叉，表示出错。同时，还会高亮显示输出文字和错误发生的堆栈。
* ## console.table()  
> * 对于某些复合类型的数据，`console.table`方法可以将其转为表格显示。  
```javaScript
// 写法一
var languages = [
  { name: "JavaScript", fileExtension: ".js" },
  { name: "TypeScript", fileExtension: ".ts" },
  { name: "CoffeeScript", fileExtension: ".coffee" }
];
console.table(languages);
// 写法二
var languages = {
  csharp: { name: "C#", paradigm: "object-oriented" },
  fsharp: { name: "F#", paradigm: "functional" }
};
console.table(languages);
```
* ## console.dir()  
> * 该方法对于输出 DOM 对象非常有用，因为会显示 DOM 对象的所有属性。
* ## console.time()，console.timeEnd()  
> * `time`表示计时开始，`timeEnd`表示计时结束。它们的`参数`是计时器的`名称`。调用`timeEnd`方法之后，控制台会显示“计时器名称: 所耗费的时间”。
```javaScript
// 写法
console.time('耗时');
var array= new Array(1000000);
for (var i = array.length - 1; i >= 0; i--) {
  array[i] = new Object();
};
console.timeEnd('耗时');
```