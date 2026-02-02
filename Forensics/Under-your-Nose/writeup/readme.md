# 📝 Write-up for Under Your Nose
---

## Challenge Summary

We are given .jpg image file:

```
D.jpg
```
The chall says that the flags us simply in front of us, so it would be a very common place but maybe hidden between some texts.

---
## Step 1 — Check the strings

Firstly take a look at the strings of the image: 
```bash
...
..
N2ecmOBgFEGp0P5toH7VDzIVgpd3Vi9HWOVWOMJFUK27ZJkeQae6Hu
vZ37R5JSI2fEanW4OFjdpIfPulgBElWrtehpCgFBAgpD0o5jvRYyf390f51D6eR+ci8fCW0Q/kGE
eanXNiyX8lh889kZ9DiHdh6uU+dUdFe20h/Zjmm9fNi/G/tvzqVsIXUy8KgsCHw=
https://drive.google.com/file/d/1lCB862tXjDXhk775S05XJJyzyYqzKhJR/view?usp=drive_link
x9Ww+sjHNYSAi/z9CN8KLBaicS2ty8WLL1nHguA/2rfuxrMDjCe4MsbFOvH2Wqi7NnpIqauWSeLI
YuaJSi0+BatdbdFVJxX3fawxJnKBJotSDOxNADrtUoUnxaGTWfDZk7G498xWXvkyFh+UvsrT8JC8
goj3eWgDXr6ukA1BYej
...
..
```
It has a lot of garbage in it, but amongst it lies this link to a google drive, when you follow it you get another image `Finale.jpeg` and when we check it's strings we get:
```bash 
Here's the flag : BBCTF{N01_1n_p14in_S1gh1} 
```

---
## 🏁 Flag

The final flag is:
```
BBCTF{N01_1n_p14in_S1gh1}
```

---