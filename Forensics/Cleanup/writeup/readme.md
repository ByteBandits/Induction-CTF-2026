# 📝 Solution / Write-up — Last Cleanup

---

## Challenge Summary

We are given a raw disk image:

```
disk.dd
```

The description suggests that a user attempted to clean up their workstation and delete sensitive files.

Our task is to perform forensic analysis on the disk image and recover whatever was hidden.

Flag format:

```
BBCTF{...}
```

---

## Step 1 — Identify the file type

Determine what kind of file we are working with:

```bash
file disk.dd
```

Output:

```
FAT filesystem
```

This confirms the file is a filesystem image rather than a simple archive.

So we proceed using forensic methods.

---

## Step 2 — Search for embedded artifacts

Scan the disk for hidden or deleted files using binwalk:

```bash
binwalk disk.dd
```

Output shows:

```
Zip archive data, encrypted ... name: tmp/priv.txt
```

This indicates an encrypted ZIP archive exists inside the disk image.

---

## Step 3 — Carve the archive

Using the offset reported by binwalk, carve the ZIP file:

```bash
dd if=disk.dd of=recovered.zip bs=1 skip=<offset> count=500
```

Now we have:

```
recovered.zip
```

---

## Step 4 — Attempt extraction

Try extracting:

```bash
unzip recovered.zip
```

The archive requests a password, meaning we must search the disk for clues.

---

## Step 5 — Search for suspicious strings

A common forensic trick is to inspect readable strings:

```bash
strings disk.dd | grep =
```

We find:

```
S2V5VG9TZWNyZXRJcw==
ZDNsM3QzMTc=
```

These appear to be Base64-encoded values.

---

## Step 6 — Decode the clues

Decode them:

```bash
echo S2V5VG9TZWNyZXRJcw== | base64 -d
```

Output:

```
KeyToSecretIs
```

This suggests the next value is the password.

Decode the second:

```bash
echo ZDNsM3QzMTc= | base64 -d
```

Output:

```
d3l3t317
```

This is likely the archive password.

---

## Step 7 — Extract with password

```bash
unzip recovered.zip
```

Enter:

```
d3l3t317
```

Extraction succeeds:

```
tmp/priv.txt
```

---

## Step 8 — Recover the flag

```bash
cat tmp/priv.txt
```

---

## 🏁 Flag

```
**`BBCTF{d3l3ti0n_is_n0t_d3struc7ion}`**
```

---

## 🔍 Concepts Used

- Disk image analysis
- File carving
- Strings extraction
- Base64 decoding
- Password-protected archives
- Basic filesystem forensics

---

## ✅ Takeaway

Deleted files are not truly gone.

Even after cleanup, data remnants can still be recovered using forensic techniques.

Deletion is **not destruction**.
