# OSU Cyber Security Club Bootcamp

By: Andrew Haberlandt, Cyber Security Club @ Ohio State

Notes and slides adapted from PHSC138 (Purdue, b01lers CTF team): [Link to Original](https://github.com/b01lers/bootcamp-training-2020/tree/master/web)

### Categories

- Reversing: Usually you hope that by doing the things listed on the slidek you'll uncover a way to cause unintended behavior
-

### Ethics
- Mention something about how they should not hack something without
permission -- it's illegal to break into a computer system without consent.
- Don't try to hack a university website, that's against student code of conduct (quote the code on a slide?)

### What *is* the 'Web' category?

- When we talk about Web challenges, we are talking about a number of things
    - Server-side vulnerabilities (slide with server/client diagram + HTTP req/res -- what if you send unintended input?)
        - Sensitive data exposure / information leakage: Can you get the server to give you information you shouldn't have access to? (OWASP #3)
            - Encryption at rest / encryption in transit
        - Can a user take actions (modify data) they shouldn't be allowed to? (OWASP #5) (non-existant security checks, or bypassable)
            - Both of the above can be accomplished with injection, such as SQL injection
        - Can you login as another user or compromise their password or session tokens? (Broken Authentication - OWASP #2)
        - Can you manipulate the server's response to other law-abiding users to make the site do unintended things? (XSS - OWASP #7)
            - Think comments on an article
    - Example

- We are not talking about:
    - Exploiting a browser bug to gain control of a user's computer
- Web is a large category. Web application paradigms vary greatly from framework-to-framework
    - backend: Express (node.js), Django (python), ASP.NET (C#)
    - frontend: Angular, React, Vue)

### Why do we care?

- You interact with hundreds of websites, you give them your data, credit cards, etc., you want them to be secure
- Every website and their dog has a API for their service -- most often accessible over HTTP ('REST' etc.), these
are used by phone apps, embedded IoT devices, etc. (how did you think Amazon Echo knows what you've purchased?)
- Web technologies and techniques are (unfortunately) bleeding into desktop apps (see: Electron)
- Bug bounties, largely web applications

----

Switch screen share to Chrome

----

### HTML
- HTML stands for Hypertext Markup Language and pretty much all web pages on the internet use HTML to show users content.
- **Make an html file in your favorite editor** `test.html`
```
<html>
    <body>
        <h1>Web exploitation 1</h1>
        <p>Hi!</p>
        <p>This is an html file</p>
    </body>
</html>
```
- This is an html file, if you notice it's got opening and closing tags; they all do different things, some are containers to put other tags in, some are for links, others are buttons, literally everything you see on a web site has a tag.
- There are templating languages and frontend frameworks that change how you interact with HTML

### Inspect element
- Right click -> inspect element
- Here you can see the HTML, when you hover over something it highlights. You should play with this sometime. There's a challenge for that.
- You can also MODIFY (ie. remove 'disabled' attribute on an element, change CSS attributes, remove an element entirely)
    - Uses: try to remove paywalls from a page, Adblock
- We are going to go over a couple of the important tabs... you'll find that they are similar in other browsers
- CSS won't be too important for us, but note that you can easily hide data on a page by setting `display: none;` or hiding something behind another element


### Console
- Javascript gives applications interactivity.
    - Browsers implement a common API for interacting with HTML (the 'DOM' document object model), making network requests, and tons more
- There is server-side Javascript too, but we don't care right now
- Javascript can be added to your page right in the HTML using the `<script>` tag (or there is also a way to tell to the browser to fetch an external Javascript file)
```html
<script>
function say_hi(){
    alert("hi");
}
</script>
```
- Simple enough, let's call our function using the javascript console.
- `say_hi()`
- Wow it worked. You can do this with any global-scope variable or function
- But most websites aren't this easy. Let's try out amazon.com.
    - Minification / Obfuscation of Javascript files
    - Frameworks, ugh

### Side note about languages / frameworks
- We aren't going to cover Javascript in detail
    - This is because the amount you will need to know varies greatly challenge-to-challenge
- We aren't going to cover specific frameworks or libraries, like at all
- While domain knowledge is useful for spotting bugs, it is more useful to learn to break down unfamilar things and try to understand
how something works
    - Example: TBD... go to some website with jquery and pretend I don't know what $ is
    and show that we can Google and figure it out.
- Spotting bugs in code is hard without domain knowledge (without knowing JS you're not gonna know how strings and numbers add, etc.)
    - Writing web applications, reading CTF write-ups, and experience can be helpful for this. You start to see patterns in code 
    (some of which we'll talk about).
- But we aren't here to do code reviews. How can we figure out how something works without going line-by-line through the code?? *hint: the debugger*

### Debugger
- Next tab: the Debugger. You'll be looking at a bunch of unfamiliar code... how do you figure out how it works?
    - One useful tool: The debugger!!
- A debugger is a tool that developers use to help them remove a bug from their code.
    - We will use it to understand their code (and sometimes find bugs in their code too :)
- This is done by setting a break point at a specific line of code, then the program stops executing at that point and we can see what's going on.
- This is useful in CTF challenges because it helps us understand what the code is doing, especially if it's way more complex and gross than our simple example.
- Add variable to `hi` function
```javascript
function say_hi(){
    let message = "hi";
    alert(message);
}
```
- Set breakpoint at alert
- Change message to bye
- We've just changed how the website works. Again note that what we just did is on the client side.


### Network Tab
- Due to `<script>`, `<img>`, `<iframe>`, a bunch of other tags, additional HTTP are often made when a page loads to fetch more resources
- Can also make requests from JS
- The server side is like a 'black box' - we don't really know how it works, but we can see what was sent and received from it
- Quick demo:
1. You type into your browser `www.wikipedia.com`
    - You can see all the requests your browser makes.
        - Compare this to a request to `www.google.com`
    - We can filter the requests by clicking the html button above the list of results.
2. Your browser sends a message, in a very specific form, called a `GET` request to `www.wikipedia.com` that asks for the index
    - The index is the root, or base of the website, much like the root of the linux filesystem '/'
    - Every request is in a specific form, we can view the request by clicking on any of the entries and clicking 'headers' on the new window that appears.
    - Then scroll down to the 'Request headers' entry and select some setting to get the raw headers.
    - We can see on the first line `GET / HTTP/2` <-- this is the line that contains the most important information.
        - `GET` is the method.
        - `/` is the resource location.
        - `HTTP/2` is the protocol and version.
    - The other section of a request is called the body.
    - You can think of the headers as information about the message and the body as the message.
    - These two sections make up an HTTP request.
    - Show example of GET request with query string (google search is a good one)
3. Show POST request

### HTTP methods and Tools
- postman, HTTP client apps, Burpsuite
- One note on http methods: they are supposed to do what the 'standard' says, but the server can interpret the request however it wants.
    - The most common example is when you make a request to google.com. You aren't explicitly requesting an html file, but the server sends one anyway.
- Encodings: Sometimes data is sent encoded in a particular format (see in tool). Show some common encodings (is there any commmon site that sends stuff in base64? idk)
- DEMO: sending a request in postman


### Storage
- Cookies are key-value pairs that the website stores locally in your browser.
- Store persistent data in the user's browser -- YOU CAN CHANGE THIS DATA... you control the entire client-side.
- Session cookies

#### Demo the inspector challenge, pretty much just show off how to find all the stuff

### Future Topics

- More than HTTP requests: We also have websockets
- SSL certificates - how do they work, how can they be broken/abused?
- SQL injection / command injection / other injection
- XSS (Cross Site Scripting)
- CSRF (Cross Site Request Forgery) and the Same Origin Policy
- HTTP(S) Interception proxies
