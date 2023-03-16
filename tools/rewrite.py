def anyBS2DEC(s: str, radix: int) -> int:
    ans = 0
    for t in s:
        if t >= '0' and t <= '9':
            ans = ans * radix + ord(t) - ord('0')
        else:
            ans = ans * radix + ord(t) - ord('a') + 10
    return ans

# 2

def DEC2anyBS(n: int, radix: int) -> str:
    ans = ""
    while n != 0:
        t = n % radix
        if t >= 0 and t <= 9:
            ans += chr(t + ord('0'))
        else:
            ans += chr(t - 10 + ord('a'))
        n //= radix
    return ans[::-1]

# 3

def replace_mod(src: str, old_value: str, new_value: str) -> str:
    while True:
        pos = src.find(old_value)
        if pos == -1:
            break
        src = src[:pos] + new_value + src[pos + len(old_value):]
    return src


# 4

def makeShortestGrain(numOfGrain: int) -> str:
    stringGrain = "1"
    for _ in range(numOfGrain - 1):
        stringGrain += "1"
    return stringGrain


# 5

def detectShortestGrainSize(dataFromURH: str) -> str:
    for tes1t in range(10, 0, -1):
        if makeShortestGrain(tes1t) in dataFromURH:
            return makeShortestGrain(tes1t)
    return ""


# 6

def decode2262FromURH(dataFromURH: str) -> str:
    result3Bit2262Code = ""
    # TODO
    return result3Bit2262Code

def makeStringFullOf0withANumber(numbersOf0: int) -> str:
    result = ""
    zero = "0"
    for _ in range(numbersOf0):
        result += zero
    return result

# 7

def replaceMeaningless0WithSpace(i2262URH: str) -> str:
    for numbersOf0 in range(100, 0, -1):
        i2262URH = replace_mod(i2262URH, makeStringFullOf0withANumber(numbersOf0), " ")
    return i2262URH

def putTheCodeIntoArray(iCodeThatAlreadySeperatedByA: str) -> str:
    line = "1 1 111 111 1 1 1 111 1 1 1 1 1 1 1 1 111 111 1 1 1 1 1 1 1"
    oCodeThatInArray = [""] * 25
    i = 0
    ssin = line.split()
    while i < 25 and ssin:
        oCodeThatInArray[i] = ssin.pop(0)
        i += 1
    for i in range(25):
        print(oCodeThatInArray[i])
    return oCodeThatInArray[24]

# 8

def outputAClearResult(explainContent: str, result: str, ADFormat: str):
    resultLength = len(result)
    explainContentLength = len(explainContent)
    print(" " * explainContentLength + "┏" + "━" * resultLength + "┓")
    print(explainContent + "┃" + result + "┃")
    print(" " * explainContentLength + "┗" + "━" * resultLength + "┛")
    print(" " * explainContentLength + " " + ADFormat + "\n")

# 9

def getLengthOfVariable(variableName: str) -> int:
    return len(variableName)

# 10

