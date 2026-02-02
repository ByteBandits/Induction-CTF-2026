🔐 RSA Reuse — Write-up

While looking at the given files, notice something interesting in public.txt.

The same RSA modulus n was used with two different public exponents:

e1 = 65537
e2 = 17


There were also two ciphertexts:

c1 → encrypted using e1
c2 → encrypted using e2


This immediately will remind of a known RSA weakness called the Common Modulus Attack.

Step 1 — RSA formula

RSA encryption works as:

c = m^e mod n


So here:

c1 = m^e1 mod n
c2 = m^e2 mod n


Both ciphertexts are of the same message and use the same modulus.

This is the exact condition required for the common modulus attack.

Step 2 — Check the important condition

The attack works only if:

gcd(e1, e2) = 1


Here:

gcd(65537, 17) = 1


So we can find integers a and b such that:

a·e1 + b·e2 = 1


Using Extended Euclidean Algorithm, we got:

a = -8
b = 30841

Step 3 — Recover the message mathematically

Using the identity:

m = c1^a * c2^b mod n


Since a is negative, we use modular inverse:

c1^(-8) = (inverse(c1))^8 mod n


So the formula becomes:

m = (inverse(c1)^8 * c2^30841) mod n

Step 4 — Python solver

Solver.py



🏁 Flag

bbCTF{r5a_h4s_b334_D3cRypT3D_5789}