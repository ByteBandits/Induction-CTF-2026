📝 Solution / Write-up

## Step 1 — Observe the image

The image shows:
- A bicycle stopped on a curved path
- Fencing along the trail
- Open grassy area
- No buildings or city features

This suggests a **rural / countryside cycling or walking trail**.

---

## Step 2 — Reverse image search

Since this is a easy OSINT challenge, the first and foremost approach is a **reverse image search**.

Uploading the image to tools like:
- Google Images
- Yandex Images

returns visually similar results and nearby locations.

From these results, we roughlyget to know the place.

---

## Step 3 — Locate the exact spot

After finding the approximate location:
- Open the area in **Google Maps**
- Enable **Street View**
- Look for a matching curve in the path, fencing style, and surrounding terrain
- Do look for photo spheres too (not necessary that whole trail is covered right?)

The scene in Street View matches the challenge image closely.

---

## Step 4 — Extract coordinates

Once the correct spot is found:
- Read the **latitude and longitude** from Google Maps
- Round both values to **two decimal places**

---

## 🏁 Flag

BBCTF{-45.11, 168.46}