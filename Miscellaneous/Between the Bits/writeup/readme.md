# 📝 Solution / Write-up

## Step 1 — Analyze the Given Image

The challenge provides an image that appears **ordinary at first glance**.  
However, the description hints that it was used as a **covert transmission medium**, suggesting the use of **steganography**.

---

## Step 2 — Perform Steganographic Analysis

To analyze hidden data inside the image, we use the tool **zsteg**, which is commonly used for detecting LSB-based steganography in PNG images.

Command used:
```
zsteg crypto.png
```
---

Findings:
- Extra data after IEND containing hex-encoded text:11272026230f5a161b6e4202320b50013a175b0b0d43025f0c110b413a1c5f16114c
- Hidden string in LSB planes: **Secretkey123**

---

## Step 3 — Extract and Decrypt Data

The hex data appears XOR-encrypted using the discovered key.

Python script used:

```python
hex_data = '11272026230f5a161b6e4202320b50013a175b0b0d43025f0c110b413a1c5f16114c'
key = 'Secretkey123'
data = bytes.fromhex(hex_data)

print(''.join(chr(data[i] ^ ord(key[i % len(key)])) for i in range(len(data))))
```
---
BBCTF{1sb_p1an3s_c0ntr0l_th3_h4sh}
