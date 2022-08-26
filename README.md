# OOKFormatCalculate
Other encoders is OTW.
JS+HTML web app is OTW.
[WebVersion](https://onlinegdb.com/jWH5Eh_ZM)
# Usage
## 1527
4Bits data <---> 2Bits data  
Data demodulated by URH ----> 4Bits data of 1527   
e.g.  
``H0FF1FHFHH0100``<--->``100001011101100110100100``  
``111010001000100010001110100011101110111010001110111010001000111011101000111010000111010001000100010`` ---> `H0FF1FHFHH 1000`
## 2262
3Bits data <---> Demodulated waveform  
3Bits data <---- Data demodulated by URH  
e.g.  
``001FFF101FFF1``<--->``NNNNWWNWNWNWWWNNWWNWNWNWWW``  
``100010001110111010001001001110100010001000100100010001000100011101110100010001000100010001000100``---->``010F000010000``  
## About the sync code
There is a sync code in the end of each frame of 2262/2260/1527 Signal. It makes Samy's De-Bruijn attack not working on these encoders.

## About the DIP switch  
If your are trying to put your code that ecoded by this script into a DIP switch remote, notice that if your ``data code`` is one of them: ``0001`` ``0010`` ``0100`` ``1000``, and if NOT, then the DIP switch remote won't work correctly. In this case you should buy a remote that able to replay.
# Note  
This repo is just a tool to decode data from URH or calculate data/code/waveform in different format, which mainly progressing strings, if you are looking for a tool to progress/demodulate raw files/ HEX datas like ```.complex``` or ```.C16```, pls refer to these project below:  
[URH](https://github.com/jopohl/urh)  
[rtl-433](https://github.com/merbanan/rtl_433)  
[ooktools](https://github.com/leonjza/ooktools)   
[RFQuack](https://github.com/rfquack/RFQuack)  
If you are trying to brute force an OOK device, please try these project below:  
[OpenSesame](https://github.com/samyk/opensesame)  
[PortapackMayhem](https://github.com/eried/portapack-mayhem)  
[2262Scan](https://github.com/zxkmm/2262Scan)
# i18n
[中文](https://github.com/zxkmm/OOKFormatCalculate/blob/main/Chinese.md)
# Credit
[PickedItMate](https://github.com/pickeditmate)  
[jimilinuxguy](https://github.com/jimilinuxguy)  
[GoblinGe](https://github.com/GoblinGe)  
 
