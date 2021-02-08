# OSU CSC Bootcamp: Reverse Engineering

By: Andrew Haberlandt and Kyle Westhaus, Cyber Security Club @ Ohio State
Adapted from: Rowan Hart, b01lers 2020 training bootcamp [Original](https://github.com/b01lers/bootcamp-training-2020/blob/master/rev/day_1/slides/day_1.pdf)

## What is reverse engineering 
- Official Definition: "...the process by which a man-made object is deconstructed
to reveal its designs, architecture, code, or to extract knowledge from the object"
- In other words, figure out how something works
  - With or without documentation
  - Level of understanding required depends on the task

- Examples
  - Figure out how a co-workers code works after they got fired
  - Figure out how a game communicates in a multiplayer session, to give you a competitive advantage
  - Figure out how a streaming service plays audio/video, so you can download your favorites (but piracy bad)

## About Computers (CSE 3421 in five minutes)
- You probably have a x86 laptop/desktop, and an ARM phone, but they have some things in common.
- A computer understands a defined set of 'instructions', which encapsulate some small operation (arithmetic, data movement, and I/O)
- The exact set of instructions depends on the architecture - x86 and ARM are 'instruction set architectures'; they have some architectural differences and these differences are reflected in the instruction set
  - x86 is **CISC** (complex instruction set computer): Many instructions, can do complex operations in 1 (slow) instruction
  - ARM is **RISC** (reduced ""): Fewer instructions, complex operations take multiple instructions
- Slide: Example of simple x86 assembly to do some math and movement
  - Memory is a 'sea of byte-addressable bits'
  - Machine code: instructions => represented as a few bytes (4 on ARM, 1-16 on x86)
- Assume instructions run **'serially'** (one at a time, previous one completes before the next one can run)
  - They don't, take CSE 3421 to learn more (see also: hardware side-channel vulnerabilities)

- EVERY APPLICATION EVER ULTIMATELY ENDS UP RUNNING MACHINE CODE
  - **Native applications (compiled code):** Compile to machine code, distribute to users, then they run it. (Examples: iOS applications, Desktop applications, web servers, web browsers, ...)
  - **JIT-ed languages:** You write Javascript, there's an 'just-in-time' interpreter (?) in the web browser that takes your JS and just-in-time (JIT) compiles it into machine code, and runs it...
  - **Intrepreted languages:** An interpreter directly runs source code, implementing all the behaviors of the language. Ex. The most common Python implementation, CPython (should i show a python sample? maybe)
  - Often some combination of above

## Reversing... what are you given?
- Native applications: You get machine code (executable, or shared library)... you can use a **disassembler** to look at the instructions. There are also 'decompiler' tools available that will decompile to a C-like representation.
- Java applications: You'll usually get a .jar (or .apk if Android) containing **bytecode**... you can look at the bytecode or there are also good tools for 'decompiling' back to nearly-runnable but often hard-to-read Java code.
- Web applications: You can always view Javascript (+ HTML + CSS) in the browser (see the web talk). But minification tools make it hard to understand what is going on.

## DEMO?: Toss Spotify in Ghidra, 2221 components.jar in jadx decompiler, view minified JS on osu.edu

## Reversing... what do we lose? (Why is reversing hard?)
Usually...
- Useless variable names
  - For native: variables can be in a register, on the stack, heap, etc.
- No documentation (no inline comments)
- Obfuscated control flow (compilers can make all kinds of optimizing decisions)
  - Function calls may no longer be function calls
- But... we still have strings! See an interesting error message? Look for it!

## If you know <interpreted language>, you are reasonably well equipped to reverse it
- Slide: example of obfuscated JS or somewhat nasty decompiled Java

## General Techniques
- Static Analysis
  - Stare at what you are given until it makes sense: machine code (we'll talk about for the rest of this talk), decompiled Java, minified Javascript or Python.
  - Hard, but easier the more you do it and the better you know the language you are staring at
- Dynamic Analysis
  - Run it and see what happens (You control a *lot* of input. Press buttons repeatedly, What happens if you disconnect it from the internet? )
  - Debuggers, other runtime inspection tools (Run it, pause it and poke around)
    - Web: Set breakpoints in Chrome, look at the arguments instead of staring at f(a, b, c) - backtraces are your new best friend
    - Native: Use a debugger such as GDB (linux), windbg (windows) - set breakpoints at addresses, look at registers
      - See also: GEF for GDB
    - Java / Android: https://frida.re/ (also useful for native), there's some other tools like this too
  - I/O interception: Web debugging proxies, wireshark, tcpdump


## We are done talking about interpreted languages
- We aren't going to teach you Javascript, Java, Python, etc. (but if you have a question of course we'll help)
- If you need to reverse a interpreted program, it will be very avantageous to have experience in that language.

## Assembly Intro

- disclaimer: i grade for 2421 and love assembly more than necessary

- push/pop
- mov
- call
- add/sub/mul/xor/shl (plus some signed/unsigned variants)
- control flow: cmp, test, cmp (jle, jge, jne, je)

- how to call functions: the stack, conventions
- what is heap?


## Native Code - Why do we care about C
- tl;dr we don't want to look at assembly all day
- First of all, lots of things are actually written in C - Linux kernel, macOS kernel (darwin)... and many more in C derivatives (C++) - web browsers
- C is a popular 'high level' language... it has a relatively simple syntax that can represent
essentially any native program regardless of what language it was written in. (compiled C++ programs decompile to C, it's just not pretty). C has very few abstractions on top of assembly, C++ has many on top of C.
  - C has variables, but no classes. Assembly has registers and memory but no variables.

## C Intro
- idk throw some stuff on the slide, explain what it does
- pointers are hard, but like super important (slide with arrows in memory??)

## Demo: C program => Run to show what it does => Decompile and compare with original C
- at some point lets note intel vs. att syntax
- stripped / unstripped?

## See also: godbolt.org compiler explorer

## GDB Reference
- run/continue
- break *address
- step/next
- set $rax = 0
- x/whatever to print stuff
- print
- disassemble 

## Demo: GDB

## Executable formats / Loaders / system calls
- Linux uses ELF
- There are other formats
- What happens when you run a program (e.g. how does a linker/loader work)? I got asked this in an interview
- GOT table? maybe leave for pwn
- probably talk about libc somewhere
- system calls are cool

## Future topics
- uhhhhh
- angr?
- fuzzing?