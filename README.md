# OOKFormatCalculate
Other encoders is OTW.
JS+HTML web app is OTW.
# Usage
## 1527
4Bits data <---> 2Bits data  
e.g.  
H0FF1FHFHH0100<--->100001011101100110100100  
## 2262
3Bits data <---> Demodulated waveform  
e.g.  
001FFF101FFF1<--->NNNNWWNWNWNWWWNNWWNWNWNWWW
### About the sync code
There is a sync code in the end of each frame of 2262 Signal, PLS note that you should manually ignore a narrow wave crest in the end when inputing your 2 Bits 2262 data.
# Note  
This repo is just a data/code/waveform calculator which mainly progressing strings, if you are looking for a tool to progress/demodulate raw files/ HEX datas like ```.complex``` or ```.C16```or data from [URH](https://github.com/jopohl/urh), pls refer to these project below:  
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
 
