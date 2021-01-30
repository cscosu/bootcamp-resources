# OSU Cyber Security Club Bootcamp

By: Kyle Westhaus, Cyber Security Club @ Ohio State

(Mention Battelle sponsorship)

References:
[Trail of Bits CTF Field Guide - Forensics](https://trailofbits.github.io/ctf/forensics/)
[CTF101 - Forensics](https://ctf101.org/forensics/overview/)

## What is Forensics?

- Any time you're trying to pull extra information out of static data files (except executables and crypto)
- Some common subcategories:
    - Image/audio/video files (including steganography)
    - Archive files
    - Disk/filesystem images
    - Network packet captures
    - Memory dumps
    - Weird file formats

## In the Real World

- Incident response within a company or law enforcement seeking attribution
    - e.g. This machine is acting sus. Is it compromised? If so, how? What data do we need to worry about getting leaked? Did they infect other hosts? Communicate back home? Given data, have to answer questions on it.
- CTF problems can seem a bit contrived
    - "One would typically not bust a criminal case by carefully reassembling a corrupted PNG file, revealing a photo of a QR code that decodes to a password for a zip archive containing an NES rom that when played will output the confession." - Trail of Bits CTF Field Guide
- However, still good at teaching you where to search for clues on a computer and exposing you to lots of different terms of technologies that you may need in the future

## Just Bytes

- When your computer opens a PDF, it shows you a document.
- When your computer opens a JPEG, it shows you an image.
- But under the hood, these files are just bytes, so you could force a text editor to open them and just show you the bytes instead of display them as a document or image.
- Problem: text editors just show ASCII bytes. Solution: hex editor.

## Demo: Hex Editor

- Open PDF and JPEG normally, then in hex editor
- So how do does image viewer know how to turn bytes from file into image?

## Important Concept: File Format

- "format" - agreed upon pattern of bytes. Programs write data in these formats so that the next program to open the file knows how to read it and get the data it represents
- All JPEG images conform to a specification that says how the bytes of the file represent pixels of colors that can be displayed
- So how do these programs know what format a file is?
    - NOT file extension but "magic bytes"
    - "magic bytes" means "these special characters at this offset into the file" -> indicator of this file type, follow the rules for opening that kind of file

## Demo: `file`/libmagic

- Just to prove that it's not extension, change an extension and show a file still opens
- Open hex editor and show magic bytes for PNG, change them and show file fails to open
- So, if you want to ID a file, you can open it in a hex editor and see if you recognize any magic bytes, but that's not very efficient
    - Solution: `file` is a command on Linux which already has a database of magic bytes for a bunch of different file formats and will automatically check those and let you know if any match. So if we give you a file with a random extension, you can probably figure out what kind of file format it is quickly using `file`!

## Common File Formats
- Zip, TAR, Gzip, 7zip, RAR -> archive file, can be unzipped
- Jpeg, GIF, BMP, PNG, TIF -> image files, can be viewed
- PCap, PCapNG -> packet captures, we'll be talking about these later
- PDF -> portable document format, can be viewed
- WAV, MP3, MP4 -> audio/video, can be viewed
- DOC(X), ODT -> word documents, can be viewed

## So you've identified the file format for it, now what?

- Check what happens when you open it in the intended fashion (e.g. is it just a PNG where the image shows the flag or a base64-version of it?)
- Check if there's a [diagram](https://github.com/corkami/pics/tree/master/binary) for it
- Google search any of the strings that get output when you run `file` on it
- Research the file format a bit. Are there any non-data sections (like comments, version strings, etc) where you could easily hide a flag without it normally showing up?
- Try to find tools that help you analyze or inspect that file format instead of just viewing it

## Image Forensics

## Packet Captures (if time?)



-------------------------------------------------------------------------------
## WIP

also `strings` for when file fails
chals: removed/false file extension

once have magic bytes, how do programs know to open file? follow the instructions - "specifications"
(demo) some file specification
chals: corrupted


pick one (multimedia and stego? mentioning binwalk is a must, but we have a lot of wireshark challenges already...) then rest future sessions?
- common file formats
- file carving (or just quickly mention?)
- archive files
- multimedia (stego)
- filesystem/disk image
- network capture
- memory dump

## 
