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
// 单一窗口按钮
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
            width: 60px;
            height: 30px;
            display: flex;
            z-index: 9999;
            position: absolute;
            top: 4px;
            right: 9px;
            background: #70a1ff;
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

    myPDom : undefined,

}
Unicycle.init(document.getElementsByTagName("body")[0]);
