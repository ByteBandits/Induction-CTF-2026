# The Surgeon's Specimen - Writeup

## Challenge Information
- **Category:** Forensics
- **Points:** 300
- **Description:** A file named `specimen_07` has a corrupted header and contains a hidden "passenger" deep within.
- **Flag Format:** `BBCTF{...}`

## Analysis

### 1. Diagnosis (Initial Triage)
The challenge provides a file named `specimen_07` with no extension.
The description suggests the file signature (Magic Bytes) is missing or has been intentionally corrupted.

### 2. Identifying the Vessel
Opening the file in a Hex Editor (e.g., `hexedit`, `HxD`, or `CyberChef`) reveals the first 8 bytes are `42 42 43 54 46 44 45 56`, which spells **"BBCTFDEV"**. This confirms the "head" (header) of the PNG has been replaced with a custom string.

## Solution

### Step 1: Repairing the Head (Header Restoration) (OPTIONAL)

To fix the corrupted PNG, we must restore its original signature.
Standard PNG Header: `89 50 4E 47 0D 0A 1A 0A`

1. Open `specimen_07` in a Hex Editor.
2. Replace the first 8 bytes (`42 42 43 54 46 44 45 56`) with the PNG Magic Bytes: `89 50 4E 47 0D 0A 1A 0A`.
3. Save the file and rename it to `specimen_07.png`.

The "vessel" is now awake—opening the file reveals a PNG image (e.g., a medical X-ray or drawing).

### Step 2: Finding the Passenger (Data Carving)
The description mentions a "hidden passenger" and "reaching deep inside." This hints at data appended to the end of the image.

We can use `binwalk` to inspect the file:
```bash
binwalk specimen_07.png
```
Binwalk will reveal a **Zip archive** appended to the PNG data.

Alternatively, since PNG viewers ignore data after the `IEND` chunk, and ZIP extractors can often find ZIP structures anywhere in a file, we can try opening the file directly with a ZIP tool:
```bash
unzip specimen_07.png
# OR
7z x specimen_07.png
```

### Step 3: Extraction
Extracting the hidden archive (originally `soul.zip`) yields a file named `flag.txt`.
```bash
cat flag.txt
```

**Flag:** `BBCTF{5urg30n_f1x3d_th3_h34d_4nd_f0und_th3_tw1n}`

---

## Summary of Creation
For those curious about how the challenge was prepared:
1. **Flag Creation**: The flag was saved in `flag.txt`.
2. **Compression**: `flag.txt` was zipped into `soul.zip`.
3. **Combination**: The zip was appended to a PNG using `cat image.png soul.zip > specimen_07`.
4. **Corruption**: The first 8 bytes of the resulting file were changed to `BBCTFDEV` (Hex: `42 42 43 54 46 44 45 56`) using a hex editor.
