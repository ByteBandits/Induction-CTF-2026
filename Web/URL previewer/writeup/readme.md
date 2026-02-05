# 📝 Solution / Write-up

The application provides a URL preview feature where the server fetches user-supplied URLs and returns the response.

Looking at the source code shows that requests are made directly by the backend, which introduces a **Server-Side Request Forgery (SSRF)** vulnerability.

Although the app attempts to block loopback and private IP ranges, the filtering is incomplete.  
It only checks the input string and does not properly validate the **resolved IP address**.

The internal service (which contains the flag) runs on a separate localhost port that is not exposed to the internet.

By using a domain that resolves to a loopback address (for example services like **nip.io**, which map subdomains to arbitrary IPs such as `127.0.0.2`), we can bypass the filter and force the server to access its own internal service.

Fetching the internal endpoint through this SSRF reveals the flag.

## 🏁 Flag

**`bbctf{3_pe_sir_pe_4_pe_modi_ke_ghar_pe}`**
