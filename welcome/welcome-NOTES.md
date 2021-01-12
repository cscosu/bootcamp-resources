# OSU Cyber Security Club Bootcamp

## Welcome Back - SP21

By: Kyle Westhaus, Cyber Security Club @ Ohio State

Template By: Andrew Haberlandt, Cyber Security Club @ Ohio State

## Reminders
[comment]: <> (Just a refresher on member resources)

### Reminder - Officers
- Kyle Westhaus, President
- Yu-Shiang Jeng, Vice President
- Andrew Haberlandt, Treasurer
- Jackson Leverett, CTF Captain
- Nick Kuhl, Outreach Coordinator

### Reminder - Communication/Links
[comment]: <> (Drop attendance link in chat, tell them to fill out while going over rest of slide)
- Attendance (because the College of Engineering and OSU make us): http://attend.osucyber.club
- Mailing list: sign up at http://mailinglist.osucyber.club
- Slack: sign up at http://slack.osucyber.club
- Website: http://osucyber.club
- Wiki: http://wiki.osucyber.club

## Bootcamp Explanation

### Feedback Results
- CTF-specific survey, club survey
- People wanted:
    - better cohesion between meetings
    - more hands-on experiences
    - preparation for the CTF, not just the competition itself 

### Our Past CTFs
- weekend-long
- range of challenge difficulty levels
- but little background info about how prepare an environment and begin competing

### The Plan
- floated idea of "Bootcamp" in winter break feedback - something other clubs have done before (Purdue)
- series of meetings dedicated to teaching those with minimal CTF experience how to be successful
    - CTF background info
    - technical knowledge for challenge categories
    - wiki content about environment/tool setup
    - challenges hosted all semester!

### This Semester
- Tonight: background on CTFs
- Next week: more Bootcamp CTF specifics, start of actual bootcamp content
- Rest of semester: more technical education content for challenge categories, you participate and use what you learn in meeting to complete more and more challenges and get prizes along the way

## CTF Background

### Capture the Flag
- "flags" -> short snippets of identifiable text (e.g. osuctf{theflagincludesthestuffbeforethebraces} or osuctf{l33tsp34k})
- not so much "find this text hidden somewhere on a computer", but rather "complete this technical challenge, the flag will be apparent at the end" (e.g. "this ciphertext is weakly encoded, decode it to get the plaintext flag")

### Why CTF?
- very popular for college clubs like our own because:
    - very effective way to learn
    - very effective way to demonstrate skills to future employers
    - fun competition

### CTF Format
- mostly jeopardy
    - many problems, grouped by category, each has an associated number of points, available for a certain amount of time
    - solve a challenge, submit flag, receive points
    - team with most points at end of competition wins
    - sometimes additional rules (e.g. only a few challenges unlocked at start, first team to solve gets to pick next unlocked challenge)
- king of the hill
- red/blue team

### CTF Interface
- usually a website for registration, team creation, list of challenges, flag submission, scoreboard
- extremely common software to run this part of a CTF is CTFd
- screenshot

### Interacting with Challenges
[comment]: <> (Mention that we will teach people to solve these)
- downloadable file in challenge description
    - demo base64, open in text editor
- URL for service to attack
    - demo Somewhat Questionable LLC, open in browser
    - demo speedrun3, view source, connect with netcat

### Need for CTF Tools
- when using any standard operating system, you can automatically do the following with challenges
- downloadable
    - look at file in file explorer, maybe extract, open in text editor
- service URL
    - open in web browser, something like netcat
- but often times you need to do more! solution:
    - use recommended tools (see the wiki!)
    - do your own searching to find helpful tools
    - write your own code

### Tool Examples (add screenshots or demo)
- web tool (cryptii)
- downloadable program with GUI (ghidra)
- downloadable terminal program (urlbuster)
- python library (pwntools)

### How do I find CTFs?
- we're hosting a semester-long one!
- other universities run them!
- conferences run them!
- CTF teams host their own!
- all on a list at https://ctftime.org/ (DEMO)

### Other Content
- livestreams/youtube videos of people solving CTFs
- CTF challenge solution writeups (github or blogs)

## Wrap Up
- questions now
- slack for questions later
- come back next week!
