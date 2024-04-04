# PARSING STEPS

## Links

[Simple command expansion](https://github.com/AnoukBV/memo/blob/main/bash_man.md#simple-command-expansion)

[Shell grammar](https://github.com/AnoukBV/memo/blob/main/bash_man.md#shell-grammar)

[Parsing expressions by precedence climbing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)

[Parse tree](https://en.wikipedia.org/wiki/Parse_tree)

[Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar)

[Abstract Syntax Tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)

--------------------------------------------------
## SUMMARY

Parsing = treating user's input.
Which we can do in  systemic way, just like bash does.

--------------------------------------------------
![Bash component architecture](https://miro.medium.com/v2/resize:fit:640/format:webp/1*Tcrp-wDL3JtLHNHpvvBlNA.png)

## Lexical analysis

Dividing a string into tokens/lexems.

## Parsing

We operate according to a **grammar**. Shell's grammar is a **CFG**(Context free grammar).
The goal is to build an **abstract syntax tree**(AST). 

First we create a **parse tree**.

We operate using **precedence climbing technique**.

Once we have our tree, we need to **initialize it**.

### Context free grammar

### Precedence climbing technique

### Parse tree

### Abstract syntax tree
