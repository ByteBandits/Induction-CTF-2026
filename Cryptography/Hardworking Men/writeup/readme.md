# 📝 Solution / Write-up

## Step 1 — Inspect the given file

We are provided with `Project.txt` containing:

**VVMBT{Y4WHD0WE1KG_L3K_0K_BYRUW_E3JV04WHS}**


At first glance, this already resembles a flag format, but the text appears scrambled or meaningless.

This suggests some kind of **substitution cipher**.

---

## Step 2 — Identify the pattern

The challenge description hints:

> "Hardworking men"  
> "I wonder what they were working on"

This suggests something related to **work** or **working layout**.

A common cryptography trick involves **keyboard layout ciphers**.

This points toward alternative keyboard layouts.

---

## Step 3 — Recognize the keyboard cipher

The text was typed using the **Workman keyboard layout** instead of the standard **QWERTY** layout.

So:

- Keys were pressed using **Workman**
- But we must interpret them as **QWERTY positions**

In other words:

👉 replace each character with the key located at the **same physical key position** on a QWERTY keyboard.

---

## Step 4 — Decode

Mapping Workman → QWERTY reveals the readable text:

BBCTF{H4RDW0RK1NG_M3N_0N_THEIR_K3YB04RDS}


---

## 🏁 Flag

**`BBCTF{H4RDW0RK1NG_M3N_0N_THEIR_K3YB04RDS}`**
