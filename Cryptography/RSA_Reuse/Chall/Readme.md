🔐 RSA Reuse

Category: Cryptography
Points: 300

🧾 Description

You intercepted two ciphertexts encrypted using RSA. On inspection, you notice something unusual — both ciphertexts were generated using the same RSA modulus n but different public exponents.

The sender seems unaware that this small mistake completely breaks the security of RSA.

Your task is to analyze the provided files, exploit this weakness, and recover the hidden message.

Flag format:

bbCTF{...}

📁 Files Provided

public.txt

c1.bin

c2.bin