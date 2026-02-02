# 📝 Write-up for Feared Shriek
---

## Challenge Summary

We are given a mp4 file:

```
scream.mp4
```
The chall says that there is some message hidden in this file. <br>
It is mentioned that *"Some truths aren’t meant to be heard… they must be seen"*, so it clearly hints us to check it's spectogram. and later on it says *"some secrets refuse to speak unless you already know the words"*, so this means we need to have some paraphrase to extract the file.

---
## Step 1 — Checking the Spectogram 

To see the spectogram of the file, we use **Audacity**.
```bash
audacity scream.mp4
```
It will open the app and then Select the spectogram mode.

![This is the image from the spectogram](Forensics/Feared-Shriek/writeup/spectogram.jpeg)

from here we get the word **'P34K'**, it might be used as a password somewhere.  

---

## Step 2 — Extracting hidden files

To check if the file contains any hidden files, we'll use **binwalk**,
```bash
binwalk scream.mp4
```
We get:
```
DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
147608        0x24098         YAFFS filesystem root entry, big endian, type symlink, v1 root directory
147743        0x2411F         Zip archive data, encrypted at least v1.0 to extract, compressed size: 37, uncompressed size: 25, name: Flag.txt
147940        0x241E4         End of Zip archive, footer length: 22
```
so it means there is some files hidden in it.
Let's extract it.
```bash
binwalk -e scream.mp4
```
The extracted files get saved to a folder **_scream.mp4.extracted**, and they are:

```bash
24098.yaffs  2411F.zip
```
---
## Step 3 — Unzip the .zip file

As we try to unzip the .zip file, it asks for password:

```bash
unzip 2411F.zip                          
Archive:  2411F.zip
[2411F.zip] Flag.txt password: 
```
here we enter the passphare we got earlier, 'P34K', and then we'll get the Flag.txt.

```bash
cat Flag.txt            
BBCTF{5cr34m!n8_ch!ck3n}    
```

## 🏁 Flag

The final flag will be:
```
BBCTF{5cr34m!n8_ch!ck3n}
```

---