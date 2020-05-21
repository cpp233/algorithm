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

//隐藏现有的dom
function removeElement(){

    document.getElementsByClassName("Horn4Category")[0].style.display = "none";         //全区喇叭
    document.getElementsByClassName("ChatNobleBarrage")[0].style.display = "none";         //全区喇叭
    document.getElementsByClassName("ChatSend-txt")[0].style.display = "none";         //
    console.log("移除元素成功")
}
//添加自己的dom
function addElement(){

    //获取需要填加的父元素
    var P = document.getElementsByClassName("ChatToolBar")[0];

    // 添加按钮
    if(document.getElementById("my_button") == null){
        //添加按钮、设置按钮属性
        var button = document.createElement("input");
        button.type = "button";
        button.value = "开";
        button.type = "button"
        button.id = "my_button";

        P.appendChild(button);
    }
    //添加 小说模式&一般模式
    if(document.getElementById("my_mod_article") == null){
        var textLab1 = document.createElement("lable");
        textLab1.innerText = " 小说";
        P.appendChild(textLab1);

        var checkbox1 = document.createElement("input");
        checkbox1.type = "checkbox";
        checkbox1.id = "my_mod_article";
        P.appendChild(checkbox1);
    }
    // 添加 是否随机模式
    if(document.getElementById("my_mod_random") == null){

        var textLab2 = document.createElement("lable");
        textLab2.innerText = " 随机";
        P.appendChild(textLab2);

        var checkbox2 = document.createElement("input");
        checkbox2.type = "checkbox";
        checkbox2.id = "my_mod_random";
        P.appendChild(checkbox2);
    }

    //添加自定义文本框
    var chat = document.getElementsByClassName("ChatSend")[0];
    var node = document.getElementsByClassName("ChatBarrageCollect")[0];
    if(document.getElementById("my_text") == null){

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
    }

    console.log("添加按钮成功");
}

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




