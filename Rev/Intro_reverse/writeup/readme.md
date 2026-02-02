# Intro Reverse

## Challenge Description
- **Category:** Reverse Engineering
- **Points:** 100
- **Level:** Beginner

Introduction to Reverse Engineering Challenge! Will you be able to conquer this devilish level?

## Analysis

The challenge provides an `index.html` file that contains a simple web interface with a flag input field and a "Check" button.

The core logic for flag verification is found within a JavaScript function called `checkFlag()`:

```javascript
function checkFlag() {
  const input = document.getElementById('flagInput').value.trim();
  const errorMsg = document.getElementById('errorMsg');

  if (!input.startsWith("BBCTF{") || !input.endsWith("}")) {
    errorMsg.textContent = "Invalid flag format.";
    return;
  }

  const core = input.slice(6, -1); // remove BBCTF{ }

  if (btoa(core.split('').reverse().join('')) === 'dDFfdDBuX3MxX3MxaHQ=') {
    errorMsg.textContent = '';
    document.getElementById('congratsModal').style.display = 'flex';
    document.getElementById('flag').textContent = input;
  } else {
    errorMsg.textContent = 'Incorrect flag. Try again!';
  }
}
```

### Breakdown of the logic:
1.  **Format Check**: The input must start with `BBCTF{` and end with `}`.
2.  **Extraction**: The part inside the braces (`core`) is extracted.
3.  **Transformation**:
    -   The `core` string is split into an array of characters.
    -   The array is reversed.
    -   The reversed characters are joined back into a string.
    -   The result is encoded using `btoa()` (Base64 encoding).
4.  **Comparison**: The Base64 string is compared against the hardcoded string `'dDFfdDBuX3MxX3MxaHQ='`.

## Solution

To find the flag, we need to reverse the transformations applied to the `core`:

1.  **Base64 Decode**: Decode the target string `'dDFfdDBuX3MxX3MxaHQ='`.
    ```bash
    echo "dDFfdDBuX3MxX3MxaHQ=" | base64 -d
    # Output: t1_t0n_s1_s1ht
    ```

2.  **Reverse the String**: Reverse the decoded string `'t1_t0n_s1_s1ht'`.
    -   Original (decoded): `t` `1` `_` `t` `0` `n` `_` `s` `1` `_` `s` `1` `h` `t`
    -   Reversed: `t` `h` `1` `s` `_` `1` `s` `_` `n` `0` `t` `_` `1` `t`
    -   Result: `th1s_1s_n0t_1t`

3.  **Construct the Flag**: Combine the core with the prefix and suffix.
    -   Flag: `BBCTF{th1s_1s_n0t_1t}`

## Flag
`BBCTF{th1s_1s_n0t_1t}`
