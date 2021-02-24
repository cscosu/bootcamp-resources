# OSU CSC Bootcamp: Binary Exploitation

By: Andrew Haberlandt, Cyber Security Club @ Ohio State

Parts adapted from: b01lers bootcamp 2020, Nathan Peercy

## What is binary exploitation
- Make a [compiled/binary] program do something it wasn't intended to do
- Usually this means the goal is arbitrary code execution
- pwn is awesome, but it is hard. you'll eventually need a good understanding of C and assembly, PLUS operating systems!!

## Why
- Native code is everywhere
- EVERY APPLICATION EVER ULTIMATELY ENDS UP RUNNING MACHINE CODE
- TURTLE IMAGE FROM REV

- GOAL: Take over ('pwn') a machine.
  - If you can run whatever code you want, you can do anything the OS allows that program to do (usually anything the user has access to do)
  - After you have code execution, 'privilege escalation' concerns exploiting (usually) the operating system to gain additional privileges (i.e. normal user -> root access, or sometimes directly to kernel code execution)
  - Some special programs (ie. sudo) are usually given extra privileges to run as root ("suid programs"); exploit one of these and you get insta-root.
  - Bug Bounties: Valve, other game companies, Tesla
  - Screenshots of bounties on HackerOne or whatever
  
## What does it look like to 'pwn' a machine
- Arbitrary code execution
  - Often demonstrated by: getting a shell (opens on stdin)
  - "popping calc" 
  - Sometimes in CTF problems: opening and reading a special 'flag' file is sufficient (can do with shell, or not)
  - After you have code execution, you're often done unless you're the NSA or CIA

## DEMO: Reverse shell in bash

# OK, so how do i get code execution

## Common vulnerabilities
- Command injection
- Memory corruption: a broad category
- Off-by-one errors
- Race conditions
- (lack of) input validation
- Miscellaneous logic bugs

## Command Injection
- Programmers are lazy and often 'shell out' to run a command
- This is a vuln if an attacker can control part of the command being run

```
void get_log_file(char *name) {
  char cmd[50];
  sprintf(cmd, "cat log_file_%s", name);
  system(cmd);
}
```
- System function just uses the fork and exec syscalls
- You can imagine doing many damaging things, or leaking many important files
- You could even launch a reverse shell!

## DEMO: Command injection + pwntools

## Logic Bugs
- Most are unintentional, *Intentional* logic bugs are essentially "backdoors".
- leaving in debug options: "bypass this security measure by adding debug=1" 
- TODO: need more logic bug examples

## Memory Corruption Bugs
- Memory is a byte-addressable array of bytes
- If a user can write somewhere they are not intended to, it can be the cause of a memory corruption bug
- The important question is "can we overwrite anything important?"
    - to answer, need to know some things about where stuff is in memory

### Simplest example: Stack buffer overflow into another variable

- C program on slide w/ buffer overflow
- Stack diagram

- But there doesn't seem to be an obvious way to exploit this without a more complex program; there won't be a win condition
  - (you can still make it do unexpected things)
- Stack layout is up to the compiler, look in Ghidra to actually find out where stuff got put
- this is essentially speedrun0

### Demo: pwn2 (same as on slide) and pwn3 (overflow into some ints w/ pwntools)

- Ok i'm tired of this, what can we possibly overwrite to give us code execution?
   - a function pointer (or a pointer to some code somewhere that will get run?)
      - GOT table
      - function pointers on the stack
      - return address

### Stack buffer overflow into return address
- Surprise, there's always a pointer to some code on the stack, it's the return pointer :)
- C program on slide w/ buffer overflow
- Stack diagram

### 1990s exploitation
- Just put your code somewhere you know the address of, and then overwrite the return address so that it holds the address of your code
- When the function returns, you win.

## DEMO: Return to the 1990s + pwntools
- pwntools shellcode generator

## Modern memory protections have entered the chat
- you can't just write your code onto the stack and jump to it. the stack is not executable.
- we need to be more creative


## ROP

- we don't just control the return address, we can keep writing and we control the whole stack
- we can return to specific locations that do useful things ('gadgets')
    - pop rdi; ret;
- chain these together and you can make syscalls, etc. (beyond the scope of this talk)
    - See: 

### More examples
- What if we can write anywhere? (Where should we write?)
- Semi-arbitrary write (controlled array index)
- There is no one-size-fits-all solution, you just have to be aware of where you can write and what else is there to corrupt

## Tools

- GDB with GEF
- Ghidra and RE tools
- python3 with pwntools
- checksec, ROPGadget, a few others

## Common Defenses
- ASLR - Address space layout randomization
- PIE - Position independent executable
    - DEMO?
- NX - non-executable memory
- Stack Canaries
- ...
