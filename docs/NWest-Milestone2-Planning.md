> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Reabs
  
**What does your program currently do? (1–3 sentences)**   
→ Weapon customization is working but not every part is implemented. The user is able to partially build a weapon right now and then can test it at the firing range. Action points are also implemented and a turn counter so the user can check how well their weapon performs.

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   Damage calculation works perfectly right now and so does most of the other weapon systems. My weapon customizer even works even with the limited pieces I have implemented.
  
**What is NOT working or incomplete?**   
→   The user needs to be able to select the health and armor of the target dummy. On top of this the rest of the weapon parts need to be implemented into the system.
  
**What feels confusing or messy in your code?**   
→ It's honestly always been design, but I've been figuring it out as I go. It does help writing a list down almost as pseudocode in order to better organize and create what I need in the moment.

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   Weapon Customizer
→   
  
**What does this feature do?**   
→   Let's the user Create and Name their weapon.
  
**Why is this feature important?**   
→   This is the main function of the program as it's what determines what stats are used in the fight against the target dummy at the firing range.
  
---
### Feature 2  
**Name:**   Save/Load Weapon
→   
  
**What does this feature do?**   
→   Stores User made presets for weapons so they can save and load weapons anytime they want. That way when they wanna use or pull a weapon they've made they can go test at the firing range they can. 
  
**Why is this feature important?**   
→   This will allow Users to actually save their creations for later use.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  
**What does this feature do?**   
→   
  
**Why is this feature important?**   
→   
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   No, I'm keeping everything within the classes I currently have.
  
**Will you modify any existing classes? How?**   
→   Yes, Weapon for example still needs the rest of it's weapon parts and the Game menu needs some extra systems.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   I've mainly been using enums for the Weapon parts, which has been interesting since I've not really used enums as much before so it's nice practice.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   User is prompted with a menu to Customize a weapon, Load a Weapon, Go to the firing range, or exit the program.
2. User chooses →   Customize weapon
3. Program responds →   Pulls up customizer weapon that allows the user to create and modify their currently selected weapon
4. Loop/next step →   Weapon customizer runs until the user confirms and exits heading back to the main menu to check out any of the other options.
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Reformating menus to make it easier for the user to navigate around.
  
- Better error handling:   
→   Error handling is already pretty good with the input validation I already implemented into the menuHandler function I made.
  
- Improved menu/navigation:   
→   UI Updates and menu reworks to include all of my planned functions. It won't change too much from what it looks like right now though.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   File IO is something I'm not super strong on just yet.
  
**What is your plan if you get stuck?**   
→   Review previous labs and notes to get a better idea for what to do. If I'm really stuck past that I'll ask a question in the discord or look online to get more research on file/io
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Class Design
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Continuing to write out functions and my design before actually writing it so I have a clearer path of what I'm building.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [x]   Weapon Customizer Function
- [x]   Create Magazine
- [x]   Set up Load function with File/IO
- [x]   Set up Save Function with File/IO
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.