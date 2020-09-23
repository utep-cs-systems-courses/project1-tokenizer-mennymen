Project 1: Tokenizer
====================

# Project Description

This project consists of a tokenizer, which receives string inputs from the
user and tokenizes it. To accomplish this, each word from the string is
separated and a pointer to each word is created, where there is a pointer of
pointers to retrieve all of the tokens. The program also stores all of the
sentences that have been tokenized and the user is able to see the list, or
retrieve a specific sentence that was tokenized.

# How To Access, Compile, and Run


1) After turning on your VM, type 'emacs' and press ENTER
2) Once in emacs, press M-x, then type 'shell', then press ENTER
3) Type 'cd project1', then press the TAB key, then press ENTER
4) Type 'cd src', then press Enter
5) Type 'make' and press ENTER to compile the program
6) Optionally, you can type 'make clean' and press ENTER to remove the .o files
7) Type './a.out' to run the program

# How To Use

Once the program is running, there are several options for the user to do.

1) Type '@' and press Enter to end the program
2) Type '$' and press Enter to see all of the sentences tokenized so far
3) Type '!' followed by a number and press Enter to see the
sentence that was tokenized in that nominal order. For example '!', then '2'
will retrieve the second sentence that was tokenized, if any.
4 Type any sentence that does not start with any of the previous characters to
have it tokenized.

