# bootcamp-resources
Presentations for Spring 2021 Bootcamp CTF

| Date (tentative)  | Topic | Presenters
|-------------------|-------|--------|
| 1/19/21    | Bootcamp CTF Kickoff + Web Exploitation 1 | Andrew |
| 1/26/21           | Intro to Cryptography | Yu-Shiang |
| 2/2/21 | TBA | TBA |
| 2/9/21   | Introduction to Reverse Engineering | Kyle + Andrew |
| 2/16/21   | Introduction to Binary Exploitation | Andrew + Yu-Shiang |
| 2/23/21 (break)   | Office Hours | N/A |
| 3/2/21    |   Cryptography 2 | Yu-Shiang |
| 3/9/21    |   Introduction to Forensics | Kyle + ?|
| 3/16/21    |   Web Exploitation 2 | ? |
| 3/23/21    |   Binary Exploitation 2 | Andrew + ? |


Useful resources for presentations:
- [Purdue Training 2020 presentations](https://github.com/b01lers/bootcamp-training-2020): MIT (Attribution + include license)
- [GreyHat (Georgia Tech) presentations](http://greyhat.gatech.edu/archives/): Unknown -- ask individual authors
- Some outlines here: https://gitlab.umich.edu/wolvsec/wolvsec-bootcamp

Be careful to credit authors and look for licenses on any material you might use from elsewhere.


How to copy the template for a new presentation
=====

- Don't copy the slides-source-dep directory.
- Copy web/slides-source/ to your-category/slides-source/
- There are a couple relative paths in the Makefile and main.tex.
    - main.tex: `\graphicspath{ {./images/}{../../slides-source-dep/images/} }`
    - Makefile: `TEXINPUTS=.:../../slides-source-dep/:$$TEXINPUTS`
    - You only need to adjust the above two things if ../../slides-source-dep/ is not the correct path.
    
    
License
=====

Ask individual authors.

Slide template is released under the MIT License, credit 'Cyber Security Club @ Ohio State'.
