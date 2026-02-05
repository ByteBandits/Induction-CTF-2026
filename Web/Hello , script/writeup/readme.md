# 📝 Solution / Write-up

The website provides a **"Message the Admin"** feature where submitted messages are viewed by the administrator.

Inspecting the page source shows that the message from the query parameter is inserted into the DOM using **innerHTML** without proper sanitization.

This introduces a **Cross-Site Scripting (XSS)** vulnerability.

Because the admin automatically views submitted messages, we can inject a malicious payload that executes JavaScript in the admin’s browser.

Using a simple payload such as:

<img src=x onerror=...>

we can run arbitrary JavaScript and extract sensitive data. The cookies are not marked **HttpOnly**, allowing us to steal them and retrieve the flag.

## 🏁 Flag

**`bbctf{@_Re@lly_loU$y_4dM!n}`**
