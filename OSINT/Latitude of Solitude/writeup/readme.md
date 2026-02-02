# 📝 Solution / Write-up

## Step 1 — Understand the clues

From the description and poem, we can tell the place is somewhere in the very northern part of the Earth.

Looking carefully at the image, we see:
- mountains
- no trees or vegetation
- a frozen lake
- complete isolation

This clearly suggests an Arctic or extreme northern location.

---

## Step 2 — Reverse image search

Since this is an OSINT challenge and the image looks like it could be taken from Street View, we perform a reverse image search.

If you are lucky, this leads to an online article mentioning the **northernmost places reached by** Google Street View, where the place name can be directly found.

---


## Step 3 — Manual searching (alternative method)

If reverse image search does not work, we can manually search for:

"northernmost place with Google Street View"

This leads us to **Quttinirpaaq National Park (Nunavut, Canada)**,

which is one of the northernmost accessible locations with Street View coverage.


---

## Step 4 — Confirm the exact spot

Opening Street View in this region shows only a few points because the area is extremely remote.

Exploring these points, we find a location with a frozen lake and surrounding mountains that exactly match the challenge image.

Reading the coordinates and rounding to two decimal places gives:

## 🏁 Flag

**`BBCTF{81.45,-76.47}`**
