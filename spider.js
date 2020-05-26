// 检测获取页面内所有的图片的地址
// 重复的文件名不入库
// 滚动页面重新进行以上动作
// 点击悬浮按钮把所有入库的文件名处理
// 下载

// document.querySelectorAll("img")

// .src =		"https://pbs.twimg.com/media/EY291CAU8AA2QHf?format=jpg&name=900x900";
// .currentSrc = 	"https://pbs.twimg.com/media/EY291CAU8AA2QHf?format=jpg&name=900x900";
// str.match(/\/\w+\?/)

function doDownload(){
    let a = document.createElement('a');
    let e = document.createEvent('MouseEvents');
    e.initEvent('click', false, false);
    a.href = "";
    a.download = "a.png";
    a.dispatchEvent(e);
}


let preDom = document.querySelectorAll("pre");

for(let i  = 0 ; i < preDom.length; ++i){
    preDom[i].style.backgroundColor = "#F6F6F6"
}

let codeDom = document.querySelectorAll("code");

for(let i  = 0 ; i < codeDom.length; ++i){
    codeDom[i].style.backgroundColor = "#F6F6F6"
    codeDom[i].style.color = "black"
}
