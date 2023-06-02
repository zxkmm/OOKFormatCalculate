# OOKFormatCalculate
Other encoders is OTW.  
JS+HTML web app is OTW.  
[WebVersion](https://onlinegdb.com/LZ19njmf9)  

https://user-images.githubusercontent.com/24917424/192080873-70d0535c-4e15-4c5a-8465-7bbb75ffa4ea.MP4

# Compile
```angular2html
git clone https://github.com/zxkmm/OOKFormatCalculate.git
cd OOKFormatCalculate
mkdir build
cd build
cmake ..
make
```

# Run
``./OOKFormatCalculate``

# Usage
## 1527/2242
### Calculate between common code and Portapack code
AKA 4Bits data <---> 2Bits data  
e.g.  
``H0FF1FHFHH0100``<--->``100001011101100110100100``  

### Decode data from URH to common code
AKA Data demodulated by URH ----> 4Bits data of 1527   
e.g.  
``111010001000100010001110100011101110111010001110111010001000111011101000111010000111010001000100010`` ---> `H0FF1FHFHH 1000`
## 2262/2260
Data demodulated by URH  ---->  3Bits data AKA common 2262 code
e.g.   
``100010001110111010001001001110100010001000100100010001000100011101110100010001000100010001000100``---->``010F000010000``  
## general
Data demodulated by URH ----> 2Bits general data 
e.g. ``101010101010101010101010100010101100101100110010110011001100110011001011010011010010110101001010110100110100110010101011010010110001010110010110011001011001100110011001100101101001101001011010100101011010011010011001010101101001011000101011001011001100101100110011001100110010110100110100101101010010101101001101001100101010110100101 ``  
--->  
``NNNNNNNNNNNNNNNWNWWNWWWWWNWNWNNWNNNNWNWNWNNNWNNWNNWNWWNWWWWWNWNWNNWNNNNWNWNWNNNWNNWNNWNWWNWWWWWNWNWNNWNNNNWNWNWNNNWNN``

## About the sync code
There is a sync code in the end of each frame of 2262/2260/1527 Signal. It makes Samy's De-Bruijn attack not working on these encoders.

## About the DIP switch  
If your are trying to put your code that decoded by this script into a DIP switch fob, you should check that if your ``data code`` is one of them: ``0001`` ``0010`` ``0100`` ``1000``, and if NOT, then the DIP switch fob won't work correctly. In this case you should buy a fob that able to replay.


# Note if you got a 2262 code
If your fob is 1527/2242 but accidently doesn't contain ``H`` in it, it might be recongnized as 2262. It's not preventable but the sync bit is different among of them, which means they have different waveform. So if you decoded something as 2262 and it doesn't work, you should try same code but in 1527/2242 protocol.
# Note  
This repo is just a tool to decode data from URH or calculate data/code/waveform in different format, which mainly operates strings, if you are looking for a tool to operate/demodulate raw files or HEX datas like ```.complex``` or ```.C16```, pls refer to these project below:  
[URH](https://github.com/jopohl/urh)  
[rtl-433](https://github.com/merbanan/rtl_433)  
[ooktools](https://github.com/leonjza/ooktools)   
[RFQuack](https://github.com/rfquack/RFQuack)  
If you are trying to brute force an OOK device, please try these project below:  
[OpenSesame](https://github.com/samyk/opensesame)  
[PortapackMayhem](https://github.com/eried/portapack-mayhem)  
[2262Scan](https://github.com/zxkmm/2262Scan)

# requirements
C++11 or Python 3 or both
# i18n
[中文](https://github.com/zxkmm/OOKFormatCalculate/blob/main/Chinese.md)
# Credit
[PickedItMate](https://github.com/pickeditmate)  
[jimilinuxguy](https://github.com/jimilinuxguy)  
[GoblinGe](https://github.com/GoblinGe)  
 
