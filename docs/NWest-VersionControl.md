# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119-L ]

- **[ Noah West ]**
- **[ 10/4/2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ Clear]: Clear the Screen
- [ pwd]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -a ]: List files and folders, including invisible files
- [ ls -lah ]: List all files and folders, in human readable form
- [ cd <directory ]: Change directory
- [ cd / ]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ I chose to use my Project Portfolio folder in here, and it seems to have now gotten the filepath for the folder that I provided all the way from my C drive. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ From what I found it's Local, Centralized, and Distributed. Local stores different versions of files on a single computer. Centralized stores the main repository on a central server that multiple users connect to. Distributed gives multiple users a complete copy of the repository and it's history on their own computers.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone <repository-url ]: Clone a repository
- [ git config --global user.name "Your Name" ]: Set-up a global user name
- [ git config --global user.email "your@email.com" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add <filename ]: Add modified files to the next commit
- [ git commit -m "Commit message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ To connect to GitHub using HTTPS, I first go to the repository on GitHub, click the Code button, select HTTPS, and copy the repository URL. In Terminal, I navigate to the folder where I want to store the repository and use `git clone <repository-url>` to clone it to my computer. If GitHub asks me to authenticate, I use my GitHub username and a personal access token. Once I've gotten that done, I can use commands such as `git pull` and `git push` to transfer changes between my local repository and GitHub. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [.gitignore tells Git which files and folders it should not track or include in commits.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [.DS_Store is a hidden file created for macOS to store folder display settings and other finder information]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [Probably some kind of build or output folder because it usually contains files that can be recreated from the source code.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ I'll be honest here I didn't really use any information here as I'm not super confident with using the terminal just yet and haven't really had a reason to due so outside of testing the commands for some of the previous questions. ]

**Terminal Commands**  
(https://dev.to/techwebster/windows-terminal-commands-cheat-sheet-for-beginners-e8l)

**Three Types of Version Control**  
(https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)

**Git Commands**  
(https://git-scm.com/cheat-sheet)

**Connecting to GitHub using Terminal**  
(https://www.geeksforgeeks.org/git/how-to-login-using-the-git-terminal/)

**Using .gitignore and Why it's Important**  
((https://github.com/orgs/community/discussions/165862)
