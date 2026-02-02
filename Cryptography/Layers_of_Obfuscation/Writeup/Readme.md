📝 Solution / Write-up

Given string:

2JTYZLU3DrDcH3x51q4fb4uqVMbYW88


Hint:
“Firstly decode in Base58, then XOR with CTF”

Step 1 — Base58 Decode

The string uses only Base58 characters, so decode it using Base58.

Base58-decoded bytes (hex):

01 16 05 17 12 3d 3b 3b 34 1c 26 23 36 27 23 1c 3d 35 1c 36 27 27 29


These bytes are not readable ASCII, so another layer is present.

Step 2 — XOR with "CTF"

We are told to XOR with "CTF" using repeating-key XOR.

Key bytes:

C = 0x43
T = 0x54
F = 0x46


Apply:

decoded_byte[i] XOR key[i % 3]

Step 3 — Result after XOR

After XORing all bytes with the repeating key "CTF", we get readable text:

BBCTF{xor_reuse_is_bad}

What this teaches

Reusing an XOR key is insecure. Once the key is known or guessed, the original message is easily recovered.

🏁 Flag

BBCTF{xor_reuse_is_bad}