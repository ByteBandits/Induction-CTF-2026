# 📝 Solution / Write-up

## Challenge — Role Escalator

**Description:**  
*“What if you can rewrite your story??”*

A web application is hosted at the given URL, hinting toward **role manipulation or privilege escalation**.

---

## Step 1 — Explore the Web Application

Visiting the website shows a basic web interface with user-level access.

Inspecting requests (using browser dev tools / Burp Suite) reveals that authentication is handled using a **JWT (JSON Web Token)**.

---

## Step 2 — Extract the JWT Token

After logging in, a JWT token is found stored in:
- Cookies / Local Storage
- Or Authorization header

The token follows the standard JWT format:


---

## Step 3 — Decode the JWT

Using an online JWT decoder (e.g. jwt.io) or local tools, the token payload is decoded.

The payload contains a field similar to:

```json
{
  "username": "user",
  "role": "user"
}
```
---

## Step 4 — Modify the Role

Since the JWT signature is not properly validated by the server, the token can be tampered with.

Steps:

1.Change the value of role from:
```
user → admin
```

2.Re-encode the JWT with the modified payload.

3.Replace the original token in the browser with the modified one.
---
## Step 5 — Access Admin Privileges

After sending the modified JWT to the server, the application now treats the user as an admin.

This grants access to restricted admin-only functionality, where the flag is revealed.
---
``BBCTF{JWT_R0L3_3SC4L4T10N_SUCC3SS}``

