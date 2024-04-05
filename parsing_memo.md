# PARSING STEPS

## Links

[Simple command expansion](https://github.com/AnoukBV/memo/blob/main/bash_man.md#simple-command-expansion)

[Shell grammar](https://github.com/AnoukBV/memo/blob/main/bash_man.md#shell-grammar)

[BashParser](https://mywiki.wooledge.org/BashParser)

[Parsing expressions by precedence climbing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)

[Parse tree](https://en.wikipedia.org/wiki/Parse_tree)

[Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar)

[Abstract Syntax Tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)

[Abstract vs Concrete Syntax Trees](https://eli.thegreenplace.net/2009/02/16/abstract-vs-concrete-syntax-trees/)

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

A grammar, in comp science has **production rules** --> when you type words, they can be expanded (variables, commands etc). 

![production rules and symbols](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1a/Terminal_and_non-terminal_symbols_example.png/675px-Terminal_and_non-terminal_symbols_example.png)

A language = generation of terminal symbols/sentences according to production rules. Non trminal symbols are symbols that can still be replaced. Trminal Symbols cannot. NTS are **variables**.
In a CFG, those rules can be applied to nonterminal symbols contextlessly : **they specify the context rules by themselves**. A -> a. No st of terminal strings like in the diagram above. One non terminal symbol = one terminal. (=/= one terminal that will only be this if it derivs from this tree specifically etc). The surroundings of both symbols donesn't matter.

**CFG = theoretical basis for the syntax of most programming lanuages.**


Recursive? We applicate the rules until we can't -> terminal symbol.

Start Symb -> NTS ... -> Terminal Symb

Bash = context free langage. Those languages are formal and can be precisely mathematically described. They allow the construction of parsing algorithms.

**G = (V, Σ, R, S)**

V = non terminal symbols. Σ = terminal symbols/final sentence. R = production rules. S = start symbol, part of V.

We can have V -> V -> V -> Σ.

Bash: single quote = V, with consequences on $... = V etc.

**Derivation of a string: sequence of grammar rule application that transform the start symbol into the string**. One step needs a rule. A derivation can be leftmost or rightmost.

From derivation : a **parse tree**. One string = one parse tree or the language is said to be ambiguous. Finding systemic rules to apply is important. Our grammar needs not to be ambiguous.

Can our grammar have eprod ? Null string.

What we ned to do: determine those rules.

### Parse tree

![Parse tree](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6e/ParseTree.svg/225px-ParseTree.svg.png)

Parse tree = derivation tree or **concrete syntax tree** (as opposed to abstract syntax tree). Represents the syntaxic structure of a string according to the production rules of a CFG.

In a way: generation of a phrase marker. We applicate phrase structure rules on a sentence. The phrase marker is the parse tree, that can later be subject to further transformation rules.

Root node.
Branch nodes.
Leaf nodes.

OR

Parent nodes and children nodes.

Leaf nodes are terminal functions. Lexical tokens.

CLE is still represented concretely, but in parsed form (above we see the text of the sentence presrved in the leaves). Usually, the concrete syntax tree only exists as a conceptual entity representing the parse structure of your source text.

Parse trees are a mapping of the grammar of the entry, they don't transform the input. They are not useful to work with. Trivial to build **when you have your rules.**

Parse tree for:
```C
return a + 2;
```

![Parse tree](https://eli.thegreenplace.net/images/2009/02/parsetree1.png)

AST for the same entry, we see that even the hierarchy has been changed.

![AST a + 2](https://eli.thegreenplace.net/images/2009/02/ast1.png)

### Abstract syntax tree

Why abstract? It does not represent the details of the sentence, but **just the structural or content related details**.

![abstract syntax tree](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c7/Abstract_syntax_tree_for_Euclidean_algorithm.svg/600px-Abstract_syntax_tree_for_Euclidean_algorithm.svg.png)

Data structure that represents a CLE. Final phase of syntax analysis, last operation of the front-end of a compiler. Useful because:
- It can be edited with further information. Source code stays unchanged.
- It does not include delimiters.
- Extra information about the program is included. EX: position of each element, used to print corresponding useful error messages (about syntax for example!!)

The AST is the form that is convenient for further manipulation. AST oncly contains semantics of the code, CST also includes information on how exactly the code was written. CST keeps things like parenthesises, quotes tc that will later be used to expand etc.

### Precedence climbing technique
