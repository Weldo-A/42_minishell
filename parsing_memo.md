# PARSING STEPS - GENERAL MEMO

## Links

### Bash\/Unix shell  grammar

[Simple command expansion](https://github.com/AnoukBV/memo/blob/main/bash_man.md#simple-command-expansion)

[Shell grammar](https://github.com/AnoukBV/memo/blob/main/bash_man.md#shell-grammar)

[The Bourne-Again Shell](https://aosabook.org/en/v1/bash.html)

[Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

### Building a parser

[Parsing expressions by precedence climbing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)

[Recursive descent parsing](https://www.youtube.com/watch?v=SToUyjAsaFk)

[Parsing expression by recursive descent](https://www.engr.mun.ca/~theo/Misc/exp_parsing.htm)

[Let's write a recursive descent parser in C (Part 1)](https://www.youtube.com/watch?v=N55XNj8KjC4)

[Making a shell grammar for a recursive descent parser](https://stackoverflow.com/questions/71769632/making-a-shell-grammar-for-a-recursive-descent-parser)

[Parse tree](https://en.wikipedia.org/wiki/Parse_tree)

[Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar)

[Abstract Syntax Tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)

[Abstract vs Concrete Syntax Trees](https://eli.thegreenplace.net/2009/02/16/abstract-vs-concrete-syntax-trees/)

[Lexical Analysis](https://en.wikipedia.org/wiki/Lexical_analysis)

--------------------------------------------------
## SUMMARY

Building a parser :

[The two main stages of front-end]
- [Lexical analysis]
- [Parsing]

[Context Free Grammar]

[Parse tree]

[Abstract Syntax Tree]

[Precedence climbing]

Extension of Bash Man :

[Bash grammar]

--------------------------------------------------
Parsing = treating user's input.
Which we can do in  systemic way, just like bash does.

![Bash component architecture](https://miro.medium.com/v2/resize:fit:640/format:webp/1*Tcrp-wDL3JtLHNHpvvBlNA.png)

## The two main stages of front-end

### Lexical analysis

Dividing a string into tokens/lexems.
We want those tokens to correspond to the categories of our grammar. Identifier, operator...
First phase of front-end.

1. Scanning: segment the input into syntactic units = lexemes + categorization into token classes. The scanner holds information about any possible tokens. ex: name = only alphanumeric
2. Evaluating: converting lexemes into processes values. Real construction of tokens. It retrieves lexem type + value from the scanning phase. Removes unnecessary characters (ex double quotes si juste "ls -l".

A lexeme is a bash word.

A lexical token is a str with an assigned and identified maning. Token name + token value.

Bash ex:
- TN = name/identifier, TV = x, a, color
- TN = reserved words, TV = for, while, cmd
- TN = metacharacters, TV = space, tab, \<nl\>
- TN = control operator, TV = ||, ;, |, |&

Token classes can be manipulated in bash using quotes to remove the signification of resrved words or metacharacters or control parameter expansions.

```bash
a=4<nl>
(name/identifier, a), (assignment operator, =), (control operator, <nl>)
```

We convert raw text into something syntaxically meaningful. This data is retrieved by the parser. 

**No syntax error management**
The combination of tokens is left for the parser. ex: a lexer doesn't car if ( is not matched with ). Syntax error will com from the parser.

Each token name is usually given a number (ex: word 0) to facilitate the feeding of the parser.

### Parsing

We operate according to a **grammar**. Shell's grammar is a **CFG**(Context free grammar).
The goal is to build an **abstract syntax tree**(AST). 

First we create a **parse tree**.

We operate using **precedence climbing technique**.

Once we have our tree, we need to **initialize it**.

## Context free grammar

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

## Parse tree

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

## Abstract syntax tree

Why abstract? It does not represent the details of the sentence, but **just the structural or content related details**.

![abstract syntax tree](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c7/Abstract_syntax_tree_for_Euclidean_algorithm.svg/600px-Abstract_syntax_tree_for_Euclidean_algorithm.svg.png)

Data structure that represents a CLE. Final phase of syntax analysis, last operation of the front-end of a compiler. Useful because:
- It can be edited with further information. Source code stays unchanged.
- It does not include delimiters.
- Extra information about the program is included. EX: position of each element, used to print corresponding useful error messages (about syntax for example!!)

The AST is the form that is convenient for further manipulation. AST oncly contains semantics of the code, CST also includes information on how exactly the code was written. CST keeps things like parenthesises, quotes tc that will later be used to expand etc.


## Recursive descent parser

A parsing algorithm that aims at: treating an expression as a bunch of nested sub-expressions. "Each sub-expression has in common the lowest precedence level of the the operators it contains."

Precedence = the order in which operations are evaluated when there a multiple operations in an expression. The higher precdence is first.

For bash, precedence is described from "Simple command expansion".

When precedence is the same : associativity.

How does bash handle nested expressions ? Do we even have to handle brackets ?


## BASH

### Before parsing

Reserved words - Words - Operators(on or more metacharactes).

Variables are user settable or built in. 
Assigning a value is the only way to set a variable.
Variables are strings.
A word beginning with a dollar introduces a variable or parameter reference.
Integer type variables are treated as numbers: str is expanded as an artihmetic expression assigned to the variable.
Arrays can be indexed or associative.

Hash tables to store and retrieve variables. Variable scoping: linked list of these hash tables. Different variable scopes for shell function calls and tmporary scops for variables set by assignment statements preceding a command.

**Simple shell command**

Command name, args, redirections. There can be pipelines, shll functions, and shell scripts.

Question to be askd(man bash) : what is passed to a shubshll??

Nearly all of the shell constructs are implemented using:
- arrays
- trees
- singly-linked lists and doubly-linked lists
- hash tables

"The basic data structure the shell uses to pass information from one stage to the next, and to operate on data units within each processing stage, is the WORD\_DESC":
```C
typedef struct word_desc {
  char *word;           /* Zero terminated string. */
  int flags;            /* Flags associated with this word. */
} WORD_DESC;
```
"Words are combined into, for example, argument lists, using simple linked lists:"
```C
typedef struct word_list {
  struct word_list *next;
  WORD_DESC *word;
} WORD_LIST;
```
"WORD\_LISTs are pervasive throughout the shell. A simple command is a word list, the result of expansion is a word list, and the built-in commands each take a word list of arguments."

**Not to be handled for minishell**:

Input processing. From str to command. Command line editing: readline library implemented for bash. First step = breaking into lines. RL has a buffer, rl\_redisplay changes what is displayed on the terminal, according to what is actually in the buffer of RL. (int rl\_redisplay()). To change what's in the buffer : void rl\_replace\_line(const char \*text, int clear\_undo).

### The Bash Parser

All of this should happen after tokenizing/lexing.

**To be escaped = stripped of their ability to mean anything special to Bash.**

1. Lexical Analysis. Separates str into words (basic unit on which the parser operates).

Read data to execute. Line by line except when nl is escaped by a reserved word like while ? Or by a quote etc. Lexical analyzer takes line from readline, breaks them into tokens at metacharacters, **identifies the tokens** and passes them to the parser.

For identification --> **context**.

Aliasing is done here, but we don't need to implement that for minishell.

**Metacharacters can be escaped**: backlash, single or double quotes. + \$\'...\' or \$\"...\".
Processes quotes. Searches for quotes. Triggers a quote : searches for the next one. '' cancels special meanings. "" doesn't cancel \" \$ and \\
```bash
$ echo 'Back\Slash $dollar "Quote"'
Back\Slash $dollar "Quote"
```
Including the others single quotes (that's why it should **never** happen according to bash man.
```bash
$ echo 'Don\'t do this'
>
```
Awaits for the second quote.
Now bash removes the quotes used to determine if characters where to be escaped.
With :
```bash
$ echo 'Back\Slash $dollar "Quote"'
```
Double quotes won't be removed since they've been escaped.
```bash
echo "anouk"$a"anou\nyoyo" | cat -e
```
Double quotes in the middle are not escaped, so what will be displayed is the result of three str concatenated anouk, the expansion of $a and anouk\nyoyo.
```bash
echo "anouk\"$a\"anou\nyoyo" | cat -e
echo "anouk'$a'anou\nyoyo" | cat -e
```
Here, the quotes in the middle are either escaped or single so escaped by the double quotes. For all cases a is expanded. Not if we had had (unescaped) single quotes!

**Note**: All of the characters (except the \$ " \\) in between quotes are considered escaped by the bash parser.

Lexical analyzer categorizes words according to the token type. To do so, it has to be given a certain number of informations by the parser regarding the context (ex: is it a here doc etc.). Command substitution: execution happens during parsing. \"A command substitution can be parsed and executed as part of expanding a prompt string in the middle of reading a command.\"

End of lexical analysis --> a **structure** representing a command. Passed to word expansion.

2. Word expansions

- Par and var expansions. Error management for minishell:
```bash
${parameter:-word}
```
expands to parameter if it's set, otherwise expands to word.

- brace expansion (unneeded fo minishell)
- command substitution (shell runs a cmd, collects the output)
- tilde expansion
- arithmetic expansion
```bash
$((expression))
```
- word splitting

**Globbing**

Each word resulting is interpreted as a potential pattern, bash tries to match it with an existing filename, including any leading directory path.

WORD\_DESC and \_LIST are enough to handle expansions. DESC can hold all of the info required to handle expansion of a single word. flags in desc = info for use within the expansion stage + to pass info from one expansion stage to the next.
> For instance, the parser uses a flag to tell the expansion and command execution stages that a particular word is a shell assignment statement, and the word expansion code uses flags internally to inhibit word splitting or note the presence of a quoted null string ("$x", where $x is unset or has a null value). Using a single character string for each word being expanded, with some kind of character encoding to represent additional information, would have proved much more difficult.

**To Command execution**

Input to the command execution stage = command structure built by the parser and a set of possibly expanded words.

### BASH EXECUTION

- redirections
In parsing: lexical analyzer classified a word as a redirection containing a variable assignement. Parser created the redirection object wth a flag indicating assignement.
In exec: the flag is interpreted and the fd is assigned to the correct variable.

**The effect of redirections should not persist beyond the command completion.** Shell has to undo the effects. 

> Since multiple redirections are implemented as simple lists of objects, the redirections used to undo are kept in a separate list. That list is processed when a command completes, but the shell has to take care when it does so, since redirections attached to a shell function or the "." builtin must stay in effect until that function or builtin completes. When it doesn't invoke a command, the exec builtin causes the undo list to simply be discarded, because redirections associated with exec persist in the shell environment.

- Builtins
Executed by the shell **without creating a new process**.
>  For the most part, the builtins use the same standard expansion rules as any other command, with a couple of exceptions: the bash builtins that accept assignment statements as arguments (e.g., declare and export) use the same expansion rules for the assignment arguments as those the shell uses for variable assignments. This is one place where the flags member of the WORD\_DESC structure is used to pass information between one stage of the shell's internal pipeline and another.

- Simple command execution

If variables precede a command, the are passed to the executed command in its env. If not, the assignement **modifies the sell's state**.

The execution environment is an exact duplicate of the shell environment, with minor modifications to things like signal disposition and files opened and closed by redirections.

**Minishell must not handle compoumd commands."
