# The Puppeteer's Scrap - Writeup

## Challenge Description
"The local police recovered a strange piece of paper from the scene of a heist. The suspect, a man obsessed with 19th-century detective fiction, left a drawing of what looks like children's stick figures. Detective Aris noted that some figures were holding flags, while others were not. He mentioned that the solution is 'elementary' and to look into the case files of a certain consultant from 221B Baker Street."

**Category:** Cryptography  
**File:** `dance.png`

## Analysis
The description heavily references Sherlock Holmes (221B Baker Street, "elementary", 19th-century detective fiction). The "children's stick figures" and "holding flags" refer to a specific cipher used in the Sherlock Holmes stories.

## Cipher Identification
The cipher is the **Dancing Men Cipher** from "The Adventure of the Dancing Men". Each figure corresponds to a letter, and figures with flags denote the end of a word.

The figures can be decoded using this tool: [dcode.fr/dancing-men-cipher](https://www.dcode.fr/dancing-men-cipher)

## Decoding
By mapping each stick figure in `dance.png` to the Dancing Men alphabet, we get the following characters:

**`NOTALLCIPHERSUSELETTERS`**

## 🏁 Flag
**`BBCTF{NOTALLCIPHERSUSELETTERS}`**
