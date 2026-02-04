📝 Write-up for Behind the Lens

Challenge Summary
We are given a .zip file named near_to_flag-1.zip:
text
near_to_flag-1.zip (110KB)

The challenge hints: "treat a file as what it truly is, rather than what it pretends to be" - classic file extension trick!

Step 1 — Check the REAL File Type
bash
file near_to_flag-1.zip

Output: JPEG image data
It's NOT a ZIP file! The .zip extension is fake - it's actually a JPEG image.
Step 2 — Extract Strings
bash
strings near_to_flag-1.zip

Among the garbage output, we spot this base64 string in the XMP metadata:
text
YmJjdGZ7ZmlsZV9tZXRhZGF0YV9yZXZlYWxzX3RydXRofQo=

Step 3 — Decode Base64 Flag
bash
echo "YmJjdGZ7ZmlsZV9tZXRhZGF0YV9yZXZlYWxzX3RydXRofQo=" | base64 -d

Output:
text
bbctf{file_metadata_reveals_truth}


🏁 Flag
The final flag is:
text
bbctf{file_metadata_reveals_truth}


💡 Key Takeaway: Always verify file types with file command - extensions lie in CTF! The flag was hiding in JPEG XMP metadata as base64.