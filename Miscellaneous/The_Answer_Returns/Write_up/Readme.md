# 📝 Write-up for The Answer Returns  
***

## Challenge Summary

We are given a compressed file:

```text
mystery.zip
```

The description + hint say we do **not** need hacking tools and that the message “tells you exactly what it is” and we should “try saying the answer out loud”. So this is more of a riddle than a technical challenge.

***

## Step 1 — Unzip the File

Unzip the archive normally:

```bash
unzip mystery.zip
```

This gives a single text file:

```text
message.txt
```

***

## Step 2 — Read the Message

Open the file:

```bash
cat message.txt
```

Content:

```text
I speak without a mouth,
And hear without ears.
I have no body,
But I come alive with wind.

Who am I?
```

This is a classic riddle.

***

## Step 3 — Solve the Riddle

Think about what:

- “speaks without a mouth”
- “hears without ears”
- “has no body”
- “comes alive with wind / sound”

The answer is an **echo** — a reflected sound that “answers” you.

According to the challenge, the flag format is `bbctf{...}`, so we wrap the answer:

```text
bbctf{echo}
```

***

## 🏁 Flag

The final flag is:

bbctf{echo}
