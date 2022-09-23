#  特别提示
## 禁止转载到CSDN/b站等平台，否则si🐎！
## 禁止违反GPL协议/闭源打包，否则si🐎！
## 禁止墨家某哥之类流氓公司使用，否则si🐎！
## 转载必须开源，否则si🐎！
# OOK调制解码/转换器
适用于ASK/OOK调制  
其他编码器正在编写.
JS+HTML 网页 app 正在编写.  
[网页版(代码不一定是最新的)](https://onlinegdb.com/jWH5Eh_ZM)
# 用法
## 1527编码芯片
4位 1527 数据 <---> 2位 1527 数据  
URH 解调的数据 ----> 4位 1527 数据    
示范：  
``H0FF1FHFHH0100``<--->``100001011101100110100100``  
``111010001000100010001110100011101110111010001110111010001000111011101000111010000111010001000100010`` ---> `H0FF1FHFHH 1000`
## 2262 编码芯片
3位 2262 数据 <---> 解调后的波形  
解调后的波形 ----> 3位 2262 数据 
URH 解调的数据 ----> 3位 2262 数据  
示范:  
``001FFF101FFF1``<--->``NNNNWWNWNWNWWWNNWWNWNWNWWW``  
``100010001110111010001001001110100010001000100100010001000100011101110100010001000100010001000100``---->``010F000010000``
## 其他广泛的编码芯片
URH 解调的数据 ----> 2位 通用数据  
示范:  
``101010101010101010101010100010101100101100110010110011001100110011001011010011010010110101001010110100110100110010101011010010110001010110010110011001011001100110011001100101101001101001011010100101011010011010011001010101101001011000101011001011001100101100110011001100110010110100110100101101010010101101001101001100101010110100101 ``  
--->  
``NNNNNNNNNNNNNNNWNWWNWWWWWNWNWNNWNNNNWNWNWNNNWNNWNNWNWWNWWWWWNWNWNNWNNNNWNWNWNNNWNNWNNWNWWNWWWWWNWNWNNWNNNNWNWNWNNNWNN``

## 同步码说明
在每个2262/2260/1527帧的末尾都有一个同步码，这使得Samy的De-Bruijn攻击无法对这些编码器进行攻击。

## 关于DIP开关（拨码开关）

如果你想把你的解码的数据放到有DIP开关（拨码开关）的遥控器中，注意你的``数据码``应该是以下其中之一：``0001`` ``0010`` ``0100`` ``1000``，如果不是，那么DIP开关遥控器将无法正常工作。在这种情况下，你应该购买一个能够重放攻击的遥控器。
# 备注
这个repo只是一个工具，用于从URH中解码（你需要先用URH解调）数据或者计算不同格式的数据/代码/波形，如果你正在寻找一个工具来处理/解调原始文件/十六进制数据，例如```.complex```或```.C16```，请参考下面的项目：  
[URH](https://github.com/jopohl/urh)  
[rtl-433](https://github.com/merbanan/rtl_433)  
[ooktools](https://github.com/leonjza/ooktools)   
[RFQuack](https://github.com/rfquack/RFQuack)  
如果你正在尝试暴力破解OOK设备，请尝试下面的项目：  
[OpenSesame](https://github.com/samyk/opensesame)  
[PortapackMayhem](https://github.com/eried/portapack-mayhem)  
[2262Scan](https://github.com/zxkmm/2262Scan)
# i18n
[English](https://github.com/zxkmm/OOKFormatCalculate/blob/main/README.md)
# Credit
[PickedItMate](https://github.com/pickeditmate)  
[jimilinuxguy](https://github.com/jimilinuxguy)  
[GoblinGe](https://github.com/GoblinGe)  
 

