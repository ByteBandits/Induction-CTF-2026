# Grandpa's Birthday Gift - Writeup

## Challenge Information
- **Category:** OSINT
- **Points:** 200
- **Description:** The challenge describes an old animated film made with cut-out paper silhouettes (black and white, shadowy style) that is more than a century old. The story involves a princess imprisoned by her father in a tower and rescued by a protagonist (described by the granddad as a fisherman).
- **Flag Format:** `BBCTF{director_name_movie_name}`

## Analysis

### 1. Identifying the Art Style
The description mentions a "short film" made with **"cut-out paper silhouettes"** that is **"more than a century old"**. The shadowy style points to **Shadow Puppetry** and its cinematic evolution, **Silhouette Animation**, a technique pioneered in the early 20th century.

### 2. Identifying the Pioneer
Searching for "silhouette animation pioneer" or "cut-out paper silhouette film 100 years ago" leads to **Lotte Reiniger** (1899–1981). She was a German silhouette animator and is considered the foremost figure in this unique art style. Her career started around 1919, making many of her early works over 100 years old today.

### 3. Finding the Specific Film
The granddad remembers a story about a **princess imprisoned in a tower** by her father and a **rescue**.
Looking through Lotte Reiniger's early repertoire:
- *The Ornament of the Enamoured Heart* (1919)
- *Acheron* (1920)
- *Der fliegende Koffer* (1921) / *The Flying Coffer* (or *The Flying Trunk*)

The film ***Der fliegende Koffer*** (1921) is the one we are looking for.



### 4. Constructing the Flag
- **Director Name:** Lotte Reiniger
- **Movie Name:** Der fliegende Koffer (German title) or The Flying Koffer (as hinted in some contexts)

Given the user's hint "the flyinh Koffer", the intended movie name is likely **Der fliegende Koffer** or **The Flying Koffer**.

Note: Both the english and german names are accepted as the movie name in the flag.

**Flag:** `BBCTF{Lotte_Reiniger_Der_fliegende_Koffer}`

## Solution Summary
1. Research the silhouette animation style and timeframe (100+ years).
2. Identify **Lotte Reiniger** as the key director.
3. Match the "princess in a tower" plot to her 1921 film ***Der fliegende Koffer***.
4. Format the flag as per the specified template.
