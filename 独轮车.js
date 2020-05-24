// ==UserScript==
// @name         斗鱼独轮车
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        https://www.douyu.com/*
// @require      https://ajax.aspnetcdn.com/ajax/jQuery/jquery-3.4.1.min.js

// @grant        none
// ==/UserScript==

//反复执行
function loop(dom, str){

    var value = Math.round( Math.random()*3000 + 2000 );
    setTimeout( function(){
        $(".ChatSend-txt")[0].value = str;
        $(".ChatSend-button ")[0].click();
        console.log( Date() );
        console.log("loop:", value);
    }, value)

}

//开始任务，并返回id为了结束任务
function doWork(time){

    var dom = document.getElementsByClassName("ChatSend")[0];
    var str = document.getElementById("my_text").value;


    var strArr = null;
    var articelMod = $("#my_mod_article")[0].checked;
    if(articelMod){
        strArr = str.split(/["。""？""！""；"/]/);
    }else{
        strArr = str.split("\n");
    }

    var radomMod = $("#my_mod_random")[0].checked;
    let max = strArr.length;
    let pos = 0;
    let timeId = setInterval(function(){

        if(radomMod){
            pos = Math.round( Math.random()*(max) );
            loop(dom, strArr[pos]);
        }
        else{
            if( pos < max ){
                loop(dom, strArr[pos]);
                ++pos;
            }
            else{
                pos = 0;
                console.log("pos太大了，重置为0")
            }
        }

        console.log("进入了循环器");
    }, time);
    console.log("doWork TimeId", timeId);

    return timeId;
}
//结束任务。用开始任务获取的ID
function stopWork(timeId){
    clearInterval(timeId);
    console.log("stopWork TimeId", timeId);
}

//绑定函数
function bind(){

    let timeId = null;

    var btn = document.getElementById("my_button");
    btn.addEventListener("click", function(){
        if(this.value == "开"){
            this.value = "关";
            timeId = doWork(30000); //控制频率
        }
        else if(this.value == "关"){
            this.value = "开";
            stopWork(timeId);
        }
    });

    console.log("绑定成功");
}


function init(){
    // 页面变动监听
    document.addEventListener('visibilitychange', function(){

        //document.title = document.hidden; // change tab text for demo
    })
    setTimeout(addElement, 4000);
    setTimeout(removeElement, 6000);
    setTimeout(bind, 6000);

    console.log("初始化成功");
}
init();


function ex(){

    var flag = true
    //添加鼠标焦点移入浏览器窗口事件
    window.addEventListener('focus', function() {
        if(flag) {
            alert('我被激活了！');
            flag = false;
        }
        document.title = 'focused';
    },false);

    //添加鼠标焦点移开浏览器窗口事件
    window.addEventListener('blur', function() {
        if(!flag) {
            alert('我被关闭了！');
            flag = false;
        }
        document.title = 'not focused';
    },false);

}

