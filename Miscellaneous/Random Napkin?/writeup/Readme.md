# 📝 Solution / Write-up


## Step 1 — Identify the string

The napkin contains:

fd1b05c1fcbe06caf1a2c133e3368236


The 32-character hexadecimal format suggests it is an **MD5 hash**.

---

## Step 2 — Crack the hash

Using an online hash cracking tool such as:

https://crackstation.net/

we submit the hash and obtain the password:

l3tm31n


---

## Step 3 — Extract the archive

Open the provided `archive.zip` using the recovered password.

Inside, an image file is found.

At first glance, the image appears normal with no visible data.

---

## Step 4 — Analyze the image

The challenge description hints:

> "look at it bit by bit"  
> "blue neon lights"

This suggests **bit-plane steganography**, specifically the **blue channel**.

Using:

https://cyberchef.org/

Load the image → Extract **Blue channel bit plane 0**.

---

## Step 5 — Recover the flag

The hidden data reveals the flag.

---

## 🏁 Flag
BBCTF{h4sh_cr4ck1ng_4nd_b17_pl4n3_st3gn0gr4phy}
