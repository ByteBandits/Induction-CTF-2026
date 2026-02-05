# 📝 Solution / Write-up

Opening the website shows that it takes an unusually long time to load.

This suggests checking the browser’s **Network tab** to observe what is happening in the background.

Inspecting the network activity reveals multiple **HTTP redirects** occurring sequentially.

Each redirect leads to a different page that displays only a **single character**.

Following the redirects in order and collecting each character gradually forms the complete flag.

Combining them correctly gives:

## 🏁 Flag

**`bbctf{4!way5Ke3p-m0v1ng}`**