var Unicycle = {
    // 初始化
    init : function(pDom){
        myPDom = pDom;
        // this.createDom()
        this.addMoveEvent( this.createDom() );
    },
    // 创建一个悬浮的dom
    createDom : function(){
        var dom = document.createElement("div");
        dom.id = "unicycleMainDiv";
        var strCSS = 
        `<style>
        #unicycleMainDiv:hover {
            box-shadow: 0 0 8px #0ca4d4;
        }
        #unicycleMainDiv {
            width: 300px;
            height: 50px;
            display: flex;
            z-index: 999;
            position: absolute;
            top: 4px;
            right: 9px;
            background: white;
            border: 1px solid #cccccc;
            border-radius: 4px;
        }
        </style>
        <div id = "myDiv1"></div>
        <div id = "myDiv2"></div>`;
        dom.innerHTML = strCSS;     // 此处用 innerText 会出BUG
        myPDom.appendChild(dom);
        return dom;
    },
    // 给特定的DOM添加可以被拖动事件
    addMoveEvent : function(parDom){
        //添加自由拖动事件(只能在父窗口区域内移动)
        var dom = parDom;
        dom.onmousedown = function(event) {
            var ev = event || window.event;
            event.stopPropagation();
            var disX = ev.clientX - dom.offsetLeft;
            var disY = ev.clientY - dom.offsetTop;
            var isMove = true;
            document.onmousemove = function(event){
                dom.style.cursor = "move";
                var ev = event || window.event;
                event.stopPropagation();
                var x = ev.clientX - disX;
                var y = ev.clientY - disY;
                if( (x > 0) &&
                    // (x < window.innerWidth - dom.clientWidth) &&
                    (x < dom.parentNode.offsetWidth - dom.clientWidth) &&
                    isMove ){
                    dom.style.left = x + "px";
                }
                if( (y > 0) &&
                    // (y < window.innerHeight - dom.clientHeight) &&
                    (y < dom.parentNode.offsetHeight - dom.clientWidth) &&
                    isMove ){
                    dom.style.top = y + "px";
                }
                // console.log(
                //     (x > 0),
                //     (x < window.innerWidth - dom.clientWidth),
                //     (y > 0),
                //     (y < window.innerHeight - dom.clientHeight)
                // );
            };
            dom.onmouseup = function() {
                document.onmousemove = null;
                disY = 0;
                disX = 0;
                isMove = false;
                dom.style.cursor = "";
            };
            dom.onmouseleave = function(){
                // dom.onmousemove = null;
                // isMove = false;
                // dom.onmousedown = null;
            };
        }; 
    },
    addElement : function (){
        // 添加按钮
        //添加按钮、设置按钮属性
        var button = document.createElement("input");
        button.type = "button";
        button.value = "开";
        button.type = "button"
        button.id = "my_button";
        P.appendChild(button);

        //添加 小说模式&一般模式
        var textLab1 = document.createElement("lable");
        textLab1.innerText = " 小说";
        P.appendChild(textLab1);
        var checkbox1 = document.createElement("input");
        checkbox1.type = "checkbox";
        checkbox1.id = "my_mod_article";
        P.appendChild(checkbox1);

        // 添加 是否随机模式
        var textLab2 = document.createElement("lable");
        textLab2.innerText = " 随机";
        P.appendChild(textLab2);
        var checkbox2 = document.createElement("input");
        checkbox2.type = "checkbox";
        checkbox2.id = "my_mod_random";
        P.appendChild(checkbox2);

        //添加自定义文本框
        var chat = document.getElementsByClassName("ChatSend")[0];
        var node = document.getElementsByClassName("ChatBarrageCollect")[0];

        //添加按钮、设置按钮属性
        var textDom = document.createElement("textarea");
        textDom.id = "my_text";
        textDom.style.width = "192px";
        textDom.style.height = "37px";
        textDom.style.float = "left";
        textDom.style.padding = "5px 13px 5px 71px";
        textDom.style.border = "1px solid ##00bcd4";
        textDom.style.borderRight = "0";
        textDom.placeholder = "自己的输入框";

        chat.insertBefore(textDom, node);
    },
    myPDom : undefined,

}
Unicycle.init(document.getElementsByTagName("body")[0]);

// var dragdiv = document.querySelector('#unicycleMainDiv');
// var x, y;  //记录到点击时鼠标到移动框左边和上边的距离

// dragdiv.addEventListener('dragstart', function (e) {
//     e.dataTransfer.effectAllowed = "move";  //移动效果
//     e.dataTransfer.setData("text", '');  //附加数据，　没有这一项，firefox中无法移动
//     x = e.offsetX || e.layerX;
//     y = e.offsetY || e.layerY;
//     return true;
// }, false);

// document.addEventListener('dragover', function (e) {//取消冒泡 ,不取消则不能触发 drop事件
//     e.preventDefault()|| e.stopPropagation();
// }, false);

// document.addEventListener('drop', function (e) {
//     dragdiv.style.left = (e.pageX - x) + 'px';
//     dragdiv.style.top = (e.pageY - y) + 'px';
//     e.preventDefault() || e.stopPropagation();  //不取消，firefox中会触发网页跳转到查找setData中的内容
// }, false);