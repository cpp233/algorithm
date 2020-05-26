// 检测获取页面内所有的图片的地址
// 重复的文件名不入库
// 滚动页面重新进行以上动作
// 点击悬浮按钮把所有入库的文件名处理
// 下载

function doDownload(){
    let a = document.createElement('a');
    let e = document.createEvent('MouseEvents');
    e.initEvent('click', false, false);
    a.href = "";
    a.download = "a.png";
    a.dispatchEvent(e);
}


