# 📝 Solution / Write-up

Inspecting the provided source code reveals that the Flask application directly renders user input inside a Jinja2 template.

Since the input is not properly sanitized or escaped, this introduces a **Server-Side Template Injection (SSTI)** vulnerability.

By supplying template expressions, the server evaluates them instead of treating them as plain text. This confirms that arbitrary Jinja2 code execution is possible.

Using a standard Jinja2 SSTI payload, we can access Python internals and read files from the filesystem, allowing us to retrieve the flag.

## 🏁 Flag

**`bbctf{UnleA5h_ThE_J1NJ@_w!TH!N_yOU!}`**
