# 📝 Write-up for Last words of the Legend

---

## Challenge Summary

We are given a zip file:

```
Acid/
   ├── Base/
   ├── Neutral/
   ├── hidden.txt
   └── thanky.bat
```
The chall ask us for 2 things, the last message of the warrior and the name of the King. <br>

---
## Step 1 — Findind the King's name

If we read the description carefully it says *"the king used to live in a base"*, it means the info about the king can be found in the folder **base**, and there's this image named `Tralala.jpg`
and it's an image of Shark wearing shoes, which matches with the description given about the king, so the king's name would be **Tralala**.

So now we proceed to find the message.

---

## Step 2 — Search for the message

As we further go through the challenge discription is says that the message *got trapped during the neutralization*, this gives a hint about checking out the folder named **Neutral**. We can find a PNG file `Waterrr.png` which can be a very easy way to hide the message.


Now our task is to perform forensic analysis on  image and recover whatever is hidden in it.

---
## Step 3 — Carve the image

For hiding data the best tool is **steghide** for .jpg, .jpeg file, and **zsteg** for .png files.<br>
So as we use this tool on the given image, 
```bash
zsteg Waterrr.png
```
We get:

```
[?] 49 bytes of extra data after image end (IEND), offset = 0xcece
extradata:0         .. text: "Hello I'm under the water, Please help me ! ! ! \n"
imagedata           .. text: "txyyz|z{|w\\\r"
chunk:1:PLTE        .. text: "&>*.:9=Y>9@>9A?8A?9AD@]EI[KJiLC\\XLhYLX[Op`UraUybVdc`jdildk"
b1,rgb,lsb,xy       .. text: "bbctf{paanipiladijiye}\n"
b2,r,msb,xy         .. text: "`UUUUUUUU\t"
....
..
```
Bingo !! we got the hidden message, **`BBCTF{paanipiladijiye}`**

## 🏁 Flag

Therefore the final flag would be
```
BBCTF{paanipiladijiye_Tralala}
```

---