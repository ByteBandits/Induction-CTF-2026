# Turing Tarpit Pika - Writeup

## Challenge Description
> Agent, we intercepted a transmission from the chaotic hacktivist group ‘The Glitch’.
> It looks like nonsense spoken by a Pokémon trainer lost in a blizzard.
> They say the message becomes clearer if you listen to the silence between the thunder.

**Category:** Cryptography  
**Points:** 100  
**File:** `pika.txt`

## Step 1: Initial Analysis
The provided file `pika.txt` contains a repetitive sequence of words like `pi`, `pika`, `pipi`, `pichu`, `ka`, and `chu`.

```text
pi pi pi pi pi pi pi pi pi pi pika pipi pi pipi pi pi pi pipi pi pi pi pi pi pi pi pipi pi pi pi pi pi pi pi pi pi pi pichu pichu pichu pichu ka chu ...
```

The mention of "Turing Tarpit" strongly suggests an esoteric programming language based on Pokémon sounds.

## Step 2: Identifying the Language
This specific vocabulary (`pika`, `chu`, `pipi`, etc.) belongs to **Pikalang**, a Brainfuck-equivalent esoteric language where each word maps to a Brainfuck command.


## Step 3: Decoding
To decode the message, we can use an online Pikalang decoder like [dcode.fr/pikalang-language](https://www.dcode.fr/pikalang-language) or write a simple script to translate it to Brainfuck and run it.




## Final Flag
decoding the code results in the following output:

**`BBCTF{p1k4_p1k4_0h_n0}`**
