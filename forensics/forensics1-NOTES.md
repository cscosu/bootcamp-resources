# OSU Cyber Security Club Bootcamp

By: Kyle Westhaus, Cyber Security Club @ Ohio State

(Mention Battelle sponsorship)

References:
[Trail of Bits CTF Field Guide - Forensics](https://trailofbits.github.io/ctf/forensics/)
[CTF101 - Forensics](https://ctf101.org/forensics/overview/)

## Announcements (7:05)

## What is Forensics? (7:10)

- Any time you're trying to pull extra information out of static data files (except executables and crypto)
- Some common subcategories:
    - Image/audio/video files (including steganography)
    - Network packet captures
    - Archive files
    - Disk/filesystem images
    - Memory dumps
    - ...and many more

## In the Real World

- Incident response within a company or law enforcement seeking attribution
    - e.g. This machine is acting sus. Is it compromised? If so, how? What data do we need to worry about getting leaked? Did they infect other hosts? Communicate back home? Given data, have to answer questions on it.
- CTF problems can seem a bit contrived
    - "One would typically not bust a criminal case by carefully reassembling a corrupted PNG file, revealing a photo of a QR code that decodes to a password for a zip archive containing an NES rom that when played will output the confession." - Trail of Bits CTF Field Guide
- However, still good at teaching you where to search for clues on a computer and exposing you to lots of different terms of technologies that you may need in the future

## Just Bytes (7:15)

- When your computer opens a PDF, it shows you a document.
- When your computer opens a JPEG, it shows you an image.
- But under the hood, these files are just bytes, so you could force a text editor to open them and just show you the bytes instead of display them as a document or image.
- Problem: text editors just show ASCII bytes. Solution: hex editor.

## Demo: Hex Editor

- Open PDF and JPEG normally, then in hex editor
- So how do does image viewer know how to turn bytes from file into image?

## Important Concept: File Format (7:20)

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

## Common File Formats (7:25)
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

## Demo: `strings`

- quickly search for long sequences of ASCII characters -> possibly hidden information, but not file format aware

## Multimedia Forensics Example

- JPEG images store metadata in "EXIF tags"
    - A perfect non-data section to hide info like flags in!

## Demo: ExifTool

- Open image normally and in hex editor and find nothing, then find base64 flag with exiftool
- exiftool is file format aware
- Many other ways to hide data in images (steganography) but we won't cover those today

## Network Forensics (7:35)

## Networking, a Simplified View

- Computers send data in chunks called packets
- Each computer has an address that you can put in a sent packet to make sure they receive it
- Can use tools to capture the packets that your computer is sending and analyze them

## Protocols

- The networking equivalent of file formats
- Describe who should send packets when, and what data will be present in the packets
- Protocol "layers" - some packets contain packets of other protocols

## Common Protocols

- IP -> address for each computer, contains:
    - TCP or UDP -> address (port) for each program on a computer, contains:
        - SSL/TLS -> encrypted tunnel
        - HTTP(S) -> web browsing
        - SSH, telnet (insecure!) -> remote administration
        - DNS -> convert human-readable address ("google.com") to computer address (172.217.4.206)
        - FTP -> file transfer protocol

## Demo: Wireshark (7:40)

- Wireshark can both capture packets and analyze them
- netcat
- HTTP example.com
- HTTPS example.com
- DNS from browser to NEW vs old website

## Recommended Challenges (Points) (7:50)

- General forensics
    - revgrep (5)
    - MyPlanForWorldDomination (6)
- Network forensics
    - JustAPacket (10)
    - Exfiltration (20)
    - TLS (75)

## Future Topics

- Archive files/file carving
- Disk/filesystem images
- Memory dumps
- Steganography


## Questions (7:55)

-------------------------------------------------------------------------------
## WIP

chals: removed/false file extension, corrupted, rest of network captures

