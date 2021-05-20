# 简介

此仓库是在 suckless 的 DWM 基础上进行客制化，原版 DWM 地址为[suckless.org](dwm.suckless.org)

## 基础配置

1. 使用字体为 FiraCode-Nerd-Font
2. 顔色和 st 的主题保持一致，随着 ST 的主题改变，我都会改变 dwm 中对应的颜色
3. 添加快捷键控制锁屏，锁屏软件为 slock
4. 添加快捷键截图，截图软件为 flameshot
5. 添加快捷键控制音量，控制软件是 amixer

## 快捷键

## 补丁

1. 透明补丁
2. 便签本补丁
3. 隐藏没有窗口的标签补丁
4. 栈区窗口可以上下移动补丁
5. 间隙补丁(我改为了 tilegap 补丁，补丁文件夹中的 uselessgap 暂时没用)
6. 标签使用图标的补丁
7. 允许每个标签布局不同补丁
8. 调整浮动窗口位置、大小的补丁
9. 窗口在自己分配的空间内全屏(方便看视频学习,还有个补丁可以实现指定窗口在分配的空间内全屏,但通过布局也能实现就没用)

### 以下为官网上的所有补丁的简要说明

hide vacant tags : 隐藏没有打开窗口的标签，而且不会为非空标签现实空矩形指示器

activetagindicatorbar : 将标签的指示器从小方块改为上方显示一个长方形

alpha ：透明，需要搭配 xcompmgr 或者 picom 一起使用。推荐 xcompmgr

alternativetags : 标签上可以使用图标

alttagsdecoration ：用尖括号替换标签的指示器

nodmenu : 去除 dmenu

notitle : 不显示标题

fancybar ：显示所有可见窗口的标题

awesomebar : 显示所有标题，单击使窗口聚焦，单击聚焦窗口使窗口隐藏，单击隐藏窗口时取消隐藏

centeredwindowname : 标题居中

extrabar : 启用额外的状态栏，和默认状态栏位置相反

dualstatus : 启用额外的状态栏，和默认状态栏位置相反

titlecolor : 使窗口标题的配色方案可以独立更改

colorbar : 允许改变每个状态栏元素的前景色和背景色

barpadding : 为状态栏和屏幕边缘进行垂直和水平填充

statuspadding : 使状态栏中的水平填充和垂直填充变为可配置选项，默认情况下，只是标题栏除了右侧填充，多了个左侧填充（即标题栏文字居中）

barheight ：设置状态栏高度

statuscolors ：使状态栏文本启用彩色文本

statuscmd ：单击状态栏时，根据鼠标按钮和位置执行指定命令

status2d : 允许在状态栏中绘制颜色和矩形（示例中用来显示电量和网络强度）

pango : 为状态栏的消息区添加 pango 支持，允许使用更多的字体特性和一些字体图标

fullscreen : 将选中的窗口全屏，并隐藏状态栏，再次按下还原布局

actualfullscreen : 全屏切换

fakefullscreen : 伪造全屏，仅允许窗口在分配的空间内全屏，如浏览器在一半屏幕上看全屏视频，另一半屏幕正常使用

selectivefakefullscreen ：允许特定的应用程序伪造全屏，其他的则正常允许，基于前一个伪造全屏的补丁

alwayscenter ：所有浮动窗口居中

alwaysfullscreen ：使用 focusstack() 时，焦点不会从全屏窗口上移开

aspectresize ：使用 moveresize 补丁手动调整窗口大小时，宽高比不变

exresize : 允许使用键盘更改浮动窗口大小和位置，根据 maximize 和 moveresize 补丁，修复前两种补丁的一些问题

moveresize : 使用快捷键移动和调整窗口大小

stackmfact : 允许垂直调整窗口大小，默认的只能左右调整

sizehints : 允许给指定程序设置初始窗口大小，设置了的程序启动时都是浮动的

save floats : 记住浮动窗口关闭时的大小，再此打开此窗口时会恢复大小

attachabove ：新建窗口在当前窗口之前，而不是成为新的主窗口

attachaside ：新建窗口在当前窗口之后，而不是成为新的主窗口

urgentborder ：允许修改紧急窗口的边框颜色，默认是亮红色

fullgaps : 动态调整间隙（内部和外部）

uselessgap ：在窗口周围添加间隙，当只有一个窗口时可以没有间隙

vanitygaps : 在窗口之间增加内部间隙，窗口和屏幕边缘增加外部间隙

singularborders : 去掉窗口之间的间隙，和屏幕四周也没有间隙，但如果有多个显示器，会在另一个显示器看到前一个显示器的边框

setborderpx : 动态设置边框像素

ru gaps : 动态调整间隙，单片模式下没有间隙和边框

movestack : 将当前窗口前移或后移

push : 将当前窗口前移或后移

tagall : 将所有浮动窗口从一个标签移动到另一个标签

viewontag ：将一个窗口移动到另一个标签

swaptags : 将当前标签中的窗口和指定标签中的窗口对换

zoomswap : 当前窗口和主窗口交换时，位置对换，而不是主窗口后移

swapfocus : 用一个快捷键，快速跳转到上一个焦点窗口

sticky : 使指定的窗口在所有标签上都可见，通过指定的快捷键，也可以取消，让其返回原始标签

systray : 一个简单的系统托盘，还支持多显示器

switchtotag ：将应用程序和标签绑定，打开时自动跳转到对应标签，关闭时跳转回来

scratchpad ：便签本，生成一个居中的浮动的小终端

scratchpads : 便签本，加强版，有多个暂存器，每个标签一个

autostart : dwm 在进入处理程序循环执行执行 .dwm 下的脚本

cool autostart : 从自启动数组中执行命令，当 dwm 退出时，其中的所有进程都会被杀死

rmaster : 主区域和堆栈区域互换，主区域在右

multikey : 允许一个组合键触发不同功能，根据短时间内连续按该组合键的次数决定触发什么功能

killunsel : 杀死所有未选中的窗口

keymodes : 添加一个类似于 vim 中的命令模式的模式，此模式下任何键都只对 dwm 起效，将窗口管理的快捷键放在此模式下，有效防止键冲突

focusonclick : 仅通过鼠标点击才能切换焦点

swallow ：窗口吞咽

gestures : 添加对简单鼠标手势的支持

xkb : 记住窗口的 xkb 状态，并在窗口获取焦点时恢复

pwkl : 记住窗口的键盘布局，并在窗口获取焦点时恢复

xrdb : 允许 dwm 从 .Xresources 中读取颜色设置

xresources ：允许 dwm 从 .Xresources 中读取任何类型的设置，不止颜色

schemeSwitch : Solarized 配色主题通过快捷键进行明暗切换

布局补丁

pertag : 允许每个标签中的布局不一样

cyclelayouts ：使用 MOD-CTRL- 循环布局，当存在多个布局时有用

bottomstack : 上下布局

three column : 三列布局，主窗口在中间

horizontal grid : 水平网格布局

centerdmaster : 居中布局

nrowgrid : 可自定义行数的网格状布局

gaplessgrid : 更改的网格布局，常规网格布局当没有足够的窗口填充网格时会留下空白单元格，此布局会调整前几列的窗口数避免空白单元格

gridmode : grid 布局，窗口以大小相等的网格排列

fibonacci : 斐波那契布局，分别是螺旋形和缩小形，第一个窗口使用一半，第二个窗口使用剩下的一半，以此类推

deck : 甲板布局，堆栈区类似卡牌重叠
