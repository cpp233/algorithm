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
* ## console.group(),console.groupEnd(),console.groupCollapsed()  
> console.group和console.groupEnd这两个方法用于将显示的信息分组。
```javaScript
console.group('一级分组');
console.log('一级分组的内容');
console.group('二级分组');
console.log('二级分组的内容');
console.groupEnd(); // 二级分组结束
console.groupEnd(); // 一级分组结束
```
> console.groupCollapsed在第一次显示时是收起的（collapsed），而不是展开的。
```javaScript
console.groupCollapsed('Fetching Data');
console.log('Request Sent');
console.error('Error: Server not responding (500)');
console.groupEnd();
```
* ## console.trace(),console.clear()
> console.trace方法显示当前执行的代码在堆栈中的调用路径。  
> console.clear方法用于清除当前控制台的所有输出，将光标回置到第一行。如果用户选中了控制台的“Preserve log”选项，console.clear方法将不起作用。  
* ## 控制台命令行 API
1. `$_`  
>> 返回上一个表达式的值。
2. `$0 - $4`  
>> 控制台保存了最近5个在 Elements 面板选中的 DOM 元素，$0代表倒数第一个（最近一个），$1代表倒数第二个，以此类推直到$4。
3. `$(selector)`  
>> $(selector)返回第一个匹配的元素，等同于document.querySelector()。注意，如果页面脚本对$有定义，则会覆盖原始的定义。比如，页面里面有 jQuery，控制台执行$(selector)就会采用 jQuery 的实现，返回一个数组。
4. `$$(selector)`  
>> $$(selector)返回选中的 DOM 对象，等同于document.querySelectorAll
5. `$x(path)`  
>> $x(path)方法返回一个数组，包含匹配特定 XPath 表达式的所有 DOM 元素。  
>> 如： 
```javaScript
$x("//p[a]");
// 上面代码返回所有包含a元素的p元素。
```
6. `inspect(object)`  
>> inspect(object)方法打开相关面板，并选中相应的元素，显示它的细节。DOM 元素在Elements面板中显示，比如`inspect(document)`会在 Elements 面板显示document元素。JavaScript 对象在控制台面板Profiles面板中显示，比如`inspect(window)`。  
7. `getEventListeners(object)`  
>> getEventListeners(object)方法返回一个对象，该对象的成员为object登记了回调函数的各种事件（比如click或keydown），每个事件对应一个数组，数组的成员为该事件的回调函数。  
8. `keys(object)，values(object)`  
>> keys(object)方法返回一个数组，包含object的所有键名。  
>> values(object)方法返回一个数组，包含object的所有键值。  
9. `monitorEvents(object[, events]) ，unmonitorEvents(object[, events])`  
>> monitorEvents(object[, events])方法监听特定对象上发生的特定事件。事件发生时，会返回一个Event对象，包含该事件的相关信息。unmonitorEvents方法用于停止监听。  
~~~javaScript
// 表示单个事件和多个事件的监听方法
monitorEvents(window, "resize");
monitorEvents(window, ["resize", "scroll"])
// 停止监听
monitorEvents($0, 'mouse');
unmonitorEvents($0, 'mousemove');
~~~
>> monitorEvents允许监听同一大类的事件。所有事件可以分成四个大类。
>> * mouse："mousedown", "mouseup", "click", "dblclick", "mousemove", "mouseover", "mouseout", "mousewheel"
>> * key："keydown", "keyup", "keypress", "textInput"
>> * touch："touchstart", "touchmove", "touchend", "touchcancel"
>> * control："resize", "scroll", "zoom", "focus", "blur", "select", "change", "submit", "reset"
~~~js
// 表示监听所有key大类的事件。
monitorEvents($("#msg"), "key");
~~~
10. `其他方法`  
>> 命令行 API 还提供以下方法。
* clear()：清除控制台的历史。
* copy(object)：复制特定 DOM 元素到剪贴板。
* dir(object)：显示特定对象的所有属性，是console.dir方法的别名。
* dirxml(object)：显示特定对象的 XML 形式，是console.dirxml方法的别名。
# debugger 语句
* debugger语句主要用于除错，作用是设置断点。如果有正在运行的除错工具，程序运行到debugger语句时会自动停下。如果没有除错工具，debugger语句不会产生任何结果，JavaScript 引擎自动跳过这一句。
* Chrome 浏览器中，当代码运行到debugger语句时，就会暂停运行，自动打开脚本源码界面。
~~~js
for(var i = 0; i < 5; i++){
  console.log(i);
  if (i === 2) debugger;
}
~~~
* 上面代码打印出0，1，2以后，就会暂停，自动打开源码界面，等待进一步处理。